#include <iostream>
#include <string>
using namespace std;

int main()
{
	
	string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ "};
	string key {"XZNLWEBGJHQDYTVKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr?"};
	string message;
	string temp_message;
	
	cout << "Enter a secret message :";
	getline(cin, message);
	
	string encrypted_message = message;
	
	//cout << message.length();
	
	for (size_t i {0}; i < message.length(); ++i)
		//for (size_t j {0}; j < message.length(); ++j)
			{
				{
					size_t message_position = alphabet.find(message.at(i))
;					size_t key_position = i;
					encrypted_message.at(i) = key.at(i); 
					
					
					//cout << key.at(key_position);
				}
			}
	cout << "the encryted message is " << encrypted_message << endl;
	
	
	
	
	
	
	/*CODING EXERCISE 20: C++ STRINGS 2
	 * 
	 * void cpp_strings() {
    
    string journal_entry_1 {"Isaac Newton"};
    string journal_entry_2 {"Leibniz"};
    
    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE YOUR CODE BELOW THIS LINE----
    journal_entry_1.erase(0, 6);
    
    if (journal_entry_2 < journal_entry_1)
    {
        journal_entry_2.swap (journal_entry_1);
    }
    
	 * 
	 * CODING EXERCISE 19: CUSING C++ STRINGS

void cpp_strings() {
    
    string unformatted_full_name {"StephenHawking"};
    
    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE YOUR CODE BELOW THIS LINE----
    string first_name {unformatted_full_name, 0, 7};
    string last_name = unformatted_full_name.substr(7, 7);
    string formatted_full_name = first_name + last_name;
    formatted_full_name.insert(7, " ");
    
    
    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    
    cout << formatted_full_name;


 CODING EXERCISE 18 USING C-STYLE STRINGS
	 * void strings_and_functions() {
    
    //----WRITE YOUR CODE BELOW THIS LINE----
    char first_name[] {"Bjarne"};
    char last_name[] {"Stroustrup"};
    char whole_name[50];
    
    size_t first_name_length = strlen(first_name);
    size_t last_name_length = strlen(last_name);
    strcpy(whole_name, first_name);
    strcat(whole_name, last_name);
    size_t whole_name_length {strlen(whole_name)};
    
    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    
    cout << "The length of the first name, " << first_name << ", is " << first_name_length << " letters long and the length of the last name, "
	<< last_name << ", is " << last_name_length << " letters long. This means that the length of the whole name must be "
	<< whole_name_length << " letters long.";
	 * 
	 * 
	 * 
	 * 
	 
	 * */
}



/*******************************NOTES********************************************
 * 93. Overview
 * 	C-style strings				C++ strings
 * 
 * 95. C-Style strings
 * 	Sequence of characters: implemented as array of chars.  terminated a null char
 * 	String literal: sequence of characters in double quotes e.g. "Frank"
 * 	constant.  terminated with null char.  null char is "\0" (we don't see it)
 * 	in the string "Frank" there is a 6th element in the array for the null char \0
 * 	char my_name[] {"Frank};
 * 	can't use the assignment operator = for C-style string variables e.g. char my_name[8];      my_name = Frank; //error
 * 	use strcpy(my_name), "Frank";
 * 	functions in #include <cstring>	strcpy (copy)	strcat (concatenate)	strlen (length)		strcmp (compare)
 * 	#include <cstdlib>		#include <cstring>		#include <cctype>
 * 
 * 96. Working with C-Style Strings
 * 	char first_name[20]{}; //array of chars called first_name initialized with {}
 * 	size_t //unsigned integer
 * 	compiler knows the end of a string by the null character \0
 * 	space in string tell compiler null char, unless cin.getline
 * 	e.g. cin.getline(full_name, 50); //stops either at 50th char or when user presses enter
 * 
 * 97. Using C++ strings
 * 	std::string is a class in the STL
 * 	#include <string>		std namespace		dynamic size		input/output streams		can be converted to C-strings		safer
 * 	operators can be used
 * 
 * 98. Working with C++ strings
 * 	
 * 
 * ********************************************************************************/
