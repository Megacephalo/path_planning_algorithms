#include "gridLocation.h"


namespace Path_Planning_Algorithms {

GridLocation::GridLocation()
: x(-1)
, y(-1)
, cost(0.)
, heuristics(0.)
, total_cost(0.)
{} /* End of default constructor */

GridLocation::GridLocation(const int& x_, const int& y_, const double& cost_, const double& heuristics_) 
: x(x_)
, y(y_)
, cost(cost_)
, heuristics(heuristics_)
, total_cost(cost + heuristics)
{} /* End of constructor */


GridLocation::GridLocation(const GridLocation& gridLoc) 
: x(gridLoc.x)
, y(gridLoc.y)
, cost(gridLoc.cost)
, heuristics(gridLoc.heuristics)
, total_cost(gridLoc.total_cost)
{} /* End of copy constructor */

GridLocation
GridLocation::operator = (const GridLocation& gridLoc) {
	this->x = gridLoc.x ;
	this->y = gridLoc.y ;
	this->cost = gridLoc.cost ;
	this->heuristics = gridLoc.heuristics ;
	this->total_cost = gridLoc.total_cost ;

	return *this ;
} /* End of assignment operator overloading */


bool
GridLocation::operator == (const GridLocation& otherCell) const {
	return (this->x == otherCell.x && this->y == otherCell.y) ;
} /* End of operator == overloading */

bool
GridLocation::operator < (const GridLocation& otherCell) const {
	if (this->total_cost == otherCell.total_cost) {
		return ( this->cost < otherCell.cost ) ;	
	}
	return (this->total_cost < otherCell.total_cost) ;
} /* End of operator < overloading */

size_t
GridLocation::Hasher::operator () (const GridLocation& a) const noexcept {
	std::hash<int> int_hasher ;
	std::hash<double> d_hasher ;

	return int_hasher(a.x) ^ int_hasher(a.y) ^ d_hasher(a.cost) ^ d_hasher(a.heuristics) ^ d_hasher(a.total_cost) ;
} /* End of operator () overloading */

std::ostream& operator << (std::ostream& os, const GridLocation& loc) {
	os << "[ (" << loc.x << ", " << loc.y << ") g: " << loc.cost << " h: " << loc.heuristics << " f: " << loc.total_cost << " ]" ;
	return os ;
} /* End of operator << overloading for GridLocation class */

} /* End of namespace */