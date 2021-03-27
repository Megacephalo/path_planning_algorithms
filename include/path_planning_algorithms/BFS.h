#ifndef _BFS_H_
#define _BFS_H_


#include "common_includes.h"
#include "gridLocation.h"
#include "grid.h"
#include "path_planner_base.h"

namespace Path_Planning_Algorithms {

class BFS : public Path_Planner {
  public:
  	BFS(const Grid& grid) ;

  	void plan(const size_t& startRow, const size_t& startCol, const size_t& endRow, const size_t& endCol) ;
  private:
  	std::list<GridLocation> frontier_ ;
  	/* (the node, its predecessor) */
  	std::unordered_map<GridLocation, GridLocation, GridLocation::Hasher> cameFrom_ ;

  	void get_neighbors( const GridLocation& cell) ;
} ; /* End of cass */

} /* End of namespace */


#endif /* _BFS_H_ */