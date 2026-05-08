#include<iostream>
#include<vector>
using namespace std;
class academicEntity {
	string ID, name, email;
public:
	virtual void display() = 0;
};

class teacher :public academicEntity {
	float score;
	vector < string > courses;
public:
};

class student :public academicEntity{
protected:
	float GPA;
	vector <string> coursesAssigntoStudent;
public:
	virtual void displayGPA() = 0;
	virtual void showTranscript() = 0;
};

class scholarshipStudent :public student {
	bool probation = false;
public:
};

class exchangeScholarship :public student {
	bool result;
public:
};

class regularStudent :public student {
	bool feepay;
public:
};


class course {
protected:
	string name;
	int credits;
public:
	virtual void showStudentinCourse() = 0;
};

class coreCourses :public course {
public:
};

class elective :course {
public:
};

class labs:public course {
public:
};

class Assessment {
protected:
	float finalexam;
	float mid;
	float quizzes;
    float assignmentss;
public:
};

int main() {
	return 0;
}