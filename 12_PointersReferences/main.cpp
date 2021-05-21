#include <iostream>
using namespace std;


// CHALLENGE: TAKE TWO ARRAYS, MULTIPLY EACH ELEMENT IN ONE BY THE OTHER, AND STORE EACH VALUE IN A NEW ARRAY



void print(const int *const arr, size_t size) // here the print function expects a CONSTANT POINTER TO A CONSTANT INT
{												//what this means is WE DO NOT WANT EITHER THE POINTER OR THE INT CHANGED BY THE FUNCTION since all we are doing is printing
	for (size_t i{0}; i < size; ++i)
	{
		cout << arr[i] << endl;					//arr[i] is pointer-subscript notation
	}
}
/*This function dynamically loops through each element of arr2 and multiplies it across all the elements of arr1 and each product is 
 * stored in the newly created array and returns a pointer to an integer */
int *apply_all(const int *const arr1, size_t size1, const int *const arr2, size_t size2) //expects arr1 which is const pointer to const int, etc
{
	int *new_array{}; //create null pointer that will point to new array on heap. THIS IS INITIALIZATION !!!
	
	new_array = new int[size1 * size2]; //here the new array of 15 ints is created on heap and assigned to new_array pointer. DO NOT USE * HERE TO DEREFERNCE
	
	int position {0};					//initialize new int position to 0
	for (size_t i{0}; i < size2; ++i) //OUTER LOOP ONLY ITERATES AFTER FULL INNER LOOP EXECUTES FULLY, IN OTHER WORDS ONLY HERE i INCREMENTS
	{
		for (size_t j{0}; j < size1; ++j) //THIS LOOP WILL EXECUTE SIZE1 TIMES. i REMAINS THE SAME IN FUNCTION BODY FOR THIS LOOP
		{
			new_array[position] = arr1[j] * arr2[i]; //each product of elements arr1 x arr2 is assigned to new_array element indexed as [position]
			++position;									//position gets incremented before restarting loop.
		}												//INNER LOOP ONLY EXITS ONCE IT HAS GONE THROUGH ALL OF SIZE1 ELEMENTS
	}
	return new_array; //RETURN ADDDRESS OF 0TH ELEMENT IN ARRAY
}

int main()
{
	const size_t array1_size{5}; // 1. USE size_t FOR ARRAY LENGTHS
	const size_t array2_size{3};
	
	const int array1[] {1,2,3,4,5};
	const int array2[] {10,20,30};
	
	print(array1, array1_size); //2. here we are calling print function with array1 as an argument which functions as ADDRESS OF its 0th element
	print(array2, array2_size);
	
	int *results = apply_all(array1, array1_size, array2, array2_size); //initialize a pointer to an int called results which is returned by this function call
	constexpr size_t results_size {array1_size * array2_size}; 		//create variable called results size to find size of newly created array
	
	print(results, results_size);
	
	delete [] results;
	
}



/*******************************NOTES********************************************
 * 117. What is a Pointer?
 * 	variable whose value is an address where another variable or function is located.
 * 	to use the data that the pointer is pointing to you must know its type
 * 
 *  118. Declaring Pointers
 * 	variable_type *pointer_name;			int *int_ptr;			char *char_ptr;		string *string_ptr;
 * 	initalize pointer variables to "point nowhere".			variable_type *pointer_name {nullptr};
 * 	always initialize pointer variables
 * 
 * 119. Accessing Pointer Address
 * 	don't confuse size of a pointer and size of what it points to
 * 	all pointers in a program have the same size.  they may be pointing to very large or very small types
 * 	Typed pointers: the compiler will make sure that the address stored in a pointer variable is of the correct type
 * 	e.g. int score {10};
 * 	double high_temp {100.7};					 	int *score_ptr {nullptr};
 * 	score_ptr = &score; //OK						score_ptr = &high_temp;	// error
 * 
 * 120. Dereferencing a Pointer
 * 	access the data we're pointing to - dereferencing a pointer
 * 	e.g. string name {"Frank"};
 * 	string *string_ptr{&name};
 * 	cout << *string_ptr << endl; //Frank
 * 	name = "James";
 * 	cout << *string_ptr << endl; // James
 * 	
 * 121. Dynamic Memory Allocation
 * 	Allocating storage from the heap at runtime
 * 	We often don't know how much storage we need until we need it.  we can allocate storage for a variable at run time
 * 	we can use pointers to access newly allocated heap storage
 * 	using new keyword to allocate storage:
 * 	e.g. int *int_ptr {nullptr};
 * 	int_ptr = new int;		//allocate an integer on the heap
 * 	cout << int_ptr; //hexadecimal address					cout << *int_ptr; // garbage
 * 	*int_ptr = 100;					cout << *int_ptr; //100
 * 	using delete keyword to deallocate storage:
 * 	e.g. int *int_ptr {nullptr};
 * 	int_ptr = new_int;	//allocate an integer on the heap
 * 	delete int_ptr; //frees the allocated storage
 * 
 * 122. The Relationship between Arrays and Pointers
 * 	value of an array name is the address of the first element in the array.		the value of a pointer variable is an address
 * 	if the pointer points to the same data type as the array element then the pointer and array name can be used interchangeably
 * 	e.g. int scores[] {100, 95, 89};
 * 	cout << scores << endl; // hexadecimal address
 * 	cout << *scores << endl; //100
 * 	Subscript and Offset notation equivalence
 * 	int array_name[] {1,2,3,4,5};
 * 	int *pointer_name {array_name};
 * 	Subscript Notation							Offset Notation
 * 	array_name[index]							*(array_name + index)
 * 	pointer_name[index]							*(pointer_name + index)
 * 
 * 	123. Pointer Arithmetic
 * 	pointers can be used in: assignment expressions		arithmetic expressions		comparison expressions
 * 	e.g. (++) increments a pointer to point to the next array element 		same with decrement --
 * (+) increment pointer by n * sizeof(type)				same with -
 * 
 * 124. Const and Pointers
 * 	Pointers to constants: data pointed to by the pointers is constant and cannot be changed.  pointer itself can cahnge and point somewhere else
 * 	Constant Pointers: the data pointed to by the pointers can be changed.  the pointedr itself cannot change and point somewhere else
 * 	Constant pointers to constants: the data pointed to by the pointer is constant.  the pointer itself cannot change
 * 
 * 125. Passing Pointers to Functions
 * 	pass-by-reference with pointer paramaters				we can use pointers and the dereference operator to achieve pass-by-reference
 * 	the function paramater is a pointer						the actual paramater can be a pointer or address of variable
 * 	e.g.
 * 	void swap(int *a, int *b)			//function called swap with input paramaters int *a and int *b (meaning two variables containing addresses of integers)
 * 	{
 * 		int temp = *a;		//local variable called temp is created which the value at address of *a is assigned to
 * 		*a = *b;
 * 		*b = temp;			//value of temp gets assigned to value at *b
 * }
 * 	int main()
 * {
 * 	int x {100}, y {200}; 		//initialize integer variables x and y
 * 	cout << x << endl;				cout << y << endl;			//print x which is 100, print y which is 200
 * 	swap (&x, &y);			//call swap function with arguments (address of)&x and (address of)&y;
 * 	cout << x endl;				cout << y << endl;			//print x which is now 200, print y which is now 100
 * 
 * 126. Returning a Pointer from a Function
 * 	functions can also return pointers 				type *function();
 * 	should return pointers to: 		memory dynamically allocated in the function			to data that was passed in
 * 	never return a pointer to a local function variable!
 * 	
 * 127. Pointer pitfalls
 * 	uninitialized pointers:  	int *int_ptr; // pointing anywhere				*int_ptr = 100; //Hopefully a crash
 * 	dangling pointer: pointer that points to memory that is invalid
 * 	not checking if new failes: if new fails an exception is thrown
 * 	leaking memory: forgetting to release allocated memory with delete
 * 
 * 128. What is a REference?
 * 	alias for a variable			must be initialized tro a variable when decalared				canot be null
 * 	once intitialized cannot be made to refer to a different variable			very useful as function paramaters
 * 	think of a reference as a constant pointer that is automatically dereferenced
 * 
 * 129. l-values and r-values
 * 	l-value: values that have names and are addressable. modifiable if they are not constants
 * 	e.g. int x {100};  string name; 			x and name l-values
 * 		100 = x;		"Frank" = name;			100 and "frank" are r-values
 * 	
 * 131. Section Recap - When to use Pass-By-Reference pointers & reference
 * 	When to use Pass-by-value: when the function does not modify the actual paramater, 		and 	the paramater is small and efficient to copy like simple types
 * 	when to use pass-by-reference using a pointer: when the function does modify the actual paramater		and		the paramater is expensive to copy
 * 				it's ok for the pointer to contain nullptr value
 * 	Pass-by-reference using a pointer to const: when the function does not modify the actual paramater		and 	the paramater is expensive to copy
 * 										and		it's ok for the pointer to contain nullptr
 * 	Pass-by-reference using a reference:  when the function does modify the actual paramater		and		the paramater is expensive to copy
										and 	the paramater will never be nullptr
 * 	Pass-by-reference using a const reference:	when the function does not modify the actual paramater		and		the paramater is expensive to copy
 * 											and 		paramater will never be a nullptr
 * 
 * ********************************************************************************/
