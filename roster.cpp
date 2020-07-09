/*
	C867 Scripting and Programming - Applications
	JYM1 — JYM1 TASK 1: CLASS ROSTER
	Tim Roberts
	Student ID# #001345394
*/

#include "roster.h"
#include "student.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*

E.  Create a Roster class (roster.cpp) by doing the following:
    1.  Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
    2.  Create a student object for each student in the data table and populate classRosterArray.
        a.  Parse each set of data identified in the “studentData Table.”
        b.  Add each student object to classRosterArray.
    3.  Define the following functions:
        a.  public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)  that sets the instance variables from part D1 and updates the roster.
        b.  public void remove(string studentID)  that removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.
        c. public void printAll() that prints a complete tab-separated list of student data in the provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.
        d.  public void printAverageDaysInCourse(string studentID)  that correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
        e.  public void printInvalidEmails() that verifies student email addresses and displays all invalid email addresses to the user.
 
            Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
        
        f.  public void printByDegreeProgram(DegreeProgram degreeProgram) that prints out student information for a degree program specified by an enumerated type.
*/

Roster::Roster(const string studentData[], int sizeofStudentData, int maxCapacity) {
// E1. Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
    this->studentCount = sizeofStudentData;
    this->classRosterArray = new Student*[maxCapacity];
    this->maxCapacity = maxCapacity;
    
    //E2a. Parse tokens (string)
    int records = 0;
    while (records < sizeofStudentData){
        // Vector of string to save tokens
        vector <string> tokens;
        // stringstream: The string stream associates a string object with a string.
        // Using this the string can be read as if it were a stream like "cin".
        stringstream streamInput(studentData[records]);
        string nextToken;
        // Tokenizing with respect to comma  ','
        while(getline(streamInput, nextToken, ',')) {
            tokens.push_back(nextToken);
        }
        
        // convert strings to int
        int daysToComplete[3] = {std::stoi(tokens[5]), std::stoi(tokens[6]), std::stoi(tokens[7])};
        int age = std::stoi(tokens[4]);
        
        // convert string to enum
        DegreeProgram degreeProgram = UNDETERMINED;
        if (tokens[8].compare("SECURITY") == 0) {
            degreeProgram = SECURITY;
        }
        else if (tokens[8].compare("NETWORK") == 0){
            degreeProgram = NETWORK;
        }
        else if (tokens[8].compare("SOFTWARE") == 0){
            degreeProgram = SOFTWARE;
        }
        else{
            degreeProgram = UNDETERMINED;
        }

        //E2 and 2b. Add each student object to classRosterArray.
        classRosterArray[records] = new Student(tokens[0], tokens[1], tokens[2], tokens[3], age, daysToComplete, degreeProgram);
        records++;
    }
}

//F5.  Implement the destructor to release the memory that was allocated dynamically in Roster.
Roster::~Roster(){
    delete[] classRosterArray;
}

// Implements add.
void Roster::add(string id, string fName, string lName, string eMail, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int daysToComplete[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    classRosterArray[studentCount] = new Student(id, fName, lName, eMail, age, daysToComplete, degreeProgram);
    studentCount++;
}


// E3b. Implements remove. Removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.
// last element of the array is then assigned to the removed slot. (There seems to be no requirement that the roster remains in the same order).
void Roster::remove(string id){
    bool idFound = false;
    for (int i = 0; (i < studentCount) && !idFound; ++i) {
        if(classRosterArray[i]->GetId() == id) {
            classRosterArray[i] = classRosterArray[studentCount - 1];
            --studentCount;
            idFound = true;
        }
    }
    if (idFound){
        cout << "Student ID " << id << " found and removed." << endl;
    }
    else {
        cout << "Error: student with this ID not found." << endl;
    }
}

// E3c. Implement printall. that prints a complete tab-separated list of student data in the provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.
void Roster::printAll(){
    for (int i = 0; i < studentCount; ++i) {
        classRosterArray[i]->print();
    }
}

// E3d. Implements printAverageDaysInCourse. Prints a student’s average number of days in the three courses. The student is identified by the id parameter.
void Roster::printAverageDaysInCourse(string id){
    for (int i = 0; i < studentCount; ++i) {
        if (classRosterArray[i]->GetId() == id) {
            cout << "Student ID " << classRosterArray[i]->GetId() << ": ";
            int *days = classRosterArray[i]->GetDaystoComplete();
            cout << "Average number of days in courses: " << (days[0] + days[1] + days[2]) / 3 << endl;
            return;
        }
    }
}

// E3e. Implements printInvalidEmails.  Verifies student email addresses and displays all invalid email addresses to the user.
void Roster::printInvalidEmails() {
    for (int i = 0; i < studentCount; ++i) {
        string email = classRosterArray[i]->GetEmail();
        u_long arroba = email.find('@');
        u_long period = email.find('.', arroba);
        // if @ is not found
        if (arroba == string::npos) {
            cout << "Invalid email. Missing an @ symbol:" << email << endl;
        }
        // if period is not found
        else if (period == string::npos) {
            cout << "Invalid email. Missing a '.' : " << email << endl;
        }
        // if a space is found
        else if (email.find(' ') != string::npos) {
            cout << "Invalid email. Spaces are not allowed in emails: " << email << endl;
        }
    }
}
    
// E3f. Implements printByDegreeProgram. Prints out student information for a degree program specified by an enumerated type.
void Roster::printByDegreeProgram(DegreeProgram degreeProgram){
    for (int i = 0; i < studentCount; ++i) {
        if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}