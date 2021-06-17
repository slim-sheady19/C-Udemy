// Section 17
// Challenge 1
/***********************************************************************************************************
Create a program that has the following:

1. a function named make that creates and returns a unique_ptr to a vector of shared_ptrs to Test objects. 

2. a function named fill that expects a vector of shared pointers to Test objects and a int
   representing the number of Test objects to create dynamically and add to the vector.
   
   This function will prompt the user to enter an integer, create a shared_ptr to a Test object 
   initialized to the entered integer and add that shared pointer to the vector.
   
3. a function named display that expects a vector of shared_ptrs to Test object and displays the
   data in each Test object
   
4. The main driver should look as follows:

    int main() {
        std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
        vec_ptr = make();
        std::cout << "How many data points do you want to enter: ";
        int num;
        std::cin >> num;
        fill(*vec_ptr, num);
        display(*vec_ptr);
        return 0;
    }
    
Below is a sample run for the user entering 3 at the console:
    
How many data points do you want to enter: 3
Enter data point [1] : 10
        Test constructor (10)
Enter data point [2] : 20
        Test constructor (20)
Enter data point [3] : 30
        Test constructor (30)
Displaying vector data
=======================
10
20
30
=======================
        Test destructor (10)
        Test destructor (20)
        Test destructor (30)

- I am providing the function prototypes in the code. 
However, feel free to modify these as you wish
***********************************************************************************************************/
#include <iostream>
#include <memory>
#include <vector>

class Test {
private:
    int data;
public:
    Test() : data{0} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    Test(int data) : data {data} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    int get_data() const {return data; }
    ~Test() {std::cout << "\tTest destructor (" << data << ")" << std::endl; }
};

// Function prototypes
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();			//function make that returns a unique_ptr to a vector of shared_ptrs.  can also use auto make()
void fill(std::vector<std::shared_ptr<Test>> &vec, int num);
void display(const std::vector<std::shared_ptr<Test>>&vec);

int main() {
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr; 		//here we make a unique pointer object to a vector of shared pointers called vec_ptr on the stack
    vec_ptr = make();
    std::cout << "How many data points do you want to enter: ";
    int num;
    std::cin >> num;			//ask user for how many data points they want and store in num
    fill(*vec_ptr, num);		
    display(*vec_ptr);		
    return 0;
}

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make()				//can also use auto make()
{
	return std::make_unique<std::vector<std::shared_ptr<Test>>>();			//OK except Needed to call constructor for the vector!!!! () at the end
}

void fill(std::vector<std::shared_ptr<Test>> &vec, int num)
{
	//MISUNDERSTOOD QUESTION
	/*for (int i{0}; i < num; i++)	//OK
	{
		std::shared_ptr<Test> ptr {new Test};
		vec.push_back(ptr);
		std::cout << "Enter an initializer int ";
		int init;
		std::cin >> init;
		std::shared_ptr<int> p_shared<Test>(init);
		vec.push_back(p_shared);
	}*/
	int init;
	for (int i{0}; i < num; ++i)
	{
		std::cout << "Enter an initializer int ";
		std::cin >> init;
		//std::shared_ptr<Temp> ptr = std::make_shared<Test>(init);  can do in two steps or one-> see below
		//vec.push_back(ptr);
		vec.push_back(std::make_shared<Test>(init));
	}
}

void display(const std::vector<std::shared_ptr<Test>>&vec)
{
	for (const auto &tests: vec) //OK
	{
		std::cout << tests->get_data() << std::endl; //OK
	}
}
