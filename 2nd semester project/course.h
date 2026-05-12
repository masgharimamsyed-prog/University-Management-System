#pragma once
#include "student.h"
#include "teacher.h"
#include<string.h >
class course {
protected:
    int noofStudents = 0;
    vector<student*> itsStudents;
    string type;
    teacher* obj = nullptr;
public:
    int code = 0;
    string name;
    virtual void assignCourse(teacher* obj) = 0;
    virtual void display() = 0;
    virtual void showitsStudents() = 0;
    friend void assignCourseToTeacher();
    virtual void AddingStudenttoCourse(student* obj) = 0;
    friend void registerStudentInCourse();
    void setno(int i) {
        noofStudents = i;
    }
    friend void saveDataforCourse();
    friend void loadDataforCourse();
    friend class section;
    friend void addSections();
    friend void loadDataforSection();
    friend void saveDataforSection();
    friend void updateCourse();
};
class core : public course {
public:
    core(int code, string name, teacher* obj);
   
    void display();
    void showitsStudents();
    void assignCourse(teacher* obj);
    void AddingStudenttoCourse(student* obj);
    friend void saveDataforAssessment();
};
class elective : public course {
public:
    elective(int code, string name, teacher* obj);
    friend void saveDataforCourse();
    void display();
    void assignCourse(teacher* obj);
    void showitsStudents();
    void AddingStudenttoCourse(student* obj);
    friend void saveDataforAssessment();
};
class lab : public course {
public:
    lab(int code, string name, teacher* obj);
    friend void saveDataforCourse();
    void display();
    void assignCourse(teacher* obj);
    void showitsStudents();
    void AddingStudenttoCourse(student* obj);
    friend void saveDataforAssessment();
};