#include <iostream>
#include <vector>
using namespace std;

void menu_selection(vector <int> vec);
void print_numbers(const vector <int> vec);
void add_int(vector <int> &vec);
void mean(const vector <int> vec);
void small(const vector <int> vec);
void large(const vector <int> vec);
void quit();

int main()
{
	vector <int> list {10,20,30,40,50};
	menu_selection(list);
	
}

void menu_selection(vector <int> vec)
{
	cout << "\nMenu Options\n\nP - Print numbers\nA- Add a number\nM - Display mean of the numbers\nS - Display the smallest number\nL - Display the largest number\nQ - Quit" << endl;
	cout << "\nEnter your selection: ";
	char selection;
	cin >> selection;
	selection = toupper(selection);
	
	if (selection == 'P')
	{
		print_numbers(vec);
		menu_selection(vec);
	}
	
	else if (selection == 'A')
	{
		add_int(vec);
		menu_selection(vec);
	}
	
    else if (selection == 'M')
	{
		mean(vec);
		menu_selection(vec);
	}
		
	else if (selection == 'S')
	{
		small(vec);
		menu_selection(vec);
	}
		
	else if (selection == 'L')
	{
		large(vec);
		menu_selection(vec);
	}
	
	else if (selection == 'Q')
	{
		quit();
	}
	
	else
	{
		cout << "Unknown selection, please try again";
		menu_selection(vec);
	}
}

void print_numbers(vector <int> vec)
{
	{
		cout << "[ ";
		for (auto i : vec)
		{
			cout << " " << i << " ";
		}
		
		cout << " ]" << endl;
	}
	menu_selection(vec);
}

void add_int(vector <int> &vec)

{
	{
		cout << "\nAdd an integer to the list: ";
		int new_int;
		cin >> new_int;
		vec.push_back(new_int);
		cout << new_int << " added.";
	}
	menu_selection(vec);
}

void mean(const vector <int> vec)
{
	int vec_size = vec.size();
	if (vec_size == 0)
	{
		cout << "\nUnable to calculate the mean - no data";
	}
	else
	{
		int sum{0};
		int mean{0};
		for (int i {1}; i < vec_size; ++i)
		{
			sum = sum + vec.at(i);
			mean = sum/vec_size;
		}
		cout << "\nThe mean of the list is : " << mean;
	}
}

void small(const vector <int> vec)
{
	int vec_size = vec.size();
	if (vec_size == 0)
		{
			cout << "\nUnable to calculate the smallest number - no data";
		}
	else
		{	
			int small{vec.at(0)};
			for (int i{1}; i< vec_size; ++i)
				{
					if (small > vec.at(i))
						{
							small = vec.at(i);
						}
				}
			cout << "\nThe smallest number is " << small;
		}
}

void large(const vector <int> vec)
{
	int vec_size = vec.size();
	if (vec_size == 0)
		{
			cout << "\nUnable to calculate the largest number - no data";
		}
	else
		{		
			int large{vec.at(0)};
			for (int i{1}; i<vec_size; ++i)
			{
				if (large < vec.at(i))
				{
					large = vec.at(i);
				}
			}
			cout << "\nThe largest number is " << large;
		}
}

void quit()
{
	cout << "Goodbye...\n";
}


/* EXERCISE 27: IMPLEMENTING A RECURSIVE FUNCTION
 * 
 * double a_penny_doubled_everyday(int, double amount = 0.01);


void amount_accumulated() {

    double total_amount = a_penny_doubled_everyday(25);

    cout <<  "If I start with a penny and doubled it every day for 25 days, I will have $" << setprecision(10) << total_amount;
}

double a_penny_doubled_everyday(int n, double amount) {
    function_activation_count++;
    
    if (n <= 1)
        return amount;
    return a_penny_doubled_everyday(--n, amount*2);  
 * 
 * 
 * 
 * 
 * EXERCISE 26: USING PASS BY REFERENCE

string print_guest_list(const string &guest_1, const string &guest_2, const string &guest_3);
void clear_guest_list(string &guest_1, string &guest_2, string &guest_3);

void event_guest_list() {

    string guest_1 {"Larry"};
    string guest_2 {"Moe"};
    string guest_3 {"Curly"};

    print_guest_list(guest_1, guest_2, guest_3);
    clear_guest_list(guest_1, guest_2, guest_3);
    print_guest_list(guest_1, guest_2, guest_3);
}

string print_guest_list(const string &guest_1, const string &guest_2, const string &guest_3) {
    cout << guest_1 << endl;
    cout << guest_2 << endl;
    cout << guest_3 << endl;
    
    string test_1 = typeid(guest_1).name(), test_2 = typeid(guest_2).name(), test_3 = typeid(guest_3).name();
    return test_1 + test_2 + test_3;
}

void clear_guest_list(string &guest_1, string &guest_2, string &guest_3) {
    guest_1 = " ";
    guest_2 = " ";
    guest_3 = " ";
    

}
 * 
 * 
 * 
 * 		EXERCISE 25: PASSING ARRAYS TO FUNCTIONS
 * 
		string print_guest_list(const string arr[], size_t size);
void clear_guest_list(string arr[], size_t size);

void event_guest_list() {

    string guest_list[] {"Larry", "Moe", "Curly"};
    size_t guest_list_size {3};

    print_guest_list(guest_list, guest_list_size);
    clear_guest_list(guest_list, guest_list_size);
    print_guest_list(guest_list, guest_list_size);


}


string print_guest_list(const string guest_list[], size_t size) {
    {
        for (size_t i{0}; i < size; ++i)
            cout << guest_list[i] << endl;
    }

    return typeid(guest_list).name();
}


void clear_guest_list(string arr[], size_t size) 
    for (size_t i {0}; i < size; ++i)
        arr[i] = " ";
 
}
 * 
 * 
 * 
 * 
 * EXERCISE 24: OVERLOADING FUNCTIONS
 * 
 * int find_area(int);
double find_area(double, double);

void area_calc() {
    
    int square_area = find_area(2);
    double rectangle_area = find_area(4.5, 2.3);
    
    cout << "The area of the square is " << square_area << "\n" << "The area of the rectangle is " << rectangle_area;
}

int find_area(int side_length)
{
    return side_length*side_length;
}

double find_area(double length, double width)
{
    return length*width;
}
 * 
 * 
 * 
 * 
 * 
 * EXERCISE 23 - USING DEFAULT VALUES	

void print_grocery_list(int apples = 3, int oranges = 7, int mangos = 13);

void modify_grocery_list() {
    
    print_grocery_list();
    print_grocery_list(5);
    print_grocery_list(7,11);

}

void print_grocery_list(int apples, int oranges, int mangos) { //----WRITE THE FUNCTION PARAMETER LIST WITHIN THE PARENTHESES
                                     //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    cout << apples << " apples" << "\n" << oranges << " oranges" << "\n" << mangos << " mangos" << "\n";
}





	CODING EXERCISE 22: FUNCTIONS AND PROTOTYPES	
 * 
 * double fahrenheit_to_celsius(double);
double fahrenheit_to_kelvin(double);

//----WRITE YOUR FUNCTION PROTOTYPES ABOVE THIS LINE----
//----DO NOT MODIFY THE CODE BELOW THIS LINE----

void temperature_conversion(double fahrenheit_temperature) {
    
    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE YOUR FUNCTION CALLS BELOW THIS LINE----
    double celsius_temperature = fahrenheit_to_celsius(fahrenheit_temperature);
    
    double kelvin_temperature = fahrenheit_to_kelvin(fahrenheit_temperature);
    
    //----WRITE YOUR FUNCTION CALLS ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    
    cout << "The fahrenheit temperature " << fahrenheit_temperature << " degrees is equivalent to " << celsius_temperature << " degrees celsius and " << kelvin_temperature << " degrees kelvin.";
}

//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE YOUR FUNCTION DEFINITIONS BELOW THIS LINE----
double fahrenheit_to_celsius(double temperature) {
    return round(((temperature - 32)*5)/9);
} 

double fahrenheit_to_kelvin(double temperature) {
    return round(((temperature - 32)*5)/9 + 273);
	 
	  * 
	  * 
	  * 
	****EXERCISE 21: USING FUNCTIONS FROM cmath LIB****
	 void c_math_functions() {
    
    double bill_total {102.78};
    int number_of_guests {5};
    
    //DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE YOUR CODE BELOW THIS LINE----
    double individual_bill = bill_total/number_of_guests;
    int individual_bill_1 = floor(individual_bill);
    int individual_bill_2 = round(individual_bill);
    double individual_bill_3 = (ceil(individual_bill*100))/100; 
	 * 
}*/




/*******************************NOTES********************************************
 * 101. Overview
 * 	divide program into units of executable code and call them as we wish
 * 	
 * 102. What is a function?
 * 	#include <cmath>, <cstdlib>, <ctime>
 * 	int min {1}; int max{6};	srand(time(nullptr));			random_number = rand() % max + min;
 * 
 * 103. Function definition
 * 	name		parameter list		return type		body
 * 	function that returns nothing -> return type void
 * 	functions can call other functions but compiler must know the function details BEFORE it is called
 * 
 * 104. Function prototypes
 * 	so the compiler is aware of the function before it gets called
 * 	.h files work for this
 * 	e.g. double calc_volume_cylinder(double radius, double height); // put this line at the top under namespaces, names of argument types
 * 			not necessary (radius and height in example above)
 * 
 * 105. Function Paramaters
 * 	in function call they are called arguments				in the function definition they are called paramters
 * 	must match in number, order, type
 * 	when you pass data in to a function it is passed-by-value.  a copy of the data is passed to function.  whatever changes you make to the paramater in the function
 * 			does not affect the argument that was passed in
 * 	formal vs actual paramaters:		formal paramaters are the parameters defined in the function header		actual paramaters are paramters used in call (arguments)
 * 	Function Return Statement: if function returns a value then it must use a return statement that returns a value
 * 		if it does not return a value then return is optional
 * 		return statement can occur anywhere in the body of the F.  return statement immediatelyu exits the F
 * 		we can have multiple return statements in a function (to be avoided)
 * 		return value is the result of the function call
 * e.g. void pass_by_value1(int num); //prototype at top
 * 		void pass_by_value1(int num)
 * 			{num = 1000;}
 * 	in main: 
 * 	num = 10;
 * 	pass_by_value1(num);
 * 	****num is not changed by pass_by_value1 called in main because the function contains a copy of num.  does not affect the var decalred in main****
 * 
 * 106. Default Argument Values
 * 	when a function is called, all arguments must be supplied. sometimes some of the arguments have the same values most of time time. we can tell the compiler
 * 		to use default values if the areguments are not supplied.
 * 	default values can be in  the prototype or definition but not both. (best practise is in the prototype.)  can have multiple default values
 * 	e.g. double calc_cost(double base_cost, double tax_rate = 0.06, double shipping = 3.50); //prototype with default values
 * 		double calc_cost(double base_cost, double tax_rate, double shipping) //function definition
 * 		{ return base_cost += (base_cost * tax_rate) + shipping; } //function body
 * 		int main(){
 * 			double cost {0};
 * 			cost = calc_cost(100.0, 0.08, 4.25) //will use no defaults 100 + 8 + 4.25
 * 			cost = calc cost(200); //will use default tax and shipping 	} 
 * 
 * 107. Overloading Functions
 * 	We can have functions that have different paramater lists that have the same name.  compiler must be able to tell the functions apart based on paramater
 * 		lists and argument supplied
 * 		e.g. int add_numbers(int, int); // ad ints 			double add_number(double, double); //add doubles
 * 		add_numbers(10,20) //ints							add_numbers(10.0, 20.0) //doubles
 * 	return type is not considered
 * 	need to ensure function is not called ambiguously
 * 
 * 108. Passing Arrays to Functions
 * 	value of arrays is not passed in to functions - the address of first element is
 * 	const keyword to prevent array elements from being changed
 * 
 * 109. Pass by Reference
 * 	sometimes we want to be able to change the paramater from within the function body.  to do this we need the location or address of the paramater
 * 	we can use reference paramaters to tell the compiler to pass in a reference to actual paramater
 * 	formal paramater will now be an alias for actual paramater
 * 	e.g. void scale_number(int &num); // prototype
 * 		main
 * 			int number {1000};						scale_number(number);	//call
 * 			cout << number << endl;		//100
 * 		void scale_number(int &num) 	//definition
 * 		if (num > 100)
 * 			num = 100;
 * 
 * 110. Scope rules
 * 	C++ uses scope rules to determine where an identifier can be used.		uses static or lexical scoping		local or block scope		global scope
 * 	local or block scope: identifiers declared in a block {}		function paramaters can have block scope
 * 	only visible within the block {} where declared
 * 	function local variables are only active while the function is executing
 * 	local variables are NOT preserved between fucntion calls			with nested blocks inner blocks can 'see' but outer blocks cannot 'see' in
 * 	Static Local Variable: declared with static qualifier e.g. static int value {10};
 * 			value is preserved between function calls		only initialized the first time the function is called
 * 	Global Scope: identifier declared outside any function or class
 * 			visible to all parts of the program after it has been declared				global constants ok			best practice don't use global variables
 * 
 * 111. How Function Calls Work
 * 	Functions are computed in the stack area of memory
 * 	Last In first Out - LIFO 		the latest function called is computed at the "top" (pushed) of the stack and is "popped" (disappears) once complete
 * 	
 * 	112. Inline Functions
 * 	function calls have a certain amount of overhead		sometimes we have simple functions
 * 	we can suggest to the compiler to compile them inline
 * 		avoid function call overhead		generate inline assembly code		faster
	e.g. inline int add_numbers(int a, int b) //definition
	 * 		return a + b;
 * 
 * 113. Recursive Functions
 * 	function that calls itself either directly or indirectly through another function
 * 	recursive problem solving		base case		divide the rest of the problem into subproblem and do recursive call
 * 	e.g. 0! = 1		base case 	factorial(0) = 1
 * 		 n! = n * (n-1)!		recursive case		factorial(n) = n * factorial(n-1)
 * 
 * ********************************************************************************/
