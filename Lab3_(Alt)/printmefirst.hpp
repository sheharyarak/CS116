#ifndef PRINTMEFIRST_H
#define PRINTMEFIRST_H

#include <iostream>
#include <string>
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