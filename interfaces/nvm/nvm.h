#ifndef NVM_H
#define NVM_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/**
 * @brief All posible return status codes for the nvm interface implementation
 */
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

/**
 * @brief Struct used to describe a nvm device.
 */
struct nvmDescription
{
    /** True if the driver is initialized */
    bool isInitialized;
    /** Total size of the underlying nvm storage device */
    size_t size;
    /** Size of a page on the underlying nvm storage device */
    size_t pageSize;
};

/**
 * Internal state of the nvm driver.
 */
struct nvmInstance;

/**
 * @brief Initialize nvm driver and allocate required resoruces.
 * @param nvmInstance[out] pointer to internal state of the driver.
 * @param desc struct containing information about the nvm device.
 * @return 
 */
enum nvmStatus nvmInit(struct nvmInstance **nvmInstance, struct nvmDescription desc);

/**
 * @brief Write data to the nvm device. Does not check if theres any data under the addess.
 * @param nvmInstance driver instance.
 * @param address where to write the data
 * @param size size of the data
 * @param data data to be written
 * @return 
 */
enum nvmStatus nvmWirte(struct nvmInstance *nvmInstance,
                        size_t address,
                        size_t size,
                        const uint8_t *data);

/**
 * @brief Read data from the device.
 * @param nvmInstance driver instance
 * @param address address of the first byte to be read
 * @param size how many bytes to read
 * @param data where to put stored data
 * @return 
 */
enum nvmStatus nvmRead(struct nvmInstance *nvmInstance, size_t address, size_t size, uint8_t *data);

/**
 * @brief erase pages on the device
 * @param nvmInstance driver instance
 * @param pageNumber number of the first page to be erased
 * @param pagesCount number of pages to be erased
 * @return 
 */
enum nvmStatus nvmErasePages(struct nvmInstance *nvmInstance, size_t pageNumber, size_t pagesCount);

/**
 * @brief deinitialize the driver and free any used resources
 * @param nvmInstance driver instance
 * @return 
 */
enum nvmStatus nvmDeinit(struct nvmInstance **nvmInstance);

/**
 * @brief format whole nvm device.
 * @param nvmInstance driver instance
 * @return 
 */
enum nvmStatus nvmEraseAll(struct nvmInstance *nvmInstance);

/**
 * @brief Get information about the device
 * @param nvmInstance driver instance
 * @return nvmDescription struct
 */
struct nvmDescription nvmGetInfo(struct nvmInstance *nvmInstance);
#endif // NVM_H
