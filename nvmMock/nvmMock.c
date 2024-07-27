/**
 * @file nvmMock.c
 * @biref A simple mock of an nvm storage created for testing higher level libraries that depend on nvm memory.
 * 
 * This mock implements a simple in memory storage that behaves like a nand memory - that is:
 * 1. split into pages
 * 2. each page can be erased independently
 * 3. erasing page change its contents to 0xfff...
 * 4. writing data can only change bits from 1 to 0, not the other way around
 */

#include "nvmPrivate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief nvmInit Allocate and initialize nvmInstance object.
 * @param nvmInstance[out] pointer to allocated instance.
 * @param desc Struct that describes the memory - its total size, page size etc.
 * @return nvmStatusOk on success. In case of an error nvmInstance is set to NULL.
 */
enum nvmStatus nvmInit(struct nvmInstance **nvmInstance, struct nvmDescription desc)
{
    if (NULL != *nvmInstance)
        return nvmStatusInvalidParam;

    *nvmInstance = malloc(sizeof(struct nvmInstance) + desc.size);
    if (NULL == *nvmInstance)
        return nvmMemoryAllocationFailed;

    memset((*nvmInstance)->memory, 0xff, desc.size);

    (*nvmInstance)->size = desc.size;
    (*nvmInstance)->pageSize = desc.pageSize;
    return nvmStatusOk;
}

/**
 * @brief nvmDeinit Deinitialize nvm mock and free used resources.
 * @param nvmInstance pointer to nvmInstance. The pointer will be set to NULL.
 * @return nvmStatusOk on success.
 */
enum nvmStatus nvmDeinit(struct nvmInstance **nvmInstance)
{
    if (NULL == nvmInstance || NULL == *nvmInstance)
        return nvmStatusInvalidParam;
    free(*nvmInstance);
    *nvmInstance = NULL;
    return nvmStatusOk;
}

/**
 * @brief nvmWirte Write data to an address. This function will only turn bits from 1 to 0 like a nand flash.
 * 
 * This function makes sure that memory block given by address and size does not exceeds size of the mocked flash.
 * 
 * @param nvmInstance
 * @param address
 * @param size
 * @param data
 * @return nvmStatusOk on success
 */
enum nvmStatus nvmWirte(struct nvmInstance *nvmInstance,
                        size_t address,
                        size_t size,
                        const uint8_t *data)
{
    if (NULL == nvmInstance || (data == NULL && size != 0))
        return nvmStatusInvalidParam;
    if (size == 0)
        return nvmStatusOk;
    if (address > nvmInstance->size || address + size > nvmInstance->size)
        return nvmStatusWriteErr;

    for (uint8_t *mem = nvmInstance->memory + address, *end = nvmInstance->memory + address + size;
         mem < end;
         mem++, data++)
        *mem &= *data;

    return nvmStatusOk;
}

/**
 * @brief nvmErasePages Erase set of pages from pageNumber to pageNumber+pagesCount to 0xff.. .
 * 
 * In case of any problems this funcion does not erase anything.
 * 
 * @param nvmInstance
 * @param pageNumber First page number to erase.
 * @param pagesCount Number of pages to be erased.
 * @return nvmStatusOk on success. nvmStatusInvalidParam when nvmInstance is null or erase operation tries to erase non existing pages.
 */
enum nvmStatus nvmErasePages(struct nvmInstance *nvmInstance, size_t pageNumber, size_t pagesCount)
{
    if (NULL == nvmInstance)
        return nvmStatusInvalidParam;

    if (0 == pagesCount)
        return nvmStatusOk;

    const size_t offsetFrom = pageNumber * nvmInstance->pageSize;
    const size_t eraseSize = pagesCount * nvmInstance->pageSize;
    const size_t offsetTo = offsetFrom + eraseSize;
    if (offsetFrom > nvmInstance->size || offsetTo > nvmInstance->size)
        return nvmStatusInvalidParam;

    memset(nvmInstance->memory + offsetFrom, 0xff, eraseSize);

    return nvmStatusOk;
}

enum nvmStatus nvmEraseAll(struct nvmInstance *nvmInstance)
{
    if (NULL == nvmInstance)
        return nvmStatusInvalidParam;

    memset(nvmInstance->memory, 0xff, nvmInstance->size);

    return nvmStatusOk;
}
