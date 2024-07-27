cmake_minimum_required(VERSION 3.28)

project(
  nvmMockLib
  VERSION 0.0.1
  DESCRIPTION "a simple nvm storage mock")
add_library(nvmMock SHARED ./nvmMock.c ./nvm.h nvmPrivate.h)
set_property(TARGET nvmMock PROPERTY C_STANDARD 11)
set_target_properties(nvmMock PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(nvmMock PROPERTIES PUBLIC_HEADER ./nvm.h)

add_executable(nvmMockTest ./tests/nvmMockTest.c)
target_link_libraries(nvmMockTest PRIVATE nvmMock)
enable_testing()
add_test(NAME nvmMockTest COMMAND $<TARGET_FILE:nvmMockTest>)

target_compile_options(nvmMockTest PRIVATE -fsanitize=address -Wall -Werror
                                           -Wpedantic)
target_link_options(nvmMockTest PRIVATE -fsanitize=address)
