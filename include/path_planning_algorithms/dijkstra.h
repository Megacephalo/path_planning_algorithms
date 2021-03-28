#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

#include "common_includes.h"
#include "gridLocation.h"
#include "grid.h"
#include "path_planner_base.h"
#include "min_priority_queue.h"

namespace Path_Planning_Algorithms {

class Dijkstra : public Path_Planner {
  public:
  	Dijkstra(const Grid& grid) ;

  	void plan(const size_t& startRow, const size_t& startCol, const size_t& endRow, const size_t& endCol) ;

  private:
  	Min_Priority_Queue<> opened_ ;
	std::unordered_set<GridLocation, GridLocation::Hasher> closed_ ;

	void get_neighbors(const GridLocation& cell) ;
	bool is_closed(const GridLocation& cell) const ;
	bool not_opened(const GridLocation& cell) const ;
} ; /* End of Dijkstra */

} /* End of namespace */

#endif /* _DIJKSTRA_H_ */