#pragma once

#include "academicEntity.h"
#include <string>
#include <vector>
using namespace std;

class teacher : public academicEntity {
    vector<float> arrayofScore;
    float avgScore;
    float score;
public:
    teacher(int ID = 0 , string name="", string email="", float avgScore=0.0);
    void display();
    void giveFeedback(float i);
    string getname() const;
    friend void saveDataforTeacher();
    friend void loadDataforTeacher();
    friend class section;
    friend void addSections();
    friend void loadDataforSection();
    friend void saveDataforSection();
    friend void addTeacher();
    friend void removeTeacher();
    friend void updateTeacher();
    friend void updateCourse();
    friend void updateSection();
};