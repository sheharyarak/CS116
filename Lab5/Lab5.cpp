#include <iostream>
#include <string>
#include "Account.hpp"
#include "Savings.hpp"
#include "Checking.hpp"
#include "printmefirst.hpp"

using namespace std;

/*Use the code below and modified the code to implement the requirement
of the lab*/

/*
Use the following test template to test your program
*/
int main()
{
 printMeFirst("Sheharyar","CS-116");
 Checking c = Checking(1000.0);
 Savings s = Savings(1000.0);
 for (int i = 1; i <= DAYS_PER_MONTH; i++)
 {
 c.deposit(i * 5);
 c.withdraw(i * 2);
 s.deposit(i * 5);
 s.withdraw(i * 2);
 c.dailyInterest();
 s.dailyInterest();
 if (i % 10 == 0) // use % to only print out days 10, 20, 30
 {
 cout << "day " << i << "\n";
 cout << "Checking balance: " << c.getBalance() << "\n";
 cout << "Savings balance: " << s.getBalance() << "\n";
 }
 }
 return 0;
}
