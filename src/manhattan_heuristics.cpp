#include "manhattan_heuristics.h"

namespace Path_Planning_Algorithms {

Manhattan::Manhattan()
: Heuristics()
{} /* End of constructor */

Manhattan::Manhattan(const GridLocation& goal)
: Heuristics(goal)
{} /* End of constructor */

double
Manhattan::calc(const int& current_x, const int& current_y) {
	return abs(current_y - goal_.x) + abs(current_y - goal_.y) ;
} /* End of calc */
} /* End of namespace */