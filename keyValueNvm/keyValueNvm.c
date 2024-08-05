/**
 * @brief Implementation of nvm based key value storage.
 * 
 * Partition consists of blocks of size KEY_VALUE_PARTITION_BLOCK_SIZE_B. The first block is a partition header, and all the remaining blocks are data blocks.
 * 
 * Each attribute can contain up to 1952 bytes. 
 * 
 * 
 * 
 * Partition header:
 * 1. bytes 0-3 - magick number
 * 2. bytes 4-7 - block size (must be 128)
 * 3. bytes 8-127 - reserved
 * 
 * Data block:
 * 1. byte 0 - block id == attribute id
 * 2. byte 1
 * 2.1. bit 0 - block not used flag
 * 2.2. bit 1 - block not erased flag
 * 2.3. bit 2,3 - reserved, always set
 * 2.4. bits 4-7 - subblocks count - number of other blocks containing rest of the data minus one.
 * 3. byte 2 - which subblock is this one
 * 4. byte 3 - size of the data contained in this block
 * 5. byte 4,5 - EEC placeholder
 * 6. bytes 6-127 - data
 **/
#include "keyValueNvm_private.h"
#include <keyValue.h>
#include <string.h>
struct keyValueNvm_instance kvSingleton = {NULL};

enum gpNvm_Result gpNvm_eraseAll(void)
{
    return gpNvm_Result_NOT_IMPLEMENTED;
}
/**
 * @brief Read uint32 value from big endian format
 */
static inline uint32_t readU32(uint8_t *buff)
{
    return (buff[3]) | (buff[2] << 8) | (buff[1] << 16) | (buff[0] << 24);
}
/**
 * @brief Read int32 value from big endian format
 */
static inline int32_t readI32(uint8_t *buff)
{
    return (buff[3]) | (buff[2] << 8) | (buff[1] << 16) | (buff[0] << 24);
}

enum gpNvm_Result verifyPartitionHeader(void)
{
    if (nvmStatusOk
        != kvSingleton.nvm->read(kvSingleton.nvm->ctx,
                                 KEY_VALUE_PARTITION_HEADER_OFFSET,
                                 KEY_VALUE_PARTITION_HEADER_SIZE,
                                 kvSingleton.buffer)) {
        return gpNvm_Result_STORAGE_READ_ERROR;
    }
    int32_t magicNumber = readI32(&kvSingleton.buffer[KEY_VALUE_PARTITION_MAGIC_NUMBER_OFFSET]);
    int32_t blockSize = readI32(&kvSingleton.buffer[KEY_VALUE_PARTITION_BLOCK_SIZE_OFFSET]);
    if (magicNumber != KEY_VALUE_PARTITION_MAGIC_NUMBER
        || blockSize != KEY_VALUE_PARTITION_BLOCK_SIZE_B) {
        return gpNvm_Result_INVALID_PARTITION;
    }
    return gpNvm_Result_OK;
}

enum gpNvm_Result gpNvm_init(struct gpNvm_nvmInterface *const nvm)
{
    if (NULL == nvm)
        return gpNvm_Result_INVALID_PARAMETER;
    kvSingleton.nvm = nvm;
    return verifyPartitionHeader();
}

/**
 * @brief Error Correcting Code context.
 */
struct EECState
{
    int placeholder;
};

/**
 * @brief Initialize error correcting code context.
 * @param state preallocated EECState struct.
 * @return gpNvm_Result_OK on success.
 */
enum gpNvm_Result EECInit(struct EECState *state)
{
    return gpNvm_Result_OK;
}

/**
 * @brief Finish calculating error correcting code and write result.
 * @param state ecc state
 * @param eec buffer to write the ecc code
 * @param eecSize size of the ecc buffer
 * @return gpNvm_Result_OK on success.
 */
enum gpNvm_Result EECFinish(struct EECState *state, uint8_t *eec, uint8_t eecSize)
{
    memset(eec, 0xac, eecSize);
    return gpNvm_Result_OK;
}

/**
 * @brief pass chunk of data to calculate ecc over.
 * @param state ecc state
 * @param data data to calculate ecc over
 * @param dataSize size of the data
 * @return gpNvm_Result_OK on success
 */
enum gpNvm_Result EECUpdate(struct EECState *state, uint8_t *data, size_t dataSize)
{
    return gpNvm_Result_OK;
}

/**
 * @brief Verify and if needed, try to fix the block using its ecc.
 * @param block data block
 * @param blockSize size of the data block
 * @return gpNvm_Result_OK on success
 */
enum gpNvm_Result EECCheckAndFixBlock(uint8_t *block, size_t blockSize)
{
    return gpNvm_Result_OK;
}

enum gpNvm_Result mkBlock(uint8_t *block,
                          size_t size,
                          uint8_t id,
                          const uint8_t *data,
                          size_t dataSize,
                          uint8_t *subBlockNumber,
                          size_t *dataWritten)
{
    if (NULL == block || NULL == data || size < KEY_VALUE_PARTITION_BLOCK_SIZE_B || dataSize == 0
        || NULL == subBlockNumber || NULL == dataWritten
        || dataSize > KEY_VALUE_BLOCK_DATA_ABSOLUTE_MAX_SIZE)
        return gpNvm_Result_INVALID_PARAMETER;

    if (*dataWritten >= dataSize)
        return gpNvm_Result_OK;
    if (*subBlockNumber > KEY_VALUE_BLOCK_SUBBLOCKS_COUNT_MAX)
        return gpNvm_Result_INVALID_PARAMETER;

    size_t dataToWrite = dataSize - *dataWritten;

    uint8_t subBlockCount = 0;
    if (dataSize > KEY_VALUE_BLOCK_DATA_MAX_SIZE) {
        subBlockCount = dataSize / KEY_VALUE_BLOCK_DATA_MAX_SIZE;
        if (subBlockCount * KEY_VALUE_BLOCK_DATA_MAX_SIZE < dataSize)
            subBlockCount++;
    }
    if (subBlockCount > KEY_VALUE_BLOCK_SUBBLOCKS_COUNT_MAX)
        return gpNvm_Result_DATA_TO_LARGE;

    memset(block, 0x0, KEY_VALUE_BLOCK_HEADER_SIZE);
    block[KEY_VALUE_BLOCK_ID_OFFSET] = id;
    uint8_t flags = (0x01 << KEY_VALUE_BLOCK_FLAG_NOT_ERASED_POS)
                    | (0x01 << KEY_VALUE_BLOCK_FLAG_RESERVED_1_POS)
                    | (0x01 << KEY_VALUE_BLOCK_FLAG_RESERVED_2_POS);
    block[KEY_VALUE_BLOCK_FLAGS_OFFSET] |= flags << KEY_VALUE_BLOCK_FLAGS_POS;
    block[KEY_VALUE_BLOCK_SUBBLOCKS_COUNT_OFFSET] |= subBlockCount
                                                     << KEY_VALUE_BLOCK_SUBBLOCKS_COUNT_POS;

    uint8_t subBlockSize = (dataToWrite > KEY_VALUE_BLOCK_DATA_MAX_SIZE)
                               ? KEY_VALUE_BLOCK_DATA_MAX_SIZE
                               : dataToWrite;

    block[KEY_VALUE_BLOCK_SUBBLOCK_NUMBER_OFFSET] = *subBlockNumber;
    (*subBlockNumber)++;
    block[KEY_VALUE_BLOCK_DATA_SIZE_OFFSET] = subBlockSize;

    memcpy(block + KEY_VALUE_BLOCK_DATA_OFFSET, data + *dataWritten, subBlockSize);
    (*dataWritten) += subBlockSize;
    size_t emptyBytes = KEY_VALUE_PARTITION_BLOCK_SIZE_B
                        - (KEY_VALUE_BLOCK_HEADER_SIZE + subBlockSize);
    memset(block + KEY_VALUE_BLOCK_DATA_OFFSET + subBlockSize, 0xff, emptyBytes);

    struct EECState eccCtx;
    if (gpNvm_Result_OK != EECInit(&eccCtx))
        return gpNvm_Result_UNKNOWN_ERROR;
    if (gpNvm_Result_OK != EECUpdate(&eccCtx, block, KEY_VALUE_BLOCK_HEADER_SIZE))
        return gpNvm_Result_UNKNOWN_ERROR;
    if (gpNvm_Result_OK != EECUpdate(&eccCtx, block + KEY_VALUE_BLOCK_DATA_OFFSET, subBlockSize))
        return gpNvm_Result_UNKNOWN_ERROR;
    if (gpNvm_Result_OK
        != EECFinish(&eccCtx, block + KEY_VALUE_BLOCK_ECC_OFFSET, KEY_VALUE_BLOCK_ECC_SIZE_B))
        return gpNvm_Result_UNKNOWN_ERROR;

    if (*dataWritten < dataToWrite)
        return gpNvm_Result_OK_CONTINUE;
    return gpNvm_Result_OK;
}

static inline bool isFlagSet(uint8_t flags, uint8_t pos)
{
    return 0x01 == (0x01 & (flags >> pos));
}

static inline bool isFlagCleared(uint8_t flags, uint8_t pos)
{
    return !isFlagSet(flags, pos);
}

enum gpNvm_Result findFreeBlock(size_t *address)
{
    if (NULL == address)
        return gpNvm_Result_INVALID_PARAMETER;
    size_t nvmSize = 0;
    size_t nvmPageSize = 0;
    uint8_t *buff = kvSingleton.buffer;
    struct nvmDescription nvmInfo = kvSingleton.nvm->getInfo(kvSingleton.nvm->ctx);
    for (*address = KEY_VALUE_FIRST_BLOCK_ADDRESS; *address < nvmInfo.size;
         *address += KEY_VALUE_PARTITION_BLOCK_SIZE_B) {
        if (nvmStatusOk
            != kvSingleton.nvm->read(kvSingleton.nvm->ctx,
                                     *address,
                                     KEY_VALUE_BLOCK_HEADER_SIZE,
                                     buff))
            return gpNvm_Result_STORAGE_READ_ERROR;

        bool isNotUsed = isFlagSet(buff[KEY_VALUE_BLOCK_FLAGS_OFFSET],
                                   KEY_VALUE_BLOCK_FLAG_NOT_USED_POS);
        if (isNotUsed)
            return gpNvm_Result_OK;
    }
    return gpNvm_Result_STORAGE_FULL;
}

enum gpNvm_Result gpNvm_SetAttribute(gpNvm_AttrId attrId, size_t length, UInt8 *pValue)
{
    size_t writeAddress = 0;
    uint8_t subBlockNumber = 0;
    size_t dataWritten = 0;
    enum gpNvm_Result findAddressRet;
    enum gpNvm_Result mkBlockRet;
    do {
        mkBlockRet = mkBlock(kvSingleton.buffer,
                             sizeof(kvSingleton.buffer),
                             attrId,
                             pValue,
                             length,
                             &subBlockNumber,
                             &dataWritten);
        if (gpNvm_Result_OK != mkBlockRet)
            return mkBlockRet;
        findAddressRet = findFreeBlock(&writeAddress);
        if (gpNvm_Result_OK != findAddressRet)
            return findAddressRet;
        // TODO should we retry after a write failure?
        if (nvmStatusOk
            != kvSingleton.nvm->write(kvSingleton.nvm->ctx,
                                      writeAddress,
                                      sizeof(kvSingleton.buffer),
                                      kvSingleton.buffer))
            return gpNvm_Result_STORAGE_WRITE_ERROR;
        // TODO verify write
    } while (mkBlockRet == gpNvm_Result_OK_CONTINUE);

    return gpNvm_Result_OK;
}

enum gpNvm_Result gpNvm_GetAttribute(gpNvm_AttrId attrId, size_t *pLength, UInt8 *pValue)
{
    size_t address;
    size_t nvmSize = 0;
    size_t nvmPageSize = 0;
    uint8_t *buff = kvSingleton.buffer;
    struct nvmDescription nvmInfo = kvSingleton.nvm->getInfo(kvSingleton.nvm->ctx);
    uint8_t subBlocksRead = 0;
    uint8_t subBlocksCount = 0;
    for (size_t address = KEY_VALUE_FIRST_BLOCK_ADDRESS; address < nvmInfo.size;
         address += KEY_VALUE_PARTITION_BLOCK_SIZE_B) {
        /* TODO we can speed up searchig by first reading only header and later the rest of the block only if the block
         id matches attrId */
        if (nvmStatusOk
            != kvSingleton.nvm->read(kvSingleton.nvm->ctx,
                                     address,
                                     KEY_VALUE_PARTITION_BLOCK_SIZE_B,
                                     buff))
            return gpNvm_Result_STORAGE_READ_ERROR;

        bool isUsed = isFlagCleared(buff[KEY_VALUE_BLOCK_FLAGS_OFFSET],
                                    KEY_VALUE_BLOCK_FLAG_NOT_USED_POS);
        bool isErased = isFlagCleared(buff[KEY_VALUE_BLOCK_FLAGS_OFFSET],
                                      KEY_VALUE_BLOCK_FLAG_NOT_ERASED_POS);

        if (isUsed && !isErased && buff[KEY_VALUE_BLOCK_ID_OFFSET] == attrId) {
            enum gpNvm_Result verifyResult = EECCheckAndFixBlock(buff,
                                                                 KEY_VALUE_PARTITION_BLOCK_SIZE_B);
            if (gpNvm_Result_OK != verifyResult)
                return verifyResult;

            uint8_t subBlocksCountFromBlock = buff[KEY_VALUE_BLOCK_SUBBLOCKS_COUNT_OFFSET]
                                              >> KEY_VALUE_BLOCK_SUBBLOCKS_COUNT_POS;
            if (subBlocksRead == 0)
                subBlocksRead = subBlocksCountFromBlock;
            else if (subBlocksCountFromBlock != subBlocksCount)
                return gpNvm_Result_DATA_INTEGRITY_ERROR;

            uint8_t subBlockNumber = buff[KEY_VALUE_BLOCK_SUBBLOCK_NUMBER_OFFSET];
            uint8_t dataSize = buff[KEY_VALUE_BLOCK_DATA_SIZE_OFFSET];
            size_t writeOffset = subBlockNumber * KEY_VALUE_BLOCK_DATA_MAX_SIZE;
            if (writeOffset + dataSize > *pLength)
                return gpNvm_Result_NOT_ENOUGHT_SPACE;
            memcpy(pValue + writeOffset, buff + KEY_VALUE_BLOCK_DATA_OFFSET, dataSize);
            subBlocksRead++;
            if (subBlocksRead > subBlocksCount)
                return gpNvm_Result_OK;
        }
    }
    if (subBlocksRead <= subBlocksCount)
        return gpNvm_Result_DATA_INTEGRITY_ERROR;
    return gpNvm_Result_ATTR_NOT_FOUND;
}
