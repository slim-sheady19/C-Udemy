#include <iostream> //allows input/output
using namespace std;

int main()
{
	const int dollar = 100;
	const int quarter = 25;
	const int dime = 10;
	const int nickel = 5;
	const int penny = 1;
	
	//variables for change to be received
	int dollars {0};
	int quarters {0};
	int dimes {0};
	int nickels {0};
	int pennies {0};
	
	cout << nickel << dollar << penny << dime << quarter << endl;
	
	int change {0};
	cout << "Enter an amount in cents: ";
	cin >> change;
	
	//first determine dollars to give
	
		dollars = change/dollar;
		change = change-(dollars*dollar);

		quarters = change/quarter;
		change = change-(quarters*quarter);

		dimes = change/dime;
		change = change-(dimes*dime);
	
		nickels = change/nickel;
		change = change-(nickels*nickel);
	
		pennies = change;
	
		cout << "dollars: " << dollars << endl;
		cout << "quarters: " << quarters << endl;
		cout << "dimes: " << dimes << endl;
		cout << "nickels: " << nickels << endl;
		cout << "pennies: " << pennies << endl;
	
	/*
	if (change = 0)
	{
		cout << "dollars: " << dollars << endl;
		cout << "quarters: " << quarters << endl;
		cout << "dimes: " << dimes << endl;
		cout << "nickels: " << nickels << endl;
		cout << "pennies: " << pennies << endl;
	}
	*/
	
	
	
	
	
	
	
}

/**************NOTES*************
 *64. Using Operators
 *Groups: assignment, arithmetic, increment/decrement, relational, logical, member access, other
 * 
 * 66. Arithmetic Operators
 * If you divide integers, output will be 0 for anything less than 1.
 * Output will give you the 0 and ignore the fraction that comes after.  E.g. 100/200 = 0 (rather than 0.5).  Use doubles for this.
 * % = modulo operator = remainder
 *only works with integers
 *200 % 100 = 0
 *10 % 3 = 1
* 
* 67. Increment and decrement operators
* prefix ++num or post fix num++ // same thing
* DO NOT USE TWICE FOR SAME VAR IN SAME STATEMENT
* preincrement: result = ++counter; //counter is incremented first and THEN assigned to result
* post-increment: result = counter++; // counter is used then incremented after assigned to result
* e.g. result = counter++ + 10; // counter + 10 gets assigned to result and then counter increments by 1.  printing counter is 11 and printing result is 20
* 
* 68. Mixed Type Expressions
* need to have same operands in operations.  e.g. flot + flot or int*int..
* higher vs lower types: long double, double, float...... int
* short and char are always converted to int.  conversion usually goes lower->higher
* Promotion: conversion to a higher type. used in mathematical expressions.  e.g. 2 * 5.2.  2 promoted to 2.0
* Demotion:  conversion to a lower type.  used with assignment to lower type.  e.g. int num {0}; num = 100.2; num demoted to 100.2
* Explicit type casting - static_cast<type>.
e.g. want to get a result that is fraction.  we have statement that is int/int. average = static_cast<double>(total)/count; //force int total to become double
* 
* 69. Equality Operators
* compares value of 2 expressions.  evaluates to a bool = true/false, 0/1.  commonly used in control flow statements
* == equals != not equals
* 100 == 100 (true); 100 == 120 (false); 100 != 120 (true); 100 != 100 (false);
* 
* 70. Relational Operators
* greater than, less than		 returns true or false;
* > greater than		 >= greater than or equal to;
* < less than		 <= less than or equal to;
*
* 71. Logical Operators
* not !		and &&		or ||
* Precedence: not, then than, then or.  use () like with math to control precedence
* Short-Circuit evaluation.  when evaluating a logical expression C++ stopes as soon as result is known.
* e.g. expr1 || expr2 || expr3 // if expr1 evaluates to true then it stopes there
* 
* 72. Compounding Operators
* +=		-=		*=		/=		%=
* a += 1; // a = a+1;
* a *= b + c; // a = a* (b + c);
* 
* 73. Operator precedence
* https://en.cppreference.com/w/cpp/language/operator_precedence
**********************************/



