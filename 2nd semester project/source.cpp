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
	string  name;
	virtual void display() = 0;
};

class teacher :public academicEntity {
	vector <float> arrayofScore;
		float avgScore;
	float score;
public:
	teacher(int ID=0, string name="", string email = "", float avgScore = 0) {
		this->score = 0;
		this->ID = ID;
		this->name = name;
		this->email = email;
		this->avgScore = avgScore;
	}
	void display() {
		cout <<"ID:"<<ID << ",Name:" << name << ",Email:" << email <<",Avg Score"<<avgScore << endl;
	}
	void giveFeedback(int i) {
		arrayofScore.push_back(i);
		float sum;
		for (int j = 0; j < arrayofScore.size(); j++) {
			sum += arrayofScore[j];
		}
		avgScore = sum / arrayofScore.size();
	}
	string getname() {
		return name;
	}
};

class student :public academicEntity {
protected:
	float GPA;
	string type;
public:
	virtual void display() = 0;
	virtual void setGPA(int GPA) = 0;
	friend void viewStudents();

};
class scholarshipStudent :public student {
	bool probation;
public:
	scholarshipStudent(int ID=0, string name="", string email="",float GPA=0){
		this->ID = ID;
		this->name = name;
		this->email = email;
		this->GPA = GPA;
		this->type = "scholarship";
		if (GPA<3.3 &&GPA!=0) {
			probation = true;
		}
		else {
			probation = false;
		}
	}
	friend void viewStudents();
	void display() {
		cout <<"Id:"<<ID << ",name:" << name << ",email:" << email << ",GPA:" << GPA <<",type:"<<type << ",Probation:" << probation << endl;
	}

	void setGPA(int GPA) {
		this->GPA = GPA;
		if (GPA < 3.3 ) {
			probation = true;
		}
		else {
			probation = false;
		}
	}

};
class exchangeStudent :public student {
	bool fail;
public:
	exchangeStudent(int ID=0, string  name="", string email = "", float GPA = 0) {
		this->ID = ID;
		this->name = name;
		this->email = email;
		this->type = "exchange";
		this->GPA = GPA;
		if (GPA < 2) {
			fail=true;
		}
		else {
			fail = false;
		}
	}
	friend void viewStudents();
	void display() {
		cout << "Id:" << ID << ",name:" << name << ",email:" << email << ",GPA:" << GPA << ",type:" << type << ",fail:" << fail << endl;
	}

	void setGPA(int GPA) {
		this->GPA = GPA;
		if (GPA < 2) {
			fail = true;
		}
		else {
			fail = false;
		}
	}
};
class regularStudent :public student {
	bool feeStatus;
public:
	regularStudent(int ID = 0, string name = "", string email= "", float GPA = 0) {
		this->ID = ID;
		this->name = name;
		this->email = email;
		this->type = "regular";
		this->GPA = GPA;
		feeStatus = true;
	}

	void display() {
		cout << "Id:" << ID << ",name:" << name << ",email:" << email << ",GPA:" << GPA << ",type:" << type << ",feepay:" << feeStatus << endl;
	}
	friend void viewStudents();
	void setGPA(int GPA) {
		this->GPA = GPA;
	}

	void setfeeStatus(bool fee) {
		feeStatus= fee;
	}
};

vector <student*> STUDENTS;
class course :public teacher {
protected:
	vector <student*> itsStudents;
	string type;
	teacher* obj;
	int code;
	string name;
public:
	course() {}
	virtual void assignCourse(teacher* obj) = 0;
	virtual void display() = 0;
	virtual void showitsStudents() = 0;
	friend void assignCourseToTeacher();
	virtual void AddingStudenttoCourse(student *obj) = 0;
	friend void registerStudentInCourse();
};
class core :public course {

public:
	core(int code, string name, teacher* obj) {
		this->code = code;
		this->name = name;
		this->obj = obj;
		this->type = "core";
	}

	void display() {
		cout << "code:" << code << ",name:" << name << ",type:" << type << ",teacher:" << obj->name;
	}
	void showitsStudents() {
		for (int i = 0; i < itsStudents.size(); i++) {
			cout << "student" << i + 1 << ":";
				itsStudents[i]->display();
		}
	}
	void assignCourse(teacher *obj) {
		this->obj = obj;
	}
	void AddingStudenttoCourse(student* obj) {
		if (STUDENTS.size() < 3) {
			itsStudents.push_back(obj);
		}
		else {
			cout << "no more seats" << endl;
		}
	}

};
class elective :public course {

public:
	elective(int code, string name, teacher* obj) {
		this->code = code;
		this->name = name;
		this->obj = obj;
		this->type = "elective";
	}

	void display() {
		cout << "code:" << code << ",name:" << name << ",type:" << type << ",teacher:" << obj->name;
	}
	void assignCourse(teacher* obj) {
		this->obj = obj;
	}
	void showitsStudents() {
		for (int i = 0; i < itsStudents.size(); i++) {
			cout << "student" << i + 1 << ":";
			itsStudents[i]->display();
		}
	}
	void AddingStudenttoCourse(student* obj) {
		if (STUDENTS.size() < 3) {
			itsStudents.push_back(obj);
		}
		else {
			cout << "no more seats" << endl;
		}
	}
};
class lab :public course {

public:
	lab(int code, string name, teacher* obj) {
		this->code = code;
		this->name = name;
		this->obj = obj;
		this->type = "lab";
	}

	void display() {
		cout << "code:" << code << ",name:" << name << ",type:" << type << ",teacher:" << obj->name;
	}
	void assignCourse(teacher* obj) {
		this->obj = obj;
	}
	void showitsStudents() {
		for (int i = 0; i < itsStudents.size(); i++) {
			cout << "student" << i + 1 << ":";
			itsStudents[i]->display();
		}
	}
	void AddingStudenttoCourse(student* obj) {
		if (STUDENTS.size() < 3) {
			itsStudents.push_back(obj);
		}
		else {
			cout << "no more seats" << endl;
		}
	}
};

class Assessment {
protected:
	course* ptrC;
	student* ptrS;
public:
	Assessment(){}
};
class finals :public Assessment {

public:
};
class dailylabs :public Assessment {

public:
	void setmarks() {}
};
class quizzes :public Assessment {};
class assignments :public Assessment {
};



class venue {
protected:
	int roomno;
	int capacity;
	bool computer;
public:
	venue(int roomno = 0, int capacity = 0, bool computer=0) {
		this->roomno = roomno;
		this->capacity = capacity;
		this->computer = computer;
	}
	void display() {
		cout << "room no:" << roomno << ",capacity:" << capacity << ",computer:" << computer;
	}
};



vector <teacher*> TEACHERS;
vector <course*> COURSES;
vector <venue*>VENUES;
vector <Assessment*> ASSESS;

void loadData();
void addStudent();//
void viewStudents();//
void addTeacher();//
void viewTeachers();//
void addCourse();//
void viewCourses();//
void registerStudentInCourse();//
void createSection();
void assignCourseToTeacher();//
void saveData();

void loadData() {}

void addStudent()
{
	int ID;
	string name;
	string email;
	float GPA;
	int type;

	cout << "Enter ID:" << endl;
	cin >> ID;
	cout << "Enter Name:" << endl;
	cin >> name;
	cout << "Enter email:" << endl;
	cin >> email;
	cout << "Enter GPA:" << endl;
	cin >> GPA;

	cout << "Enter Type:" << endl;
	cout << "1. Regular Student\n";
	cout << "2. Scholarship Student\n";
	cout << "3. Exchange Student\n";

	cin >> type;
	while (type != 1 && type != 2 && type != 3) {
		cout << "Inavlid input ,input again:" << endl;
		cin >> type;
	}
	
	if (type == 1)
	{
		
		STUDENTS.push_back(new regularStudent(ID,name,email,GPA));

		cout << "\nRegular Student Added!\n";
	}

	else if (type == 2)
	{
		STUDENTS.push_back(new scholarshipStudent(ID,name,email,GPA));

		cout << "\nScholarship Student Added!\n";
	}

	else if (type == 3)
	{
		STUDENTS.push_back(new exchangeStudent(ID,name,email,GPA));

		cout << "\nExchange Student Added!\n";
	}

}

void viewStudents()
{
	for (int i = 0; i < STUDENTS.size(); i++) {
		 (*STUDENTS[i]).display();
	}

	system("pause");
}

void addTeacher()
{
	int ID;
	string name;
	string email;


	cout << "Enter ID:" << endl;
	cin >> ID;
	cout << "Enter Name:" << endl;
	cin >> name;
	cout << "Enter email:" << endl;
	cin >> email;


	
		TEACHERS.push_back(new teacher(ID, name, email));

		cout << "\nExchange Student Added!\n";
}

void viewTeachers()
{
	for (int i = 0; i < TEACHERS.size(); i++) {
		 (*TEACHERS[i]).display();
	}

	system("pause");
}

void addCourse()
{
	int code; string name;
	cout << "Enter code of Course:" << endl;
	cin >> code;
	cout << "Enter name of course:" << endl;
	cin >> name;

	int type;
	
	
	cout << "\nEnter Course Type:\n";
	cout << "1. Core Course\n";
	cout << "2. Elective Course\n";
	cout << "3. Lab Course\n";

	cout << "Choice: ";
	cin >> type;
	while (type != 1 && type != 2 && type != 3) {
		cout << "Inavlid input ,input again:" << endl;
		cin >> type;
	}
	viewTeachers();
	string t_name;
	teacher* obj=NULL;
	while (1) {
		cout << "Select Teacher by name which teaches this course:" << endl;
		cin >> t_name;
		bool found = true;
		for (int i = 0; i < TEACHERS.size(); i++) {
			if (((*TEACHERS[i]).getname()) == t_name) {
				obj = TEACHERS[i];
			}
		}
		if (found) {
			cout << "No such exist " << endl;
			obj = NULL;
		}
		else {
			break;
		}
	}
	if (type == 1)
	{
		COURSES.push_back(new core(code,name,obj));
	}
	else if (type == 2)
	{
		COURSES.push_back(new elective(code,name,obj));
	}
	else if (type == 3)
	{
		COURSES.push_back(new lab(code,name,obj));
	}
}

void viewCourses()
{
	for (int i = 0; i < COURSES.size(); i++) {
		COURSES[i]->display();
	}
	int cl;

	cout << "If want to know the details of student in it,then press 1 otherwsie 0" << endl;
	cin >> cl;
	while (1) {
		if (cl == 1) {
			for (int i = 0; i < COURSES.size(); i++) {
				COURSES[i]->display();
				COURSES[i]->showitsStudents();
			}
			break;
		}
		else if (cl == 0) {
			break;
		}
		else {
			cout << "invalid input ,input again" << endl;
			cin >> cl;
		}
	}
	system("pause");

}

void registerStudentInCourse(){
	cout << "Course we educate" << endl;
	viewCourses();
	cout << "Teachers we have:" << endl;
	viewTeachers();
	string t_name;
	student* t_obj = nullptr;
	int C_code;
	cout << "Enter the student you want to assign" << endl;
	cin >> t_name;
	bool f;
	for (int i = 0; i < STUDENTS.size(); i++) {
		if (STUDENTS[i]->name == t_name) {
			t_obj = STUDENTS[i];
			f = true;
		}
	}

	if (!f) {
		cout << "No ,such course exist !" << endl;
	}
	cout << "Enter the course code you want to assign the student" << endl;
	cin >> C_code;
	bool found=true;
	for (int i = 0; i < COURSES.size(); i++) {
		if (COURSES[i]->code == C_code) {
			COURSES[i]->AddingStudenttoCourse(t_obj);
			found = true;
		}
	}

	if (!found) {
		t_obj = nullptr;
		cout << "No ,such course exist !" << endl;
	}
	else {
		cout << "assigned!" << endl;
	}
}

void createSection()
{

}

void assignCourseToTeacher()
{
	cout << "Course we educate" << endl;
	viewCourses();
	cout << "Teachers we have:" << endl;
	viewTeachers();
	string t_name;
	teacher* t_obj = nullptr;
	int C_code;
	cout << "Enter the teacher you want to assign" << endl;
	cin >> t_name;
	bool f;
	for (int i = 0; i < TEACHERS.size(); i++) {
		if (TEACHERS[i]->name == t_name) {
			t_obj = TEACHERS[i];
			f = true;
		}
	}

	if (!f) {
		cout << "No ,such course exist !" << endl;
	}
	cout << "Enter the course code you want to assign the teacher" << endl;
	cin >> C_code;
	bool found=true;
	for (int i = 0; i < COURSES.size(); i++) {
		if (COURSES[i]->code == C_code) {
			COURSES[i]->obj = t_obj;
			found = true;
		}
	}

	if (!found) {
		cout << "No ,such course exist !" << endl;
		t_obj = nullptr;
	}
	else {
		cout << "assigned!" << endl;
	}

}

void saveData()
{


}

int main()
{
	int c;



	while (1)
	{
		system("cls");

		cout << "\n=====================================\n";
		cout << " FAST Academic Office System\n";
		cout << "=====================================\n";

		cout << "1. Add Student\n";
		cout << "2. View Students\n";
		cout << "3. Add Teacher\n";
		cout << "4. View Teachers\n";
		cout << "5. Add Course\n";
		cout << "6. View Courses\n";
		cout << "7. Register Student in Course\n";
		cout << "8. Create Section\n";
		cout << "9. Assign Course to Teacher\n";
		cout << "10. Exit\n";

		cout << "Enter Choice: ";
		cin >> c;

		if (c == 1)
		{
			addStudent();
		}

		else if (c == 2)
		{
			viewStudents();
		}

		else if (c == 3)
		{
			addTeacher();
		}

		else if (c == 4)
		{
			viewTeachers();
		}

		else if (c == 5)
		{
			addCourse();
		}

		else if (c == 6)
		{
			viewCourses();
		}

		else if (c == 7)
		{
			registerStudentInCourse();
		}

		else if (c == 8)
		{
			createSection();
		}

		else if (c == 9)
		{
			assignCourseToTeacher();
		}


		else if (c == 10)
		{
			saveData();

			cout << "\nProgram Closed...\n";

			break;
		}

		else
		{
			cout << "\nInvalid Choice!\n";

			system("pause");
		}
	}

	return 0;
}