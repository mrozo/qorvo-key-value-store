cmake_minimum_required(VERSION 3.28)

add_library(nvmInterface INTERFACE)
target_include_directories(nvmInterface INTERFACE .)
target_sources(nvmInterface INTERFACE ./nvm.h)
set_property(TARGET nvmInterface PROPERTY C_STANDARD 11)
