#ifndef NVM_H
#define NVM_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

enum nvmStatus {
    nvmStatusOk = 0,
    nvmStatusReadErr,
    nvmStatusWriteErr,
    nvmStatusNotInitialized,
    nvmStatusUnknownErr,
    nvmStatusInvalidParam,
    nvmMemoryAllocationFailed,
    nvmStatusNotImplemented,

    nvmStatusMax
};

struct nvmDescription
{
    bool isInitialized;
    size_t size;
    size_t pageSize;
};

struct nvmInstance;

enum nvmStatus nvmInit(struct nvmInstance **nvmInstance, struct nvmDescription desc);

enum nvmStatus nvmWirte(struct nvmInstance *nvmInstance,
                        size_t address,
                        size_t size,
                        const uint8_t *data);
enum nvmStatus nvmRead(struct nvmInstance *nvmInstance, size_t address, size_t size, uint8_t *data);
enum nvmStatus nvmErasePages(struct nvmInstance *nvmInstance, size_t pageNumber, size_t pagesCount);
enum nvmStatus nvmDeinit(struct nvmInstance **nvmInstance);
enum nvmStatus nvmEraseAll(struct nvmInstance *nvmInstance);

#endif // NVM_H
