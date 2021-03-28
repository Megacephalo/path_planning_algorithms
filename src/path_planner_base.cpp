#include "path_planner_base.h"

namespace Path_Planning_Algorithms {

Path_Planner::Path_Planner(const Grid& grid)
: grid_(grid)
, trajectory_({})
{
	directions_ = {
		GridLocation(-1, -1),
		GridLocation(-1, 0),
		GridLocation(-1, 1),
		GridLocation(0, 1),
		GridLocation(1, 1),
		GridLocation(1, 0),
		GridLocation(1, -1),
		GridLocation(0, -1)
	} ;
} /* End of constructor */

void
Path_Planner::plan(const GridLocation& start, const GridLocation& goal) {
	plan(start.x, start.y, goal.x, goal.y) ;
} /* End of plan */

void Path_Planner::extract_trajectory(const GridLocation& start, const GridLocation& goal) {
	if (cameFrom_.empty()) {
		std::cerr << "The registered steps to be backtracked are missing. No trajectory is extracted." ;
		return ;
	}

	trajectory_.push_back(goal) ;

	auto backtrackIt = cameFrom_.find(goal) ;
	if (backtrackIt == cameFrom_.end()) {
		std::cerr << "Apparently there is no way to reach the goal. No trajectory extracted.\n" ;
		return ;
	}

	while( backtrackIt != cameFrom_.find(start) ) {
		auto predecessor = backtrackIt->second ;

		if (predecessor == backtrackIt->first) continue ;

		trajectory_.push_back(predecessor) ;

		backtrackIt = cameFrom_.find(predecessor) ;
	}

	std::reverse(trajectory_.begin(), trajectory_.end()) ;

	grid_.update_trajectory(trajectory_) ;
} /* End of extract_trajectory */

Grid
Path_Planner::get_grid() const {
	return grid_ ;
} /* End of get_grid */

bool
Path_Planner::not_in_cameFrom(const GridLocation& cell) const {
	return (cameFrom_.find(cell) == cameFrom_.end()) ;
} /* End of not_in_cameFrom */

} /* End of namespace */