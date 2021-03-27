#ifndef _MIN_PRIORITY_QUEUE_H_
#define _MIN_PRIORITY_QUEUE_H_

#include "common_includes.h"
#include "gridLocation.h"

namespace Path_Planning_Algorithms {

struct minPriorQueue_Comp {
	bool operator () (const GridLocation& a, const GridLocation& b) {
		if (a.total_cost == b.total_cost) {
			return (a.cost > b.cost) ;
		}
		return (a.total_cost > b.total_cost) ;
	} /* operator < overloading for min priority queue */
} ; /* End of minPriorQueue_Comp */

template < typename T = GridLocation,
		   typename Container = std::vector<T>,
		   typename Compare = minPriorQueue_Comp >
struct Min_Priority_Queue : public std::priority_queue<T, Container, Compare> {
	typedef typename std::priority_queue<T, Container, Compare>::container_type::const_iterator const_iterator ;

	const_iterator find(const T& cell) const {
		auto foundIt = this->c.begin() ;
		auto last = this->c.end() ;
		while(foundIt != last) {
			if (*foundIt == cell) {
				return foundIt ;
			}
			++foundIt ;
		}

		return last ;
	} /* End of find */

	const_iterator begin() const {
		return this->c.begin() ;
	} /* End of begin */

	const_iterator end() const {
		return this->c.end() ;
	} /* End of end */
} ; /* End of Min_Priority_Queue */





} /* End of namespace */
#endif /* _MIN_PRIORITY_QUEUE_H_ */