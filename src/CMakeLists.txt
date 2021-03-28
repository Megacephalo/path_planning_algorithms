add_library(Path_planning
	gridLocation.cpp
	grid.cpp
	path_planner_base.cpp
	BFS.cpp
	min_priority_queue.cpp
	dijkstra.cpp
	heuristics.cpp
	euclidean_heuristics.cpp
	manhattan_heuristics.cpp
	diagonal_heuristics.cpp
	A_star.cpp

)
target_link_libraries(Path_planning
	${THIRD_PARTIES}
)