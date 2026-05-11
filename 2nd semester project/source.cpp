

#include<iostream>
#include<vector>
#include<fstream>
#include<cstring>
#include<string>

using namespace std;

class academicEntity {
protected:
    int ID;
    string email;
public:
    string name;
    virtual void display() = 0;
};

class teacher : public academicEntity {
    vector<float> arrayofScore;
    float avgScore;
    float score;
public:
    teacher(int ID = 0, string name = "", string email = "", float avgScore = 0) {
        this->score = 0;
        this->ID = ID;
        this->name = name;
        this->email = email;
        this->avgScore = avgScore;
    }
    void display() {
        cout << "ID:" << ID << ", Name:" << name << ", Email:" << email << ", Avg Score:" << avgScore << endl;
    }
    void giveFeedback(int i) {
        arrayofScore.push_back(i);
        float sum = 0;
        for (int j = 0; j < (int)arrayofScore.size(); j++) {
            sum += arrayofScore[j];
        }
        avgScore = sum / arrayofScore.size();
    }
    string getname() {
        return name;
    }
    friend void saveDataforTeacher();
    friend void loadDataforTeacher();
};

class student : public academicEntity {
protected:
    float GPA;
    string type;
public:
    virtual void display() = 0;
    virtual void setGPA(float GPA) = 0;
    friend void viewStudents();
    friend void saveDataforStudent();
};

class scholarshipStudent : public student {
protected:
    bool probation;
public:
    scholarshipStudent(int ID = 0, string name = "", string email = "", float GPA = 0, bool extra = false) {
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
    friend void viewStudents();
    void display() {
        cout << "ID:" << ID << ", Name:" << name << ", Email:" << email
            << ", GPA:" << GPA << ", Type:" << type
            << ", Probation:" << (probation ? "Yes" : "No") << endl;
    }
    void setGPA(float GPA) {
        this->GPA = GPA;
        probation = (GPA < 3.3);
    }
    friend void saveDataforStudent();
};

class exchangeStudent : public student {
protected:
    bool fail;
public:
    exchangeStudent(int ID = 0, string name = "", string email = "", float GPA = 0, bool extra = false) {
        this->ID = ID;
        this->name = name;
        this->email = email;
        this->type = "exchange";
        this->GPA = GPA;
        fail = (GPA < 2);

    }
    friend void viewStudents();
    void display() {
        cout << "ID:" << ID << ", Name:" << name << ", Email:" << email
            << ", GPA:" << GPA << ", Type:" << type
            << ", Fail:" << (fail ? "Yes" : "No") << endl;
    }
    void setGPA(float GPA) {
        this->GPA = GPA;
        fail = (GPA < 2);
    }
    friend void saveDataforStudent();
};

class regularStudent : public student {
protected:
    bool feeStatus;
public:
    regularStudent(int ID = 0, string name = "", string email = "", float GPA = 0, bool extra = true) {
        this->ID = ID;
        this->name = name;
        this->email = email;
        this->type = "regular";
        this->GPA = GPA;
        feeStatus = extra;
    }
    void display() {
        cout << "ID:" << ID << ", Name:" << name << ", Email:" << email
            << ", GPA:" << GPA << ", Type:" << type
            << ", Fee Paid:" << (feeStatus ? "Yes" : "No") << endl;
    }
    friend void viewStudents();
    void setGPA(float GPA) {
        this->GPA = GPA;
    }
    void setfeeStatus(bool fee) {
        feeStatus = fee;
    }
    friend void saveDataforStudent();
};

vector<student*> STUDENTS;

class course {
protected:
    int noofStudents = 0;
    vector<student*> itsStudents;
    string type;
    teacher* obj;
    int code;
    string name;
public:
 
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
};

class core : public course {
public:
    core(int code, string name, teacher* obj) {
        this->code = code;
        this->name = name;
        this->obj = obj;
        this->type = "core";
    }
    friend void saveDataforCourse();
    void display() {
        cout << "Code:" << code << ", Name:" << name << ", Type:" << type
            << ", Teacher:" << (obj ? obj->name : "None") << endl;
    }
    void showitsStudents() {
        for (int i = 0; i < (int)itsStudents.size(); i++) {
            cout << "  Student " << i + 1 << ": ";
            itsStudents[i]->display();
        }
    }
    void assignCourse(teacher* obj) {
        this->obj = obj;
    }
    void AddingStudenttoCourse(student* obj) {
        if ((int)itsStudents.size() < 30) {
            noofStudents++;
            itsStudents.push_back(obj);
        }
        else {
            cout << "No more seats in this course." << endl;
        }
    }
};

class elective : public course {
public:
    elective(int code, string name, teacher* obj) {
        this->code = code;
        this->name = name;
        this->obj = obj;
        this->type = "elective";
    }
    friend void saveDataforCourse();
    void display() {
        cout << "Code:" << code << ", Name:" << name << ", Type:" << type
            << ", Teacher:" << (obj ? obj->name : "None") << endl;
    }
    void assignCourse(teacher* obj) {
        this->obj = obj;
    }
    void showitsStudents() {
        for (int i = 0; i < (int)itsStudents.size(); i++) {
            cout << "  Student " << i + 1 << ": ";
            itsStudents[i]->display();
        }
    }
    void AddingStudenttoCourse(student* obj) {
        if ((int)itsStudents.size() < 30) {
            noofStudents++;
            itsStudents.push_back(obj);
        }
        else {
            cout << "No more seats in this course." << endl;
        }
    }
};

class lab : public course {
public:
    lab(int code, string name, teacher* obj) {
        this->code = code;
        this->name = name;
        this->obj = obj;
        this->type = "lab";
    }
    friend void saveDataforCourse();
    void display() {
        cout << "Code:" << code << ", Name:" << name << ", Type:" << type
            << ", Teacher:" << (obj ? obj->name : "None") << endl;
    }
    void assignCourse(teacher* obj) {
        this->obj = obj;
    }
    void showitsStudents() {
        for (int i = 0; i < (int)itsStudents.size(); i++) {
            cout << "  Student " << i + 1 << ": ";
            itsStudents[i]->display();
        }
    }
    void AddingStudenttoCourse(student* obj) {
        if ((int)itsStudents.size() < 30) {
            noofStudents++;
            itsStudents.push_back(obj);
        }
        else {
            cout << "No more seats in this course." << endl;
        }
    }
};

class Assessment {
protected:
    course* ptrC;
    student* ptrS;
public:
};
class finals : public Assessment {};
class dailylabs : public Assessment {
public:
    void setmarks() {}
};
class quizzes : public Assessment {};
class assignments : public Assessment {};

class venue {
protected:
    int roomno;
    int capacity;
    bool computer;
public:
    venue(int roomno = 0, int capacity = 0, bool computer = 0) {
        this->roomno = roomno;
        this->capacity = capacity;
        this->computer = computer;
    }
    void display() {
        cout << "Room No:" << roomno << ", Capacity:" << capacity
            << ", Computer:" << (computer ? "Yes" : "No") << endl;
    }
};

vector<teacher*> TEACHERS;
vector<course*>  COURSES;
vector<venue*>   VENUES;
vector<Assessment*> ASSESS;


void loadData();
void addStudent();
void viewStudents();
void addTeacher();
void viewTeachers();
void addCourse();
void viewCourses();
void registerStudentInCourse();
void createSection();
void assignCourseToTeacher();
void saveData();
void loadDataforTeacher();
void loadDataforStudent();
void loadDataforCourse();
void saveDataforTeacher();
void saveDataforStudent();
void saveDataforCourse();


static string trim(string s) {
    while (!s.empty() && (s.back() == '\r' || s.back() == '\n' || s.back() == ' '))
        s.pop_back();
    return s;
}


void loadData() {
    loadDataforTeacher();
    loadDataforStudent();
    loadDataforCourse();
}

void loadDataforTeacher() {
    TEACHERS.clear();
    ifstream file("Teachers.txt");
    if (!file.is_open()) return;

    string tempID, name, email, tempscore;
    while (getline(file, tempID, ',')) {
        tempID = trim(tempID);
        if (tempID.empty()) continue;

        getline(file, name, ',');
        getline(file, email, ',');
        getline(file, tempscore);
        tempscore = trim(tempscore);
        if (!tempscore.empty() && tempscore.back() == ',')
            tempscore.pop_back();

        int   id = stoi(tempID);
        float avgScore = tempscore.empty() ? 0.0f : stof(tempscore);
        TEACHERS.push_back(new teacher(id, name, email, avgScore));
    }
}

void loadDataforStudent() {
    STUDENTS.clear();
    ifstream file("Students.txt");
    if (!file.is_open()) return;

    string tempID, name, email, tempscore, type, extratemp;
    while (getline(file, tempID, ',')) {
        tempID = trim(tempID);
        if (tempID.empty()) continue;

        getline(file, name, ',');
        getline(file, email, ',');
        getline(file, tempscore, ',');
        getline(file, type, ',');
        getline(file, extratemp);
        extratemp = trim(extratemp);
        if (!extratemp.empty() && extratemp.back() == ',')
            extratemp.pop_back();

        int   id = stoi(tempID);
        float GPA = stof(tempscore);
        bool  extra = (extratemp == "1" || extratemp == "true");

        if (type == "scholarship")
            STUDENTS.push_back(new scholarshipStudent(id, name, email, GPA, extra));
        else if (type == "exchange")
            STUDENTS.push_back(new exchangeStudent(id, name, email, GPA, extra));
        else if (type == "regular")
            STUDENTS.push_back(new regularStudent(id, name, email, GPA, extra));
    }
}

void loadDataforCourse() {
    COURSES.clear();
    ifstream file("Courses.txt");
    if (!file.is_open()) return;

    string tempID, name, type, teachername, tempno;
    while (getline(file, tempID, ',')) {
        tempID = trim(tempID);
        if (tempID.empty()) continue;

        getline(file, name, ',');
        getline(file, type, ',');
        getline(file, teachername, ',');
        getline(file, tempno, ',');
        tempno = trim(tempno);

        int id = stoi(tempID);
        int no = stoi(tempno);

        teacher* t_obj = nullptr;
        for (int i = 0; i < (int)TEACHERS.size(); i++) {
            if (TEACHERS[i]->name == teachername) {
                t_obj = TEACHERS[i];
                break;
            }
        }

        vector<student*> enrolled;
        for (int i = 0; i < no; i++) {
            string studentname;
            if (i < no - 1)
                getline(file, studentname, ',');
            else {
                getline(file, studentname);
                studentname = trim(studentname);
                if (!studentname.empty() && studentname.back() == ',')
                    studentname.pop_back();
            }
            for (int j = 0; j < (int)STUDENTS.size(); j++) {
                if (STUDENTS[j]->name == studentname) {
                    enrolled.push_back(STUDENTS[j]);
                    break;
                }
            }
        }
        if (no == 0) {
            string dummy; getline(file, dummy);
        }

        course* c = nullptr;
        if (type == "core")    c = new core(id, name, t_obj);
        else if (type == "lab")     c = new lab(id, name, t_obj);
        else if (type == "elective")c = new elective(id, name, t_obj);

        if (c) {
            COURSES.push_back(c);
            for (int k = 0; k < (int)enrolled.size(); k++)
                c->AddingStudenttoCourse(enrolled[k]);
        }
    }
}


void saveData() {
    saveDataforTeacher();
    saveDataforStudent();
    saveDataforCourse();
}

void saveDataforTeacher() {
    ofstream file("Teachers.txt", ios::out | ios::trunc);
    for (int i = 0; i < (int)TEACHERS.size(); i++) {
        teacher* t = TEACHERS[i];
        file << t->ID << "," << t->name << "," << t->email << "," << t->avgScore << "\n";
    }
}

void saveDataforStudent() {
    ofstream file("Students.txt", ios::out | ios::trunc);
    for (int i = 0; i < (int)STUDENTS.size(); i++) {
        if (STUDENTS[i]->type == "scholarship") {
            scholarshipStudent* ptr = (scholarshipStudent*)STUDENTS[i];
            file << ptr->ID << "," << ptr->name << "," << ptr->email << ","
                << ptr->GPA << "," << ptr->type << "," << ptr->probation << "\n";
        }
        else if (STUDENTS[i]->type == "regular") {
            regularStudent* ptr = (regularStudent*)STUDENTS[i];
            file << ptr->ID << "," << ptr->name << "," << ptr->email << ","
                << ptr->GPA << "," << ptr->type << "," << ptr->feeStatus << "\n";
        }
        else if (STUDENTS[i]->type == "exchange") {
            exchangeStudent* ptr = (exchangeStudent*)STUDENTS[i];
            file << ptr->ID << "," << ptr->name << "," << ptr->email << ","
                << ptr->GPA << "," << ptr->type << "," << ptr->fail << "\n";
        }
    }
}

void saveDataforCourse() {
    ofstream file("Courses.txt", ios::out | ios::trunc);
    for (int i = 0; i < (int)COURSES.size(); i++) {
        file << COURSES[i]->code << "," << COURSES[i]->name << ","
            << COURSES[i]->type << ","
            << (COURSES[i]->obj ? COURSES[i]->obj->name : "None") << ","
            << COURSES[i]->noofStudents;
        for (int j = 0; j < (int)COURSES[i]->itsStudents.size(); j++)
            file << "," << COURSES[i]->itsStudents[j]->name;
        file << "\n";
    }
}


void addStudent() {
    int    ID, type;
    string name, email;
    float  GPA;

    cout << "Enter ID: ";    cin >> ID;
    cout << "Enter Name: ";  cin >> name;
    cout << "Enter Email: "; cin >> email;
    cout << "Enter GPA: ";   cin >> GPA;

    cout << "\nEnter Type:\n";
    cout << "1. Regular Student\n";
    cout << "2. Scholarship Student\n";
    cout << "3. Exchange Student\n";
    cout << "Choice: ";
    cin >> type;
    while (type < 1 || type > 3) {
        cout << "Invalid input, try again: ";
        cin >> type;
    }

    if (type == 1) { STUDENTS.push_back(new regularStudent(ID, name, email, GPA));    cout << "\nRegular Student Added!\n"; }
    else if (type == 2) { STUDENTS.push_back(new scholarshipStudent(ID, name, email, GPA)); cout << "\nScholarship Student Added!\n"; }
    else { STUDENTS.push_back(new exchangeStudent(ID, name, email, GPA));   cout << "\nExchange Student Added!\n"; }
}

void viewStudents() {
    if (STUDENTS.empty()) { cout << "No students found.\n"; }
    else for (int i = 0; i < (int)STUDENTS.size(); i++) STUDENTS[i]->display();
    system("pause");
}

void addTeacher() {
    int    ID;
    string name, email;
    cout << "Enter ID: ";    cin >> ID;
    cout << "Enter Name: ";  cin >> name;
    cout << "Enter Email: "; cin >> email;
    TEACHERS.push_back(new teacher(ID, name, email));
    cout << "\nTeacher Added!\n";
}

void viewTeachers() {
    if (TEACHERS.empty()) { cout << "No teachers found.\n"; }
    else for (int i = 0; i < (int)TEACHERS.size(); i++) TEACHERS[i]->display();
    system("pause");
}

void addCourse() {
    int    code, type;
    string name;
    cout << "Enter Course Code: "; cin >> code;
    cout << "Enter Course Name: "; cin >> name;

    cout << "\nEnter Course Type:\n";
    cout << "1. Core\n2. Elective\n3. Lab\nChoice: ";
    cin >> type;
    while (type < 1 || type > 3) { cout << "Invalid, try again: "; cin >> type; }

    cout << "\nAvailable Teachers:\n";
    for (int i = 0; i < (int)TEACHERS.size(); i++) TEACHERS[i]->display();

    teacher* obj = nullptr;
    string t_name;
    while (!obj) {
        cout << "Enter teacher name: ";
        cin >> t_name;
        for (int i = 0; i < (int)TEACHERS.size(); i++) {
            if (TEACHERS[i]->getname() == t_name) { obj = TEACHERS[i]; break; }
        }
        if (!obj) cout << "Teacher not found, try again.\n";
    }

    if (type == 1) COURSES.push_back(new core(code, name, obj));
    else if (type == 2) COURSES.push_back(new elective(code, name, obj));
    else                COURSES.push_back(new lab(code, name, obj));
    cout << "\nCourse Added!\n";
}

void viewCourses() {
    if (COURSES.empty()) { cout << "No courses found.\n"; system("pause"); return; }
    for (int i = 0; i < (int)COURSES.size(); i++) COURSES[i]->display();

    int cl;
    cout << "\nShow enrolled students? (1=Yes, 0=No): ";
    cin >> cl;
    while (cl != 0 && cl != 1) { cout << "Invalid, try again: "; cin >> cl; }
    if (cl == 1)
        for (int i = 0; i < (int)COURSES.size(); i++) {
            COURSES[i]->display();
            COURSES[i]->showitsStudents();
        }
    system("pause");
}

void registerStudentInCourse() {
    if (STUDENTS.empty()) { cout << "No students available.\n"; return; }
    if (COURSES.empty()) { cout << "No courses available.\n";  return; }

    cout << "--- Students ---\n";
    for (int i = 0; i < (int)STUDENTS.size(); i++) STUDENTS[i]->display();

    string t_name;
    student* t_obj = nullptr;
    cout << "Enter student name to register: ";
    cin >> t_name;
    for (int i = 0; i < (int)STUDENTS.size(); i++) {
        if (STUDENTS[i]->name == t_name) { t_obj = STUDENTS[i]; break; }
    }
    if (!t_obj) { cout << "Student not found!\n"; return; }

    cout << "--- Courses ---\n";
    for (int i = 0; i < (int)COURSES.size(); i++) COURSES[i]->display();

    int C_code;
    cout << "Enter course code: ";
    cin >> C_code;
    bool found = false;
    for (int i = 0; i < (int)COURSES.size(); i++) {
        if (COURSES[i]->code == C_code) {
            COURSES[i]->AddingStudenttoCourse(t_obj);
            found = true;
            break;
        }
    }
    if (!found) cout << "Course not found!\n";
    else        cout << "Student registered successfully!\n";
}

void createSection() {
    cout << "Section creation not yet implemented.\n";
    system("pause");
}

void assignCourseToTeacher() {
    if (TEACHERS.empty()) { cout << "No teachers available.\n"; return; }
    if (COURSES.empty()) { cout << "No courses available.\n";  return; }

    cout << "--- Teachers ---\n";
    for (int i = 0; i < (int)TEACHERS.size(); i++) TEACHERS[i]->display();

    string t_name;
    teacher* t_obj = nullptr;
    cout << "Enter teacher name: ";
    cin >> t_name;
    for (int i = 0; i < (int)TEACHERS.size(); i++) {
        if (TEACHERS[i]->name == t_name) { t_obj = TEACHERS[i]; break; }
    }
    if (!t_obj) { cout << "Teacher not found!\n"; return; }

    cout << "--- Courses ---\n";
    for (int i = 0; i < (int)COURSES.size(); i++) COURSES[i]->display();

    int C_code;
    cout << "Enter course code to assign: ";
    cin >> C_code;
    bool found = false;
    for (int i = 0; i < (int)COURSES.size(); i++) {
        if (COURSES[i]->code == C_code) {
            COURSES[i]->obj = t_obj;
            found = true;
            break;
        }
    }
    if (!found) cout << "Course not found!\n";
    else        cout << "Teacher assigned successfully!\n";
}


int main() {
    loadData();
    int c;
    while (1) {
        system("cls");
        cout << "\n=====================================\n";
        cout << "   FAST Academic Office System\n";
        cout << "=====================================\n";
        cout << "1.  Add Student\n";
        cout << "2.  View Students\n";
        cout << "3.  Add Teacher\n";
        cout << "4.  View Teachers\n";
        cout << "5.  Add Course\n";
        cout << "6.  View Courses\n";
        cout << "7.  Register Student in Course\n";
        cout << "8.  Create Section\n";
        cout << "9.  Assign Course to Teacher\n";
        cout << "10. Exit\n";
        cout << "Enter Choice: ";
        cin >> c;

        switch (c) {
        case 1:  addStudent();             break;
        case 2:  viewStudents();           break;
        case 3:  addTeacher();             break;
        case 4:  viewTeachers();           break;
        case 5:  addCourse();              break;
        case 6:  viewCourses();            break;
        case 7:  registerStudentInCourse(); break;
        case 8:  createSection();          break;
        case 9:  assignCourseToTeacher();  break;
        case 10:
            saveData();
            cout << "\nData saved. Program closed.\n";
            return 0;
        default:
            cout << "\nInvalid Choice!\n";
            system("pause");
        }
    }
    return 0;
}