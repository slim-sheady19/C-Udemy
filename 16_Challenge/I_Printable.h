#ifndef I_PRINTABLE_H
#define I_PRINTABLE_H

#include <iostream>

class I_Printable
{
	friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj); //friend function that returns operator by reference& with paramaters 
																				//reference to ostream os and reference to I_Printable &obj
public:
	virtual void print(std::ostream &os) const = 0;
	virtual ~I_Printable() = default;
};

#endif // I_PRINTABLE_H
