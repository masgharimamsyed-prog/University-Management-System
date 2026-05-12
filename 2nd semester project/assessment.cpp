
#include<iostream>
#include"course.h"
#include "assessment.h"



    finals::finals(course* Cobj, float totalMarks, float obtainMarks) {
        this->Cobj = Cobj;
        this->totalMarks = totalMarks;
        this->obtainMarks = obtainMarks;
        this->type = "finals";
    }

    void finals::display() {
        cout << "coursename:" << Cobj->name
            << ",type:" << type
            << ",total:" << totalMarks
            << ",obtain:" << obtainMarks << endl;
    }


    quizzes::quizzes(course* Cobj, float totalMarks, float obtainMarks) {
        this->Cobj = Cobj;
        this->totalMarks = totalMarks;
        this->obtainMarks = obtainMarks;
        this->type = "quiz";
    }

    void quizzes::display() {
        cout << "course name:" << Cobj->name
            << ",type:" << type
            << ",total:" << totalMarks
            << ",obtain:" << obtainMarks << endl;
    }


    assignments::assignments(course* Cobj, float totalMarks, float obtainMarks) {
        this->Cobj = Cobj;
        this->totalMarks = totalMarks;
        this->obtainMarks = obtainMarks;
        this->type = "assignment";
    }

    void assignments::display() {
        cout << "course name:" << Cobj->name
            << ",type:" << type
            << ",total:" << totalMarks
            << ",obtain:" << obtainMarks << endl;
    }

