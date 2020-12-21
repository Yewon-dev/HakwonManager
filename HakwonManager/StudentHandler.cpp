//
//  StudentHandler.cpp
//  HakwonManager
//
//  Created by kimyewon on 2020/12/17.
//

#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

#include "StudentHandler.hpp"
#include "NormalStudent.h"
#include "SpecialStudent.h"
#include "StudentCommonDecl.h"
#include "Student.hpp"


void StudentHandler::ShowMenu(void) const{
    cout<< "\t 메뉴를 선택해주세요 :)"<<endl;
    cout<<endl;
    cout<<"\t1. 수강생 등록"<<endl;
    cout<<"\t2. 수강생 삭제"<<endl;
    cout<<"\t3. 수강생 수정"<<endl;
    cout<<"\t4. 수강생 검색"<<endl;
    cout<<"\t5. 성적표"<<endl;
    cout<<"\t6. 전체 수강생 조회"<<endl;
    cout<<"\t7. 저장하기"<<endl;
    cout<<"\t8. 종료"<<endl;
    cout<<endl;
    cout<<"\t >> ";
    
}
void StudentHandler::AddStudent(void){
    int num;
    cout<<"\t\t [* M E N U *]"<<endl;
    cout<<" "<<endl;
    cout<<"\t1. 수강생 등록"<<endl;
    cout<<"\t2. 특강 신청"<<endl;
    cout<<" "<<endl;
    cout<<"\t 선 택: ";
    cin>>num;
    
    if(num == NORMAL)
        AddNormalStudent();     //수강생 등록
    else if (num == SPCLEC)
        AddSpecialStudent();    //특강 신청
}

void StudentHandler::AddNormalStudent(void){
    string name;
    int grade;  //학년
    int tuition;//수강료
    int score;  //점수
    
    cout<<"\t[* 수강생 등록 *]"<<endl;
    cout<<" "<<endl;
    cout<<"\t이   름: ";    cin>>name;
    cout<<"\t학   년: ";    cin>>grade;
    cout<<"\t점   수: ";    cin>>score;
    cout<<"\t* 수강료: ";    cin>>tuition;
    cout<<endl;
    
    stdArr.push_back(shared_ptr<Student>(new NormalStudent(name, grade, score, tuition)));
    
    searchMap.insert(make_pair(name, score));
    scoreMap.insert(make_pair(score, name));

}
void StudentHandler::AddSpecialStudent(void){
    string name;
    int grade;
    int tuition;
    int score;
    string specialLec; //특강 수강 유무(o,x)
    
    cout<<"\t[* 겨울특강 신청 *]"<<endl;
    cout<<" "<<endl;
    cout<<"\t이   름: ";    cin>>name;
    cout<<"\t학   년: ";    cin>>grade;
    cout<<"\t점   수: ";    cin>>score;
    cout<<"\t특강유무(o,x): ";    cin>>specialLec;
    cout<<"\t* 수강료: ";    cin>>tuition;
    cout<<endl;
    
    stdArr.push_back(shared_ptr<Student>(new SpecialStudent(name, grade, score, specialLec, tuition)));
    
}

void StudentHandler::DeleteStudent(void){
    string dname;
    
    cout<<"\t[* 학생 삭제 *]"<<endl;
    cout<<" "<<endl;
    cout<<"\t삭제할 학생의 이름을 입력해주세요 : ";
    cin>>dname;
    
    
    for (int i = 0 ; i < stdArr.size(); i++){
        if (stdArr[i]->GetStdName() == dname){
            stdArr.erase(stdArr.begin()+i);
            cout << "삭제 완료 되었습니다"<<endl;
            break;
        }
    }
    
}
void StudentHandler::ModifyStudent(void){
    string mname;
    int ntuition;
    
    cout<<"\t[* 수   정 *]"<<endl;
    cout<<" "<<endl;
    cout<<"\t수정할 학생의 이름을 입력하시오. "<<endl;
    cout<<" "<<endl;
    cout<<"\t 이 름: ";
    cin>>mname;
    
    for (int i = 0; i<stdArr.size(); i++){
        if (stdArr[i]->GetStdName() == mname){
            cout<<" "<<endl;
            cout<<mname<<"학생의 새로운 수강료를 입력하세요."<<endl;
            cout<<">> ";
            cin>>ntuition;
            
            stdArr[i]->SetStdTuition(ntuition);
            
            cout<<"변경이 완료되었습니다 :)"<<endl;
            cout<<" "<<endl;
            cout<<" "<<endl;
        }
    }
}
void StudentHandler::SearchStudent(void){
    int num;
    string sname;
    
    cout<<"\t\t[* 검   색 *]"<<endl;
    cout<<" "<<endl;
    cout<<"\t1. 수강생 검색"<<endl;
    cout<<"\t2. 점수 검색"<<endl;
    cout<<" "<<endl;
    cout<<"\t 선 택: ";
    cin>>num;
    
    switch (num) {
        case 1:
            cout<<" "<<endl;
            cout << "학생의 이름을 입력하세요: ";
            cin >> sname;
            for (int i = 0; i<stdArr.size(); i++){
                if (stdArr[i]->GetStdName() == sname){
                    stdArr[i]->ShowStdInfo();
                }
            }
            break;
        case 2:
            cout<<" "<<endl;
            cout << "학생의 이름을 입력하세요: ";
            cin >> sname;
            
            if(searchMap.find(sname) == searchMap.end())
                cout << sname << "은 없는 사람입니다."<<endl;
            else {
                int score = searchMap[sname];
                cout << sname << "의 점수는 " << score <<"점 입니다."<<endl;
                cout<<" "<<endl;
            }
            break;
    }
}


void StudentHandler::SortStudent(void){ // 성적표
    map<int, string>::reverse_iterator it;
    int count=1;
    for (it=scoreMap.rbegin(); it != scoreMap.rend(); it++) {
        cout << count <<"등 : " << it->second << " \t 점수 : " << it->first <<endl;
        count ++;
    }
    
}

void StudentHandler::AllStudent(void) const{
    for (int i = 0; i<stdArr.size(); i++){
        stdArr[i]->ShowStdInfo();
        cout<<"============================="<<endl;
    }
}


int StudentHandler::SaveStudent(void){
    ofstream fout;
    
    fout.open("/Users/kimyewon/Documents/학교/cpp/StudentList.txt");
    
    if(!fout){
        cout << "파일을 열지 못했습니다 :( " <<endl;
        return 0;
    }
    
    for (int i = 0; i<stdArr.size(); i++){
        fout <<"이름: "<<stdArr[i]->GetStdName() <<endl;
        fout <<"수강료: "<<stdArr[i]->GetStdTuition() <<endl;
        fout << "=========================="<<endl;
        fout << endl;
    }
    
    fout.close();
    
    cout << "\t저장되었습니다! " <<endl;
    cout<<" "<<endl;
    return 0;
}


bool StudentHandler::checkInputError(){
    if (cin.fail()) { // 숫자가 입력되지 않았을 때
        cin.clear();
        cin.ignore(100, '\n');
        cout << "다시 입력해주세요." << endl;
        cout<<" "<<endl;
        return true; // 오류 있음
    }
    else
        return false; // 오류 없음
}
