set(SOURCE_FILES
	path_planner.cpp
)

foreach(SRC_FILE ${SOURCE_FILES})
        get_filename_component(SOURCE_NAME ${SRC_FILE} NAME_WE)

        add_executable(${SOURCE_NAME} ${SRC_FILE})
        target_link_libraries(${SOURCE_NAME}
        	Path_planning
        )
endforeach()
