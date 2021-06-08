#include "Account.h"

Account::Account(std::string name, double balance) 
    : name{name}, balance{balance} {
}

//Removing because adding the same functionality to print function below
/*std::ostream &operator<<(std::ostream &os, const Account &account) {
    os << "[Account: " << account.name << ": " << account.balance << "]";
    return os;
}*/

void Account::print(std::ostream &os) const //Needed to fully qualify with Account:: and keep const
{
	//formatting
	os.precision(2);
	os << std::fixed;
	os << "[Account: " << name << ": " << balance << "]"; //remove account. since we are now a member method
}

//SHOULD NOT HAVE DELETED THESE

bool Account::deposit(double amount)
{
	if (amount < 0)
		return false;
	else
	{
		balance += amount;
		return true;
	}
}

bool Account::withdraw(double amount)
{
	if (balance-amount >= 0)
	{
		balance -= amount;
		return true;
	}
	else
		return false;
}
