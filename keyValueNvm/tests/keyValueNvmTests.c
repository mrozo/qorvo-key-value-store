#include "../keyValueNvm_private.h"
#include <Mocknvm.h>
#include <keyValue.h>
#include <nvm.h>
#include <string.h>
#include <unity.h>

#define ASSERT_OK(x) TEST_ASSERT_EQUAL_INT(gpNvm_Result_OK, (x))

int nvmContextFake;
struct gpNvm_nvmInterface nvmMock;
extern struct keyValueNvm_instance kvSingleton;
struct nvmReadCallbackReturn
{
    uint8_t data[KEY_VALUE_PARTITION_BLOCK_SIZE_B];
} nvmReadCallbackReturnData;

enum nvmStatus nvmReadCallback(struct nvmInstance *nvmInstance,
                               size_t address,
                               size_t size,
                               uint8_t *data,
                               int cmock_num_calls)
{
    memcpy(data, nvmReadCallbackReturnData.data, size);
    // cmock does not check return status of callback
    return nvmStatusOk;
}

void setup_gpNvm(void)
{
    const uint8_t test_vector_partition_header[KEY_VALUE_PARTITION_BLOCK_SIZE_B] = {
        /*magic number*/ 0xDE,
        0xAD,
        0xBE,
        0xEF,
        /* block size */ 0x00,
        0x00,
        0x00,
        0x80,
        /* reseved */ 0xff,
    };
    memcpy(nvmReadCallbackReturnData.data,
           test_vector_partition_header,
           sizeof(nvmReadCallbackReturnData.data));
    nvmRead_AddCallback(nvmReadCallback);
    nvmRead_ExpectAndReturn(nvmMock.ctx, 0, 128, kvSingleton.buffer, nvmStatusOk);

    ASSERT_OK(gpNvm_init(&nvmMock));
}

void setUp(void)
{
    nvmContextFake = 0;
    nvmMock = (struct gpNvm_nvmInterface){
        .write = (gpNvm_write) nvmWirte,
        .read = (gpNvm_read) nvmRead,
        .erasePages = (gpNvm_erasePages) nvmErasePages,
        .format = (gpNvm_format) nvmEraseAll,
        .getInfo = (gpNvm_getInfo) nvmGetInfo,
        .ctx = (void *) &nvmContextFake,
    };
    // TODO move to gpNvm_deinit()
    memset(&kvSingleton, 0x00, sizeof(kvSingleton));

    memset(&nvmReadCallbackReturnData, 0x00, sizeof(nvmReadCallbackReturnData));
    setup_gpNvm();
}
void tearDown(void) {}

void test_init(void)
{
    TEST_ASSERT_EQUAL_INT(gpNvm_Result_INVALID_PARAMETER, gpNvm_init(NULL));

    const uint8_t invalid_partition_header[KEY_VALUE_PARTITION_BLOCK_SIZE_B]
        = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

    memcpy(nvmReadCallbackReturnData.data,
           invalid_partition_header,
           sizeof(nvmReadCallbackReturnData.data));
    nvmRead_AddCallback(nvmReadCallback);
    nvmRead_ExpectAndReturn(nvmMock.ctx, 0, 128, kvSingleton.buffer, nvmStatusNotInitialized);
    TEST_ASSERT_EQUAL_INT(gpNvm_Result_INVALID_PARTITION, gpNvm_init(&nvmMock));
}

void test_mkBlock(void)
{
    const uint8_t blockId = 0x0f;
    const uint8_t testData[] = {0xDE, 0xAD, 0xBE, 0xEF};
    const uint8_t expectedBlock[] = {0x0f, 0x0E, 0x00, 0x04, 0xac, 0xac, 0xDE, 0xAD, 0xBE, 0xEF};

    size_t dataWritten = 0;
    uint8_t subBlockNumber = 0;
    uint8_t block[KEY_VALUE_PARTITION_BLOCK_SIZE_B];

    ASSERT_OK(mkBlock(
        block, sizeof(block), blockId, testData, sizeof(testData), &subBlockNumber, &dataWritten));

    TEST_ASSERT_EQUAL_MEMORY(expectedBlock, block, sizeof(expectedBlock));
}

void test_mkBigBlock(void)
{
    const uint8_t blockId = 0xaf;
    uint8_t bigData[361]; //almost 3 blocks
    for (uint32_t i = 0; i < sizeof(bigData); i++)
        bigData[i] = (uint8_t) (i & 0xff);

    // TODO: replace expected block generation with a proper test vectors
    uint8_t expectedFirstBlock[KEY_VALUE_PARTITION_BLOCK_SIZE_B]
        = {blockId, 0x3E, 0x0, 0x7a, 0xac, 0xac};
    memcpy(expectedFirstBlock + KEY_VALUE_BLOCK_DATA_OFFSET, bigData, KEY_VALUE_BLOCK_DATA_MAX_SIZE);

    uint8_t expectedSecondBlock[KEY_VALUE_PARTITION_BLOCK_SIZE_B]
        = {blockId, 0x3E, 0x01, 0x7a, 0xac, 0xac};
    memcpy(expectedSecondBlock + KEY_VALUE_BLOCK_DATA_OFFSET,
           bigData + KEY_VALUE_BLOCK_DATA_MAX_SIZE,
           KEY_VALUE_BLOCK_DATA_MAX_SIZE);

    uint8_t expectedThirdBlock[KEY_VALUE_PARTITION_BLOCK_SIZE_B]
        = {blockId, 0x3E, 0x02, 0x75, 0xac, 0xac};
    memset(expectedThirdBlock + KEY_VALUE_BLOCK_DATA_OFFSET, 0xff, KEY_VALUE_BLOCK_DATA_MAX_SIZE);
    memcpy(expectedThirdBlock + KEY_VALUE_BLOCK_DATA_OFFSET,
           bigData + (2 * KEY_VALUE_BLOCK_DATA_MAX_SIZE),
           sizeof(bigData) - (2 * KEY_VALUE_BLOCK_DATA_MAX_SIZE));

    size_t dataWritten = 0;
    uint8_t subBlockNumber = 0;
    uint8_t block[KEY_VALUE_PARTITION_BLOCK_SIZE_B];

    TEST_ASSERT_EQUAL_INT(gpNvm_Result_OK_CONTINUE,
                          mkBlock(block,
                                  sizeof(block),
                                  blockId,
                                  bigData,
                                  sizeof(bigData),
                                  &subBlockNumber,
                                  &dataWritten));
    TEST_ASSERT_EQUAL_MEMORY(expectedFirstBlock, block, sizeof(expectedFirstBlock));

    TEST_ASSERT_EQUAL_INT(gpNvm_Result_OK,
                          mkBlock(block,
                                  sizeof(block),
                                  blockId,
                                  bigData,
                                  sizeof(bigData),
                                  &subBlockNumber,
                                  &dataWritten));
    TEST_ASSERT_EQUAL_MEMORY(expectedSecondBlock, block, sizeof(expectedSecondBlock));
    ASSERT_OK(mkBlock(
        block, sizeof(block), blockId, bigData, sizeof(bigData), &subBlockNumber, &dataWritten));
    TEST_ASSERT_EQUAL_MEMORY(expectedThirdBlock, block, sizeof(expectedThirdBlock));
}

void test_mkBlockBadParams(void)
{
    uint8_t block[128] = {0};
    uint8_t data[64] = {0};
    uint8_t id = 12;
    uint8_t subBlockNumber = 0;
    size_t dataWritten = 0;
    TEST_ASSERT_EQUAL_INT(gpNvm_Result_INVALID_PARAMETER,
                          mkBlock(NULL, 128, id, data, sizeof(data), &subBlockNumber, &dataWritten));
    TEST_ASSERT_EQUAL_INT(gpNvm_Result_INVALID_PARAMETER,
                          mkBlock(block, 0, id, data, sizeof(data), &subBlockNumber, &dataWritten));
    TEST_ASSERT_EQUAL_INT(gpNvm_Result_INVALID_PARAMETER,
                          mkBlock(block, 128, id, NULL, sizeof(data), &subBlockNumber, &dataWritten));
    TEST_ASSERT_EQUAL_INT(gpNvm_Result_INVALID_PARAMETER,
                          mkBlock(block, 128, id, data, 0, &subBlockNumber, &dataWritten));
    TEST_ASSERT_EQUAL_INT(gpNvm_Result_INVALID_PARAMETER,
                          mkBlock(block, 128, id, data, sizeof(data), NULL, &dataWritten));
    TEST_ASSERT_EQUAL_INT(gpNvm_Result_INVALID_PARAMETER,
                          mkBlock(block, 128, id, data, sizeof(data), &subBlockNumber, NULL));
}

enum nvmStatus nvmReadCallbackReturn0xFF(struct nvmInstance *nvmInstance,
                                         size_t address,
                                         size_t size,
                                         uint8_t *data,
                                         int cmock_num_calls)
{
    memset(data, 0xff, size);
    // cmock does not check return status of callback
    return nvmStatusOk;
}

void test_findFreeBlock(void)
{
    struct nvmDescription nvmInfo = {.size = 8192, .pageSize = 4096};
    nvmGetInfo_ExpectAndReturn(nvmMock.ctx, nvmInfo);

    nvmRead_AddCallback(nvmReadCallbackReturn0xFF);
    nvmRead_ExpectAndReturn(nvmMock.ctx,
                            KEY_VALUE_FIRST_BLOCK_ADDRESS,
                            6,
                            kvSingleton.buffer,
                            nvmStatusOk);
    size_t address = 0;
    findFreeBlock(&address);
}
enum nvmStatus nvmReadCallbackReturn0x00(struct nvmInstance *nvmInstance,
                                         size_t address,
                                         size_t size,
                                         uint8_t *data,
                                         int cmock_num_calls)
{
    memset(data, 0x00, size);
    // cmock does not check return status of callback
    return nvmStatusOk;
}

void test_findFreeBlockWhenFull(void)
{
    size_t nvmSize = 8192;
    struct nvmDescription nvmInfo = {.size = nvmSize, .pageSize = 4096};
    nvmGetInfo_ExpectAndReturn(nvmMock.ctx, nvmInfo);

    nvmRead_AddCallback(nvmReadCallbackReturn0x00);
    // TODO replace for loop with ignore args
    // f*** unity does not clear xxxx_expectAndReturn between tests!
    for (int i = 0; i < (nvmSize / KEY_VALUE_PARTITION_BLOCK_SIZE_B) - 1; i++) {
        nvmRead_ExpectAndReturn(nvmMock.ctx,
                                KEY_VALUE_FIRST_BLOCK_ADDRESS
                                    + (i * KEY_VALUE_PARTITION_BLOCK_SIZE_B),
                                6,
                                kvSingleton.buffer,
                                nvmStatusOk);
    }
    size_t address = 0;
    findFreeBlock(&address);
}

void test_setAttribute(void)
{
    uint8_t data[] = {0xDE, 0xAD, 0xBE, 0xEF};
    uint8_t id = 12;

    nvmRead_AddCallback(nvmReadCallbackReturn0xFF);
    nvmRead_ExpectAnyArgsAndReturn(nvmStatusOk);
    size_t nvmSize = 8192;
    struct nvmDescription nvmInfo = {.size = nvmSize, .pageSize = 4096};
    nvmGetInfo_ExpectAndReturn(nvmMock.ctx, nvmInfo);
    // TODO werify written block
    nvmWirte_ExpectAnyArgsAndReturn(nvmStatusOk);
    ASSERT_OK(gpNvm_SetAttribute(id, sizeof(data), data));
}

void test_getAttribute(void)
{
    const uint8_t expectedData[128] = {0xDE, 0xAD, 0xBE, 0xEF};
    uint8_t data[sizeof(expectedData)];
    size_t dataSize = sizeof(expectedData);
    const uint8_t id = 12;

    size_t nvmSize = 8192;
    struct nvmDescription nvmInfo = {.size = nvmSize, .pageSize = 4096};
    nvmGetInfo_ExpectAndReturn(nvmMock.ctx, nvmInfo);

    // TODO replace with a proper test vector
    uint8_t dataBlock[KEY_VALUE_PARTITION_BLOCK_SIZE_B]
        = {id, 0x0E, 0x00, 0x04, 0xAC, 0xAC, 0xDE, 0xAD, 0xBE, 0xEF};
    memset(dataBlock + 9, 0xff, sizeof(dataBlock) - 9);
    memcpy(nvmReadCallbackReturnData.data, dataBlock, sizeof(dataBlock));
    nvmRead_AddCallback(nvmReadCallback);

    nvmRead_ExpectAnyArgsAndReturn(nvmStatusOk);
    ASSERT_OK(gpNvm_GetAttribute(id, &dataSize, data));
}

int main(int argc, char *argv[])
{
    UNITY_BEGIN();
    RUN_TEST(test_init);
    RUN_TEST(test_mkBlock);
    RUN_TEST(test_mkBigBlock);
    RUN_TEST(test_mkBlockBadParams);
    RUN_TEST(test_findFreeBlock);
    RUN_TEST(test_findFreeBlockWhenFull);
    RUN_TEST(test_setAttribute);
    RUN_TEST(test_getAttribute);
    // TODO test_getBigAttribute
    // TODO test_setBigAttribute

    return UNITY_END();
}
