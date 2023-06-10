#include <iostream>
#include "degree.h"
#ifndef Student         
// #define Student
#pragma once
using std::string;

class Student {
    private:
        string studentID;
        int age;
        int remainingDays[3];
        string firstName;
        string lastName;
        string emailAddress;
        DegreeProgram degreeProgram;

    public:
    
    //Constructor
       Student();
    
    //Overload Constructor
        Student(string studentID, int age, int remainingDays[3], 
         string firstName, string lastName, string emailAddress, 
         DegreeProgram degreeProgram);

    // Getters
    void print();
    string getStudentID();
    int getAge();
    string getRemainingDays();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    DegreeProgram getDegreeProgram();

    //Setters
    void setStudentID(string studentID);
    void setAge(int age);
    void setRemainingDays(int remainingDays, int j);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setDegreeProgram(DegreeProgram degreeProgram);
};

#endif
