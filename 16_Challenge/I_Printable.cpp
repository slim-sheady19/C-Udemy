#include "I_Printable.h"
#include <iostream>


//OK
std::ostream &operator<<(std::ostream &os, const I_Printable &obj)
{
	obj.print(os); //calling the I_Printable object's overriden print function
	return os;
}


