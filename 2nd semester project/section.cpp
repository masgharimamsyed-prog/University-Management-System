
#include<iostream>
#include"section.h"
#include"course.h"
#include"teacher.h"
#include"venue.h"

    section::section(int id, course* Cobj, teacher* Tobj, venue* Vobj) {
        this->id = id;
        this->Cobj = Cobj;
        this->Tobj = Tobj;
        this->Vobj = Vobj;
    }
    void section::display() {
        cout << "Section ID: " << id
            << "\nCourse: " << (Cobj != nullptr ? Cobj->name : "No Course")
            << "\nTeacher: " << (Tobj != nullptr ? Tobj->name : "No Teacher")
            << "\nVenue: " << (Vobj != nullptr ? to_string(Vobj->id) : "No Venue")
            << endl;
    }
    