// Section 15
// Challenge 
#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Account_Util.h"
#include "Chequing_Account.h"

using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;
   
    // Accounts
    vector<Account> accounts;
    accounts.push_back(Account {});
    accounts.push_back(Account {"Larry"});
    accounts.push_back(Account {"Moe", 2000} );
    accounts.push_back(Account {"Curly", 5000} );
    
    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts,2000);
    
    // Savings 

    vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account {} );
    sav_accounts.push_back(Savings_Account {"Superman"} );
    sav_accounts.push_back(Savings_Account {"Batman", 2000} );
    sav_accounts.push_back(Savings_Account {"Wonderwoman", 5000, 5.0} );

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);
	
	//Chequings
    
	vector<Chequing_Account> chq_accounts;
    chq_accounts.push_back(Chequing_Account {});
    chq_accounts.push_back(Chequing_Account {"Phil"});
    chq_accounts.push_back(Chequing_Account {"Lucy", 3000} );
    chq_accounts.push_back(Chequing_Account {"Jill", 6000} );
	
	display(chq_accounts);
    deposit(chq_accounts, 1000);
    withdraw(chq_accounts, 2000);
	
	//Trust Accounts
	
	vector<Trust_Account> tru_accounts;
    tru_accounts.push_back(Trust_Account {});
    tru_accounts.push_back(Trust_Account {"Rachel"});
    tru_accounts.push_back(Trust_Account {"Shea", 3000, 3.0} );
    tru_accounts.push_back(Trust_Account {"JillyBean", 6000, 5.0} );

	display(tru_accounts);
    deposit(tru_accounts, 50000);
    withdraw(tru_accounts, 53000);

    return 0;
}

