cmake_minimum_required(VERSION 3.28)

project(
  nvmSim
  VERSION 0.0.1
  DESCRIPTION "a simple nvm storage mock")
add_library(nvmSim SHARED ./nvmSim.c nvmPrivate.h)
target_link_libraries(nvmSim PUBLIC nvmInterface)
set_property(TARGET nvmSim PROPERTY C_STANDARD 11)
set_target_properties(nvmSim PROPERTIES VERSION ${PROJECT_VERSION})

add_executable(nvmSimTest ./tests/nvmSimTest.c)
target_link_libraries(nvmSimTest nvmSim testHelper)

enable_testing()
target_compile_options(nvmSimTest PRIVATE -fsanitize=address -Wall -Werror
                                          -Wpedantic)
target_link_options(nvmSimTest PRIVATE -fsanitize=address)
add_test(NAME nvmSimTest COMMAND $<TARGET_FILE:nvmSimTest>)
