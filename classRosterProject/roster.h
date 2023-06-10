
#include <iostream>
#include "student.h"
#ifndef Roster
// #define Roster
#pragma once
using std::string;

const int rosterSize = 5;

class Roster {
    public:
    int index = 0;
    Student *classRosterArray[rosterSize];
    Roster();
    ~Roster();
    void parseData(string str);

    void add(string studentID, string firstName, string lastName, string emailAddress,
        int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);

    void add(int tableLocation, string studentID ,string firstName, 
        string lastName, string emailAddress, DegreeProgram degreeProgram);

    void add(int tableLocation, int age);

    void add(int tableLocation, int remainingDays, int j);

    void remove(string studentID);

    void printStudent(int i);

    void printAll();

    int printAverageDaysInCourse(string studentID);

    void printInvalidEmails();

    void printByDegreeProgram(DegreeProgram degreeProgram);
};

#endif
