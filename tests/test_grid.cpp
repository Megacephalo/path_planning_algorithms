#include <gtest/gtest.h>
#include <iostream>

#include "gridLocation.h"
#include "grid.h"

using namespace Path_Planning_Algorithms ;



TEST(GridTests, copy_constructor_test) {
	std::vector< std::vector<int> > testGrid = {
		{0, 1, 0, 0},
		{1, 0, 1, 0},
		{1, 1, 1, 1},
		{1, 1, 1, 0}
	} ;

	Grid grid(testGrid) ;

	std::cout << grid << std::endl ;
}

TEST(GridTests, assignment_operator_test) {
	Grid grid_A({
		{0, 0, 0},
		{1, 1, 0},
		{1, 1, 0}
	}) ;

	Grid grid_B = grid_A ;

	std::cout << "Grid A: " << grid_A << std::endl << "Grid B: " << grid_B << std::endl ;
}

TEST(GridTests, at_test) {
	Grid grid_A({
		{0, 0, 0},
		{1, 1, 0},
		{1, 1, 0}
	}) ;

	std::cout << "Before: " << grid_A << std::endl ; 
	ASSERT_EQ(0, grid_A.at(0, 2)) ;

	grid_A.at(0, 2) = 1 ;

	std::cout << "After: " << grid_A << std::endl ;
	ASSERT_EQ(1, grid_A.at(0, 2)) ;	

	EXPECT_THROW( grid_A.at(-1, -2), std::invalid_argument) ;
}

TEST(GridTests, get_canvas_test) {
	Grid grid_A({
		{0, 0, 0},
		{1, 1, 0},
		{1, 1, 0}
	}) ;

	std::cout << "Grid A: Before: " << grid_A.get_canvas() << std::endl ;

	grid_A.set_start(0, 0) ;
	grid_A.set_goal(2, 2) ;

	std::cout << "Grid A: After setting start and goal: " << grid_A.get_canvas() << std::endl ;	

	Grid grid_B({
		{1, 0, 0},
		{0, 1, 0},
		{1, 1, 0}
	}) ;

	std::cout << "Grid B: Before: " << grid_B.get_canvas() << std::endl ;

	grid_B.set_start(0, 1) ;
	grid_B.set_goal(0, 1) ;

	std::cout << "Grid B: After: " << grid_B.get_canvas() << std::endl ;
}

TEST(GridTests, render_dimensions_test) {
	Grid grid_A({
		{0, 1, 0, 0},
		{1, 0, 1, 0},
		{1, 1, 1, 0},
		{1, 1, 1, 0}
	}) ;

	ASSERT_EQ(3, grid_A.height()) ;
	ASSERT_EQ(3, grid_A.width()) ;
	ASSERT_EQ(16, grid_A.total_cells()) ;
}

TEST(GridTests, empty_test) {
	Grid emptyGrid ;

	ASSERT_TRUE( emptyGrid.empty() ) ;
	#if 0
	Grid grid_A( int_2d() ) ;

	std::cout << grid_A.raw_grid_.empty() << std::endl ;


	ASSERT_EQ(0, grid_A.width()) ;
	ASSERT_EQ(0, grid_A.height()) ;
	ASSERT_EQ(0, grid_A.total_cells()) ;
	ASSERT_TRUE(grid_A.raw_grid_.empty()) ;
	ASSERT_TRUE( grid_A.empty() ) ;
	#endif
}

TEST(GridTests, is_traversible_at_test) {

}

TEST(GridTests, update_trajectory_test) {
	std::vector< std::vector<int> > vectGrid = {
		{0, 1, 0, 0},
		{1, 0, 1, 0},
		{1, 1, 1, 0},
		{1, 1, 1, 0}
	} ;

	Grid testGrid(vectGrid) ;
	testGrid.set_start(0, 0) ;
	testGrid.set_goal(3, 3) ;

	std::cout << "Initial map: " << testGrid.get_canvas() << std::endl ;

	std::vector<GridLocation> trajectory({
		GridLocation(0, 0),
		GridLocation(1, 1),
		GridLocation(0, 2),
		GridLocation(1, 3),
		GridLocation(2, 3),
		GridLocation(3, 3)
	}) ;

	testGrid.update_trajectory(trajectory) ;

	std::cout << "Planned map: " << testGrid.get_canvas() << std::endl ;
}





int main(int argc, char** argv) {
        ::testing::InitGoogleTest(&argc, argv) ;

        return RUN_ALL_TESTS() ;
}