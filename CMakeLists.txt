cmake_minimum_required(VERSION 3.17)
project(philosophers C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")
set(SRCS_DIR srcs)

include_directories(include
        ${SRCS})

file(GLOB SRCS ${SRCS_DIR}/*.c)
file(GLOB INCLUDES include/*.h)

add_executable(philosophers ${SRCS} ${INCLUDES})
#set_target_properties(philosophers_mandatory PROPERTIES COMPILE_FLAGS "-D BONUS=0")

add_executable(philosophers_bonus ${SRCS} ${INCLUDES})
#set_target_properties(philosophers_bonus PROPERTIES COMPILE_FLAGS "-D BONUS=1")
