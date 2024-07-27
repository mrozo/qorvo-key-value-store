#ifndef NVMPRIVATE_H
#define NVMPRIVATE_H
#include "nvm.h"

struct nvmInstance
{
    size_t size;
    size_t pageSize;
    uint8_t memory[];
};

#endif // NVMPRIVATE_H
