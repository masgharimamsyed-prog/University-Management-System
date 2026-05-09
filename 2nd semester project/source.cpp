#include<iostream>
#include<vector>
#include<fstream>
void showAllTeachers();
void mainMenu();

using namespace std;

class academicEntity {
protected:
	string ID, name, email;
public:
	virtual void display() = 0;
};

class teacher :public academicEntity {
	float score;
public:
	teacher(string ID, string name,string email) {
		this->score = 0;
		this->ID = ID;
		this->name = name;
		this->email = email;
		
		fstream File("Teachers.txt");
		File << ID << "," << name << "," << email << ";" << endl;
	}
	void display() {
		cout <<"ID:"<<ID << " | Name:" << name << " |  Email:" << email << endl;
	}
};
class student :public academicEntity {
protected:
	float GPA;
public:
	student(string ID="", string name="", string email="") {
	
		this->ID = ID;
		this->name = name;
		this->email = email;

		fstream File("Students.txt");
		File << ID << "," << name << "," << email << ";" << endl;
	}
	void display() {
		cout << "ID:" << ID << " | Name:" << name << " |  Email:" << email << endl;
	}
};
class scholarshipStudent :public student {
	bool probation = false;
public:
	scholarshipStudent(const char ID[], const char name[], const char email[], float GPA) {
		this->ID = ID;
		this->name = name;
		this->email = email;
		if (GPA < 3.3) {
			probation = true;
		}
		fstream studentFile("Students.txt");
		studentFile << ID << "," << name << "," << email << ",Scholarship," << GPA << ";" << endl;
	}

	void displayGPA() {
		cout << GPA;
	}
};
class exchangeStudent :public student {
	bool result;
public:
	exchangeStudent(const char ID[], const char name[], const char email[], float GPA) {
		this->ID = ID;
		this->name = name;
		this->email = email;
		this->result = result;
		if (GPA < 2) {
			result = true;
		}
		fstream studentFile("Students.txt");
		studentFile << ID << "," << name << "," << email << ",Exchange," << GPA << ";" << endl;
	}
	void setResult(bool result) {
		this->result = result;
	}
	void displayresult() {
		cout << result;
	}
	void displayGPA() {
		cout << GPA;
	}
};
class regularStudent :public student {
	bool feepay;
public:
	regularStudent(const char ID[], const char name[], const char email[], float GPA) {
		this->ID = ID;
		this->name = name;
		this->email = email;
		fstream studentFile("Students.txt");
		studentFile << ID << "," << name << "," << email << ",regular," << GPA << ";" << endl;
	}
	void setFee(bool feepay) {
		this->feepay = feepay;
	}
	void displayFeedetail() {
		cout << feepay;
	}
	void displayGPA() {
		cout << GPA;
	}
};

class Assessment {
protected:
	float totalAbsolutes;
	float obtainAbsolutes;
public:
};
class finals :public Assessment {
	float totalMarks;
	float obtainMarks;
public:
	void setmarks() {}
};
class dailylabs :public Assessment {
	int totalLabs;
	float totalMarks;
	float obtainMarks;
public:
	void setmarks() {}
};
class quizzes :public Assessment {
	int totalQuizzes;
	float totalMarks;
	float obtainMarks;
public:
	void setmarks() {}
};
class assignments :public Assessment {
	int totalassignments;
	float totalMarks;
	float obtainMarks;
public:
	void setmarks() {}
};

class course{
protected:
	string code, name, type, teacher;
	char grade;
public:
	course(string code,string name,string type,string teacher) {
		this->code = code;
		this->name = name;
		this->type = type;
		this->teacher = teacher;

		fstream File("Courses.txt");
		File << code<< "," << name << "," << type <<"," <<teacher <<";" << endl;
	}
	/*virtual void calculateFinalGrade() = 0;
	virtual int getExamDuration() = 0;
	virtual void showStudentinCourse() = 0;*/
};
class coreCourses :public course {
	float marks;
	int examDuration = 3;

public:
	void setFinalMarks(float total, float obtain) {
		marks = (obtain / total) * 100;
	}

	
	int getExamDuration() {
		return examDuration;
	}
	void calculateFinalGrade() {
		if (marks >= 90)
			grade = 'A';
		else if (marks >= 80)
			grade = 'B';
		else if (marks >= 70)
			grade = 'C';
		else if (marks >= 60)
			grade = 'D';
		else
			grade = 'F';
	}
	void showStudentinCourse(){}

};
class elective :course {
	float assignmentsMarks;
	float projectmarks;
	int examDuration = 2;
public:

	void setassigmentMarks(float total, float obtain) {
		assignmentsMarks = (obtain / total) * 0.30;
	}
	void setProjectMarks(float total, float obtain) {
		projectmarks = (obtain / total) * 0.70;
	}

	int getExamDuration() {
		return examDuration;
	}

	void calculateFinalGrade() {
		float marks = projectmarks + assignmentsMarks;

		if (marks >= 90)
			grade = 'A';
		else if (marks >= 80)
			grade = 'B';
		else if (marks >= 70)
			grade = 'C';
		else if (marks >= 60)
			grade = 'D';
		else
			grade = 'F';
	}

	void showStudentinCourse() {}
};
class labs :public course {
	float labsMarks[10];
	int examDuration = 1;
public:
	void setLabMarks(int labno, float total, float obtain) {
		if (labno > 9) {
			cout << "wrong input" << endl;
			return;
		}
		else if (labno < 0) {
			cout << "wrong input" << endl;
			return;
		}
		this->labsMarks[labno - 1] = (obtain / total) * 0.10;
	}

	void calculateFinalGrade() {
		float marks;
		for (int i = 0; i < 10; i++) {
			marks += labsMarks[i];
		}
		if (marks >= 90)
			grade = 'A';
		else if (marks >= 80)
			grade = 'B';
		else if (marks >= 70)
			grade = 'C';
		else if (marks >= 60)
			grade = 'D';
		else
			grade = 'F';
	}

	void showStudentinCourse() {}
	int getExamDuration() {
		return examDuration;
	}

};

void assigningCourse() {
	system("cls");
	cout << "ENTER THE ASSIGNING THE COURSE TO TEACHER" << endl;
	cout << "These are All teachers ,we have:" << endl;
	showAllTeachers();
	cout << "Enter the ID of t";
}
void showAllTeachers() {
	system("cls");
	cout << "ENTERING THE TEACHER SHOWING TABLE" << endl;
	fstream File("Teachers.txt");
	char ch;
	cout << "ID,Name,email;" << endl;
	while (File>>ch) {

			cout << ch;
			if (ch == ';'){
				cout << endl;
			}
	}
	cout << "Press any key to return to Main menu" << endl;
	system("pause");


}
void addTeacher() {
	string name, email, ID;
	system("cls");
	cout << "ADDING NEW TEACHER PAGE" << endl;
	cout << "Enter the ID of new teacher:" << endl;
	cin >> ID;
	cout << "Enter the name of new teacher:" << endl;
	cin >> name;
	cout << "Enter the email of new teacher:" << endl;
	cin >> email;
	teacher t1(ID, name, email) ;	
	cout << "New teacher Added Successfully\nPress any key to return to Main menu" << endl;
	system("pause");
	mainMenu();
}
void teacherpage() {
	system("cls");
	cout << "TEACHER PAGE" << endl;
	int c;
	bool again = true;
	while (again) {
		cout << "1:Show All Teacher " << endl;
		cout << "2:New Teacher Adding Page" << endl;
		cout << "3:Assigning the course to teacher" << endl;
		cout << "0: Main menu" << endl;
		cin >> c;
		again = false;
		switch (c) {
		case 1:
			showAllTeachers();
			break;
		case 2:
			addTeacher();
			break;
		case 3:
			assigningCourse();
			break;
		case 0:
			mainMenu();
		default:
			cout << "Invalid Input.\nInput Again!" << endl;
			again = true;
		}
	}
}

void showAllStudents() {
	system("cls");
	fstream File("Students.txt");
	char ch;
	cout << "ID,Name,email;" << endl;
	while (File >> ch) {

		cout << ch;
		if (ch == ';') {
			cout << endl;
		}
	}


	cout << "press any key to return to main menu";
	system("pause");
	mainMenu();
}
void addStudents() {

	string name, email, ID;
	system("cls");
	cout << "ENTER THE ADDING NEW STUDENT PAGE" << endl;
	cout << "Enter the ID of new student:" << endl;
	cin >> ID;
	cout << "Enter the name of new student:" << endl;
	cin >> name;
	cout << "Enter the email of new student:" << endl;
	cin >> email;
	student t1(ID, name, email);
	cout << "Student Added Successfully" << endl;
	cout << "Enter any key to go to main menu" << endl;
	system("cls");
	mainMenu();
}
void assigningCoursetoStudent(){

}
void studentpage() {
	system("cls");
	cout << "ENTERING THE STUDENT PAGE" << endl;
	int c;
	
	bool again=true;
	while (again) {
		again = false;
		cout << "1:Show All students " << endl;
		cout << "2:New Student Adding Page" << endl;
		cout << "3:Register the course for Student" << endl;
		cout << "0:Main Menu" << endl;
		cin >> c;
		switch (c) {
		case 1:
			showAllStudents();
			break;
		case 2:
			addStudents();
			break;
		case 3:
			assigningCoursetoStudent();
			break;
		case 0:
			mainMenu();
		default:
			cout << "Invalid Input.\nInput Again!" << endl;
			again = false;
		}
	}
}

void showAllCourses() {
	system("cls");
	fstream File("Courses.txt");
	char ch;
	cout << "Code,Name,type,teacher;" << endl;
	while (File >> ch) {

		cout << ch;
		if (ch == ';') {
			cout << endl;
		}
	}
	int c;
	cout << "0:Main Menu" << endl;
	cin >> c;

	while (c != 0) {
		cout << "Invalid input !" << endl;
		cout << "Input again:" << endl;
		cin >> c;
	}
}
void addCourse() {

	string code,name,type,teacher;
	system("cls");
	cout << "Enter the code of new course:" << endl;
	cin >> code;
	cout << "Enter the name of new course:" << endl;
	cin >> name;
	cout << "Enter the type of new course:" << endl;
	cin >> type;
	cout << "Enter the teacher of new course:" << endl;
	cin >> teacher;
	course c1(code,name,type,teacher);
}
void coursepage() {
	system("cls");
	int c;
	bool again = true;
	while (again) {
		again = false;
		cout << "1:Show All Courses " << endl;
		cout << "2:Add new Course" << endl;
		cin >> c;
		switch (c) {
		case 1:
			showAllCourses();
			break;
		case 2:
			addCourse();
			break;
		default:
			cout << "Invalid Input.\nInput Again!" << endl;
			again = true;
		}
	}
}

void coreAssessment(){}
void electiveAssessment() {}
void labAssessment(){}
void assessmentpage() {
	int c;
	system("cls");
	
	bool again = true;
	while (again) {
		again = false;
		cout << "1:Assessment of Core" << endl;
		cout << "2:Assessment of Elective" << endl;
		cout << "3:Assessment of labs" << endl;
		cout << "0:return to Main Menu" << endl;
		cin >> c;
		switch (c) {
		case 1:
			coreAssessment();
			break;
		case 2:
			electiveAssessment();
			break;
		case 3:
			labAssessment();
			break;
		case 0:
			mainMenu();
			break;
		default:
			cout << "Invalid Input.\nInput Again!" << endl;
			again = true;
		}
	}
}

void venuepage() {
	system("cls");
	fstream File("Venues.txt");
	char ch;
	cout << "Room no,Capacity,available;" << endl;
	while (File >> ch) {

		cout << ch;
		if (ch == ';') {
			cout << endl;
		}
	}
	cout << "Enter any key to go to main menu" << endl;
	system("cls");
	mainMenu();

}


void mainMenu() {
	
	int c = 0;
	while (1) {
		system("cls");
		cout << "WELCOME TO UNIVERSITY MANAGEMENTS SYSTEM" << endl;
		cout << endl;
		cout << "1:Teacher Page" << endl;
		cout << "2:Student Page" << endl;
		cout << "3:Courses Page" << endl;
		cout << "4:Assessments Page" << endl;
		cout << "5:Venue Page" << endl;
		cout << "0:Exit the Program" << endl;
		cin >> c;

		switch (c) {
		case 1:
			teacherpage();
			break;
		case 2:
			studentpage();
			break;
		case 3:
			coursepage();
			break;
		case 4:
			assessmentpage();
			break;
		case 5:
			venuepage();
			break;
		case 0:
			cout << "Closing the program..........." << endl;
			return;
			break;
		default:
			cout << "Invalid Input.\nInput Again!" << endl;

		}
		if (c == 0) {
			break;
		}
	}
}
int main() {
	mainMenu();
	
	return 0;
}