/*
	C867 Scripting and Programming - Applications
	JYM1 — JYM1 TASK 1: CLASS ROSTER
	Tim Roberts
	Student ID#001345394
*/

#include "student.h"
#include "degree.h"
#include <string>
#include <iostream>


/*
D.  For the Student class, do the following:
    1.  Create the class Student  in the files student.h and student.cpp, which includes each of the following variables:
        •  student ID
        •  first name
        •  last name
        •  email address
        •  age
        •  array of number of days to complete each course
        •  degree program
2.  Create each of the following functions in the Student class:
        a.  an accessor (i.e., getter) for each instance variable from part D1
        b.  a mutator (i.e., setter) for each instance variable from part D1
        c.  All external access and changes to any instance variables of the Student class must be done using accessor and mutator functions.
        d.  constructor using all of the input parameters provided in the table
        e.  print() to print specific student data
*/

//Full Constructor
Student::Student(string id, string fName, string lName, string eMail, int age, int daysToComplete[], DegreeProgram degreeProgram) {
    this->id = id;
    this->fName = fName;
    this->lName = lName;
    this->age = age;
    this->eMail = eMail;
    this->daysToComplete = new int[daysNumArray];
    for (int i = 0; i < daysNumArray; i++) {
        this->daysToComplete[i] = daysToComplete[i];
    }
    this->degreeProgram = degreeProgram;
}

//garbage collection
Student::~Student(){
    delete[] daysToComplete;
}

//The Getters
string Student::GetId() {
    return id;
}

string Student::GetfName() {
    return fName;
}

string Student::GetlName() {
    return lName;
}

int Student::GetAge() {
    return age;
}

string Student::GetEmail() {
    return eMail;
}

int *Student::GetDaystoComplete() {
    return daysToComplete;
}
DegreeProgram Student::GetDegreeProgram() {
    return degreeProgram;
}


//The Setters
void Student::SetId(string id) {
    this->id = id;
    return;
}
void Student::SetfName(string fName) {
    this->fName = fName;
    return;
}
void Student::SetlName(string lName) {
    this->lName = lName;
    return;
}

void Student::SetAge(int age) {
    this->age = age;
    return;
}

void Student::SetEmail(string eMail) {
    this->eMail = eMail;
    return;
}

void Student::SetDaystoComplete(int daysToComplete[]) {
    for (int i = 0; i < daysNumArray; i++)  {
        this->daysToComplete[i] = daysToComplete[i];
    }
}

void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
    return;
}

//D2e. print() to print specific student data
//E3c. print in the provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security.
void Student::print() {
    cout << "ID:"               << id       << '\t';
    cout << "First name: "      << fName    << '\t';
    cout << "Last name: "       << lName    << '\t';
    cout << "Email: "           << eMail    << endl;
    cout << "Age: "             << age      << '\t';
    cout << "Days In Course: "  << "{" << daysToComplete[0] << "," <<  daysToComplete[1] << "," <<  daysToComplete[2] << "}" << '\t';
    cout << "Degree Program: ";
        switch(degreeProgram) {
        case SECURITY :
            cout << "SECURITY";
            break;
        case NETWORK :
            cout << "NETWORK";
            break;
        case SOFTWARE :
            cout << "SOFTWARE";
            break;
        case UNDETERMINED :
            cout << "OTHER";
            break;
    }
    cout << endl;
    return;

}