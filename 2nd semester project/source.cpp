#include<iostream>
#include<vector>
#include<fstream>


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
	virtual void displayGPA() = 0;
	virtual void showTranscript() = 0;
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
	int roomno;
	int time;
	teacher* teacherassign;
	char grade;
	vector <student*> enrollStudents;
public:
	string courseName;
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

	void teacher(teacher* obj) {
		teacherassign = obj;
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
	void teacher(teacher* obj) {
		teacherassign = obj;
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


void previousTeachers() {


}
void addTeacher() {
	string name, email, ID;
	system("cls");
	cout << "Enter the ID of new teacher:" << endl;
	cin >> ID;
	cout << "Enter the name of new teacher:" << endl;
	cin >> name;
	cout << "Enter the email of new teacher:" << endl;
	cin >> email;
	teacher t1(ID, name, email) ;	
	fstream myfile("Teacher.txt");
	myfile >> name;
}
void teacherpage() {
	system("cls");
	int c;
	cout << "1:Previous Teacher Details Page" << endl;
	cout << "2:New Teacher Adding Page" << endl;
	cin >> c;
	switch (c) {
	case 1:
		previousTeachers();
		break;
	case 2:
		addTeacher();
		break;
	default:
		cout << "Invalid Input.\nInput Again!" << endl;
	}
}

int main() {
	cout << "WELCOME TO UNIVERSITY MANAGEMENTS SYSTEM" << endl;
	cout << endl;
	int c=0;
	while (1) {
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
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 0:
			cout << "Closing the program..........." << endl;
			break;
		default:
			cout << "Invalid Input.\nInput Again!" << endl;

		}
		if (c == 0) {
			break;
		}
	}
	return 0;
}