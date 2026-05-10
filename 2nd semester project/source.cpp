#include<iostream>
#include<vector>
#include<fstream>
#include<cstring>
#include<string>
vector <teacher*> TEACHERS;
vector <student*> STUDENTS;
vector <course*> COURSES;
vector<venue*>VENUES;
vector <Assessment*> ASSESS;


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
	teacher(int ID=0, string name,string email,float avgScore=0) {
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
};

class student :public academicEntity {
protected:
	float GPA;
	string type;
public:
	virtual void display() = 0;
	virtual void setGPA() = 0;
};
class scholarshipStudent :public student {
	bool probation;
public:
	scholarshipStudent(int ID=0, const char name[]="", const char email[]="",float GPA=0) {
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
	exchangeStudent(int ID=0, const char name[]="", const char email[] = "", float GPA = 0) {
		this->ID = ID;
		this->name = name;
		this->email = email;
		this->type = "exchange";
		if (GPA < 2) {
			fail=true;
		}
		else {
			fail = false;
		}
	}
	
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
	bool feepay;
public:
	regularStudent(int ID = 0, const char name[] = "", const char email[] = "", float GPA = 0) {
		this->ID = ID;
		this->name = name;
		this->email = email;
		this->type = "regular";
		feepay = true;
	}

	void display() {
		cout << "Id:" << ID << ",name:" << name << ",email:" << email << ",GPA:" << GPA << ",type:" << type << ",feepay:" << feepay << endl;
	}

	void setGPA(int GPA) {
		this->GPA = GPA;
	}

	void feepay(bool feepay) {
		this->feepay = feepay;
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

class course:public teacher{
protected:
	int code;
	string name, type;
	teacher* obj;
public:
	course() {}
	virtual void display() = 0;

};
class core :public course {

public:
	core(int code,string name,teacher *obj) {
		this->code = code;
		this->name = name;
		this->obj = obj;
		this->type = "core";
	}

	void display() {
		cout << "code:" << code << ",name:" << name << ",type:" << type << ",teacher:" << obj->name;
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
};

class venue {
protected:
	int roomno;
	int capacity;
	bool computer;
public:
	venue(int roomno = 0, int capacity = 0, bool computer) {
		this->roomno = roomno;
		this->capacity = capacity;
		this->computer = computer;
	}
	void display() {
		cout << "room no:" << roomno << ",capacity:" << capacity << ",computer:" << computer;
	}
};


#include <iostream>
using namespace std;

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

void addStudent()
{

}

void viewStudents()
{
	
}

void addTeacher()
{

}

void viewTeachers()
{

}

void addCourse()
{

}

void viewCourses()
{

}

void registerStudentInCourse()
{

}

void createSection()
{

}

void assignCourseToTeacher()
{

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