#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector <int> list {10,20,30,40,50};
	char selection{};
	
	do
		{
			cout << "\nMenu Options\n\nP - Print numbers\nA- Add a number\nM - Display mean of the numbers\nS - Display the smallest number\nL - Display the largest number\nQ - Quit" << endl;
			cout << "\nEnter your selection: ";
		
			cin >> selection;
		
			if (selection == 'p' || selection == 'P')
			{
				cout << "[ ";
				for (auto i : list)
				{
					cout << " " << i << " ";
				}
				
				cout << " ]" << endl;
			}
			
			else if (selection == 'A' || selection == 'a')
			{
				cout << "\nAdd an integer to the list: ";
				int new_int;
				cin >> new_int;
				list.push_back(new_int);
				cout << new_int << " added.";
			}
		
			else if (selection == 'M' || selection == 'm')
			{
				if (list.size() == 0)
				{
					cout << "\nUnable to calculate the mean - no data";
				}
				else
				{
					int sum{0};
					int mean{0};
					for (int i {1}; i < list.size(); ++i)
					{
						sum = sum + list.at(i);
						mean = sum/list.size();
					}
					cout << "\nThe mean of the list is : " << mean;
				}
				
				
			}
		
			else if (selection == 'S' || selection == 's')
			{
				if (list.size() == 0)
					{
						cout << "\nUnable to calculate the smallest number - no data";
					}
			else
				{	
					int small{list.at(0)};
					for (int i{1}; i< list.size(); ++i)
						{
							if (small > list.at(i))
								{
									small = list.at(i);
								}
						}
					cout << "\nThe smallest number is " << small;
				}
			}
		
			else if (selection == 'L' || selection == 'l')
			{
				if (list.size() == 0)
					{
						cout << "\nUnable to calculate the largest number - no data";
					}
			else
				{		
					int large{list.at(0)};
					for (int i{1}; i<list.size(); ++i)
					{
						if (large < list.at(i))
						{
							large = list.at(i);
						}
					}
					cout << "\nThe largest number is " << large;
				}
			}
			
			else if (selection == 'Q' || selection == 'q')
			{
				
			}
		
			else
			{
				cout << "Unknown selection, please try again";
			}	
		}
	
	while (selection != 'q' && selection != 'Q');
		{
			cout << "Goodbye..." << endl;
		}
	
	
	
//NESTED LOOPS CODING (EXERCISE 17) SOLUTION

/*int calculate_pairs(vector<int> vec) {
    int result{};
    
    for (size_t i=0; i< vec.size(); ++i)
       for (size_t j=i+1; j< vec.size(); ++j) 
            result = result + vec.at(i) * vec.at(j);
    -
    return result;*/

}



/*******************************NOTES********************************************
 * 77. If Statement
 * Local variables: variables declared inside the block of the if statement that only exist inside that scope
 * 
 * 78. If else
 * If the if statement is evaluated as false, we execute the else code.
 * Else if: the first if statement is not true, flow of control moves to the following else if, and so on.  If no else ifs are true, flow of control moves to the else statement
 * ("catch all")
 * 
 * 79. Nested if Statement
 * in C++ "else" belongs to closest "if"
 * 
 * 80. Switch statement
 * control expression must evaluate to integer type.  same for case expressions or integer literals.
 * when a match occurs, all following case sections execute until break is reached
 * best practice: break for each case and add default at the end
 * e.g. switch (day_code)
 * {
 * 		case 0:
 * 			cout << "Sunday";
 * 			break;
 * 		case 1:
 * 			cout << "Monday";
 * 			break;
 * 		etc...
 * 		default:
 * 			cout << "Invalid day code";
 * }
 * 
 * 81. Conditional operator ?
 * is handy and can replace a short if-else statement
 * e.g. (num%2 == 0) ? "even" : "odd"
 * in other words, if a number divided by 2 has remainder 0, it is an even number.  if not, it is odd.  true prints out "even", false prints out "odd"
 * 
 * 82. Looping (aka iteration or repetition)
 * Typical use-cases: specific number of times, for each element in a collection, while a specific condition remains true / becomes false, until we reach the end of input stream,
 * forever, etc.
 * C++ Looping Contructs
 * 		for loop: iterate a specific number of times e.g. 10 times or n times
 * 	Range-based for loop
 * 		one iteration for each element in a range or collection e.g. arrays, vectors, other collections
 * 	While loop
 * 		iterate while a condition remains true
 * 		stop when a condition becomes false
 * 		check the condition at the beginning of every iteration
 * 	Do-while loop (same to while except condition is checked at end of iteration)
 * 
 * 83. for Loop
 * for keyword followed by condition being checked
 * for (initialization, condition, increment) statement;
 * e.g. int i {0};
 *  for (i = 1; i <= 5; ++i)
 * 		cout << i << endl;
 * e.g. for (int i {1}; i <= 5; ++i)
 * 			cout << i <<endl;
 * e.g. int scores [] {100,90,87};
 * 		for (int i {0}; i < 3; ++i) //ensure condition (i<3) is size-1 of array or vector
 * 		cout << scores[i] << endl;
 * 
 * 84. Range-based for loop
 * skip the condition statements
 * e.g. int scores [] {100,90,97};
 * 		for (int score : scores)
 * 			cout << score << endl;
 * auto keyword asks  compiler to figure out type based on declarations
 * 
 * 85. While Loop (pre-test loop)
 * 	e.g. int i {1};
 * 	while (i <= 5)
 * {cout << i << endl;
 * 	++i; //remember to increment
 * 	e.g. bool done {false};
 * int number {0};
 * while (!done)
 * ......code
 * done = true; // done returns true which is checked before next iteration
 * 
 * 86. do While
 * e.g. int number {};
 * 	do
 * {	cout << "Enter an integer between 1 and 5:"
 * 		cin >> number;
 * }
 * 	while (number <= 1 || number >= 5);
 * 	cout << "Thanks" << endl;
 * check condition expression after the loop.  which means any variables in the condition expression need to be declared outside the loop
 * use do-while for when at least one iteration is needed
 * 
 * 87. continue and break
 * 	continue: no further statements in the loop body executed, control immediately returns to beginning for next iteration
 * 	break: loop is terminated and control goes to the statement following loop construct
 * 
 * 89. Nested Loops
 * 	useful for multi dimensional data structures.
 * 	outer loop vs inner loop
 * 	
 * 
 * 
 * ********************************************************************************/
