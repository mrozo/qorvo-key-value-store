cmake_minimum_required(VERSION 3.28)

project(
  keyValueNvm
  VERSION 0.0.1
  DESCRIPTION "Key value store with nvm support")
add_library(keyValueNvm SHARED ./keyValueNvm.c ./keyValueNvm_private.h)
set_property(TARGET nvmSim PROPERTY C_STANDARD 11)
set_target_properties(keyValueNvm PROPERTIES VERSION ${PROJECT_VERSION})

target_link_libraries(keyValueNvm PUBLIC keyValueInterface)

enable_testing()
add_executable(keyValueNvmTests ./tests/keyValueNvmTests.c)
target_link_libraries(keyValueNvmTests mocknvm unity keyValueNvm)

target_compile_options(keyValueNvmTests PRIVATE -fsanitize=address -Wall
                                                -Werror -Wpedantic)
target_link_options(keyValueNvmTests PRIVATE -fsanitize=address)
add_test(NAME keyValueNvmTests COMMAND $<TARGET_FILE:keyValueNvmTests>)
