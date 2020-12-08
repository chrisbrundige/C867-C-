//
//  roster.hpp
//  C867 Project
//
//  Created by Chris Brundige on 8/9/20.
//

#ifndef roster_hpp
using namespace std;
#define roster_hpp
#include <stdio.h>
#include "student.hpp"
#include "degree.h"



class Roster {
public:
    int lastIndex;
    int capacity;
    Student* classRosterArray[5];
    Roster();
    Roster(int capacity);
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram, int ite);
    bool remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
   ~Roster();
    
    
    
};



#endif /* roster_hpp */
