/*
	C867 Scripting and Programming - Applications
	JYM1 — JYM1 TASK 1: CLASS ROSTER
	Tim Roberts
	Student ID# #001345394
*/

#ifndef roster_h
#define roster_h

#include <stdio.h>
#include <iostream>
#include "student.h"
#include "degree.h"

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

class Roster {
public:
    Roster(const string studentData[], int sizeofStudentData, int maxCapacity);
    ~Roster();
    void ParseId(string data);

    //E3a through f Define the following functions:
    void add(string id, string fName, string lName, string eMail, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(string id);
    void printAll();
    void printAverageDaysInCourse(string id);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);

// assuming that there is a max capacity of students on the roster
private:
    int maxCapacity;
    int studentCount;
    Student* *classRosterArray;
};

#endif /* roster_h */






