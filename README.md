# key value nvm storage example

This repository contains implementation of key value storage for nvm memory.

The main module - keyValueNvm uses nvm interface to create a simple file system with header and data blocks. When an attribute data is bigger than a single data block, the system will split the attribute data into multiple data blocks (thats untested). Each data block can contain up to 122 bytes of data, and each attribute can split into up to 16 blocks, thus max size of an attribute data is 1952 bytes. For more information on partiton format read documentation inside ./keValueNvm/keyValueNvm.c .

## How to start

First clone the repository:

```bash
git clone git@github.com:mrozo/qorvo-key-value-store.git --recurse-submodules
```

Then build and run some tests:

```bash
mkdir build && cd build
cmake ../
cmake --build . --target all
# example test
./keyValueNvm/keyValueNvmTests 

```

Or use QT creator - it will handle everything for you. 

## Repository structure

 * ./sample - maybe in the future ;]
 * ./interfaces - this directory contains public interfaces for the modules.
   * ./interfaces/nvm - interface for an nvm storage device driver
   * ./interfaces/keyValue - the main interface for the keyValue storage driver
   * ./interfaces/mocks - directory contains mocks created from interfaces using cmock. Each mock contains project.yml used to generate it.
 * ./ext - external tools - unity, cmock
 * ./testsHelper - test utility used to tes nvm, to be replaced with unity/CMock
 * ./keyValueNvm - implementation of the key value storage - the main module
 * ./nvmSim - nvm in memory simulator created to test the key value storage module. Currently not used.

## Documentation

Each source file contains documentation in doxygen format. Each module main documentation is located in the main c or h file.

Main source file for a module has the same name as the module itself - for keyValueNvm its keyValueNvm.c and for nvm interface its nvm.h .

Functions that implement some interface contain own documentation only when required. To read related documentation check the interface definition in a proper header file.

## Tests

Each module contains a tests subdirectory. Tests are compiled into a separate executable. 
 
## Status of the project

The project is half backed - the main module - keyValue is tested only using tests located in ./keyValue/tests.

What is working:
1. `gpNvm_setAttribute` - writes data to the underlying storage, but for now it does not check if the attribute already exists in the storage
2. `gpNvm_getAttribute` - reads attribute from the storage. Should handle even data sizes that are bigger then one block of data 

## TODO

1. unify the naming style - diffrent modules use different naming styles, eg. `nvmStatusOk` vs `gpNvm_Result_OK`
2. add sample - testing file system using unit tests is not perfect, a sample application can be used for better testing
3. add a swap page to keyValueNvm
4. add ability to remove/override existing attribute
5. add defragmentation feature to the keyValueNvm
... and many, many more.

 
 

