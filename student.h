/*
	C867 Scripting and Programming - Applications
	JYM1 — JYM1 TASK 1: CLASS ROSTER
	Tim Roberts
	Student ID#001345394
*/

#ifndef student_h
#define student_h
#include "degree.h"
#include <string>
#include <iostream>

using namespace std;

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

#define daysNumArray 3

class Student {
public:
 //Full Constructor
    Student(string id, string fName, string lName, string eMail, int age, int daysToComplete[], DegreeProgram degreeProgram);
    ~Student();//Empty Constructor

//The Getters
    string GetId();
    string GetfName();
    string GetlName();
    string GetEmail();
    int GetAge();
    int *GetDaystoComplete();
    DegreeProgram GetDegreeProgram();

//The Setters
    void SetId(string id);
    void SetfName(string fName);
    void SetlName(string lName);
    void SetAge(int age);
    void SetEmail(string eMail);
    void SetDaystoComplete(int daysToComplete[]);
    void SetDegreeProgram(DegreeProgram degreeProgram);

//print() to print the student data
    void print();

//Private Items are ccessible only internally
private:
    string id;
    string fName;
    string lName;
    int age;
    string eMail;
    int *daysToComplete;
    DegreeProgram degreeProgram;
};

#endif /* student_hpp */
