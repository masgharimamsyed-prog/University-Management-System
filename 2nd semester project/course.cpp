#include "course.h"
#include<string>
//core 
    core::core(int code, string name, teacher* obj) {
        this->code = code;
        this->name = name;
        this->obj = obj;
        this->type = "core";
    }
 
    void core::display() {
        cout << "Code:" << code << ", Name:" << name << ", Type:" << type
            << ", Teacher:" << (obj ? obj->name : "None") << endl;
    }
    void core::showitsStudents() {
        for (int i = 0; i < (int)itsStudents.size(); i++) {
            cout << "  Student " << i + 1 << ": ";
            itsStudents[i]->display();
        }
    }
    void core::assignCourse(teacher* obj) {
        this->obj = obj;
    }
    void core::AddingStudenttoCourse(student* obj) {
        if ((int)itsStudents.size() < 30) {
            noofStudents++;
            itsStudents.push_back(obj);
        }
        else {
            cout << "No more seats in this course." << endl;
        }
    }
    

    //elective
        elective::elective(int code, string name, teacher* obj) {
            this->code = code;
            this->name = name;
            this->obj = obj;
            this->type = "elective";
        }
   
        void elective::display() {
            cout << "Code:" << code << ", Name:" << name << ", Type:" << type
                << ", Teacher:" << (obj ? obj->name : "None") << endl;
        }
        void elective::assignCourse(teacher* obj) {
            this->obj = obj;
        }
        void elective::showitsStudents() {
            for (int i = 0; i < (int)itsStudents.size(); i++) {
                cout << "  Student " << i + 1 << ": ";
                itsStudents[i]->display();
            }
        }
        void elective::AddingStudenttoCourse(student* obj) {
            if ((int)itsStudents.size() < 30) {
                noofStudents++;
                itsStudents.push_back(obj);
            }
            else {
                cout << "No more seats in this course." << endl;
            }
        }
   

        //labs
       
            lab::lab(int code, string name, teacher* obj) {
                this->code = code;
                this->name = name;
                this->obj = obj;
                this->type = "lab";
            }
        
            void  lab::display() {
                cout << "Code:" << code << ", Name:" << name << ", Type:" << type
                    << ", Teacher:" << (obj ? obj->name : "None") << endl;
            }
            void lab::assignCourse(teacher* obj) {
                this->obj = obj;
            }
            void lab::showitsStudents() {
                for (int i = 0; i < (int)itsStudents.size(); i++) {
                    cout << "  Student " << i + 1 << ": ";
                    itsStudents[i]->display();
                }
            }
            void lab::AddingStudenttoCourse(student* obj) {
                if ((int)itsStudents.size() < 30) {
                    noofStudents++;
                    itsStudents.push_back(obj);
                }
                else {
                    cout << "No more seats in this course." << endl;
                }
            }
         