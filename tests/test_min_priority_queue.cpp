#include <gtest/gtest.h>
#include <iostream>

#include "common_includes.h"
#include "gridLocation.h"
#include "min_priority_queue.h"

using namespace Path_Planning_Algorithms ;

TEST(Min_Priority_Queue_tests, basic_function_test) {
	Min_Priority_Queue<> mp_queue ;

	mp_queue.push( GridLocation(2, 0, 5.) ) ;
	mp_queue.push( GridLocation(0, 0, 1.) ) ;
	mp_queue.push( GridLocation(1, 0, 2.) ) ;
	mp_queue.push( GridLocation(0, 1, 3.) ) ;
	mp_queue.push( GridLocation(1, 1, 4.) ) ;

	ASSERT_EQ( mp_queue.top(), GridLocation(0, 0, 1.) ) ;
	mp_queue.pop() ;
	ASSERT_EQ( 4, mp_queue.size() ) ;
	ASSERT_FALSE( mp_queue.empty() ) ;

	ASSERT_EQ(mp_queue.top(), GridLocation(1, 0, 2.) ) ;
	mp_queue.pop() ;
	ASSERT_EQ(mp_queue.top(), GridLocation(0, 1, 3.) ) ;
	mp_queue.pop() ;
	mp_queue.pop() ;
	mp_queue.pop() ;

	ASSERT_TRUE( mp_queue.empty() ) ;
}

TEST(Min_Priority_Queue_tests, find_test) {
	Min_Priority_Queue<> mp_queue ;

	mp_queue.push( GridLocation(2, 0, 5.) ) ;
	mp_queue.push( GridLocation(0, 0, 1.) ) ;
	mp_queue.push( GridLocation(1, 0, 2.) ) ;
	mp_queue.push( GridLocation(0, 1, 3.) ) ;
	mp_queue.push( GridLocation(1, 1, 4.) ) ;

	auto foundIt = mp_queue.find( GridLocation(1, 0, 2.) ) ;
	ASSERT_EQ( *foundIt, GridLocation(1, 0, 2.) ) ;

	auto notFoundIt = mp_queue.find( GridLocation(3, 0, 7.) ) ;

	ASSERT_TRUE( notFoundIt == mp_queue.end() ) ;
}



int main(int argc, char** argv) {
        ::testing::InitGoogleTest(&argc, argv) ;

        return RUN_ALL_TESTS() ;
}