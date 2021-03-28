#ifndef _DIAGONAL_HEURISTICS_H_
#define _DIAGONAL_HEURISTICS_H_

#include "common_includes.h"
#include "gridLocation.h"
#include "heuristics.h"

namespace Path_Planning_Algorithms {

/**
This heuristics is used when the agent is only allowed
to move in eight directions only (similar to how a King 
chess piece moves).
**/
class Diagonal : public Heuristics {
  public:
  	Diagonal() ;
  	Diagonal(const GridLocation& goal) ;
  	double calc(const int& current_x, const int& current_y) ;
} ; /* End of class */

} /* End of namespace */

#endif /* _DIAGONAL_HEURISTICS_H_ */