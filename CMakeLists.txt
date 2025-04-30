cmake_minimum_required(VERSION 3.30)
project(TaskTracker)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Use static runtime for Visual Studio on Windows
if (MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

# Include headers from include/
include_directories(include)

# Main executable
add_executable(task_manager
        main.cpp
        src/task_utils.cpp
)

# GoogleTest Setup
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
# Prevent GoogleTest from overriding MSVC settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable testing support
enable_testing()

# Test executable
add_executable(task_tests
        test/task_tests.cpp
        src/task_utils.cpp
)
target_include_directories(task_tests PRIVATE include)
target_link_libraries(task_tests gtest_main)

# Register tests
include(GoogleTest)
gtest_discover_tests(task_tests)
