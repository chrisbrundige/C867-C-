
#include <string>
#include <iostream>
#include "roster.hpp"
#include "student.hpp"
#include "degree.h"
#include <vector>
using namespace std;

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram, int ite){
    
    int courseArray[]={daysInCourse1,daysInCourse2,daysInCourse3};
    
    int* arrPtr = courseArray;
    Student* sPtr = new Student (studentID,firstName,lastName,emailAddress,age,arrPtr,degreeProgram);
    
    sPtr->SetCourseComplete(courseArray);
    
    classRosterArray[ite]=sPtr;
    
    
};

bool Roster::remove(string studentID){
    bool found = false;
    for (int i = 0;  i <5 ; i++){
        if((this->classRosterArray[i])->GetStudentID()== studentID){
            found = true;
            delete this->classRosterArray[i];
            this->classRosterArray[i]=this->classRosterArray[lastIndex];
            lastIndex--;
        }
    }
    
    if(found==false){
        cout << studentID << " NOT FOUND" << endl;
    }
    return found;
};

void Roster::printAll(){
    for (int i = 0 ;i < 5; i++){
        classRosterArray[i]->print();
    }
};

void Roster::printAverageDaysInCourse(string studentID){
    
    for(int i=0; i < 5; i++){
        if(classRosterArray[i]->GetStudentID() == studentID ){
            int* p = classRosterArray[i]->GetCourseComplete();
            cout <<studentID << "'s"  << " Average Days in Course is : "  << (p[0] + p[1] + p[2])/3 << endl;
        }
    }
    
    
};
void Roster::printInvalidEmails(){
    
    cout << "INVALID EMAIL ADDRESS: \n" ;
    
    bool valid = false;
        for (int i = 0; i < 5; ++i) {
            if (classRosterArray[i] == nullptr) {
                continue;
            }
            valid = false;
            string email = classRosterArray[i]->GetEmail();
            size_t emailLength = email.size();
            size_t j = 0;
            while (email[j] != ' ' && email[j] != '@' && j < emailLength) {
                ++j;
                if (email[j] == '@' && j < emailLength) {
                    ++j;
                    while (email[j] != ' ' && email[j] != '@' && email[j] != '.' && j < emailLength) {
                        ++j;
                        if (email[j] == '.' && j < emailLength) {
                            ++j;
                            while (email[j] != ' ' && email[j] != '@' && email[j] != '.' && j < emailLength) {
                                ++j;
                                if (j == emailLength) {
                                    valid = true;
                                }
                            }
                        }
                    }
                }
            }
            if (valid == false) {
                std::cout << email << "\n";
            }
        }
    };
void Roster::printByDegreeProgram(DegreeProgram degreeProgram){
    
    cout << "STUDENTS BY DEGREE PROGRAM : " << endl ;
    
    for(int i =0; i< 5; i ++){
        
        if(classRosterArray[i]->getDP() == degreeProgram ){
            
            
            
            cout << "\n" << classRosterArray[i]->GetFirstName() <<" " <<classRosterArray[i]->GetLastName() <<" "<< classRosterArray[i]->GetEmail() << " "<< classRosterArray[i]->GetDegree(classRosterArray[i]->getDP()) << "\n" <<endl;
        }
    }
    
};
//constructor
Roster::Roster(){
    
    
    
};
//deconstructor
Roster::~Roster(){};










