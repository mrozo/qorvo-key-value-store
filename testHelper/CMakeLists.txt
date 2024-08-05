cmake_minimum_required(VERSION 3.28)

add_library(testHelper INTERFACE)
target_include_directories(testHelper INTERFACE .)
target_sources(testHelper INTERFACE ./testHelper.h)
set_property(TARGET testHelper PROPERTY C_STANDARD 11)
