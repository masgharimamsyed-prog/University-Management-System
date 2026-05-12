#include<iostream>
#include<vector>
#include<fstream>
#include<cstring>
#include<string>
class Assessment;
class student;
class teacher;
class course;
class venue;
class section;

using namespace std;
class academicEntity {
protected:
    int ID=0;
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
    void giveFeedback(float i) {
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
    friend class section;
   friend void addSections();
   friend void loadDataforSection();
   friend void saveDataforSection();
   friend void addTeacher();
  friend void removeTeacher();
};
class student : public academicEntity {
protected:
    float GPA=0.0;
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
    teacher* obj = nullptr;
public:
    int code=0;
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
    friend void saveDataforAssessment();
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
    friend void saveDataforAssessment();
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
    friend void saveDataforAssessment();
};
class Assessment {
protected:
    course* Cobj = nullptr;
    string type;
    float totalMarks=0;
    float obtainMarks=0;
public:
    virtual void display() = 0;
    friend void addAssessment();
    friend void saveDataforAssessment();
    friend void showAssessmentofStudent();
};
class finals : public Assessment {
public:
    finals(course* Cobj, float totalMarks, float obtainMarks) {
        this->Cobj = Cobj;
        this->totalMarks = totalMarks;
        this->obtainMarks = obtainMarks;
        this->type = "finals";
    }

    void display() {
        cout << "coursename:" << Cobj->name
            << ",type:" << type
            << ",total:" << totalMarks
            << ",obtain:" << obtainMarks << endl;
    }
};
class quizzes : public Assessment {
public:
    quizzes(course* Cobj, float totalMarks, float obtainMarks) {
        this->Cobj = Cobj;
        this->totalMarks = totalMarks;
        this->obtainMarks = obtainMarks;
        this->type = "quiz";
    }

    void display() {
        cout << "course name:" << Cobj->name
            << ",type:" << type
            << ",total:" << totalMarks
            << ",obtain:" << obtainMarks << endl;
    }
};
class assignments : public Assessment {
public:
    assignments(course* Cobj, float totalMarks, float obtainMarks) {
        this->Cobj = Cobj;
        this->totalMarks = totalMarks;
        this->obtainMarks = obtainMarks;
        this->type = "assignment";
    }

    void display() {
        cout << "course name:" << Cobj->name
            << ",type:" << type
            << ",total:" << totalMarks
            << ",obtain:" << obtainMarks << endl;
    }
};
class venue {
protected:
    int id;
    int capacity;
    bool hascomp;
public:
    venue(int roomno = 0, int capacity = 0, bool computer = 0) {
        this->id = roomno;
        this->capacity = capacity;
        this->hascomp = computer;
    }
    void display() {
        cout << "Room No:" << id << ", Capacity:" << capacity
            << ", Computer:" << (hascomp ? "Yes" : "No") << endl;
    }
   friend void saveDataforVenue();
   friend class section;
   friend void addSections();
   friend void loadDataforSection();
   friend void saveDataforSection();
   friend void addVenue();
   friend void removeVenue();
};

class section {
    int id;
    course* Cobj;
    teacher* Tobj;
    venue* Vobj;
public:
    section(int id,course* Cobj,teacher *Tobj,venue* Vobj) {
        this->id = id;
        this->Cobj = Cobj;
        this->Tobj = Tobj;
        this->Vobj = Vobj;
    }
    void display() {
        cout << "Section ID: " << id
            << "\nCourse: " << (Cobj != nullptr ? Cobj->name : "No Course")
            << "\nTeacher: " << (Tobj != nullptr ? Tobj->name : "No Teacher")
            << "\nVenue: " << (Vobj != nullptr ? to_string(Vobj->id) : "No Venue")
            << endl;
    }
    friend void saveDataforSection();
    friend void addSections();
    friend void removeSection();
};
vector<teacher*> TEACHERS;
vector<course*>  COURSES;
vector<venue*>   VENUES;
vector<Assessment*> ASSESS;
vector<section*> SECTIONS;

void loadData();
void removeStudent();
void removeTeacher();
void removeCourse();
void removeVenue();
void removeSection();
void addStudent();
void viewStudents();
void addTeacher();
void viewTeachers();
void addCourse();
void viewCourses();
void registerStudentInCourse();
void assignCourseToTeacher();
void addVenue();
void showAllVenues();
void saveData();
void showAllSections();
void addSections();
void addAssessment();
void showAssessmentofStudent();

void loadDataforTeacher();
void loadDataforStudent();
void loadDataforCourse();
void loadDataforVenue();
void loadDataforSection();
void loadDataforAssessment();

void saveDataforTeacher();
void saveDataforStudent();
void saveDataforCourse();
void saveDataforVenue();
void saveDataforSection();
void saveDataforAssessment();

static string trim(string s) {
    while (!s.empty() && (s.back() == '\r' || s.back() == '\n' || s.back() == ' '))
        s.pop_back();
    return s;
}

void loadData() {
    loadDataforTeacher();
    loadDataforStudent();
    loadDataforCourse();
    loadDataforVenue();
    loadDataforSection();
    loadDataforAssessment();
}
void loadDataforTeacher() {
    TEACHERS.clear();
    ifstream file("Teachers.txt");
    if (!file.is_open()) return;
     
    string tempID, name, email, tempscore;
    while (getline(file, tempID, ',')) {
        tempID = trim(tempID);//
        if (tempID.empty()) continue;

        getline(file, name, ',');
        getline(file, email, ',');
        getline(file, tempscore);
        tempscore = trim(tempscore);//
        if (!tempscore.empty() && tempscore.back() == ',')//
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
        tempID = trim(tempID);//
        if (tempID.empty()) continue;
      
        getline(file, name, ',');
        getline(file, email, ',');
        getline(file, tempscore, ',');
        getline(file, type, ',');
        getline(file, extratemp);
        extratemp = trim(extratemp);//
        if (!extratemp.empty() && extratemp.back() == ',')
            extratemp.pop_back();// 

        int   id = stoi(tempID);
       
        float GPA = stof(tempscore);
        bool  extra = (extratemp == "1" || extratemp == "true");

        if (type == "scholarship") {
            STUDENTS.push_back(new scholarshipStudent(id, name, email, GPA, extra));
        }
        else if (type == "exchange") {
           
            STUDENTS.push_back(new exchangeStudent(id, name, email, GPA, extra));
        }
        else if (type == "regular") {
         
            STUDENTS.push_back(new regularStudent(id, name, email, GPA, extra));
        }

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
                    studentname.pop_back();//
            }
            for (int j = 0; j < (int)STUDENTS.size(); j++) {
                if (STUDENTS[j]->name == studentname) {
                    enrolled.push_back(STUDENTS[j]);
                    break;
                }
            }
        }
        if (no == 0) {//
            string dummy;
            getline(file, dummy);
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
void loadDataforVenue() {
    VENUES.clear();
    int id, capacity;
    bool hascomp;
    ifstream file("Venues.txt");
    if (!file.is_open()) return;
    string tempid, tempcapacity, temphascomp;
    while (getline(file,tempid,',') ){
        //id
        tempid = trim(tempid);
        if (tempid.empty()) continue;
        id = stoi(tempid);
        //cacpity
        getline(file, tempcapacity, ',');
        tempcapacity = trim(tempcapacity);
        if (tempid.empty()) continue;
        capacity = stoi(tempcapacity);
        //hascomp
        getline(file, temphascomp, ',');
        temphascomp = trim(temphascomp);
        if (temphascomp == "true" || temphascomp == "1") {
            hascomp = true;
        }
        else {
            hascomp = false;
        }
        
        //laodig 
        VENUES.push_back(new venue(id, capacity, hascomp));


    }
   
    
}
void loadDataforSection() {
    SECTIONS.clear();
    ifstream file("Sections.txt");
    if (!file.is_open()) return;
    int id;
    int cid;
    int tid;
    int vid;
    string sectionid,courseid, teacherid, venueid;
    course* Cobj = NULL;
    teacher* Tobj=NULL;
    venue* Vobj = NULL;

    while (getline(file,sectionid,',')) {
        sectionid = trim(sectionid);

        if (sectionid.empty()) continue;
        id = stoi(sectionid);
        //course
        getline(file, courseid, ',');
        courseid = trim(courseid);
        if (courseid.empty()) continue;
        cid = stoi(courseid);
        for (int i = 0; i < COURSES.size(); i++) {
            if (COURSES[i]->code==cid) {
                Cobj = COURSES[i];
            }
        }
        //teacher
        getline(file, teacherid, ',');
        teacherid = trim(teacherid);
        if (teacherid.empty()) continue;
        tid = stoi(teacherid);
        for (int i = 0; i < TEACHERS.size(); i++) {
            if (TEACHERS[i]->ID == tid) {
                Tobj = TEACHERS[i];
            }
        }
        //venue
        getline(file, venueid, ',');
        venueid = trim(venueid);
        if (venueid.empty()) continue;
        vid = stoi(venueid);
        for (int i = 0; i < VENUES.size(); i++) {
            if (VENUES[i]->id == vid) {
                Vobj = VENUES[i];
            }
        }

        SECTIONS.push_back(new section(id, Cobj, Tobj, Vobj));


    }
   
 
}
void loadDataforAssessment() {

    ASSESS.clear();

    ifstream file("Assessments.txt");

    if (!file.is_open()) return;

    string studentid;
    string courseid;
    string type;
    string total;
    string obtain;

    while (getline(file, studentid, ',')) {

        getline(file, courseid, ',');
        getline(file, type, ',');
        getline(file, total, ',');
        getline(file, obtain);

        int sid = stoi(studentid);
        int cid = stoi(courseid);

        float t = stof(total);
        float o = stof(obtain);

        student* Sobj = nullptr;
        course* Cobj = nullptr;

        for (int i = 0; i < STUDENTS.size(); i++) {

            if (STUDENTS[i]->ID == sid) {
                Sobj = STUDENTS[i];
                break;
            }
        }

        for (int i = 0; i < COURSES.size(); i++) {

            if (COURSES[i]->code == cid) {
                Cobj = COURSES[i];
                break;
            }
        }

        if (Sobj == nullptr || Cobj == nullptr) {
            continue;
        }

        Assessment* A = nullptr;

        if (type == "finals") {
            A = new finals(Cobj, t, o);
        }
        else if (type == "quiz") {
            A = new quizzes(Cobj, t, o); 
        }
        else if (type == "assignment") {
            A = new assignments(Cobj, t, o);
        }

        if (A != nullptr) {

            Sobj->assess.push_back(A);
            ASSESS.push_back(A);
        }
    }
  
}

void saveData() {
    saveDataforTeacher();
    saveDataforStudent();
    saveDataforCourse();
    saveDataforVenue();
    saveDataforSection();
    saveDataforAssessment();
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
void saveDataforVenue() {
    ofstream file("Venues.txt", ios::out | ios::trunc);
    for (int i = 0; i < (int)VENUES.size(); i++) {
        file << VENUES[i]->id << "," <<VENUES[i]->capacity<< "," << VENUES[i]->hascomp << "," << endl;
    }
}
void saveDataforSection() {
    ofstream file("Sections.txt", ios::trunc);
    for (int i = 0; i < SECTIONS.size(); i++) {
        file << SECTIONS[i]->id << ","<< (*(SECTIONS[i]->Cobj)).code<<"," << (*(SECTIONS[i]->Tobj)).ID << "," << (*(SECTIONS[i]->Vobj)).id << "," << endl;
    }
}
void saveDataforAssessment() {

    ofstream file("Assessments.txt", ios::out | ios::trunc);

    for (int i = 0; i < STUDENTS.size(); i++) {

        for (int j = 0; j < STUDENTS[i]->assess.size(); j++) {

            Assessment* A = STUDENTS[i]->assess[j];

            file << STUDENTS[i]->ID << ","
                << A->Cobj->code << ","
                << A->type << ","
                << A->totalMarks << ","
                << A->obtainMarks << "\n";
        }
    }
}

void addStudent() {
    int    ID, type;
    string name, email;
    float  GPA;

   
    bool unique = true;
    while (unique) {
        unique = false;
        cout << "Enter ID: ";    cin >> ID;
        for (int i = 0; i < STUDENTS.size(); i++) {
            if (STUDENTS[i]->ID == ID) {
                unique = true;
            }
        }
        if (unique) {
            cout << "the id you enter already exist,input again:" << endl;
        }
    }
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
void removeStudent() {
    int id;
    cout << "Enter the id of student you want to remove" << endl;
    cin >> id;
    for (int i = 0; i < STUDENTS.size(); i++) {
        if (STUDENTS[i]->ID == id) {
            STUDENTS.erase(STUDENTS.begin()+i);
        }

    }
    system("pause");
}
void removeTeacher() {
    int id;
    cout << "Enter the id of teacher you want to remove" << endl;
    cin >> id;
    for (int i = 0; i < TEACHERS.size(); i++) {
        if (TEACHERS[i]->ID == id) {
            TEACHERS.erase(TEACHERS.begin() + i);
        }

    }
    system("pause");
}
void removeVenue() {
    int id;
    cout << "Enter the id of venue you want to remove" << endl;
    cin >> id;
    for (int i = 0; i < VENUES.size(); i++) {
        if (VENUES[i]->id == id) {
            VENUES.erase(VENUES.begin() + i);
        }

    }
    system("pause");
}
void removeCourse() {
    int id;
    cout << "Enter the id of course you want to remove" << endl;
    cin >> id;
    for (int i = 0; i < COURSES.size(); i++) {
        if (COURSES[i]->code == id) {
            COURSES.erase(COURSES.begin() + i);
        }

    }
    system("pause");
}
void removeSection() {
    int id;
    cout << "Enter the id of section you want to remove" << endl;
    cin >> id;
    for (int i = 0; i < SECTIONS.size(); i++) {
        if (SECTIONS[i]->id == id) {
            STUDENTS.erase(STUDENTS.begin() + i);
        }

    }
    system("pause");
}
void viewStudents(){
    if (STUDENTS.size() == 0) {
        cout << "no student" << endl;
    }
    for (int i = 0; i < (int)STUDENTS.size(); i++)
        STUDENTS[i]->display();
    system("pause");
}
void addTeacher() {
    int    ID;
    string name, email;
  
    bool unique = true;
    while (unique) {
        unique = false;
        cout << "Enter ID: ";    cin >> ID;
        for (int i = 0; i < TEACHERS.size(); i++) {
            if (TEACHERS[i]->ID == ID) {
                unique = true;
            }
        }
        if (unique) {
            cout << "the id you enter already exist,input again:" << endl;
        }
    }
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
    int  code;
        int type;
    string name;
    
    bool unique = true;
    while (unique) {
        unique = false;
        cout << "Enter Course Code: "; cin >> code;
        for (int i = 0; i < COURSES.size(); i++) {
            if (COURSES[i]->code == code) {
                unique = true;
            }
        }
        if (unique) {
            cout << "the id you enter already exist,input again:" << endl;
        }
    }
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

    cout << "Students:\n";
    for (int i = 0; i < (int)STUDENTS.size(); i++) STUDENTS[i]->display();

    string t_name;
    student* t_obj = nullptr;
    cout << "Enter student name to register: ";
    cin >> t_name;
    for (int i = 0; i < (int)STUDENTS.size(); i++) {
        if (STUDENTS[i]->name == t_name) { t_obj = STUDENTS[i]; break; }
    }
    if (!t_obj) { cout << "Student not found!\n"; return; }

    cout << "Courses:\n";
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
void assignCourseToTeacher() {
    if (TEACHERS.empty()) { cout << "No teachers available.\n"; return; }
    if (COURSES.empty()) { cout << "No courses available.\n";  return; }

    cout << "Teachers:\n";
    for (int i = 0; i < (int)TEACHERS.size(); i++) TEACHERS[i]->display();

    string t_name;
    teacher* t_obj = nullptr;
    cout << "Enter teacher name: ";
    cin >> t_name;
    for (int i = 0; i < (int)TEACHERS.size(); i++) {
        if (TEACHERS[i]->name == t_name) { t_obj = TEACHERS[i]; break; }
    }
    if (!t_obj) { cout << "Teacher not found!\n"; return; }

    cout << "Courses:\n";
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
void addVenue() {
    int id;
   
    bool unique = true;
    while (unique) {
        unique = false;
        cout << "Enter the ID of venue:" << endl;
        cin >> id;
        for (int i = 0; i < VENUES.size(); i++) {
            if (VENUES[i]->id == id) {
                unique = true;
            }
        }
        if (unique) {
            cout << "the id you enter already exist,input again:" << endl;
        }
    }
    int capacity;
    cout << "Enter the capacity of venue:" << endl;
    cin >> capacity;
    bool hascomp=true;
    int choice;
    cout << "Enter computer capacity or not?(1 for has computers,0 for no computers):" << endl;
    cin >> choice;
    if (choice == 1) {
        hascomp = true;
    }
    else if (choice == 0) {
        hascomp = false;
    }
    VENUES.push_back(new venue(id, capacity, hascomp));


}
void showAllVenues() {
    cout << "Venues:" << endl;
    for (int i = 0; i < VENUES.size(); i++) {
        VENUES[i]->display();
    }
    system("pause");
}
void showAllSections() {
    for (int i = 0; i < SECTIONS.size(); i++) {
        SECTIONS[i]->display();
    }
    system("pause");
}
void addSections() {
    int id;
    course* Cobj=nullptr;
    teacher* Tobj=nullptr;
    venue* Vobj=nullptr;
    int tid;
    int cid;
    int vid;
    bool unique = true;
    while (unique) {
        unique = false;
        cout << "Enter the ID of section:" << endl;
        cin >> id;
        for (int i = 0; i < SECTIONS.size(); i++) {
            if (SECTIONS[i]->id == id) {
                unique = true;
            }
        }
        if (unique) {
            cout << "the id you enter already exist,input again:" << endl;
        }
    }
  
  
    bool found =true;
    //teacher
    while (found) {
        cout << "Enter the id of teacher new section:" << endl;
        cin >> tid;
        for (int i = 0; i < TEACHERS.size(); i++) {
            if (TEACHERS[i]->ID == tid) {
                Tobj = TEACHERS[i];
                found = false;
                break;
            }
        }
        if (found) {
            cout << "No id exist for that,enter again" << endl;
        }
    }
    found = true;
    //course
    while (found) {
        cout << "Enter the id of course new section:" << endl;
        cin >> cid;
        for (int i = 0; i <COURSES.size(); i++) {
            if (COURSES[i]->code == cid) {
                Cobj = COURSES[i];
                found = false;
                break;
            }
        }
        if (found) {
            cout << "No id exist for that,enter again" << endl;
        }
    }
    //venue
    found = true;
    while (found) {
        cout << "Enter the id of venue of new section:" << endl;
        cin >> vid;
        for (int i = 0; i <VENUES.size(); i++) {
            if (VENUES[i]->id == vid) {
                Vobj = VENUES[i];
                found = false;
                break;
            }
        }
        if (found) {
            cout << "No id exist for that,enter again" << endl;
        }
    }

    SECTIONS.push_back(new section(id, Cobj, Tobj, Vobj));

}
void addAssessment() {

    int sid;
    int cid;
    int choice;

    float total;
    float obtain;

    student* Sobj = nullptr;
    course* Cobj = nullptr;

    cout << "Enter Student ID: ";
    cin >> sid;

    for (int i = 0; i < STUDENTS.size(); i++) {

        if (STUDENTS[i]->ID == sid) {

            Sobj = STUDENTS[i];
            break;
        }
    }

    if (Sobj == nullptr) {

        cout << "Student not found\n";
        return;
    }

    cout << "Enter Course Code: ";
    cin >> cid;

    for (int i = 0; i < COURSES.size(); i++) {

        if (COURSES[i]->code == cid) {

            Cobj = COURSES[i];
            break;
        }
    }

    if (Cobj == nullptr) {

        cout << "Course not found\n";
        return;
    }

    cout << "1. Finals\n";
    cout << "2. Quiz\n";
    cout << "3. Assignment\n";
    cout << "Enter choice: ";
    cin >> choice;

    cout << "Enter total marks: ";
    cin >> total;

    cout << "Enter obtained marks: ";
    cin >> obtain;

    Assessment* A = nullptr;

    if (choice == 1) {

        A = new finals(Cobj, total, obtain);
    }
    else if (choice == 2) {

        A = new quizzes(Cobj, total, obtain);
    }
    else if (choice == 3) {

        A = new assignments(Cobj, total, obtain);
    }

    if (A != nullptr) {

        Sobj->assess.push_back(A);

        ASSESS.push_back(A);

        cout << "Assessment added successfully\n";
    }
}
void showAssessmentofStudent() {

    int sid;

    cout << "Enter Student ID: ";
    cin >> sid;

    student* Sobj = nullptr;

    for (int i = 0; i < STUDENTS.size(); i++) {

        if (STUDENTS[i]->ID == sid) {

            Sobj = STUDENTS[i];
            break;
        }
    }

    if (Sobj == nullptr) {

        cout << "Student not found\n";
        return;
    }

    cout << "\nAssessments of " << Sobj->name << ":\n";

    for (int i = 0; i < Sobj->assess.size(); i++) {

        Sobj->assess[i]->display();
    }

    system("pause");
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
        cout << "8.  Assign Course to Teacher\n";
        cout << "9.  Add venue\n";
        cout << "10. show venue\n";
        cout << "11. show All Sections\n";
        cout << "12. add Section\n";
        cout << "13. add assessment\n";
        cout << "14. show all assements\n";
        cout << "15. remove student\n";
        cout << "16. remove teacher\n";
        cout << "17. remove course\n";
        cout << "18. remove section\n";
        cout << "19. remove venue\n";
        cout << "20. Exit\n";
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
        case 8:  assignCourseToTeacher();  break;
        case 9:  addVenue;                 break;
        case 10: showAllVenues();           break;
        case 11: showAllSections();          break;
        case 12: addSections();          break;
        case 13: addAssessment();          break;  
        case 14: showAssessmentofStudent();          break;
        case 15: removeStudent();           break;
        case 16: removeTeacher();          break;
        case 17: removeCourse();          break;
        case 18: removeSection();          break;
        case 19: removeVenue();          break;
        case 20:
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

