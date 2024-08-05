#ifndef TESTS_HELPER_H_
#define TESTS_HELPER_H_
#include <stdio.h>
#include <string.h>
#define NELEMS(arr) (sizeof(arr) / sizeof(arr[0]))

static struct
{
    int passedCount;
    int failCount;
    char calls[1024][128];
    char printBuff[4096];
} testStatus = {0, 0, {{0, 0}}, "\0"};

#define ERR(fmt, ...) \
    do { \
        sprintf(testStatus.printBuff, fmt, __VA_ARGS__); \
        fprintf(stderr, "FAILED: %s(%d): %s\n", __func__, __LINE__, testStatus.printBuff); \
    } while (0)

#define FAIL_MSG(fmt, ...) ERR(fmt, __VA_ARGS__);

#define ASSERT(x) \
    if (!(x)) { \
        testStatus.failCount++; \
        ERR("Assertion failed: %s", #x); \
    } else { \
        testStatus.passedCount++; \
    }

#define TEST_RESET_CALLS() memset(testStatus.calls, '\0', sizeof(testStatus.calls))

#define TEST_SUMMARY() \
    if (0 != testStatus.failCount) { \
        fprintf(stderr, \
                "Test suite failed with %d fails out of %d total assertions.\n", \
                testStatus.failCount, \
                testStatus.failCount + testStatus.passedCount); \
    }

#define TEST_RESULT() (testStatus.failCount)

#define TEST_REGISTER_CALL() \
    do { \
        char *callRecord = NULL; \
        for (char *fundCallRecord = testStatus.calls[0]; \
             fundCallRecord != testStatus.calls + NELEMS(testStatus.calls); \
             fundCallRecord++) { \
            callRecord = fundCallRecord; \
        } \
        if (NULL != fundCallRecord) { \
            snprintf(fundCallRecord, sizeof(testStatus.calls[0]), "%s", __func__); \
        } else { \
            fprintf(stderr, "failed to register function call"); \
        } \
    } while (0)
#endif
