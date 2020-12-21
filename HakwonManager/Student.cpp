//
//  Student.cpp
//  HakwonManager
//
//  Created by kimyewon on 2020/12/17.
//

#include "Student.hpp"
#include "StudentCommonDecl.h"

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

Student::Student(string name, int grade, int score, int tuition){
    this->name=name;
    this->grade=grade;
    this->score=score;
    this->tuition=tuition;
}
void Student::SetStdTuition(int t){
    this->tuition=t;
}
int Student::GetStdTuition(){
    return tuition;
};

void Student::SpecialLecture(int tuition){
    tuition+= 50000;
}

Student::Student(const Student& stu){ // 복사생성자 구현
    this->name=stu.name;
    this->grade=stu.grade;
    this->score=stu.score;
    this->tuition=stu.tuition;
}


void Course::addCourse(){
    cout<<"원하는 선생님의 이름을 선택하시오."<<endl;
    cout<<"1. 김선생님 \t 2. 이선생님 \t 3. 박선생님"<<endl;
    cout<<">> ";
    cin>>professor;
    
    cout<<"학생의 이름을 입력하시오."<<endl;
    cout<<">> ";
    cin>>name;
    
    crs.insert(make_pair(professor, name));
    
};
