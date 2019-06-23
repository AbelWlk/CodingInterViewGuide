cmake_minimum_required(VERSION 3.14)
project(CodingInterViewGuide)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR})

set(Stack_getMin00 Chapter01_Stack&Queue/01.Stack_getMin00.c Stack/Stack.c)
set(Stack_getMin01 Chapter01_Stack&Queue/01.Stack_getMin01.c Stack/Stack.c)
set(QueueConsistOf2Stacks Chapter01_Stack&Queue/02.QueueConsistOf2Stacks.c Stack/Stack.c)

add_executable(Stack_getMin00 ${Stack_getMin00})
add_executable(Stack_getMin01 ${Stack_getMin01})
add_executable(QueueConsistOf2Stacks ${QueueConsistOf2Stacks})