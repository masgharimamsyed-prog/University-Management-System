#pragma once
#include"course.h"
#include"teacher.h"
#include"venue.h"
class section {
    int id;
    course* Cobj;
    teacher* Tobj;
    venue* Vobj;
public:
    section(int id, course* Cobj, teacher* Tobj, venue* Vobj);
    void display();
    friend void saveDataforSection();
    friend void addSections();
    friend void removeSection();
    friend void updateSection();
};