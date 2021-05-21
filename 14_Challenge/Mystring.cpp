#include <iostream>
#include <cstring>
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
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
 //       std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring( Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
//        std::cout << "Move constructor used" << std::endl;
}

 // Destructor
Mystring::~Mystring() {
    delete [] str;
}

 // Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
//    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=( Mystring &&rhs) {
	std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

//Lowercase assignment
Mystring Mystring::operator-() const
{
	std::cout << "Lowercase operator called" << std::endl;
	char *buff = new char[std::strlen(str) + 1]; //create space on heap for the new array
	std::strcpy(buff, str);
	for (size_t i{0}; i < std::strlen(buff); i++)
	{
		buff[i] = std::tolower(buff[i]);
	}
	Mystring temp {buff};
	delete [] buff;
	return temp;
}

Mystring Mystring::operator+(const Mystring &rhs) const
{
	char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1]; //temporary object array of chars on heap with length of both strings
	std::strcpy(buff, str);	 				//copy str in to buff											
	std::strcat(buff, rhs.str);				//concatenate rhs.str in to buff
	Mystring temp {buff};					//new object temp of type Mystring
	delete [] buff;
	return temp;
}

Mystring &Mystring::operator+=(const Mystring &rhs)
{
	std::cout << "calling += operator" << std::endl;
	std::strcat(str, rhs.str);
	
}

Mystring Mystring::operator*(const int n)
{
	char *buff = new char[std::strlen(str)*n + 1];
	int buff_pos{0};
	for (int i {0}; i < n; i++)
	{
		for (int j {0}; j < std::strlen(str); j++)
		{
			buff[buff_pos] = str[j];
			buff_pos++;
		}
	}
	Mystring temp {buff};
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

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}

