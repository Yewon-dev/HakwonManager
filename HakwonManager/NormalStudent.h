//
//  NormalStudent.h
//  HakwonManager
//
//  Created by kimyewon on 2020/12/17.
//

#ifndef NormalStudent_h
#define NormalStudent_h

#include "Student.hpp"

class NormalStudent : public Student {

public:
    NormalStudent(string name, int grade, int score, int tuition): Student(name, grade, score, tuition){
        this->name = name;
        this->grade = grade;
        this->score = score;
        this->tuition = tuition;
    };
    virtual string GetStdName() const;
    virtual void ShowStdInfo() const;
};

string NormalStudent::GetStdName() const{
    return name;
}

void NormalStudent::ShowStdInfo() const{
    cout<<"이  름: "<<name<<endl;
    cout<<"학  년: "<<grade<<endl;
    cout<<endl;
    cout<<"* 수강료: "<<tuition<<endl;
}
#endif /* NormalStudent_h */
