#include "grid.h"

namespace Path_Planning_Algorithms {

Grid::Grid()
: raw_grid_({})
, width_(0)
, height_(0)
, total_cells_(0)
, startRow_(0)
, startCol_(0)
, endRow_(0)
, endCol_(0)
{} /* End of constructor */

Grid::Grid(const int_2d& vect_grid) 
: raw_grid_(vect_grid)
, width_( vect_grid.empty() ? 0 : vect_grid.at(0).size() - 1)
, height_(vect_grid.size() - 1)
, total_cells_( (width_ + 1) * (height_ + 1))
, startRow_(0)
, startCol_(0)
, endRow_(0)
, endCol_(0)
{} /* End of constructor */

Grid::Grid(const Grid& grid) 
: raw_grid_(grid.raw_grid_)
, width_(grid.width_)
, height_(grid.height_)
, total_cells_(grid.total_cells_)
, startRow_(grid.startRow_)
, startCol_(grid.startCol_)
, endRow_(grid.endRow_)
, endCol_(grid.endCol_)
{} /* End of copy constructor */


Grid
Grid::operator = (const Grid& otherGrid) {
	raw_grid_ = otherGrid.raw_grid_ ;
	width_ = otherGrid.width_ ;
	height_ = otherGrid.height_ ;
	total_cells_ = otherGrid.total_cells_ ;
	startRow_ = otherGrid.startRow_ ;
	startCol_ = otherGrid.startCol_ ;
	endRow_ = otherGrid.endRow_ ;
	endCol_ = otherGrid.endCol_ ;

	return *this ;
} /* End of assignment operator overloading */



int&
Grid::at(const int& x, const int& y) {
	return at( (size_t)x, (size_t)y ) ;
} /* End of at */

int&
Grid::at(const size_t& x, const size_t& y) {
	if (!within_bounds(x, y)) {
		throw std::invalid_argument( "the input coordinates (" + std::to_string(x) + ", " + std::to_string(y) + ") is out of bounds.") ;
	}

	return raw_grid_.at(x).at(y) ;
} /* End of at */



void
Grid::set_start(const GridLocation& start) {
	size_t x = start.x ;
	size_t y = start.y ;

	set_start(x, y) ;
} /* End of set_start */

void
Grid::set_start(const size_t& startRow, const size_t& startCol) {
	if (!within_bounds(startRow, startCol)) {
		throw std::invalid_argument("The start coordinates (" + std::to_string(startRow) + ", " + std::to_string(startCol) + ") is out of bounds" ) ;
	}

	if (!is_traversible_at(startRow, startCol)) {
		throw std::invalid_argument("The given start coordinates (" + std::to_string(startRow) + ", " + std::to_string(startCol) + ") is on a non-traversible spot thus cannot be placed.") ;
	}

	startRow_ = startRow ;
	startCol_ = startCol ;

	if (startRow_ != endRow_ && startCol_ != endCol_) {
		raw_grid_.at(startRow_).at(startCol_) = 2 ;
	}
	else {
		raw_grid_.at(startRow_).at(startCol_) = 4 ;	
	}
} /* End of set_start */

void
Grid::set_goal(const GridLocation& goal) {
	size_t x = goal.x ;
	size_t y = goal.y ;

	set_goal(x, y) ;
} /* End of set_goal */

void
Grid::set_goal(const size_t& endRow, const size_t& endCol) {
	if (!within_bounds(endRow, endCol)) {
		throw std::invalid_argument("The given goal coordinates (" + std::to_string(endRow) + ", " + std::to_string(endCol) + ") is out of bounds.") ;
	}

	if (!is_traversible_at(endRow, endCol)) {
		throw std::invalid_argument("The given goal coordinates (" + std::to_string(endRow) + ", " + std::to_string(endCol) + ") is on a non-traversible spot thus cannot be placed.") ;
	}

	endRow_ = endRow ;
	endCol_ = endCol ;

	if (endRow_ != startRow_ && endCol_ != startCol_) {
		raw_grid_.at(endRow_).at(endCol_) = 3 ;
	}
	else {
		raw_grid_.at(endRow_).at(endCol_) = 4 ;	
	}
} /* End of set_goal */

bool
Grid::is_traversible_at(const int& x, const int& y) const {
	return is_traversible_at( (size_t)x, (size_t)y ) ;
} /* End of is_traversible_at */

bool
Grid::is_traversible_at(const size_t& x, const size_t& y) const {
	if (!within_bounds(x, y)) return false ;

	return ( raw_grid_.at(x).at(y) != 1 ) ;
} /* End of is_traversible_at */

bool
Grid::within_bounds(const size_t& x, const size_t& y) const {
	return (x >= 0 && x <= height_) && (y >= 0 && y <= width_) ;
} /* End of within_bounds */

char_2d
Grid::get_canvas() const {
	auto char_grid = char_2d(raw_grid_.size()) ;
	size_t i = 0 ;
	for (auto& row : raw_grid_) {
		for (auto& cell : row) {
			const char* symbol ;
			/* passible cell */
			if (cell == 0) {
				symbol = "*" ;
			}
			/* obstacle cell */
			else if ( cell == 1 ) {
				symbol = "#" ;
			}
			/* Start cell */
			else if ( cell == 2 ) {
				symbol = "S" ;
			}
			/* Goal cell */
			else if ( cell == 3 ) {
				symbol = "G" ;
			}
			/* Start and goal cell */
			else if ( cell == 4 ) {
				symbol = "SG" ;
			}
			/* Found trajectory */
			else if ( cell == 5 ) {
				symbol = "@" ;
			}
			else {
				std::cerr << cell << " is not recognizable. Leaving it a blank\n" ;
				symbol = " " ;
			}
			char_grid.at(i).push_back( symbol ) ;
		}
		++i ;
	}


	return char_grid ;
} /* End of get_canvas */

size_t
Grid::width() const {
	return width_ ;
} /* End of width */

size_t
Grid::height() const {
	return height_ ;
}

size_t
Grid::total_cells() const {
	return total_cells_ ;
} /* End of total_cells */

bool
Grid::empty() const {
	return raw_grid_.empty() ;
} /* End of empty */

void
Grid::update_trajectory(const trajectory& traj) {
	for (auto& step : traj) {
		raw_grid_.at(step.x).at(step.y) = 5 ;
	}
} /* End of update_trajectory */

std::ostream& operator << (std::ostream& os, const Grid& grid) {
	os << grid.raw_grid_ ;
	return os ;
} /* End of operator << overloading for Grid class */


} /* End of namespace */