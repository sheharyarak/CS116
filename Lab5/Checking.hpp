#ifndef CHECKING_H
#define CHECKING_H

#include "Account.hpp"
#include <iostream>
#include <string>

using namespace std;
/**
 Determine the daily interest and deposit it into the account.
 Checking accounts yield interest of 3 percent monthly on balances over $1,000.

 Calling dailyInterest() will calculate daily interest and add the daily interest to
 the balance
*/
// define class Checking which will inheritance class
// object Account – modify ????? below with correct code
class Checking: public Account // modify ?????? with correct code to inherent Account
{
public:
 Checking(); // doing nothing
 Checking(double b); // set balance to b
 void dailyInterest();
};
//You need to implement all the member functions for the class Checking
void Checking::dailyInterest()
{   
    double balance= getBalance();
    const double RATE = 0.03;
    const double MIN_BALANCE = 1000;

    if (balance>MIN_BALANCE)
    {   // balance - min balance because interest is calculated on the amount of money above the minimum balance
        double amount =((balance-MIN_BALANCE)*RATE)/DAYS_PER_MONTH;
        deposit(amount);
    }
}
Checking::Checking(double b)
{
    setBalance(b);
}

#endif