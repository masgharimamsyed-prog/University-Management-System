#include "venue.h"
#include<iostream>


    venue::venue(int roomno, int capacity , bool computer ) {
        this->id = roomno;
        this->capacity = capacity;
        this->hascomp = computer;
    }
    void venue::display() const {
        cout << "Room No:" << id << ", Capacity:" << capacity
            << ", Computer:" << (hascomp ? "Yes" : "No") << endl;
    }
  
