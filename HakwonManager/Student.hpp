//
//  Student.hpp
//  HakwonManager
//
//  Created by kimyewon on 2020/12/17.
//

#ifndef Student_hpp
#define Student_hpp

#include "StudentCommonDecl.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Student{
protected:
    string name;
    int grade;
    int tuition;
    int score;
public:
    Student(string name, int grade, int score, int tuition);
    Student(const Student& stu); // 복사 생성자
    
    int GetStdTuition();
    void SetStdTuition(int t);
    virtual string GetStdName() const = 0; // 순수 가상함수
    virtual void ShowStdInfo() const = 0; // 순수 가상함수
    void SpecialLecture(int tuition);
};

class Course : public Student{
    string professor;
    map<string, string> crs;
public:
    Course(string professor, string name, int grade, int score, int tuition): Student(name, grade, score, tuition) {
        this->professor=professor;
    };
    
    void addCourse();
    
};

#endif /* Student_hpp */
