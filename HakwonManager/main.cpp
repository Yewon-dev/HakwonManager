//
//  main.cpp
//  HakwonManager
//
//  Created by kimyewon on 2020/12/16.
//
//

#include "StudentHandler.hpp"
#include "StudentCommonDecl.h"

#include <iostream>
#include <string>
using namespace std;

int main() {
    StudentHandler manager;
    int choice;
    while(1) {
        cout<<"******************************"<<endl;
        cout<<"********* Yewon Math *********"<<endl;
        cout<<"******************************"<<endl;
        
        manager.ShowMenu();
        cin>>choice;
        cout<<endl;
        
        if (manager.checkInputError()) // 정수형을 입력하지 않을 때
            continue;
        
        switch(choice){
            case ADD:
                manager.AddStudent();
                break;
            case DELETE:
                manager.DeleteStudent();
                break;
            case MOD:
                manager.ModifyStudent();
                break;
            case SEARCH:
                manager.SearchStudent();
                break;
            case SORT:
                manager.SortStudent();
                break;
            case ALL:
                manager.AllStudent();
                break;
            case TXT:
                manager.SaveStudent();
                break;
            case EXIT:
                return 0;
                
        }
    }
    return 0;
}
