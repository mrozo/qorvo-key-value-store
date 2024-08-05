cmake_minimum_required(VERSION 3.28)

add_library(keyValueInterface INTERFACE)
target_include_directories(keyValueInterface INTERFACE .)
target_sources(keyValueInterface INTERFACE ./keyValue.h)
set_property(TARGET keyValueInterface PROPERTY C_STANDARD 11)
target_link_libraries(keyValueInterface INTERFACE nvmInterface)
