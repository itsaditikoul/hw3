#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

struct EventLess {
        //write the operator() required to make this a functor that compares Events by time
        bool operator() (const Event* a, const Event* b) const{
          // ret true when a above b in min heap
          return a->time < b->time;
        }
};
	
#endif
