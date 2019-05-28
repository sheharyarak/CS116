/**
 *TODO:The purpose of this program is to keep track of employee information such as name, ID number, Departmant, and position
 @param name - Sheharyar Khan
 @param courseInfo - CS-116
 @return - none
*/

#include <iostream>
#include "header.hpp" //using a header file for the class and the functions
#include "printmefirst.hpp" //using a separate header file for the print me first function as it will probably be used in every project for this course and this would be easier than copying the code over and over again. I also wanted to apply what I learned today in class

using namespace std;

int main()
{
 printMeFirst ("Sheharyar Khan", "CS - 116: Lab 2"); //put your name instead of “Ron Sha”
 // Create an Employee object to test constructor #1.
 Employee susan ("Susan Meyers", 47899, "Accounting", "Vice President");
 // Create an Employee object to test constructor #2.
 Employee mark ("Mark Jones", 39119);
 mark.setDepartment("IT");
 mark.setPosition("Programmer");
 // Create an Employee object to test constructor #3.
 Employee joy;
 joy.setName("Joy Rogers");
 joy.setIdNumber(81774);
 joy.setDepartment("Manufacturing");
 joy.setPosition("Engineer");

 // Display each employee's data.
 displayEmployee(susan);
 displayEmployee(mark);
 displayEmployee(joy);
 
 return 0;
}