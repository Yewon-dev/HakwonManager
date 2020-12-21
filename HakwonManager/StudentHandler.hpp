//
//  StudentHandler.hpp
//  HakwonManager
//
//  Created by kimyewon on 2020/12/17.
//

#ifndef StudentHandler_hpp
#define StudentHandler_hpp

#include "Student.hpp"
#include <map>
#include <vector>
#include <memory>
using namespace std;

class StudentHandler{
private:
    vector<shared_ptr<Student>> stdArr;
    map<string, int> searchMap;
    map<int, string> scoreMap;
    
public:
    void ShowMenu(void) const;
    void AddStudent(void);
    void DeleteStudent(void);
    void ModifyStudent(void);
    void SearchStudent(void);
    void SortStudent(void);
    void AllStudent(void) const;
    int SaveStudent(void);
    bool checkInputError();
protected:
    void AddSpecialStudent(void);
    void AddNormalStudent(void);
};

#endif /* StudentHandler_hpp */
