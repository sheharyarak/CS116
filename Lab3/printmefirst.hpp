#ifndef PRINTMEFIRST_H
#define PRINTMEFIRST_H

/**
 *TODO:The purpose of this program is to keep track of employee information such as name, ID number, Departmant, and position
 @param name - Sheharyar Khan
 @param courseInfo - CS-116
 @return - none
*/

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void printMeFirst(string name, string courseInfo)
{
cout <<" Program written by: "<< name << endl; // put your name here
cout <<" Course info: "<< courseInfo << endl;
time_t now = time(0); // current date/time based on current system
char* dt = ctime(&now); // convert now to string for
 cout << " Date: " << dt << endl;
}

#endif