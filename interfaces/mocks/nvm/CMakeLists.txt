cmake_minimum_required(VERSION 3.28)

add_library(mocknvm ./Mocknvm.c ./Mocknvm.h)
target_link_libraries(mocknvm unity cmock nvmInterface)
target_include_directories(mocknvm PUBLIC ./)
