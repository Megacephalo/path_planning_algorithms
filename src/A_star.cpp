#include "A_star.h"

namespace Path_Planning_Algorithms {

AStar::AStar(const Grid& grid)
: Path_Planner(grid)
, H_(std::make_unique<Euclidean>())
// , H_(std::make_unique<Diagonal>())
{} /* End of constructor */

void
AStar::plan(const size_t& startRow, const size_t& startCol, const size_t& endRow, const size_t& endCol) {
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

	H_->set_goal(goal) ;

	opened_.push( start ) ;

	bool exist_path = false ;
	while( !opened_.empty() ) {
		auto current = opened_.top() ;
		opened_.pop() ;
		closed_.insert(current) ;

		if ( current == goal ) {
			exist_path = true ;
			break ;
		}

		get_neighbors(current) ;
	} /* while */

	if ( !exist_path ) {
		std::cerr << "The goal is unreachable. Failed to find a valid trajectory.\n" ;
		return ;
	}

	extract_trajectory(start, goal) ;
} /* End of plan */

void
AStar::get_neighbors(const GridLocation& cell) {
	for (auto& direction : directions_) {
		int neighbor_row = cell.x + direction.x ;
		int neighbor_col = cell.y + direction.y ;
		double neighbor_cost = cell.cost + 1. ;
		GridLocation neighbor(neighbor_row, neighbor_col, neighbor_cost, H_->calc(neighbor_row, neighbor_col) ) ;

		if ( !grid_.is_traversible_at(neighbor_row, neighbor_col) || is_closed(neighbor) ) continue ;

		if ( not_opened(neighbor) ) {

			opened_.push( neighbor ) ;

			if ( not_in_cameFrom(neighbor) ) {
				cameFrom_.insert( std::make_pair(neighbor, cell) ) ;	
			}
		}
		/* if the node is already explored, but we are finding a lower cost for the same node, relax it. */ 
		else {
			opened_.Find(neighbor)->cost = std::min( opened_.Find(neighbor)->cost, neighbor_cost ) ;
		}
	} /* for */
} /* End of get_neighbors */

bool
AStar::is_closed(const GridLocation& cell) const {
	return ( closed_.find(cell) != closed_.end() ) ;
} /* End of is_closed */

bool
AStar::not_opened(const GridLocation& cell) const {
	return ( opened_.find(cell) == opened_.end() ) ;
} /* End of not_opened */


} /* End of namespace */