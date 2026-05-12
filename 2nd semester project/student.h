#pragma once
#include "academicEntity.h"
#include <vector>
#include<iostream>
#include<string>


class Assessment;
class student : public academicEntity {
protected:
    float GPA = 0.0;
    string type;
    vector <Assessment*> assess;
public:
    friend void saveDataforAssessment();
    virtual void display() = 0;
    virtual void setGPA(float GPA) = 0;
    friend void viewStudents();
    friend void saveDataforStudent();
    friend void loadDataforAssessment();
    friend void addAssessment();
    friend void addStudent();
    friend void showAssessmentofStudent();
    friend void addTeacher();
    friend void removeStudent();
    friend void updateStudent();
};
class scholarshipStudent : public student {
protected:
    bool probation;
public:
    scholarshipStudent(int ID = 0, string name = "", string email = "", float GPA = 0, bool extra = false);
    friend void viewStudents();
    void display();
    void setGPA(float GPA);
    friend void saveDataforStudent();
};
//
class exchangeStudent : public student {
protected:
    bool fail;
public:
    exchangeStudent(int ID = 0, string name = "", string email = "", float GPA = 0, bool extra = false);
    friend void viewStudents();
    void display();
    void setGPA(float GPA);
    friend void saveDataforStudent();
};
class regularStudent : public student {
protected:
    bool feeStatus;
public:
    regularStudent(int ID = 0, string name = "", string email = "", float GPA = 0, bool extra = true);
    void display();
    friend void viewStudents();
    void setGPA(float GPA);
    void setfeeStatus(bool fee);
    friend void saveDataforStudent();
};