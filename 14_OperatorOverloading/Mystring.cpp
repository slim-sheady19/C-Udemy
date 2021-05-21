#include <cstring>
#include <iostream>
#include "Mystring.h"

// No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[std::strlen(s)+1];
            std::strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[std::strlen(source.str) + 1];
        std::strcpy(str, source.str);
}

// Move constructor NOT assignment, so this creates a new object based on r-value reference
Mystring::Mystring(Mystring &&source)
	:str(source.str) //steal pointer from source object and moving it to left-hand side object str
	{
		source.str = nullptr; //nullify source object pointer
		std::cout << "Move constructer used" << std::endl;
	}


// Destructor
Mystring::~Mystring() {
    delete [] str;
}

// Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
    std::cout << "Copy assignment" << std::endl;
    if (this == &rhs)
        return *this;
    delete [] this->str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(this->str, rhs.str);
    return *this;
}

//Move assignment
Mystring &Mystring::operator=(Mystring &&rhs)
{
	std::cout << "Using Move assignment" <<std::endl;
	if (this == &rhs)
	{
		return *this;
	}
	delete [] str;
	str = rhs.str;
	rhs.str = nullptr;
	return *this;
}
//Equality
bool Mystring::operator==(const Mystring &rhs) const
{
	return std::strcmp(str, rhs.str) == 0;
}

//Make lowercaSE
Mystring Mystring::operator-() const
{
	//create copy of current object, make it lower case, then create new object from it
	char *buff = new char[std::strlen(str) +1]; //create temporary space on heap for new array of chars called buff with length of str + 1
	std::strcpy(buff, str);							//copy string in str to buff
	for (size_t i=0; i<std::strlen(buff); i++) //loop through buff
		buff[i] = std::tolower(buff[i]);		//set each char in buff to lower case
	Mystring temp {buff};						//create new object called temp of type Mystring intitalized to buff.
	delete [] buff;								//deallocate buff's space otherwise memory leak
	return temp;								
		
}

//Concatenate
Mystring Mystring::operator+(const Mystring &rhs) const
{
	char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1]; //temporary object array of chars on heap with length of both strings
	std::strcpy(buff, str);	 				//copy str in to buff											
	std::strcat(buff, rhs.str);				//concatenate rhs.str in to buff
	Mystring temp {buff};					//new object temp of type Mystring
	delete [] buff;
	return temp;
}

// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// getters
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }

