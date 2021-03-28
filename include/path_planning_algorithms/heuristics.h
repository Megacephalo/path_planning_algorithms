#ifndef _HEURISTICS_H_
#define _HEURISTICS_H_

#include "common_includes.h"
#include "gridLocation.h"

namespace Path_Planning_Algorithms {

class Heuristics {
  public:
  	Heuristics() ;
  	Heuristics(const GridLocation& goal) ;

  	void set_goal(const GridLocation& goal) ;
  	double calc(const GridLocation& current) ;
  	virtual double calc(const int& current_x, const int& current_y) = 0 ;
  
  protected:
  	GridLocation goal_ ;
} ; /* End of Heuristics */

} /* End of namespace */

#endif /* _HEURISTICS_H_ */