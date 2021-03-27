#include <gtest/gtest.h>
#include <iostream>

#include "gridLocation.h"

using namespace Path_Planning_Algorithms ;

#if 0
class GridLocationTests : public ::testing::Test {
  protected:
  	GridLocation cell_ ;
} ;
#endif

TEST(GridLocationTests, constructor_test) {
	GridLocation cell(10, 20, 2, 1) ;
	ASSERT_EQ(10, cell.x) ;
	ASSERT_EQ(20, cell.y) ;
	ASSERT_EQ(2, cell.cost) ;
	ASSERT_EQ(1, cell.heuristics) ;
	ASSERT_EQ(3, cell.total_cost) ;
}

TEST(GridLocationTests, copy_constructor_test) {
	GridLocation otherCell(1, 2, 3.14159, 4.68) ;
	GridLocation newCell(otherCell) ;

	ASSERT_EQ(otherCell.x, newCell.x) ;
	ASSERT_EQ(otherCell.y, newCell.y) ;
	ASSERT_EQ(otherCell.cost, newCell.cost) ;
	ASSERT_EQ(otherCell.heuristics, newCell.heuristics) ;
	ASSERT_EQ(otherCell.total_cost, newCell.total_cost) ;
}

TEST(GridLocationTests, assignment_operator_test) {
	GridLocation cell_A(1, 2, 3., 4.) ;
	GridLocation cell_B = cell_A ;

	ASSERT_EQ(cell_A.x, cell_B.x) ;
	ASSERT_EQ(cell_A.y, cell_B.y) ;
	ASSERT_EQ(cell_A.cost, cell_B.cost) ;
	ASSERT_EQ(cell_A.heuristics, cell_B.heuristics) ;
	ASSERT_EQ(cell_A.total_cost, cell_B.total_cost) ;
}

TEST(GridLocationTests, equal_operator_test) {
	GridLocation cell_A(1, 2, 3, 4) ;
	GridLocation cell_B(1, 2, 3, 4) ;
	GridLocation cell_C ;

	ASSERT_EQ(cell_A, cell_B) ;
	ASSERT_FALSE(cell_A == cell_C) ;
}

TEST(GridLocationTests, smallerThan_operator_test) {
	GridLocation cell_A(1, 2, 1.3, 4) ;
	GridLocation cell_B(1, 2, 2.2, 4) ;
	GridLocation cell_C(1, 2, 1.4, 3.9) ;  

	ASSERT_TRUE( cell_A < cell_B ) ;
	ASSERT_TRUE( cell_A < cell_C ) ;
	ASSERT_FALSE( cell_B < cell_C ) ;

}

int main(int argc, char** argv) {
        ::testing::InitGoogleTest(&argc, argv) ;

        return RUN_ALL_TESTS() ;
}
