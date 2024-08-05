add_library(unity STATIC unity/src/unity.c)

target_include_directories(unity PUBLIC unity/src)

add_library(cmock STATIC CMock/src/cmock.c CMock/src/cmock.h
                         CMock/src/cmock_internals.h)
target_include_directories(cmock PUBLIC CMock/src/)
target_link_libraries(cmock unity)
