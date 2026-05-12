#include "student.h"
#include<string>
using namespace std;

 scholarshipStudent::scholarshipStudent(int ID , string name , string email, float GPA, bool extra) {
    this->ID = ID;
    this->name = name;
    this->email = email;
    this->GPA = GPA;
    this->type = "scholarship";
    if (GPA < 3.3 && GPA != 0) {
        probation = true;
    }
    else {
        probation = false;
    }
 }

void scholarshipStudent::display() {
    cout << "ID:" << ID << ", Name:" << name << ", Email:" << email
        << ", GPA:" << GPA << ", Type:" << type
        << ", Probation:" << (probation ? "Yes" : "No") << endl;
}
void scholarshipStudent::setGPA(float GPA) {
    this->GPA = GPA;
    probation = (GPA < 3.3);
}


    exchangeStudent::exchangeStudent(int ID , string name , string email , float GPA , bool extra ) {
        this->ID = ID;
        this->name = name;
        this->email = email;
        this->type = "exchange";
        this->GPA = GPA;
        fail = (GPA < 2);

    }
    void exchangeStudent::display() {
        cout << "ID:" << ID << ", Name:" << name << ", Email:" << email
            << ", GPA:" << GPA << ", Type:" << type
            << ", Fail:" << (fail ? "Yes" : "No") << endl;
    }
    void exchangeStudent::setGPA(float GPA) {
        this->GPA = GPA;
        fail = (GPA < 2);
    }
   

 
    regularStudent::regularStudent(int ID , string name, string email , float GPA , bool extra) {
            this->ID = ID;
            this->name = name;
            this->email = email;
            this->type = "regular";
            this->GPA = GPA;
            feeStatus = extra;
        }
        void  regularStudent::display() {
            cout << "ID:" << ID << ", Name:" << name << ", Email:" << email
                << ", GPA:" << GPA << ", Type:" << type
                << ", Fee Paid:" << (feeStatus ? "Yes" : "No") << endl;
        }
        void  regularStudent::setGPA(float GPA) {
            this->GPA = GPA;
        }
        void   regularStudent::setfeeStatus(bool fee) {
            feeStatus = fee;
        }
      