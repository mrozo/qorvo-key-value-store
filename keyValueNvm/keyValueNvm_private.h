#ifndef KEYVALUENVM_H
#define KEYVALUENVM_H
#include <keyValue.h>
#include <nvm.h>
#include <stdint.h>

/**
 * @brief Consts describing the partition header.
 */
enum KEY_VALUE_PARTIOTN {
    KEY_VALUE_PARTITION_HEADER_OFFSET = 0,
    KEY_VALUE_PARTITION_HEADER_SIZE = 128,
    KEY_VALUE_PARTITION_BLOCK_SIZE_B = 128,
    KEY_VALUE_PARTITION_BLOCK_SIZE_OFFSET = 4,
    KEY_VALUE_PARTITION_BLOCK_SIZE_SIZE = 4,
    KEY_VALUE_PARTITION_MAGIC_NUMBER = (int32_t) 0xDEADBEEF,
    KEY_VALUE_PARTITION_MAGIC_NUMBER_OFFSET = 0,
    KEY_VALUE_PARTITION_MAGIC_NUMBER_SIZE = 4,
};

/**
 * @brief Consts describing each data block on the partition. Read documentation in keyValueNvm.c for more information.
 */
enum KEY_VALUE_BLOCK {
    KEY_VALUE_FIRST_BLOCK_ADDRESS = KEY_VALUE_PARTITION_HEADER_SIZE,
    // byte 0
    KEY_VALUE_BLOCK_ID_OFFSET = 0,
    KEY_VALUE_BLOCK_ID_SIZE = 1,
    // byte 1
    KEY_VALUE_BLOCK_FLAGS_OFFSET = 1,
    KEY_VALUE_BLOCK_FLAGS_POS = 0,
    KEY_VALUE_BLOCK_FLAGS_SIZE = 1,
    KEY_VALUE_BLOCK_FLAG_NOT_USED_POS = 0,
    KEY_VALUE_BLOCK_FLAG_NOT_ERASED_POS = 1,
    KEY_VALUE_BLOCK_FLAG_RESERVED_1_POS = 2,
    KEY_VALUE_BLOCK_FLAG_RESERVED_2_POS = 3,
    KEY_VALUE_BLOCK_SUBBLOCKS_COUNT_OFFSET = 1,
    KEY_VALUE_BLOCK_SUBBLOCKS_COUNT_POS = 4,
    KEY_VALUE_BLOCK_SUBBLOCKS_COUNT_MAX = 0x0f,
    // byte 2
    KEY_VALUE_BLOCK_SUBBLOCK_NUMBER_OFFSET = 2,
    // byte 3
    KEY_VALUE_BLOCK_DATA_SIZE_OFFSET = 3,
    // byte 4,5
    KEY_VALUE_BLOCK_ECC_OFFSET = 4,
    KEY_VALUE_BLOCK_ECC_SIZE_B = 2,
    //
    KEY_VALUE_BLOCK_HEADER_SIZE = 6,
    // data
    KEY_VALUE_BLOCK_DATA_OFFSET = KEY_VALUE_BLOCK_HEADER_SIZE,
    KEY_VALUE_BLOCK_DATA_MAX_SIZE = KEY_VALUE_PARTITION_BLOCK_SIZE_B - KEY_VALUE_BLOCK_HEADER_SIZE,
    KEY_VALUE_BLOCK_DATA_ABSOLUTE_MAX_SIZE = KEY_VALUE_BLOCK_SUBBLOCKS_COUNT_MAX
                                             * KEY_VALUE_BLOCK_DATA_MAX_SIZE,
};

/**
 * @brief Internal state of the keyValue module.
 */
struct keyValueNvm_instance
{
    struct gpNvm_nvmInterface *nvm;
    /**
     * @brief read write buffer.
     */
    uint8_t buffer[KEY_VALUE_PARTITION_BLOCK_SIZE_B];
};

/**
 * @brief Generate a block that is ready to be written to the NVM.
 * 
 * Whith each call, this function will put chunk of the data into a block. Keep calling this function untill 
 * gpNvm_Result_OK is returned.
 * 
 * @param block buffer for the block
 * @param size size of the block
 * @param id Identificator of the block
 * @param data data to put inside the block
 * @param dataSize size of the data
 * @param subBlockNumber[in,out] On input number of the current subblock. On output number of the next sub block.
 * @param dataWritten amount[in,out] of bytes consumed.
 * @return gpNvm_Result_OK_CONTINUE untill not all data has been consumed. When finished returns gpNvm_Result_OK.
 */
enum gpNvm_Result mkBlock(uint8_t *block,
                          size_t size,
                          uint8_t id,
                          const uint8_t *data,
                          size_t dataSize,
                          uint8_t *subBlockNumber,
                          size_t *dataWritten);

/**
 * @brief Search nvm storage for a data block that is not used.
 * 
 * The returned address is valid only if the returned value is gpNvm_Result_OK.
 * 
 * @param address[out] On success address of a free data block.
 * @return gpNvm_Result_OK on success.
 */
enum gpNvm_Result findFreeBlock(size_t *address);

#endif // KEYVALUENVM_H
