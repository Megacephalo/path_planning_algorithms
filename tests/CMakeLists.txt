find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


set(TEST_FILES
	test_gridLocation.cpp
	test_grid.cpp
	test_min_priority_queue.cpp
)

foreach(SRC_FILE ${TEST_FILES})
        get_filename_component(SOURCE_NAME ${SRC_FILE} NAME_WE)

        add_executable(${SOURCE_NAME} ${SRC_FILE})
        target_link_libraries(${SOURCE_NAME}
        	${THIRD_PARTY_LIBS}
			${GTEST_LIBRARIES}
        	Path_planning
        )
endforeach()