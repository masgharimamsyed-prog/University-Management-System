#pragma once
#include<iostream>
#include"course.h"

class Assessment {
protected:
    course* Cobj = nullptr;
    string type;
    float totalMarks = 0;
    float obtainMarks = 0;
public:
    virtual void display() = 0;
    friend void addAssessment();
    friend void saveDataforAssessment();
    friend void showAssessmentofStudent();
};
class finals : public Assessment {
public:
    finals(course* Cobj, float totalMarks, float obtainMarks);

    void display();
};
class quizzes : public Assessment {
public:
    quizzes(course* Cobj, float totalMarks, float obtainMarks);

    void display();
};
class assignments : public Assessment {
public:
    assignments(course* Cobj, float totalMarks, float obtainMarks);

    void display();
};
