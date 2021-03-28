#ifndef _A_STAR_H_
#define _A_STAR_H_

#include "common_includes.h"
#include "gridLocation.h"
#include "grid.h"
#include "path_planner_base.h"
#include "min_priority_queue.h"
#include "heuristics.h"
#include "euclidean_heuristics.h"
#include "diagonal_heuristics.h"

namespace Path_Planning_Algorithms {

class AStar : public Path_Planner {
  public:
  	AStar(const Grid& grid) ;

  	void plan(const size_t& startRow, const size_t& startCol, const size_t& endRow, const size_t& endCol) ;

  private:
  	Min_Priority_Queue<> opened_ ;
	std::unordered_set<GridLocation, GridLocation::Hasher> closed_ ;
	std::unique_ptr<Heuristics> H_ ;

	void get_neighbors(const GridLocation& cell) ;
	bool is_closed(const GridLocation& cell) const ;
	bool not_opened(const GridLocation& cell) const ;
} ; /* End of class */

} /* End of namespace */

#endif /* _A_STAR_H_ */