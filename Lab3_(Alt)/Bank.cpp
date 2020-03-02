#include <iostream>
#include "Bank.h"

using namespace std;

		Bank::Bank()
		{
			checking.withdraw(checking.getBalance());
			savings.withdraw(savings.getBalance());
		}
		Bank::Bank(double checkingAmount, double savingsAmount)
		{
			checking.deposit(checkingAmount);			
			savings.deposit(savingsAmount);			
		}
void	Bank::deposit(double amount, string account)
{
	if(account == "S")
		savings.deposit(amount);
	else
		checking.deposit(amount);
}
void	Bank::withdraw(double amount, string account)
{
	if(account == "S")
		savings.withdraw(amount);
	else
		checking.withdraw(amount);
}
void	Bank::transfer(double amount, string account)
{
	if(account == "S")
	{
		savings.withdraw(amount);
		checking.deposit(amount);
	}
	else
	{
		checking.withdraw(amount);
		savings.deposit(amount);
	}
}
void	Bank::printBalances() const
{
	cout	<< "Checking Amount: "	<< checking.getBalance()
	<< endl << "Savings Amount: "	<< savings.getBalance();
}