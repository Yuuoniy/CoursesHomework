 #include <iostream>
#include <sstream>
#include "vehicle.h"

#ifndef TOU_H
#define TOU_H

class Tourist {
 public:
    explicit Tourist(Vehicle* strategy_){
    	strategy = strategy_;
    }

    inline void setStrategy(Vehicle* strategy_){
    	strategy = strategy_;
    }

    inline void travel(const City& src, const City& dest){
    	strategy->doTravel(src,dest);
    }

 private:
    Vehicle* strategy;
};
#endif


