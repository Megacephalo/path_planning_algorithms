#include "BFS.h"

namespace Path_Planning_Algorithms {

BFS::BFS(const Grid& grid)
: Path_Planner(grid)
{} /* End of constructor */

void
BFS::plan(const size_t& startRow, const size_t& startCol, const size_t& endRow, const size_t& endCol) {
	if ( !grid_.is_traversible_at(startRow, startCol) ) {
		std::cerr << "The start coordinates (" << startRow << ", " << startCol << ") is not traversible.\n" ;
		return ;
	}
	if ( !grid_.is_traversible_at(endRow, endCol) ) {
		std::cerr << "The goal coordinates (" << endRow << ", " << endCol << ") is not traversible.\n" ;
		return ;
	}

	GridLocation start(startRow, startCol, 1) ;
	GridLocation goal(endRow, endCol) ;
	
	frontier_.push_back( start ) ;
	cameFrom_.insert( std::make_pair(start, start) ) ;

	bool exists_path = false ;
	while( !frontier_.empty() ) {
		auto current = frontier_.front() ;
		frontier_.pop_front() ;

		closed_.push_back(current) ;

		if (current == goal) {
			exists_path = true ;
			break ;
		}

		get_neighbors(current) ;
	} /* while */

	if (!exists_path) {
		std::cerr << "The goal is unreachable. Failed to find a valid trajectory.\n" ;
		return ;
	}

	extract_trajectory(start, goal) ;

} /* End of plan */

void
BFS::get_neighbors( const GridLocation& cell) {
	for (auto& direction : directions_) {
		int neighbor_row = cell.x + direction.x ;
		int neighbor_col = cell.y + direction.y ;
		int neighbor_cost = cell.cost + 1 ;
		GridLocation neighbor(neighbor_row, neighbor_col, neighbor_cost) ;

		if ( !grid_.is_traversible_at(neighbor_row, neighbor_col) || in_closed(neighbor) ) continue ;

		if ( not_in_cameFrom(neighbor) && not_opened(neighbor)) {
			frontier_.push_back(neighbor) ;
			cameFrom_.insert( std::make_pair(neighbor, cell) ) ;
		}

	}
} /* End of get_neighbors */

bool
BFS::not_opened(const GridLocation& cell) const {
	return std::find(frontier_.begin(), frontier_.end(), cell) == frontier_.end() ;
} /* end of not_opened */

bool
BFS::in_closed(const GridLocation& cell) const {
	return std::find(closed_.begin(), closed_.end(), cell) != closed_.end() ;
} /* End of not_in_closed */

} /* End of namespace */