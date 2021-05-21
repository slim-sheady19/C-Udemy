// Section 14
// Overloading copy assignment
#include <iostream>
#include <vector>
#include "Mystring.h"

using namespace std;

int main() {

								//161. OVERLOADING ASSIGNMENT OPERATOR (MOVE)
	
	Mystring a{"Hello"};				//Overloaded constructor
	a = Mystring{"Hola"};				//Overloaded constructor then move assignmenet.  'Hola' is a temporary object
	a = "Bonjour";						//Overloaded constructor then move assignment
	
	/*
	//*******************160. OVERLOADING ASSIGNMENT OPERATOR (COPY)************
    Mystring a {"Hello"};                // overloaded constructor
    Mystring b;                             // no-args contructor
    b = a;                                      // copy assignment 
                                                  // b.operator=(a)
    b = "This is a test";                 // b.operator=("This is a test");
	 */
  
    Mystring empty;                      // no-args constructor
    Mystring larry("Larry");             // overloaded constructor
    Mystring stooge {larry};            // copy constructor 
    Mystring stooges;                   // no-args constructor
    
    empty = stooge;                     // copy assignment operator
    
    empty.display();                      // Larry : 5
    larry.display();                         // Larry : 5
    stooge.display();                     // Larry : 5
    empty.display();                      // Larry : 5
    
    stooges = "Larry, Moe, and Curly";  
    stooges.display();                              // Larry, Moe, and Curly : 21
    
    vector<Mystring> stooges_vec;
    stooges_vec.push_back("Larry");
    stooges_vec.push_back("Moe");
    stooges_vec.push_back("Curly");
    
    cout << "=== Loop 1 ==================" << endl;
    for (const Mystring &s: stooges_vec) 
        s.display();                                        // Larry
                                                                // Moe
                                                                //Curly
    cout << "=== Loop 2 ==================" << endl;
    for (Mystring &s: stooges_vec)
        s = "Changed";                              // copy assignment
        
    cout << "=== Loop 3 ================" << endl;
    for (const Mystring &s: stooges_vec) 
        s.display();                                     // Changed
                                                            // Changed
                                                            // Changed
    
    return 0;
	
	
}



/*******************************NOTES********************************************
 * 159. What is Operator Overloading?
 * 	Using traditional operators such as +, =, *, etc with user defined types
 * 	Allows user defined types to behave similar to built-in types						Can make code more readable and writable
 * 	Not done automatically (except for asignment operator).  Must be explicitly defined
 * 	Cannot overload operators		::		:?		.*		.		sizeof
 * 	
 * 160. Overloading the Assignment Operator (copy)
 * 	C++ provides a default assignment operator used for assigning one object to another
 * 		remember that 		Mystring s2 = s1 		// not assignment, this is initialization
 * 		s2 = s1 		//assignment because s2 has already been created and initialized
 * 		Default is memberwise assignment (shallow copy)				If we have raw pointer data member we must deep copy
 * 	Overloading the assignment operator (deep copy)
 * 		must be overloaded as member function
 * 		Type &Type::operator=(const Type &rhs);
 * 		Mystring &Mystring::operator=(const Mystring &rhs);
 * 		s2 = s1;			//We write this						s2.operator=(s1);		//operator= method is called
 * 		Mystring &Mystring::operator=(const Mystring &rhs)
 * 		{
 * 			if (this == &rhs)		//check for self assignment (p1 = p1).  address of left hand object inside pointer this compared to address of right hand object
 * 				return *this;		//return current object (dereferenced object)
 * 		
 * 			delete [] str;			// deallocate storage for this->str since we are overwriting it
 * 			str = new char[std::strlen(rhs.str) +1];  //once left side object is ready to be assigned, we need allocate storage on the heap for deep copy
 * 														use the +1 for the string null character \0
 * 			std::strcpy(str, rhs.str);				//	using C-style string so we can call method std::strcpy copy right hand side to left hand side
 * 
 * 			return *this;							//return the current by reference to allow chain assignment e.g. s1 = s2 = s3
 * 		}
 * 
 * 161. Overloading the assignment operator (Move)
 * 	You can choose to overload the move assignment operator
 * 	Mystring s1;
 * 	s1 = Mystring {"Frank"}; // move assignment
 * 	if we have raw pointer we should overload the move assignment operator for efficiency
 * 	Overloading the Move assignment operator
 * 		Type &Type::operator=(Type &&rhs);						//double ampersand && in paramater list tells compiler that rhs is R-value reference
 * 		Mystring &Mystring::operator=(Mystring &&rhs);
 * 		s1 = Mystring ("Joe); 		//move operator= called
 * 		s1 = "Frank";				//move operator= called
 * 
 * 162. Overloading Operators as Member Functions
 * 	Unary operators as member methods (++,--,-,!)
 * 	ReturnType Type::operatorOp();
 * 	Number Number::operator-() const;
 * 	Number Number::operator++();		//pre-increment
 * 	Number Number::operator++(int);		//post-increment
 * 	bool Number::operator!() const;
 *	Number n1 {100};
 * 	Number n2 = -n1;					//n1.operator-()
 * 	n2 = ++n1;							//n1.operator()
 * 	n2 = n1++;							//n1.operator++(int)
 * 
 * 163. Overloading Operators as Global Functions
 * 	2 arguments required by function instead of 1.
 * 	Mystring operator+(const Mystring &lhs, const myString &rhs)
 * 
 * 164. Overloading the Stream Insertion and Extraction Operators (<<, >>)
 * 	doesn't make sense to implement as member methods
 * 		left operand must be user-define class			not the way we normally use these operators
 * 	e.g. std::ostream &operator<<(std::ostream &os, const Mystring &obj)
 * 	{
 * 		os << obj.str;		//if friend function
 * 		// os << obj.get_str(); 		//if not friend function
 * 		return os;
 * 	}
 * 	return a reference to the ostream so we can keep inserting.  don't return by value
 * 	std::istream &operator>>(std::istream &is, Mystring &obj)
 * 	{
 * 		char *buff = new char[1000];
 * 		is >> buff;
 * 		obj = Mystring{buff};		// If you have copy or move assignment
 * 		delete [] buff;
 * 		return is;
 * 	}
 * 	return a reference to the istream so we can keep inserting.  update the object passed in
 * 
 * ********************************************************************************/
