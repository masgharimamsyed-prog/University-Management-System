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

//id,name,email
class teacher :public academicEntity {
	float score;
	vector < course*> assignedCourses;
public:
	teacher(const char ID[], const char name[], const char email[]) {
		this->ID = ID;
		this->name = name;
		this->email = email;
		
		fstream studentFile("Teachers.txt");
		studentFile << ID << "," << name << "," << email << ";" << endl;
	}
	void addcoursetoteacher(course* obj) {
		assignedCourses.push_back(obj);
	}
	void showassigncourses() {
	}

};


//id,name,email,type,gpa
class student :public academicEntity{
protected:
	float GPA;
public:
	virtual void displayGPA() = 0;
	virtual void showTranscript() = 0;
};
class scholarshipStudent :public student {
	bool probation = false;
public:
	scholarshipStudent(const char ID[], const char name[], const char email[],float GPA) {
		this->ID = ID;
		this->name = name;
		this->email = email;
		if (GPA < 3.3) {
			probation = true;
		}
		fstream studentFile("Students.txt");
		studentFile << ID << "," << name << "," << email << ",Scholarship," << GPA <<";" << endl;
	}

	void displayGPA() {
		cout << GPA;
	}
};
class exchangeStudent :public student {
	bool result;
public:
	exchangeStudent(const char ID[], const char name[], const char email[],float GPA) {
		this->ID = ID;
		this->name = name;
		this->email = email;
		this->result = result;
		if (GPA < 2) {
			result= true;
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

class course {
protected:
	string name;
	int roomno;
	int time;
	teacher* teacherassign;
	char grade;
	vector <student*> enrollStudents;
public:
	virtual void calculateFinalGrade() = 0;
	virtual int getExamDuration() = 0;
	virtual void showStudentinCourse() = 0;
};
class coreCourses :public course {
	float marks;
	int examDuration = 3;

public:
	void setFinalMarks(float total, float obtain) {
		marks=( obtain/total) *100;
	}
	
	void teacher(teacher* obj) {
		teacherassign = obj;
	}
	int getExamDuration() {
		return examDuration;
	}
	void showStudentinCourse() {
		for (int i = 0; i < enrollStudents.size(); i++) {
			cout << (enrollStudents[i]).name << endl;
		}
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

};
class elective :course {
	float assignmentsMarks;
	float projectmarks;
	int examDuration = 2;
public:

	void setassigmentMarks(float total,float obtain) {
		assignmentsMarks=( obtain/total )*0.30;
	}
	void setProjectMarks(float total,float obtain) {
		projectmarks=(obtain / total)*0.70;
	}
	void teacher(teacher* obj) {
		teacherassign = obj;
	}
	int getExamDuration() {
		return examDuration;
	}
	void showStudentinCourse() {
		for (int i = 0; i < enrollStudents.size(); i++) {
			cout <<"Course "<<i+1<<":" << (enrollStudents[i]).name << endl;
		}
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
};
class labs:public course {
	float labsMarks[10];
	int examDuration = 1;
public:
	void setLabMarks(int labno,float total,float obtain) {
		if (labno > 9) {
			cout << "wrong input" << endl;
			return;
		}
		else if (labno<0) {
			cout << "wrong input" << endl;
			return;
		}
		this->labsMarks[labno-1]= (obtain/total)  * 0.10;
	}
	void showStudentinCourse() {
		for (int i = 0; i < enrollStudents.size(); i++) {
			cout << "Course " << i + 1 << ":" << (enrollStudents[i]).name << endl;
		}
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
	int getExamDuration() {
		return examDuration;
	}

};

class Assessment:public course {

protected:
	float totalAbsolutes;
	float obtainAbsolutes;
public:
};
class finals :public Assessment {
	float totalMarks;
	float obtainMarks;
public:
};
class labs :public Assessment {
	int totalLabs;
	float totalMarks;
	float obtainMarks;
public:
};
class quizzes :public Assessment {
	int totalQuizzes;
	float totalMarks;
	float obtainMarks;
public:
};
class assignments :public Assessment {
	int totalassignments;
	float totalMarks;
	float obtainMarks;
public:
};

int main() {
	return 0;
}