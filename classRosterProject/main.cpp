#include <iostream>
#include <string>
#include <windows.h>
#include "roster.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

/*This function parses the data in the studentData[] in main() and
adds the students to the roster object*/

/* Prints out the course title, project name, 
programming language used, my name, and my student ID.
*/
void intro() {
        cout << "||===================================================||" << endl;
        cout << "||Scripting and Programming - Applications -- C867   ||" << endl;
        cout << "||Class Roster Project                               ||" << endl;
        cout << "||(made in C++)                                      ||" << endl;
        cout << "||===================================================||" << endl;
        cout << "||by Joshua Washington                               ||" << endl;
        cout << "||ID: 009015794                                      ||" << endl;
        cout << "||===================================================||" << endl;
        cout << "                                                       " << endl;
    };

int main() {
    string studentData[] = 
   {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
   "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
   "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
   "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
   "A5,Joshua,Washington,jwas249@wgu.edu,21,14,32,24,SOFTWARE"};

    Roster classRoster;

    Student johnSmith;
    Student suzanErickson;
    Student jackNapoli;
    Student erinBlack;
    Student joshuaWashington;

    /*
    classRoster.classRosterArray stores the addresses for each student
    */
    classRoster.classRosterArray[0] = &johnSmith;
    classRoster.classRosterArray[1] = &suzanErickson;
    classRoster.classRosterArray[2] = &jackNapoli;
    classRoster.classRosterArray[3] = &erinBlack;
    classRoster.classRosterArray[4] = &joshuaWashington;

    /*
    This loop adds all of the student data from studentData[] to classRoster
    */
    for(int i = 1; i < sizeof(studentData)/sizeof(studentData[0]) + 1; i++) {
    classRoster.parseData(studentData[i - 1]);
    }

    // I added Sleep() in-between each method call so that the application is "smoother"
    // (It's better to see the information slowly rather than all at once for this application)
    intro();

    Sleep(3000);

    classRoster.printAll();
    cout << " " << endl;

    Sleep(3000);

    classRoster.printInvalidEmails();
    cout << " " << endl;

    Sleep(3000);

    // Loops over classRoster.classRosterArray[] and prints the average days for each student individually
    for(int i = 0; i < sizeof(classRoster.classRosterArray)/sizeof(classRoster.classRosterArray[0]); i++) {
        string IDContainer = classRoster.classRosterArray[i]->getStudentID();
        cout << "Average days for " << IDContainer << ": " << classRoster.printAverageDaysInCourse(IDContainer) << endl;
    };
    cout << " " << endl;

    Sleep(3000);

    cout << "Searching for students with degree program of 'SOFTWARE'..." << endl;
    Sleep(3000);

    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    cout << " " << endl;

    Sleep(3000);

    cout << "Deleting 'A3' from table..." << endl;
    Sleep(3000);

    classRoster.remove("A3");
    cout << " " << endl;

    Sleep(3000);

    classRoster.printAll();
    cout << " " << endl;

    Sleep(3000);

    cout << "Deleting 'A3' from table..." << endl;
    Sleep(3000);

    classRoster.remove("A3");
    cout << " " << endl;
    cout << "Program has finished all tasks." << endl;

    return 0;   
}