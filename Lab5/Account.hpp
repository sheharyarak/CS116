#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

int const DAYS_PER_MONTH = 30;
double const SAVING_RATE = 0.06;

using namespace std;
//You need to implement all the member functions for the class Account
//..................................................................
class Account
{
public:
 Account(); // doing nothing
 Account(double b); // set balance to b
 void deposit(double amount); // balance is increased by amount
 void withdraw(double amount); // balance is reduced by amount
 // make sure you can’t withdraw if
 // amount is larger than balance
 double getBalance() const; // return the account balance
 void setBalance(double b);
private:
 double balance;
};
Account::Account()
{

}

Account::Account(double b)
{
    balance = b;
}
void Account::deposit(double amount)
{
    balance += amount;
}

void Account::withdraw(double amount)
{
    if(amount>balance)//only withdraws if balance is greater than the amount to be withdrawn
    {
        cout<<"insufficient funds. please enter a lower amount."<<endl;
    }
    else
    {
        balance-=amount;
    }
}
double Account::getBalance() const {//for accessing the balance attribute. is const because we dont wanna change it
    return balance;
}

void Account::setBalance(double b){//for setting the value of balance in the checking/savings constructor
    balance = b;
}
#endif