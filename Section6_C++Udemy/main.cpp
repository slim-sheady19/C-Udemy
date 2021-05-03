#include <iostream> //allows input/output
using namespace std;

int main()
{
	int SmallRooms{0};
	int LargeRooms {0};
	
	cout << "Estimate for carpet cleaning service:\n";
	cout << "Number of small rooms? Price is $25 each\n";
	cin >> SmallRooms;
	cout << "Number of Largew rooms? Price is $35 each\n";
	cin >> LargeRooms;
	cout << "Number of small rooms is " << SmallRooms << endl;
	cout << "Number of Large rooms is " << LargeRooms << endl;
	cout << "Cost is " << (SmallRooms*25 + LargeRooms*35) << endl;
	cout << "Tax is " << ((SmallRooms*25 + LargeRooms*35)*.06) << endl;
	cout << "Total is " << ((SmallRooms*25 + LargeRooms*35) + ((SmallRooms*25 + LargeRooms*35)*.06)) << endl;
	cout << "This estimate is valid for 30 days" << endl;
	
	
}
