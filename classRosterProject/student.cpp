#include <iostream>
#include <string>
#include "student.h"
using std::cout;
using std::endl;
using std::string;


        Student::Student() {

        }

        Student::Student(string studentID, int age, int remainingDays[3], 
        string firstName, string lastName, string emailAddress, 
        DegreeProgram degreeProgram) {
            this->studentID = studentID;
            this->age = age;
            this->remainingDays[0] = remainingDays[0];
            this->remainingDays[1] = remainingDays[1];
            this->remainingDays[2] = remainingDays[2];
            this->firstName = firstName;
            this->lastName = lastName;
            this->emailAddress = emailAddress;
            this->degreeProgram = degreeProgram;
        }
        
        // Getters
        void Student::print() {
            cout << " || " << getStudentID() << " || ";
            cout << getFirstName() << " || ";
            cout << getLastName() << " || ";
            cout << getEmailAddress() << " || ";
            cout << getAge() << " || ";
            cout << getRemainingDays() << " || ";
            cout << degreeProgramString[getDegreeProgram()] << " || ";
            cout << "                                                       " << endl;
        };
        string Student::getStudentID() {
            return studentID;
        }
        int Student::getAge() {
            return age;
        }

        string Student::getRemainingDays() {
            string remainingDaysContainer = "";
            for (int i = 0; i < sizeof(remainingDays) / sizeof(remainingDays[0]); i++) {
            remainingDaysContainer += std::to_string(remainingDays[i]) + ", ";
            };
            remainingDaysContainer.resize(remainingDaysContainer.size() - 2);
            return remainingDaysContainer;
        }

        string Student::getFirstName() {
            return firstName;
        }
        string Student::getLastName() {
            return lastName;
        }
        string Student::getEmailAddress() {
            return emailAddress;
        }
        DegreeProgram Student::getDegreeProgram() {
            return degreeProgram;
        }

        // Setters
        void Student::setStudentID(string studentID) {
            this->studentID = studentID;
        }
        void Student::setAge(int age) {
            this->age = age;
        }
        
        void Student::setRemainingDays(int remainingDays, int j) {
            this->remainingDays[j] = remainingDays;
        }
        void Student::setFirstName(string firstName) {
            this->firstName = firstName;
        }
        void Student::setLastName(string lastName) {
            this->lastName = lastName;
        }
        void Student::setEmailAddress(string emailAddress) {
            this->emailAddress = emailAddress;
        }
        void Student::setDegreeProgram(DegreeProgram degreeProgram) {
            this->degreeProgram = degreeProgram;
        }
