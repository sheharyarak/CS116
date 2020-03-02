#ifndef BANK_H
#define BANK_H

#include "Account.h"
#include <iostream>
#include <string>

using namespace std;

const double PENALTY = 5;

class Bank
{
	public:
		Bank();
		Bank(double checkingAmount, double savingsAmount);
		void deposit(double amount, string account);
		void withdraw(double amount, string account);
		void transfer(double amount, string account);
		void printBalances() const;
	private:
		Account checking; // change ????? with correct data type variable checking
		Account savings; // use correct data type for variable savings
};

#endif