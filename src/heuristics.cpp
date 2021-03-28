#include "heuristics.h"

namespace Path_Planning_Algorithms {

Heuristics::Heuristics()
: goal_(0, 0)
{} /* End of default constructor */

Heuristics::Heuristics(const GridLocation& goal)
: goal_(goal)
{} /* End of constructor */

void
Heuristics::set_goal(const GridLocation& goal) {
	goal_ = goal ;
} /* End of set_goal */

double
Heuristics::calc(const GridLocation& current) {
	return calc(current.x, current.y) ;
} /* End of calc */

} /* End of namespace */