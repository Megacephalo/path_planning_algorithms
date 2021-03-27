#ifndef _GRID_H_
#define _GRID_H_

/**
TODO: optimize the update of canvas_grid_ to be pointer-based
**/

#include "common_includes.h"
#include "gridLocation.h"

namespace Path_Planning_Algorithms {

typedef std::vector< std::vector<int> > int_2d ;
typedef std::vector< std::vector<const char*> > char_2d ;
typedef std::vector<GridLocation> trajectory ;


struct Grid {
  	int_2d raw_grid_ ;
  	size_t width_ ;
  	size_t height_ ;
  	size_t total_cells_ ;
  	size_t startRow_ ;
  	size_t startCol_ ;
  	size_t endRow_ ;
  	size_t endCol_ ;

  	Grid() ;
  	Grid(const int_2d& vect_grid) ;
  	Grid(const Grid& grid) ;
  	Grid operator = (const Grid& otherGrid) ;

  	int& at(const int& x, const int& y) ;
  	int& at(const size_t& x, const size_t& y) ;
  	void set_start(const GridLocation& start) ;
  	void set_start(const size_t& startRow, const size_t& startCol) ;
  	void set_goal(const GridLocation& goal) ;
  	void set_goal(const size_t& endRow, const size_t& endCol) ;
  	bool is_traversible_at(const int& x, const int& y) const ;
  	bool is_traversible_at(const size_t& x, const size_t& y) const ;
  	bool within_bounds(const size_t& x, const size_t& y) const ;
  	char_2d get_canvas() const ;
  	size_t width() const ;
  	size_t height() const ;
  	size_t total_cells() const ;
  	bool empty() const ;

  	void update_trajectory(const trajectory& traj) ;

  	
} ; /* End of class*/


std::ostream& operator << (std::ostream& os, const Grid& grid) ;

} /* End of namespace */

#endif /* _GRID_H_ */