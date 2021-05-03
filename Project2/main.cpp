#include <iostream> //allows input/output

int main()
{
	int favourite_number;
	
	std::cout << "Enter your favourite number:";
	std::cin >> favourite_number;
	std::cout << "that's my favourite number too" << std::endl;
	std::cout << "no really, " << favourite_number << " is my favourite number!" << std::endl;
	return 0;
}
