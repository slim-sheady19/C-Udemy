#ifndef CHEQUING_ACCOUNT_H
#define CHEQUING_ACCOUNT_H

#include "Account.h" // Base class: Account.h

class Chequing_Account : public Account
{
	friend std::ostream &operator<<(std::ostream &os, const Chequing_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Chequing Account";
    static constexpr double def_balance = 0.0;
	
public:
	Chequing_Account(std::string name = def_name, double balance = def_balance);    
    bool withdraw(double amount);
    
};

#endif // CHEQUING_ACCOUNT_H
