#ifndef SAVINGS_H
#define SAVINGS_H

#include "Account.hpp"
#include <iostream>
#include <string>

using namespace std;

// define class Savings which will inherit class
// object Account – modify ????? below with correct code
class Savings : public Account // modify ??? with correct code to inherent Account
{
public:
 Savings(); // doing nothing
 Savings(double b); // initialize balance to b
 void dailyInterest();
};
//You need to implement all the member functions for the class Savings
/** */

Savings::Savings(double b){
    setBalance(b);
}

/*
 Determine the daily interest and deposit it into the account.
*/
void Savings::dailyInterest()
{
 //
 // calculate the daily interest rate which is
 // balance * SAVING_RATE / DAYS_PER_MONTH
    double balance = getBalance();
    double amount =(balance*SAVING_RATE)/DAYS_PER_MONTH;

 // Then call member function to deposit the interest to the
 // balance
    deposit(amount);
}
//..................................................................


#endif