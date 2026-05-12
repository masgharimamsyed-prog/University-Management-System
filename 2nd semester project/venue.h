#pragma once
#include<iostream>
using namespace std;
class venue {
protected:
    int id;
    int capacity;
    bool hascomp;
public:
    venue(int roomno = 0, int capacity = 0, bool computer = 0);
    void display() const;
    friend void saveDataforVenue();
    friend class section;
    friend void addSections();
    friend void loadDataforSection();
    friend void saveDataforSection();
    friend void addVenue();
    friend void removeVenue();
    friend void updateVenue();
    friend void updateSection();
};