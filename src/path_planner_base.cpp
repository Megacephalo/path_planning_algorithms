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

Grid
Path_Planner::get_grid() const {
	return grid_ ;
} /* End of get_grid */

} /* End of namespace */