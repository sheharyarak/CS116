/**
 *TODO:To perform calculations with classes and practice overloading operators
 @param name - Sheharyar Khan
 @param courseInfo - CS-116
 @return - none
*/

#include <iostream>
#include <string>
#include <cmath>
#include "printmefirst.hpp"
#include "moneyclass.hpp"

int main()
{
 Money m1(8, 75); // set dollars to 8 and cents to 75
 Money m2 (5, 80); // set dollars to 5 and cents to 80
 Money m3; // initialize dollars to 0 and cents to 0

 printMeFirst("Sheharyar Khan", "CS-116 2018 Fall - Lab Money"); // use your name
 //multiply by 2
 cout << m1 << " * 2 = " << (m1 * 2) << "\n";
 //subract
 cout << m1 << " - " << m2 << " = " << (m1 - m2) << "\n";
 //addition
 m3 = m1 + m2;
 cout << m1 << " + " << m2 << " = " << m3 << "\n";
 if (m1 < m2) // check to see if Money object m1 is less than m2 or not
 cout << m1 << " < " << m2 << "\n";
 else
 cout << m1 << " > " << m2 << "\n";
 m1.setValue(10,1); // set m1.dollars to 10; m1.cents to 1
 m2.setValue(10,1);
 //checks if equals
 if (m1 == m2)
cout << m1 << " equals to " << m2 << endl;
 else
 cout << m1 << " NOT equals to " << m2 << endl;
 m2.setValue(10,45);
 if (m1 == m2) // compare Money object m1 and m2
cout << m1 << " equals to " << m2 << endl;
 else
 cout << m1 << " NOT equals to " << m2 << endl;
 return 0;
}
