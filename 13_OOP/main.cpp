/******************************************************************
 * Section 13 Challenge
 * main.cpp
 * 
 * Test the Movies project
 * 
 * ***************************************************************/
#include <iostream>
#include "Movies.h"
using namespace std;

// Function prototypes
void increment_watched(Movies &movies, std::string name);
void add_movie(Movies &movies, std::string name, std::string rating, int watched);

/******************************************************************
 * helper function 
 * increment_watched expects a reference to a Movies object 
 * and the name of the movie to increment the watched count
 *
 * If the watched count was incremented successfully it
*  displays a success message
*  clTabCtrlotherwise the watched count could not be incremented
*  because the name of the movie was not found
 * ***************************************************************/

void increment_watched(Movies &movies, std::string name) {
    if (movies.increment_watched(name)) {
        std::cout << name << " watch incremented" <<  std::endl;
    } else {
        std::cout << name << " not found" <<  std::endl;
    }
}

/******************************************************************
* helper function
*  add_movie expects a reference to a Movies object 
 * and the name of the movie, the rating and the watched count
 *
 * If the movie was successfully added to the movies object it
*  displays a success message
*  otherwise the movie was not added 
*  because the name of the movie was already in movies
 * ***************************************************************/
void add_movie(Movies &movies, std::string name, std::string rating, int watched) {
    if (movies.add_movie(name,rating,watched)) {
        std::cout << name << " added" << std::endl;
    } else {
        std::cout << name << " already exists" <<  std::endl;
    }
}

int main() {
    
    Movies my_movies; //create object my_movies of type Movies.  class Movies contains a private vector of type Movie.  see Movies.h
    
    my_movies.display(); //call display function on my_movies (function is in Movies class)
    
    add_movie(my_movies, "Big", "PG-13",2);                 // OK
    add_movie(my_movies,"Star Wars", "PG",5);             // OK
    add_movie(my_movies,"Cinderella", "PG",7);           // OK
     
    my_movies.display();   // Big, Star Wars, Cinderella
    
    add_movie(my_movies,"Cinderella", "PG",7);            // Already exists
    add_movie(my_movies,"Ice Age", "PG",12);              // OK
 
    my_movies.display();    // Big, Star Wars, Cinderella, Ice Age
    
    increment_watched(my_movies,"Big");                    // OK
    increment_watched(my_movies,"Ice Age");              // OK
    
    my_movies.display();    // Big and Ice Age watched count incremented by 1
    
    increment_watched(my_movies,"XXX");         // XXX not found
	
	add_movie(my_movies, "XXX", "R", 2);
	my_movies.display();

	return 0;
}
	
/*	EXERCISE 33: ADD COPY CONSTRUCTOR TO EXISTING CLASS
 * class Dog {
private:
    string name;
    int age;
public:
        Dog(string name, int age) : name{name}, age{age} { }


    Dog (const Dog &source):				//we only use Dog::Dog when outside the scope of the class
        name{source.name}, age{source.age}
 * 
 * 
 * 
 * 
 * EXERCISE 32
 * class Dog {
private:
    string name;
    int age;
public:

//---- WRITE YOUR OVERLOADED CONSTRUCTOR BELOW THIS LINE
Dog(string new_name, int new_age)
{
    name = new_name;
    age = new_age;

}

 * 
 * EXERCISE 30: ADD MORE PUBLIC METHODS TO AN EXISTING CLASS
	class Dog {
private:
    string name;
    int age;
public:

    string get_name() {return name; }
    void set_name(string n) {name = n; }
    int get_age() {return age; }
    void set_age(int a) { age = a;}
    int get_human_years() {return age*7;}
    string speak() {string bark = "Woof"; return bark;}
	 
	  * 
	  * EXERCISE 29: ADDING PUBLIC METHODS TO ACCESS PRIVATE ATTRIBUTES
	  * class Dog {
private:
    string name;
    int age;
public:

//---- WRITE YOUR CLASS FUNCTIONS BELOW THIS LINE----
string get_name()
{
    return name;
}
void set_name(string new_name)
{
    name = new_name;
}

int get_age()
{
    return age;
}

void set_age(int new_age)
{
    age = new_age;
}
	  * 
	  * 
	  * * */




/*******************************NOTES********************************************
 * 135. What is Object-Oriented Programming?
 * 	Procedural programming: programs that are made up of functions.  works for small programs
 * 	Classes and objects allow us to think in a higher level of abstaraction.  E.g. student database software. Class
 *"Student" and object "Frank" Encapsulation: objects contain data and operations that work on that data.  Abstract Data
 *Type Information hiding: implementation-specific logic can be hidden.  Users of the class code to the interface since
 *they don't need to know the implementation More abstraction			easier to test, debugb, maintain, extend
 * 	Reusability: easier to reuse classes in other applications			faster development
 *higher quality Inheritance: can create new class in term of exisiting class.		reusability
 *polymorphic classes
 *
 * 	136. What are classes and objects?
 * 	Classes: blueprints from which objects are created.			user-defined data type		has
 *attributes (data)
 * 			has methods (functions)					can hide data and methods
 *public interface e.g. Account, employee, Image, vector, string Object: created from a class.  represents a specific
 *instance of a class.  can create many many objects.  eachs has its own identity.
 *
 * 	137. Declaring a class
 * 	class Class_Name
 * 	{		//declarations;			}
 * 	Player frank;			Player hero;
 * 	Player *enemy = new Player();
 * 	delete enemy;
 * class Account
 * { // attributes:				std::string name;			double balance;
 * 	//methods:					bool withdraw(double amount);			bool deposit(double
 *amount); Account frank_account;					Account jim_account; Account *mary_account = new
 *Account(); //pointer to account object delete mary_account;
 *
 * 138.  Accessing Class Members
 * 	we can access: class attributes, methods
 * 	some class members will not be accessible.			we need an object to access instance variables
 * 	if we have an object (dot operator)
 * 	e.g. Account frank_account;
 * 	frank_account.balance;				frank_account.deposit(1000.00);
 * 	if we have a pointer to an object:
 *	dereference the pointer then use the dot operator.  e.g. Account *frank_account = new Account();
 * //*frank_account is a POINTER, not an Account object
 * 		(*frank_account).balance;				(*frank_account).deposit(1000.00);
 * 		^^ IMPORTANT the (*frank_account) is a pointer so it must be derefenced so we can access the actual
 *	object frank_account and use its methods or use the member of a pointer operator (arrow operator) Account
 *	*frank_account = new Account(); frank_account->balance;			frank_account->deposit(1000.00);
 *
 * 139. Class Member Access Modifier
 * 	public: accessible everywhere		private: accessible only by members or friends of the class
 *	protected: used with inheritance if we try to access a private class member we get a compiler error 
 *	idea is to control certain variables from within the class.
 *
 * 140. Implementing Member Methods
 * 	Member methods have access to member attributes			Can be implemented inside the class declaration (class_name::method_name)
 * 	can separate specification from implementation:.h file for class declaration and .cpp file for class implementation
 * 
 *	141. Constructors and Destructors
 * 	Constructors:
 * 	Special member method		Invoked during object creation			Useful for initialization
 * 	Same name as class			No return type specified			Can be overloaded
 * 	Destructors:
 * 	Special member method		Same name as classe but with a tilde`		Invoked automatically when an object is destroyed
 * 	No return type is allowed per class - cannot be overloaded				USeful to release memory and other resources
 * 	
 * 142. Default Constructor
 * 	does not expect any arguments (no-args constructor)				if you write no constructors for a class, C++ generates a default constructor that does nothing
 * 	called when you instantiate a new object with no arguments
 * 
 * 143. Overloaded Constructors
 * 	Classes can have as many constructors as necessary			Each must have a unique signature			Default constructor is no longer compiler-generated
 * 																											once another constructor is declared
 * 144. Constructor Initialization Lists
 * 	are more efficient			intitalization list immediately follows the paramater list
 * 	intializes the data memebers as the object is created			order of intialization is the order of declaration in the class
 * 	initializes immediately to desired value rather than initialized and THEN assigned desired value
 * 
 * 145. Delegating Constructors
 * 	C++ allows delegating constructors.  code for one constructor can call another in the initilization list.  avoids duplicating code
 * 	
 * 147. Copy Constructor
 * 	When objects are copied C++ must create a new object from an existing object
 * 	A copy of an object is made by: passing object by value as a paramater			returning an object from a function by value
 * 				constructing one object based on another of the same class
 * 	C++ must have a way of accomplishing this so it provides a compiler-defined copy constructor if you don't
 * 	If you don't provide your own way of copying objects by value then the compiler provides a default way of copying objects
 * 	copies the values of each data member to the new object, default memberwise copy
 * 	If you have a pointer data member, pointer will be copied and not what it is pointing to.  Shallow vs Deep copy.
 * 	Best practice: provide a copy constructor when your class has raw pointer members
 * 		provide the copy constructor with a const reference paramater			use STL classes as they already provide copy constructors
 * 		Avoid using raw pointer data members if possible
 * 
 * 150. Move Constructors
 * 	Sometimes copy constructors are called many times automatically due to the copy semantics of C++ and copy constructors doing deep copying have a
 * 		significant performance bottleneck.
 * 	C++11 introduced move semantics and the move constructor, which moves the object instead of ocpying.  Optional but recommended when we have a raw pointer
 * 	
 * 151. This pointer
 * 	contains address of the current object - pointer.			can only be used in class scope			all member access is done via the this pointer
 * 	can be used by the programmer:	to access data member and methods			to determine if two objects are the same
 * 			can be dereferenced (*this) to yield the current object
 * 
 * 152. Using const with classes
 * 	Pass arguments to class memeber methods as const			We can also create const objects					Const-correctness
 * 
 * 153. Static Class Members
 * 	Class data members can be declared as static			A single data member that belongs to the class, not the objects			Useful to store class-wide information
 * 	Class functions can be declared as static, independent of any objects. Can be called using the class name
 * 
 * 154. Structs vs Classes
 * 	In addition to define a class we can declare a struct				Essentially the same as a class is except members are public by default
 * 	class Person							struct Person
 * 	get name function - copiler error		get name function - OK
 * 	use struct for passive objects with public access			don't declare methods in struct
 * 	use class for active objects with private access			implement getters/setters as needed			implement member methods as needed
 * 
 * 155. Friends of a Class
 * 	A Friend is a function or class that has access to private class member			And that function of or class is NOT a member of the class it is accessing
 * 	Friendship must be granted not taken.			decalred explicitly in the class that is granting friendship.			Declared in the function prototype keyword friend
 * 	Friendship is not symmetric, mujst be granted explicitly both ways.  also not inherited
 * 
 * *******************************************************************************/
