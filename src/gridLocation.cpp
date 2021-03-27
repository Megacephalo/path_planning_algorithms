#include "gridLocation.h"


namespace Path_Planning_Algorithms {

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


std::ostream& operator << (std::ostream& os, const GridLocation& loc) {
	os << "[ (" << loc.x << ", " << loc.y << ") g: " << loc.cost << " h: " << loc.heuristics << " f: " << loc.total_cost << " ]" ;
	return os ;
} /* End of operator << overloading for GridLocation class */

} /* End of namespace */