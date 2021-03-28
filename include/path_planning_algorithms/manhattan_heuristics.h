#ifndef _EUCLIDEAN_HEURISTICS_H_
#define _EUCLIDEAN_HEURISTICS_H_

#include "common_includes.h"
#include "gridLocation.h"
#include "heuristics.h"

namespace Path_Planning_Algorithms {

/**
This heuristic type is used when the agent is only allowed to 
move on four directions (instead of eight).
**/
class Manhattan : public Heuristics {
  public:
  	Manhattan() ;
  	Manhattan(const GridLocation& goal) ;
  	double calc(const int& current_x, const int& current_y) ;
} ; /* End of class */

} /* End of namespace */

#endif /* _EUCLIDEAN_HEURISTICS_H_ */