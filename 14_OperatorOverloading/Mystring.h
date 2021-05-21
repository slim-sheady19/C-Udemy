#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                                                         // No-args constructor
    Mystring(const char *s);                                     // Overloaded constructor
    Mystring(const Mystring &source);                    // Copy constructor
	Mystring(Mystring &&source);							//Move constructor
    ~Mystring();                                                      // Destructor
    
    Mystring &operator=(const Mystring &rhs);       // Copy assignment
	Mystring &operator=(Mystring &&rhs);			// Move assignment.  don't use const in rhs because we will be nullifying the string attribute
    
	Mystring operator-() const;						//Overloading the - operator as a member method, unary operator take no paramaters.
													//Make lowercase
	Mystring operator+(const Mystring &rhs) const;	//binary operator so we need 1 paramater
													//concatenate
	bool operator==(const Mystring &rhs) const;		//binary so it expects one paramater.  
	
	
    void display() const;

    int get_length() const;                                       // getters
    const char *get_str() const;
};

#endif // _MYSTRING_H_
