#ifndef _GRID_LOCATION_H_
#define _GRID_LOCATION_H_

#include <iostream>

namespace Path_Planning_Algorithms {

struct GridLocation {
	int x ;
	int y ;
	double cost ;
	double heuristics ;
	double total_cost ;

	GridLocation(const int& x_ = 0, const int& y_ = 0, const double& cost_ = 0., const double& heuristics_ = 0.) ;
	GridLocation(const GridLocation& gridLoc) ;
	GridLocation operator = (const GridLocation& gridLoc) ;

	bool operator == (const GridLocation& otherCell) const ;
	bool operator < (const GridLocation& otherCell) const ;
} ; /* End of class */

std::ostream& operator << (std::ostream& os, const GridLocation& loc) ;

} /* End of namespace */


#endif /* _GRID_LOCATION_H_ */