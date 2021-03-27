#ifndef _GRID_LOCATION_H_
#define _GRID_LOCATION_H_

#include "common_includes.h"

namespace Path_Planning_Algorithms {

struct GridLocation {
	int x ;
	int y ;
	double cost ;
	double heuristics ;
	double total_cost ;

	GridLocation() ;
	GridLocation(const int& x_ = 0, const int& y_ = 0, const double& cost_ = 0., const double& heuristics_ = 0.) ;
	GridLocation(const GridLocation& gridLoc) ;
	GridLocation operator = (const GridLocation& gridLoc) ;

	bool operator == (const GridLocation& otherCell) const ;
	bool operator < (const GridLocation& otherCell) const ;

	/* Functor to deeliver hash function for set, map, unordered_set, and unordered_map */
	struct Hasher {
		size_t operator() (const GridLocation& a) const noexcept ;
	} ; /* End of Hasher */
} ; /* End of class */

std::ostream& operator << (std::ostream& os, const GridLocation& loc) ;

} /* End of namespace */


#endif /* _GRID_LOCATION_H_ */