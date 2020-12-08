
#ifndef student_hpp
#define student_hpp
#include <string>
using namespace std;
#include <stdio.h>
#include "degree.h"
class Student {
public:
    const static int courseDayArraySize = 3;
    //getters
    string GetFirstName();
    string GetLastName();
    string GetEmail();
    string GetStudentID();
    int GetAge();
    int* GetCourseComplete();
    string GetDegree(DegreeProgram dp);
    DegreeProgram getDP();
    
    //setters
    void SetStudentID(string);
    void SetFirstName(string first);
    void SetLastName(string last);
    void SetEmail(string email);
    void SetDegree(DegreeProgram degreeProgram);
    void SetAge(int age);
    void SetCourseComplete(int courseCompleted[]);
    
    //other methods
    
    void print();
    //constructor
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int courseCompleted[], DegreeProgram degreeProgram);
    //Default Contructor
    Student();
    ~Student();
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int* courseComplete;
    DegreeProgram degree;
};
#endif /* student_hpp */
