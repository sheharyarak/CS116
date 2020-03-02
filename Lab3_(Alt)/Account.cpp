#include "Account.h"
		Account::Account()
		{
			balance = 0;
		}
		Account::Account(double bal)
		{
			balance = bal;
		}
void	Account::deposit(double amount) // need to implement member function program
{
	balance += amount;
}
void	Account::withdraw(double amount)
{
	if(amount <= balance)
	{
		balance -= amount;
	}
}
double	Account::getBalance() const
{
	return balance;
}