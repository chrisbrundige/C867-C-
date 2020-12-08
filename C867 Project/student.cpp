
#include <iostream>
using namespace std;
#include <algorithm>
#include "student.hpp"
#include "degree.h"

//getters
string Student::GetStudentID(){
    return studentID ;
}
string Student::GetFirstName(){
    return firstName ;
}
string Student::GetLastName(){
    return lastName ;
}
string Student::GetEmail(){
    return emailAddress ;
}
string Student::GetDegree(DegreeProgram dp){
    static const string degreeTypeStrings[]={"SECURTY","NETWORK","SOFTWARE","NONE"};
    string res = degreeTypeStrings[dp];
    return res;
}
int Student::GetAge(){
    return age;
}
int* Student::GetCourseComplete(){
    return courseComplete;
}
//HELPER FX
DegreeProgram Student::getDP(){
    return degree;
}




//setters
void Student::SetStudentID(string id){
    studentID = id;
    return ;
}
void Student::SetFirstName(string first){
    firstName = first;
    return ;
}
void Student::SetLastName(string last){
    lastName  = last;
    return ;
}
void Student::SetEmail(string email){
    emailAddress= email;
    return ;
}
void Student::SetDegree(DegreeProgram degreeProgram){
    
    return ;
}
void Student::SetCourseComplete(int courseCompleted[]){
    
    this->courseComplete[0] = courseCompleted[0];
    this->courseComplete[1] = courseCompleted[1];
    this->courseComplete[2] = courseCompleted[2];

    return ;
}
void Student::SetAge(int sAge){
    this->age=sAge;
    return ;
}


//Default Constructor
Student::Student(){
    studentID = "none";
    firstName = "none";
    lastName = "none";
    emailAddress ="none";
    age = 0;
    degree = NONE;
 
    
}
//DEconstructor
Student::~Student()
{
    if( courseComplete != nullptr){
        delete[] courseComplete;
        courseComplete = nullptr;
    }
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int courseCompleted[] , DegreeProgram degreeProgram){
    
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress=emailAddress;
    this->age=age;
    this->courseComplete = new int[courseDayArraySize];
    for(int i = 0; i < courseDayArraySize; i++) this->courseComplete[i]=0;
    this->degree = degreeProgram;
    
    
};


void Student::print(){
    
  
    
    cout << studentID
    <<  "\tFirst Name: " << firstName
    << "\tLast Name:"  << lastName
    << "\t\t Age:" << age
    << "\tdaysInCourse:" << courseComplete[0]<< ","<< courseComplete[1]<< ","<<  courseComplete[2]
    << "\tDegree Program: " << GetDegree(degree) << "\n"
    << endl ;
    
    
};



