#include "all_headers.h"

using namespace Path_Planning_Algorithms ;

int main(int argc, char** argv) {
	std::cout << "path_planner launched!!" << std::endl ;
	
	std::vector< std::vector<int> > vectGrid = {
		{0, 0, 0, 1, 0, 0, 0},
		{0, 1, 1, 1, 0, 0, 0},
		{0, 1, 0, 0, 0, 1, 1},
		{0, 0, 1, 1, 1, 0, 1},
		{0, 1, 1, 1, 0, 0, 0}
	} ;
	Grid grid(vectGrid) ;

	GridLocation start(0, 0), goal(vectGrid.size() - 1, vectGrid.at(0).size() - 1) ; 
	
	grid.set_goal( goal ) ;
	grid.set_start( start ) ;

	std::cout << "Given map:" << grid.get_canvas() << std::endl ;

	/* Using BFS planner */
	std::unique_ptr<Path_Planner> planner = std::make_unique<BFS>(grid) ;

	planner->plan(start, goal) ;

	std::cout  << "Trajectory: " << planner->get_grid().get_canvas() << std::endl ;

	return 0 ;
}