#include "diagonal_heuristics.h"

namespace Path_Planning_Algorithms {

Diagonal::Diagonal()
: Heuristics()
{} /* End of constructor */

Diagonal::Diagonal(const GridLocation& goal)
: Heuristics(goal)
{} /* End of constructor */

double
Diagonal::calc(const int& current_x, const int& current_y) {
	return std::max( abs(current_x - goal_.x), abs(current_y - goal_.y) ) ;
} /* End of calc */

} /* End of namespace */