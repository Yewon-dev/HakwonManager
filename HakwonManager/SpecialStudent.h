//
//  SpecialStudent.h
//  HakwonManager
//
//  Created by kimyewon on 2020/12/17.
//

#ifndef SpecialStudent_h
#define SpecialStudent_h

#include "NormalStudent.h"

class SpecialStudent : public NormalStudent{
private:
    int tuition;
    string specialLec;
public:
    SpecialStudent(string name, int grade, int score, string specialLec, int tuition): NormalStudent(name, grade, score, tuition){
        this->specialLec = specialLec;
    }
    string GetStdLec() { return specialLec; }
    int GetStdTuition() { return tuition; }
    
};

#endif /* SpecialStudent_h */
