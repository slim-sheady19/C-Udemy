#include <iostream>
using namespace std;

int main()
{
	
}



/*******************************NOTES********************************************
 * 169. What is Inheritance?
 * 	create new classes from existing classes			new class contains the data and behaviours of existing class
 * 	allow for reuse of existing classes					allows us to focus on the common attributes of existing classes
 * 	allows new classes to modify behaviours of existing classers to make it unique (without modifying original class)
 * 
 * 170. Terminology and Notation
 * 	Inheritance: process of creating new classes from existing classes
 * 				Reuse mechanism
 * 	Single Inheritence: a New class is created from another "single" class
 * 	Multiple Inheritance: A new class is created from two or more other classes
 * 	Inheritance terminology:
 * 			Base class (parent class, super class).  The class being extened or inherited from
 * 			Derived class (child class, sub class). class being created from the Base class, inherits attributes and operations from Base
 * 			"Is-A" relationship. Public inheritance			Derived classes are sub-types of base classes.		Can use a derived class object whereever we use a base class object
 * 			Generalization. Combining similar classes into a single more general class based on common attributes
 * 			Specialization. Creating new classes from existing classes proving more specialized attributes or operations.
 * 			Inheritance or Class Hierarchies.  Organization of our inheritance relationships.
 * 	
 * 	171. Inheritance vs Composition
 * 			Both allow reuse of existing classes
 * 		Public Inheritance:		"is-a" relationship			Employee "is-a" person, circle "is-a" shape
 * 		Composition:			"Has-a" relationship		Player "has-a" Special Attack, Circle "has-a" location
 * 
 * 172. Deriving Classes from Existing Classes
 * 	3 types of access: public, private, protected.  we are only discussing public in this course.
 * 		public: accessible anywhere.				private: accessible from all derived classes.			protected: inaccessible outside base class
 * 		*friend of* class has access to everything!
 * 
 * 173. Protected members and Class Access
 * 		
 * 
 * 174. Constructors and Destructors
 * 	Constructors
 *		Base part of class must be intiialized before the derived class is initialized.
 * 		When a derived object is created, first the Base class constructor executes then the Derived class constructor executes
 * 	Destructors
 * 		Derived part of Derived class must be destroyed befpre base class destructor is invoked
 *  	Destructors are exectured in reverse order and should free resources allocated
 * 	Derived class does not inherit from base class: constructors, destructors, overloaded assignment operators, friend functions
 * 
 * 175. Passing Arguments to Base class constructors
 * 	
 * 176. Copy/Move Constructors
 * 	Copy/Move constructors and overloaded operator=
 * 		Often you do not need to provide your own
 * 		If you do not define them in Derived, then compiler will create them and automatically call the base class's version
 * 		If you do provide derived versions, then you must invoke the Baser versions explicitly
 * 		Be careful with raw pointers, especially if Base and Derived have raw pointers.  provide with deep copy semantics
 * 
 * 177. Redefining Base class methods
 * 		Derived class can directly invoke Base class methods
 * 		Derived class can override or redefine Base class methods
 * 	Static binding of method calls
 * 		Binding of which method to use is done at compile time
 * 			Default binding for C++  is static											Derived class objects will use Derived::deposit
 * 			But we can explicitly invoke Base::deposit from Derived::DEposit			much better apporach is dynamic binding
 *
 * 
 * 
 * ********************************************************************************/
