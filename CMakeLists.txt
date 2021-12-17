cmake_minimum_required(VERSION 3.20)
project(UniverGroupsLAB)

# Requirements
set(CMAKE_CXX_STANDARD 17)
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

# Testing
enable_testing()
add_executable(
        tests
        tests/basic_tests.cpp
        tests/table_tests.cpp
)
target_include_directories(tests PUBLIC ${GTEST_INCLUDE_DIRS})
target_link_libraries(tests ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

gtest_discover_tests(tests)

add_library(Main funcs.h funcs.cpp classes/Group.h classes/Group.cpp classes/DayShift.cpp classes/DayShift.h
        classes/NightShift.cpp classes/NightShift.h classes/PaidGroup.cpp classes/PaidGroup.h classes/vector.h
        classes/Table.h classes/Table.cpp)
add_executable(UniverGroupsLAB main.cpp)

target_link_libraries(UniverGroupsLAB Main)
target_link_libraries(tests Main)



