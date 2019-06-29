cmake_minimum_required(VERSION 3.14)
project(CodingInterViewGuide)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR})

set(Stack_getMin00 Chapter01_Stack&Queue/01.Stack_getMin00.c datastructure/Stack.c)
set(Stack_getMin01 Chapter01_Stack&Queue/01.Stack_getMin01.c datastructure/Stack.c)
set(QueueConsistOf2Stacks Chapter01_Stack&Queue/02.QueueConsistOf2Stacks.c datastructure/Stack.c)
set(ReverseStackOnlyByRecurion Chapter01_Stack&Queue/03.ReverseStackOnlyByRecurion.c datastructure/Stack.c)
set(SortStackByStack Chapter01_Stack&Queue/05.SortStackByStack.c datastructure/Stack.c)
set(DogCatQueue Chapter01_Stack&Queue/04.DogCatQueue.c datastructure/PetQueue.c)
set(GetMaxWindow Chapter01_Stack&Queue/06.GetMaxWindow.c datastructure/LinkedList.c)

add_executable(01.Stack_getMin00 ${Stack_getMin00})
add_executable(01.Stack_getMin01 ${Stack_getMin01})
add_executable(02.QueueConsistOf2Stacks ${QueueConsistOf2Stacks})
add_executable(03.ReverseStackOnlyByRecurion ${ReverseStackOnlyByRecurion})
add_executable(04.DogCatQueue ${DogCatQueue})
add_executable(05.SortStackByStack ${SortStackByStack})
add_executable(06.GetMaxWindow ${GetMaxWindow})