#include "teacher.h"
#include<iostream>


    teacher::teacher(int ID = 0, string name = "", string email = "", float avgScore = 0) {
        this->score = 0;
        this->ID = ID;
        this->name = name;
        this->email = email;
        this->avgScore = avgScore;
    }
    void teacher:: display() {
        cout << "ID:" << ID << ", Name:" << name << ", Email:" << email << ", Avg Score:" << avgScore << endl;
    }
     void teacher::giveFeedback(float i) {
        arrayofScore.push_back(i);
        float sum = 0;
        for (int j = 0; j < (int)arrayofScore.size(); j++) {
            sum += arrayofScore[j];
        }
        avgScore = sum / arrayofScore.size();
    }
    string teacher::getname() const {
        return name;
    }
 