#ifndef KEY_VALUE_H_
#define KEY_VALUE_H_
#include <nvm.h>
#include <stdio.h>

typedef unsigned char UInt8;
typedef UInt8 gpNvm_AttrId;

/**
 * @brief All possible return codes for the keyValue interface implemetnation
 */
enum gpNvm_Result {
    gpNvm_Result_OK = 0,
    gpNvm_Result_OK_CONTINUE,
    gpNvm_Result_INVALID_PARTITION,
    gpNvm_Result_INVALID_PARAMETER,
    gpNvm_Result_NOT_IMPLEMENTED,
    gpNvm_Result_STORAGE_READ_ERROR,
    gpNvm_Result_STORAGE_WRITE_ERROR,
    gpNvm_Result_NOT_ENOUGHT_SPACE,
    gpNvm_Result_KEY_NOT_FOUND,
    gpNvm_Result_DATA_TO_LARGE,
    gpNvm_Result_UNKNOWN_ERROR,
    gpNvm_Result_STORAGE_FULL,
    gpNvm_Result_DATA_INTEGRITY_ERROR,
    gpNvm_Result_ATTR_NOT_FOUND,
};

// TODO this is dumb, remove gpNvm_nvmInterface and directly use nvm interface. Initially i wanted to use it remove dependency on nvm interace //      from this module, but it makes no sence.
/** Write function for the nvm driver. To be removed */
typedef enum nvmStatus (*gpNvm_write)(void *ctx, size_t offset, size_t size, UInt8 *const pValue);
/** Read function for the nvm driver. To be removed */
typedef enum nvmStatus (*gpNvm_read)(void *ctx, size_t offset, size_t size, UInt8 *pValue);
/** Erase all function for the nvm driver. To be removed */
typedef enum nvmStatus (*gpNvm_format)(void *ctx);
/** Erase selected pages from the nvm. To be removed */
typedef enum nvmStatus (*gpNvm_erasePages)(void *ctx, size_t firstPage, size_t count);
/** Get information about the nvm device */
typedef struct nvmDescription (*gpNvm_getInfo)(void *ctx);

/**
 * @brief nvm driver interface.
 */
struct gpNvm_nvmInterface
{
    gpNvm_write write;
    gpNvm_read read;
    gpNvm_format format;
    gpNvm_erasePages erasePages;
    gpNvm_getInfo getInfo;
    void *ctx;
};

/**
 * @brief initialize the module, read and verify partition header.
 * @param nvm nvm driver interface. The driver must be already initialized.
 * @return 
 */
enum gpNvm_Result gpNvm_init(struct gpNvm_nvmInterface *const nvm);

/**
 * @brief Read the attribute.
 * @param attrId id of the attribute to be read.
 * @param pLength size of the pValue buffer
 * @param pValue buffer to store the attibutes data.
 * @return 
 */
enum gpNvm_Result gpNvm_GetAttribute(gpNvm_AttrId attrId, size_t *pLength, UInt8 *pValue);

/**
 * @brief Write attribute to the underlying storage
 * 
 * TODO decide what to do if the attribute already exists
 * 
 * @param attrId id of the attribute
 * @param length size of the pValue
 * @param pValue data associated with the attribute
 * @return 
 */
enum gpNvm_Result gpNvm_SetAttribute(gpNvm_AttrId attrId, size_t length, UInt8 *pValue);

/**
 * @brief Erase all the data from the underlying device.
 * @return 
 */
enum gpNvm_Result gpNvm_eraseAll(void);

#endif // KEY_VALUE_H_
