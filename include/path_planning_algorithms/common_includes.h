#ifndef _COMMON_INCLUDES_H_
#define _COMMON_INCLUDES_H_

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <exception>
#include <list>
#include <utility>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>			// std::reverse
#include <cmath>

namespace Path_Planning_Algorithms {

template <typename T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& v) {
	for (auto& ele : v) {
		os << ele << "  " ;
	}
	os << std::endl ;

	return os ;
} /* End of operator << overloading for vector<T> */


template <typename T>
std::ostream& operator << (std::ostream& os, const std::vector< std::vector<T> >& grid) {
	os << std::endl ;
	for (auto& row : grid) {
		for (auto& cell : row) {
			os << cell << "  " ;
		}
		os << std::endl ;
	}
	return os ;
} /* End of operator << overloading for vector< vector<T> > */

} /* End of namespace */

#endif /* _COMMON_INCLUDES_H_ */