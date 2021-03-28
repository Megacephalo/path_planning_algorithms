#include "euclidean_heuristics.h"

namespace Path_Planning_Algorithms {

Euclidean::Euclidean()
: Heuristics()
{} /* End of constructor */

Euclidean::Euclidean(const GridLocation& goal)
: Heuristics(goal)
{} /* End of construcror */

double
Euclidean::calc(const int& current_x, const int& current_y) {
	auto diff_x_sqr = (current_x - goal_.x) * (current_x - goal_.x) ;
	auto diff_y_sqr = (current_y - goal_.y) * (current_y - goal_.y) ;

	return sqrt(diff_x_sqr + diff_y_sqr) ;
} /* End of calc */

} /* End of namespace */
