cmake_minimum_required(VERSION 3.0.2)
project(LeetCode_problems)

set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_BUILD_TYPE RelWithDebInfo)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

set(THIRD_PARTIES
	pthread
)

include_directories(
	include/path_planning_algorithms
)

add_subdirectory(src)
add_subdirectory(apps)
add_subdirectory(tests)