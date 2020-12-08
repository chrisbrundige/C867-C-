//
//  main.cpp
//  C867 Project
//
//  Created by Chris Brundige on 8/9/20.
//

#include <iostream>
#include "student.hpp"
#include "roster.hpp"
#include <sstream>
#include <vector>
#include <string>
#include <typeinfo>

using namespace std;
static const string degreeTypeStrings[]={"SECURTY","NETWORK","SOFTWARE","NONE"};
const string studentData[] =

{"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Chris,Brundige,chrisbrundige@gmail.com,33,1,2,3,SOFTWARE"
};


int main() {
    
    //iterates through student data and parses each string, formatting the arguments for use in the classRoster.add() method.
    int arSze = sizeof(studentData) / sizeof(studentData[0]);
    Roster classRoster;
    
    
    for(int i=0; i < arSze ; i++){
        
        string eachStudent = studentData[i];
        vector<string> studs;
        
        stringstream stgToCheck(eachStudent);
        
        while (stgToCheck.good()){
            string substr;
            getline(stgToCheck,substr,',');
            studs.push_back(substr);
            
        }
        
        
        string alpha = studs.at(8) ;
        DegreeProgram degreeProgram;
        
        
        
        if (alpha == "SOFTWARE"){
            
            degreeProgram = SOFTWARE;
        }
        
        else if (alpha == "SECURITY")
        {
            degreeProgram = SECURITY;
        }
        
        else if(alpha == "NETWORK")
        {
            degreeProgram = NETWORK;
        }
        
        else {
            degreeProgram = NONE;
        }
        
        
        
        
        
        classRoster.add(studs.at(0),studs.at(1),studs.at(2),studs.at(3),stoi(studs.at(4)),stoi(studs.at(5)),stoi(studs.at(6)),stoi(studs.at(7)), degreeProgram, i);
        
        
        
        
    };
    
    cout << "Programming Applications C867" << endl ;
    cout << "Written in C++ by Chris Brundige ID#001380466" << endl;
    cout << "Displaying all students: \n" << endl;
    classRoster.printAll();
    
    classRoster.printInvalidEmails();
    
    for(int i=0; i < 5; i++){
        
        string sID = classRoster.classRosterArray[i]->GetStudentID();
        
        classRoster.printAverageDaysInCourse(sID);
        
        
        
    }
    
    
    
    classRoster.printByDegreeProgram(SOFTWARE);
    
    classRoster.remove("A3");
    
    classRoster.printAll();
    
    classRoster.remove("A3");
    
    
    
    
};

















