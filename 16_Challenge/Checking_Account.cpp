#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance)
    : Account {name, balance} {
}

bool Checking_Account::withdraw(double amount)
{
    amount += per_check_fee;
    return Account::withdraw(amount);
}

bool Checking_Account::deposit(double amount) //do not need virtual or override keywords in implementation
{
	return Account::deposit(amount);	//OK
}

void Checking_Account::print(std::ostream &os) const //forgot to fully qualify Checking_Account::
{
	os.precision(2);
	os << std::fixed;
	os << "[Checking_Account: " << name << ": " << balance << "]"; 
}

//removing because it's being added to print function
/*std::ostream &operator<<(std::ostream &os, const Checking_Account &account) {
    os << "[Checking_Account: " << account.name << ": " << account.balance  << "]";
    return os;
}*/

