cmake_minimum_required(VERSION 3.30)
project(TaskTracker)

set(CMAKE_CXX_STANDARD 20)


# Include src
include_directories(include)

# Main executable
add_executable(task_manager main.cpp
        src/task_utils.cpp)

# GoogleTest Setup
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Test executable
add_executable(task_tests
        test/task_tests.cpp
        src/task_utils.cpp
)
target_include_directories(task_tests PRIVATE include)
target_link_libraries(task_tests gtest_main)

include(GoogleTest)
gtest_discover_tests(task_tests)

