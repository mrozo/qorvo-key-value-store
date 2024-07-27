#include "../nvmPrivate.h"
#include <stdio.h>
#include <string.h>
static struct
{
    int passedCount;
    int failCount;
} testStatus = {0, 0};

char printBuff[4096] = {'\0'};

#define ERR(fmt, ...) \
    do { \
        sprintf(printBuff, fmt, __VA_ARGS__); \
        fprintf(stderr, "FAILED: %s(%d): %s\n", __func__, __LINE__, printBuff); \
    } while (0)

#define FAIL_MSG(fmt, ...) ERR(fmt, __VA_ARGS__);

#define ASSERT(x) \
    if (!(x)) { \
        testStatus.failCount++; \
        ERR("Assertion failed: %s", #x); \
    } else { \
        testStatus.passedCount++; \
    }

#define ASSERT_OK(x) \
    do { \
        enum nvmStatus status = (x); \
        if (nvmStatusOk != status) { \
            testStatus.failCount++; \
            FAIL_MSG(#x " returned error %d", status); \
        } else \
            testStatus.passedCount++; \
    } while (0)

bool isMemFilledWith(const uint8_t *mem, uint8_t val, size_t memSize)
{
    for (const uint8_t *end = mem + memSize - 1; mem <= end; mem++) {
        if (*mem != val)
            return false;
    }
    return true;
}

bool isNvmFormatted(const struct nvmInstance *nvm)
{
    return isMemFilledWith(nvm->memory, 0xFF, nvm->size);
}

void testNvmInitDeinit(void)
{
    struct nvmInstance *nvm = NULL;
    struct nvmDescription nvmDesc = {
        .size = 8192,
        .pageSize = 4096,
    };
    ASSERT_OK(nvmInit(&nvm, nvmDesc));
    ASSERT(8192 == nvm->size);
    ASSERT(4096 == nvm->pageSize);
    ASSERT(isNvmFormatted(nvm));
    ASSERT_OK(nvmDeinit(&nvm));
}

void testNvmWriteRead(void)
{
    struct nvmInstance *nvm = NULL;
    struct nvmDescription nvmDesc = {
        .size = 8192,
        .pageSize = 4096,
    };
    ASSERT_OK(nvmInit(&nvm, nvmDesc));

    uint8_t testBuff[128] = {0xAC};
    size_t address = 0;

    ASSERT(nvmStatusInvalidParam == nvmWirte(NULL, address, sizeof(testBuff), testBuff));

    ASSERT_OK(nvmWirte(nvm, address, sizeof(testBuff), testBuff));
    ASSERT(0 == memcmp(testBuff, nvm->memory + address, sizeof(testBuff)))

    uint8_t zeroes[128] = {0x00};
    ASSERT_OK(nvmWirte(nvm, address, sizeof(zeroes), zeroes));
    ASSERT(0 == memcmp(nvm->memory + address, zeroes, sizeof(zeroes)));

    // we cant set 0 back to 1 without reformatting
    ASSERT_OK(nvmWirte(nvm, address, sizeof(testBuff), testBuff));
    ASSERT(0 == memcmp(nvm->memory + address, zeroes, sizeof(zeroes)));

    ASSERT_OK(nvmDeinit(&nvm));
}

void testNvmErasePages(void)
{
    struct nvmInstance *nvm = NULL;
    struct nvmDescription nvmDesc = {
        .size = 8192,
        .pageSize = 4096,
    };
    ASSERT_OK(nvmInit(&nvm, nvmDesc));

    ASSERT(nvmStatusInvalidParam == nvmErasePages(NULL, 1024, 1));
    ASSERT(nvmStatusInvalidParam == nvmErasePages(nvm, 1024, 1));
    ASSERT(nvmStatusInvalidParam == nvmErasePages(nvm, 0, 1024));

    const uint8_t testBuff[128] = {0xAC};
    uint8_t ones[128];
    memset(ones, 0xff, sizeof(ones));
    size_t address = 0;
    ASSERT_OK(nvmWirte(nvm, address, sizeof(testBuff), testBuff));
    ASSERT(0 == memcmp(testBuff, nvm->memory + address, sizeof(testBuff)));

    unsigned int page = 0;
    unsigned int pageCount = 1;
    ASSERT_OK(nvmErasePages(nvm, page, pageCount));
    ASSERT(0 == memcmp(ones, nvm->memory + address, sizeof(ones)))

    ASSERT_OK(nvmDeinit(&nvm));
}

void testNvmEraseAll(void)
{
    struct nvmInstance *nvm = NULL;
    struct nvmDescription nvmDesc = {
        .size = 8192,
        .pageSize = 4096,
    };
    ASSERT_OK(nvmInit(&nvm, nvmDesc));

    size_t address = 0;
    const uint8_t testBuff[128] = {0xAC};
    ASSERT_OK(nvmWirte(nvm, address, sizeof(testBuff), testBuff));

    address = 4096; //second page
    ASSERT_OK(nvmWirte(nvm, address, sizeof(testBuff), testBuff));
    ASSERT(!isNvmFormatted(nvm));

    ASSERT(nvmStatusOk != nvmEraseAll(NULL));
    ASSERT_OK(nvmEraseAll(nvm));
    ASSERT(isNvmFormatted(nvm));

    ASSERT_OK(nvmDeinit(&nvm));
}

int main(int argc, char *argv[])
{
    testNvmInitDeinit();
    testNvmWriteRead();
    testNvmErasePages();
    testNvmEraseAll();
    if (0 != testStatus.failCount) {
        fprintf(stderr,
                "Test suite failed with %d fails out of %d total assertions.\n",
                testStatus.failCount,
                testStatus.failCount + testStatus.passedCount);
    }
    return testStatus.failCount;
}
