// Section 16 
// Challenge 
#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std; 


int main() 
{
    
	
	//Account joe; 			cannot do this since Account class is abstract
	

	
/*	Savings_Account larry {"Larry", 5000, 2.6};
	cout << s << endl;
	s.deposit(10000);
	cout << s <<endl;
	s.withdraw(10000);
	cout << s << endl;*/
	
	Checking_Account frank {"Frank, 5000"};
	cout << frank << endl;  	//prints [Checking_Account: Unnamed Checking Account: 0].  works because we are not using base class pointer
	
	Account *ptr = new Trust_Account("Leo", 10000, 2.6); //Create a pointer to type Account and assign newly created Trust account on heap to point to it.
															//valid because Trust Account is child of Account.  However, when this runs we are only getting the 
															//Account part of the object and not Trust, because it is statically bound.  Object is being sliced
															//Fix this by using interface class I_Printable.  ACccount will derive from I_Printable, and all concrete classes
															//implement their own printing functionality inherited from I_Printable
	cout << *ptr << endl;
	
	//Below we proceed with dynamic binding
	
	//Create pointers to Account on heap of whatever child class we want
	Account *p1 = new Checking_Account("Larry", 10000);
	Account *p2 = new Savings_Account("Moe", 1000);
	Account *p3 = new Trust_Account("Curly");
	
	//store them in a vecotr of pointers to type Account, named accounts
	std::vector<Account *> accounts {p1, p2, p3};
	
	//call Util functions on the vector
	display(accounts);
	deposit(accounts, 1000);
	withdraw(accounts, 2000);
	
	display(accounts);
	
	//clean up pointers
	delete p1;
	delete p2;
	delete p3;
	
	return 0;
	
	fruits [];
	
	
	
	
   
    //BELOW IS STATIC BINDING, REMOVED
/*    // Savings 

    vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account {} );
    sav_accounts.push_back(Savings_Account {"Superman"} );
    sav_accounts.push_back(Savings_Account {"Batman", 2000} );
    sav_accounts.push_back(Savings_Account {"Wonderwoman", 5000, 5.0} );

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts,2000);
   
   // Checking
   
    vector<Checking_Account> check_accounts;
    check_accounts.push_back(Checking_Account {} );
    check_accounts.push_back(Checking_Account {"Kirk"} );
    check_accounts.push_back(Checking_Account {"Spock", 2000} );
    check_accounts.push_back(Checking_Account {"Bones", 5000} );

    display(check_accounts);
    deposit(check_accounts, 1000);
    withdraw(check_accounts, 2000);

    // Trust
  
    vector<Trust_Account> trust_accounts;
    trust_accounts.push_back(Trust_Account {} );
    trust_accounts.push_back(Trust_Account {"Athos", 10000, 5.0} );
    trust_accounts.push_back(Trust_Account {"Porthos", 20000, 4.0} );
    trust_accounts.push_back(Trust_Account {"Aramis", 30000} );

    display(trust_accounts);
    deposit(trust_accounts, 1000);
    withdraw(trust_accounts, 3000);
    
    // Withdraw 5 times from each trust account
    // All withdrawals should fail if there are too many withdrawals or if the withdrawl is > 20% of the balance
    for (int i=1; i<=5; i++)
        withdraw(trust_accounts, 1000);*/
}

