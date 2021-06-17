#include <iostream>
using namespace std;

int main()
{
	
}



/*******************************NOTES********************************************
 * 197. Issues with Raw Pointers
 * 	Memory management: Allocation			Deallocation			Lifetime management
 * 	Serious problems:	uninitialized (wild) pointers, memory leaks, dangling poiinters, not exception safe
 * 	Ownership: Who owns the pointer?  When should a pointer be deleted?
 * 
 * 198. What is a smart pointer?  Ownership and RAII
 * 	Objects					Can only point to heap-allocated memory				Automatically call delete when no longer needed
 * 	Adhere to RAII principles
 * 	Unique pointers, Shared pointers, Weak pointers
 * 	#include <memory>
 *	implemented as class templates:	wrapper around a raw pointer
 * 		Overloaded operators: Dereference *
 * 								Member selection ->
 * 								Pointer arithmetic not supported ++, --, etc
 * 								custom deleters
 * 	RAII - Resource Acquisition Is Initilalization
 * 		RAII objects are allocated on stack
 * 		Resource acquisition: Open a file, Allocate memory, Acquire a lock
 * 		Is Initilization: The resource is acquired in a constructor
 * 		Resource relinquishing: happens in the destructor.				close the file, deallocate memory, release the lock
 * 
 * 199. Unique pointers
 * 	Simple smart pointer - very efficient
 * 	unique_ptr<T>
 * 		points to object of type T on the heap
 * 		unique - there can only be one unique_ptr<T> pointing to the object on the heap
 * 		owns what it points to
 * 		cannot be assigned or copied
 * 		CAN be moved
 * 		when pointer is destroyed, what it points to is automatically destroyed
 * 	
 * 200. Shared Pointers
 * 	Provides shared ownership of heap objects
 * 	shared_ptr<T>
 * 		points to an object of type T on the heap
 * 		not unique - there can be many shared_ptrs pointing to the same object on the heap
 * 		Establishes shared ownership relationship
 * 		CAN be assigned, copied, moved
 * 		Does not support managing arrays by default
 * 		When use count is 0, managed object on the heap is destroyed
 * 
 * 201. Weak Pointers
 * 	weak_ptr: provides a non-owning "weak" reference
 * 	weak_ptr<T>:
 * 		points to an object of type T on heap
 * 		Does not participate in owning relationship
 * 		Always created from a shared_ptr
 * 		DOES NOT increment or decrement reference use count
 * 		USed to prevent strong ref cycles which could prevent objects from being deleted
 * 		
 * 202. Custom Deleters
 * 	Sometimes when we destroy a smart pointer we need more than just to destroy the object on the heap.  These are special use cases
 * 	C++ smart pointers allow us to provide custom deleters: functions, lambdas, others...
 * 
 * ********************************************************************************/
