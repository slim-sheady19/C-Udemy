#include <iostream>
using namespace std;

int main()
{
	
}



/*******************************NOTES********************************************
 * 183. What is Polymorphism?
 * 	2 types of polymorphism: compile-time, run-time
 * 			Compile-time: function overloading, operator overloading
 * 			Run-time: Function overriding
 * 	Static-Binding is done at compile time.  E.g. child class calling parent class inherited functions
 * 	if we create a pointer to a parent class and store in it a new child class on the heap, and try to call a function from that pointer,
 * 		it will call the parent class' function, not inherited function in child class
 * 	using Dynamic Binding we can call the child class' specific functions, not the parents
 * 	
 * 184. Using a Base class pointer
 * 		For dynamic polymophism, we must have: Inheritance, base class pointer or Base class reference, and virtual functions
 * 
 * 185. Virtual Functions
 * 		Redefined functions are bound statically				Overrideen functions are bound dynamically
 * 		Virtual Functions are overrideen						Allow us to treat all objects generally as objects of Base class
 * 		Virtual Functions allow us to create a specialized version of the function specific to the derived class
 * 		without virtual keyword, functions are statically bound
 * 	Declaring virtual functions
 * 		Declare the function you want to override as virtual in the Base class
 * 		Virtual functions are virtual all the way down the hierarchy from this point
 * 		Dynamic polymorphism only via Account class pointer or reference
 * 		Override the function in the Derived classes					Signature and return type must match EXACTLY
 * 		Virtual keyword not required but is best practice
 * 		If you don't provide an overrideen version it is inherited from its base class
 * 
 * 186. Virtual Destructors
 * 		If a derived class is destroyed by deleting its storage via the base class pointer and the class is a non-virtual destructor, then the behaviour is undefined in C++
 * 	If a class has virtual functions, always provide a public virtual destructor.  If base class destructor is virtual then all derived class destructors are also virtual
 * 	virtual ~Account()
 * 
 * 187. Override specifier
 * 		We can override Base class virtual functions				Function signature and return must be a precise match
 * 		If they are deifferent then we have redefinition not overrriding
 * 		Redefinition is statically bound.			Override is dynamically bound
 * 		C++11 provides an override specifier to have the compiler ensure overriding
 * 
 * 188. Final Specifier
 * 		class My_class final
 * 		prevents class from being extended or function from being overridden further down the inheritance line
 * 
 * 189. Using Base Class References
 * 		We can use Base class references with dynamic polymorphism
 * 		Useful when we pass objects to functions that expect a Base class reference
 * 		
 * 190. Pure Virtual Functions and Abstract Classes
 * 		Abstract Class: cannot instantiate objects.  These classes are used as base classes in inheritance hierarchies.  "Abstract Base Classes"
 * 		Concrete class: Used to instantiate objects from.  All member functions are defined
 * 	An abstract class is usually too general to create objects from.  E.g. nobody ever creates an Account, they create a Chequing account, Savings account, etc
 * 	An abstract base class always contains at least one pure virtual function
 * 	Derived classes must override the base class functions.  If this does not happen then the derived is also abstract.
 * 			Used when it doesn't make sense for a base class to have an implementation.  E.g. we never call "draw" from Shape class since we never create Shape object
 * 					But concrete classes must implement it.
 * 
 *  191. Abstract Classes as Interfaces
 * 	What is Using class as interface?
 * 		An abstract class that has only pure virtual functions.							These functions provide a general set of services to the user of the class
 * 		Provided as public				Each subclass is free to implement these services as needed.
 * 		Every service (method) must be implemented						The service type is strictly enforced by C++
 * *REVIEW*
 * 		
 *
 * 
 * ********************************************************************************/
