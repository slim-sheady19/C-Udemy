#include "Chequing_Account.h"

Chequing_Account::Chequing_Account(std::string name, double balance)
	: Account {name, balance} //use base constructor
{
	
}

bool Chequing_Account::withdraw(double amount)
{
	amount = (amount+1.50);
	return Account::withdraw(amount);
}

std::ostream &operator<<(std::ostream &os, const Chequing_Account &account) {
    os << "[Chequing_Account: " << account.name << ": " << account.balance << "]";
    return os;
}

