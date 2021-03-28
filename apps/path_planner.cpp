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

	GridLocation start(0, 0), goal( grid.height(), grid.width() ) ; 
	
	grid.set_goal( goal ) ;
	grid.set_start( start ) ;

	std::cout << "Given map:" << grid.get_canvas() << std::endl ;

	/* Using BFS planner */
	std::cout << "Using BFS Planner\n" ;
	std::unique_ptr<Path_Planner> planner = std::make_unique<BFS>(grid) ;

	planner->plan(start, goal) ;

	std::cout  << "Trajectory: " << planner->get_grid().get_canvas() << std::endl ;

	std::cout << "Using Dijkstra planner.\n" ;
	planner = std::make_unique<Dijkstra>(grid) ;

	planner->plan(start, goal) ;

	std::cout  << "Trajectory: " << planner->get_grid().get_canvas() << std::endl ;

	return 0 ;
}