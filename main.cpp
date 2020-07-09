/*
	C867 Scripting and Programming - Applications
	JYM1 — JYM1 TASK 1: CLASS ROSTER
	Tim Roberts
	Student ID#001345394
*/
#include <iostream>
#include "student.h"
#include "roster.h"

using namespace std;

/*
F.  Demonstrate the program’s required functionality by adding a main() function in main.cpp, which will contain the required function calls to achieve the following results:
    1.  Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
    2.  Create an instance of the Roster class called classRoster.
    3.  Add each student to classRoster.
    4.  Convert the following pseudo code to complete the rest of the  main() function:
        classRoster.printAll();
        classRoster.printInvalidEmails();
        //loop through classRosterArray and for each element:

        classRoster.printAverageDaysInCourse(current_object's student id);
        classRoster.printByDegreeProgram(SOFTWARE);
        classRoster.remove("A3");
        classRoster.printAll();
        classRoster.remove("A3");
        //expected: the above line should print a message saying such a student with this ID was not found.
    5.  Implement the destructor to release the memory that was allocated dynamically in Roster.

*/


int main()
{
    //F1.  Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.

    cout << "--------------------------------------------"  << endl;
    cout << "C867: Scripting and Programming Applications"  << endl;
    cout << "Language used: C++"                            << endl;
    cout << "ID: 001345394"                                 << endl;
    cout << "Tim Roberts"                                   << endl;
    cout << "--------------------------------------------"  << endl;
    cout << endl;
    //A.  Modify the “studentData Table” to include your personal information as the last item.
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Tim,Roberts,trob522@wgu.edu,50,14,14,14,SOFTWARE"
    };

    //F2.  Create an instance of the Roster class called classRoster. MaxCapacity of the roster (max number of students) is set to 20.
    Roster* classRoster = new Roster (studentData, 5, 20);
    
    //F4.  Convert the following pseudo code to complete the rest of the  main() function:
    //classRoster.printAll();
    cout << "Outputting the full roster of students:" << endl;
    classRoster->printAll();
    cout << endl;
    
    //Add
    //classRoster->add("A6","Chloe","Ramos","chloe@catsuniversity.edu",11,30,31,32,SOFTWARE);
    
    //classRoster.printInvalidEmails();
    cout << "The following emails are invalid:" << endl;
    classRoster->printInvalidEmails();
    cout << endl;

    //loop through classRosterArray and for each element:
    //classRoster.printAverageDaysInCourse(/*current_object's student id*/);
    cout << "Average days spent in courses: " << endl;
    classRoster->printAverageDaysInCourse("A1");
    classRoster->printAverageDaysInCourse("A2");
    classRoster->printAverageDaysInCourse("A3");
    classRoster->printAverageDaysInCourse("A4");
    classRoster->printAverageDaysInCourse("A5");
    cout << endl;

    
    //classRoster.printByDegreeProgram(SOFTWARE);
    cout << "Displaying roster by SOFTWARE program:" << endl;
    classRoster->printByDegreeProgram(SOFTWARE);
    cout << endl << "Displaying roster by NETWORK program:" << endl;
    classRoster->printByDegreeProgram(NETWORK);
    cout << endl << "Displaying roster by SECURITY program:" << endl;
    classRoster->printByDegreeProgram(SECURITY);
    cout << endl << endl;

    //classRoster.remove("A3");
    classRoster->remove("A3");
    
    // classRoster.printAll(); again
    classRoster->printAll();
    
    // classRoster.remove("A3"); again
    classRoster->remove("A3");
    cout << endl;
    //expected: the above line should print a message saying such a student with this ID was not found.

   
}


