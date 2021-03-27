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

	while( !frontier_.empty() ) {
		auto current = frontier_.front() ;
		frontier_.pop_front() ;

		if (current == goal) {
			break ;
		}

		get_neighbors(current) ;
	} /* while */

	/* back-tracking trajectory */
	auto backtrackIt = cameFrom_.find(goal) ;
	trajectory_.push_back(goal) ;
	while( backtrackIt != cameFrom_.find(start) ) {
		auto predecessor = backtrackIt->second ;

		if (predecessor == backtrackIt->first) continue ;

		trajectory_.push_back(predecessor) ;

		backtrackIt = cameFrom_.find(predecessor) ;
	}

	std::reverse(trajectory_.begin(), trajectory_.end()) ;

	grid_.update_trajectory(trajectory_) ;
} /* End of plan */

void
BFS::get_neighbors( const GridLocation& cell) {
	for (auto& direction : directions_) {
		int neighbor_row = cell.x + direction.x ;
		int neighbor_col = cell.y + direction.y ;

		if (!grid_.is_traversible_at(neighbor_row, neighbor_col)) continue ;

		int neighbor_cost = cell.cost + 1 ;
		GridLocation neighbor(neighbor_row, neighbor_col, neighbor_cost) ;

		if ( cameFrom_.find(neighbor) == cameFrom_.end() ) {
			frontier_.push_back(neighbor) ;
			cameFrom_.insert( std::make_pair(neighbor, cell) ) ;
		}

	}
} /* End of get_neighbors */

} /* End of namespace */