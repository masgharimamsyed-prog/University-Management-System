#pragma once
#include <string>   
using namespace std;

class academicEntity {
protected:
    int ID = 0;
    string email;
public:
    string name;
    virtual void display() = 0;
};