#include <iostream>
#include <string>
#include "roster.h"
using std::cout;
using std::endl;
using std::string;


// Destructor
        Roster::~Roster() {
            for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); i++) {
                classRosterArray[i] = nullptr;
            };
};
        // Constructor
        Roster::Roster() {
        };
        void Roster::parseData(string str) {
            // arr[] stores the studentID, firstName, lastName, and emailAddress
            string arr[4] = {};


            //This variable stores the degree program
            DegreeProgram degreeProgram = DegreeProgram::NETWORK;


            /*
            numArr[1-3] is a placeholder for the remaining course days for each student and
            numArr[0] stores the students' age
            */
            int numArr[4] = {};
            int courseDaysArr[3] = { numArr[1], numArr[2], numArr[3] };

            /*
            This variable is a container for the words that are parsed from str.
            The argument str in this function one of the values from studentData[]
            (This function is being looped over in main().)
            */
            string word = "";

            /*
            These nested loops parses the string provided.
            Once x == ',' it stops parsing and adds it to arr[i].
            After every instance of ',' it clears the word variable so that there
            is room for the next word in the string.
            */
            int i = 0;
            int y = 0;


            string dProgram = "";
            while (i < 10) {
                for (char x : str) {
                    if (i < 4 && x == ',') {
                        arr[i] = word;
                        i++;

                        word = "";

                    }
                    else if (i >= 4 && i < 8 && x == ',') {
                        numArr[y] = stoi(word);
                        word = "";
                        i++;
                        y++;

                    }
                    else if (i >= 8) {
                        word += x;
                        dProgram = word;
                        i++;

                    }
                    else {
                        word += x;
                    }

                    /*
                    This for loop skips numArr[0] and adds numArr[1-3] to courseDaysArr[].
                    I did this because numArr[0] stores the students' age.
                    */
                    for (int j = 0; j < 3; j++) {
                        courseDaysArr[j] = numArr[j + 1];
                    };
                }
            }
            if (dProgram == "SOFTWARE") {
                degreeProgram = DegreeProgram::SOFTWARE;
            }
            else if (dProgram == "SECURITY") {
                degreeProgram = DegreeProgram::SECURITY;
            };

            /*
            This method add the students to the classRoster object
            */
            add(arr[0], arr[1], arr[2], arr[3], numArr[0], courseDaysArr[0], courseDaysArr[1], courseDaysArr[2], degreeProgram);

        }
        void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
            int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
            int numArr[3] = {daysInCourse1, daysInCourse2, daysInCourse3};

            classRosterArray[index] = new Student(studentID, age, numArr, firstName, lastName, emailAddress, degreeProgram);
            index++;
        };

        /* This function deletes the information in the student object, 
        via the classRosterArray, by studentID
        */
        void Roster::remove(string studentID) {
            bool found = false;
            for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); i++) {
                if (classRosterArray[i] != nullptr) {
                    string studentIDContainer = classRosterArray[i]->getStudentID();
                    int y = i + 1;
                    if (studentIDContainer == studentID) {
                        found = true;
                        classRosterArray[i] = nullptr;
                        cout << studentID + " has been successfully deleted from the roster" << endl;
                    }
                };
             
            };
            if (!found) {
                cout << "Error: Student ID was not found" << endl;
            };
        };

        // This method prints all student information via classRosterArray
        void Roster::printAll() {
            char ID = 'A';
            cout << "==============================================================================" << endl;
            cout << " || ID || First || Last ||        Email        || Age || Days in Course || Degree ||" << endl;
            for(int i = 0; i < sizeof(classRosterArray)/sizeof(classRosterArray[0]); i++){
                if (classRosterArray[i] != nullptr) {
                    if (classRosterArray[i]->getStudentID().find(ID) != std::string::npos) {
                        classRosterArray[i]->print();
                    };
                }
            };
            cout << "==============================================================================" << endl;
        };
        
        // This method prints the average of the course completion days for each student
        int Roster::printAverageDaysInCourse(string studentID) {

            string daysInCourseContainer = "";
            string IDValue = "";
            string output = "";
            int numArr[3] = {};
            int sum = 0;
            int average = 0;
            for(int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); i++) {
                IDValue = classRosterArray[i]->getStudentID();
                /* 
                This checks if the provided studentID is in the table. 
                If it is, store the remaining days in the daysInCourseContainer
                */
                if (studentID == IDValue) {
                    daysInCourseContainer = classRosterArray[i]->getRemainingDays();
                    for(int i = 0; i < daysInCourseContainer.size(); ++i) {
                        if(daysInCourseContainer[i] != ',' & daysInCourseContainer[i] != ' ') {
                            output += daysInCourseContainer[i];
                            if(output.size() == 2) {
                                numArr[i] = stoi(output);

                                sum += numArr[i];
                                output = "";
                            };

                        };
                    };
                } 
                /* 
                I don't think I need an else statement here, theres a for loop 
                in main() on line 77 that loops over this method. If I manually passed the 
                location, then I would need an else statement in case the 
                location didn't exist.
                */
            };

            average = sum / (sizeof(numArr) / sizeof(numArr[0]));
            return average;
        }

        /* 
        This method prints all of the emails that are invalid. It checks if the emails 
        contain an '@' and a ','. If they do not contain these characters or if it contains
        ' ', it prints "This email is invalid." 
        */
        void Roster::printInvalidEmails() {
            for(int i = 0; i < sizeof(classRosterArray)/sizeof(classRosterArray[0]); i++){

                int y = 0;
                string word = "";

                //Stores the email address
                string emailAddressContainer = classRosterArray[i]->getEmailAddress();

                // These are the checks
                char spaceChar = ' ';
                char atSymbolChar = '@';
                char periodChar = '.';

                // Loops over each character of emailAddressContainer
                while(y < 1){
                for (char x : emailAddressContainer) {
                    if (x == spaceChar) {
                        cout << classRosterArray[i]->getStudentID() << ": " << emailAddressContainer << " <- This email is invalid."<< endl;
                        break;
                        y++;
                        word = "";
                    }  else {
                        word += x;
                        y++;
                    }
                    if (emailAddressContainer.find(atSymbolChar) != std::string::npos) {
                        y++;
                        } else {
                        cout << classRosterArray[i]->getStudentID() << ": " << emailAddressContainer << " <- This email is invalid."<< endl;
                        break;
                        y++;
                        }
                    if (emailAddressContainer.find(periodChar) != std::string::npos) {
                        y++;
                        } else {
                        cout << classRosterArray[i]->getStudentID() << ": " << emailAddressContainer << " <- This email is invalid."<< endl;
                        break;
                        y++;
                        }
                };
            };
        };
 

    };

        /* 
        This method loops over classRosterArray[] and finds all instances of degreeProgram. 
        For each instance it prints the student information.
        */
        void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
            bool found = false;
            for(int i = 0; i < sizeof(classRosterArray)/sizeof(classRosterArray[0]); i++){
                int y = 0;
                DegreeProgram degreeProgramContainer = classRosterArray[i]->getDegreeProgram();
                string word = "";
                if(degreeProgramContainer == degreeProgram) {
                    classRosterArray[i]->print();
                    found = true;
                };
            };
            if (!found) {
                cout << "Student with degree program of __ not found" << endl;
                };
        }


