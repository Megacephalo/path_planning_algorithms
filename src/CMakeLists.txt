add_library(Path_planning
	gridLocation.cpp
	grid.cpp
)
target_link_libraries(Path_planning
	${THIRD_PARTIES}
)