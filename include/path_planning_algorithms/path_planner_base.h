#ifndef _PATH_PLANNER_BASE_H_
#define _PATH_PLANNER_BASE_H_

#include "common_includes.h"

#include "gridLocation.h"
#include "grid.h"

namespace Path_Planning_Algorithms {

class Path_Planner {
  public:
  	Path_Planner(const Grid& grid) ;
  	void plan(const GridLocation& start, const GridLocation& goal) ;
  	virtual void plan(const size_t& startRow, const size_t& startCol, const size_t& endRow, const size_t& endCol) = 0 ;
  	Grid get_grid() const ;

  protected:
  	Grid grid_ ;
  	std::vector<GridLocation> directions_ ;
  	std::vector<GridLocation> trajectory_ ;

  	/* (the node, its predecessor) */
  	std::unordered_map< GridLocation, GridLocation, GridLocation::Hasher > cameFrom_ ;

    void extract_trajectory(const GridLocation& start, const GridLocation& goal) ;
    bool not_in_cameFrom(const GridLocation& cell) const ;
} ; /* End of class */


} /* End of namespace */

#endif /* _PATH_PLANNER_BASE_H_ */