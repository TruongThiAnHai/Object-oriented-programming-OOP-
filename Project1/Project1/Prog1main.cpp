#include <iostream>
#include "Prog1.h"
using namespace Prog1;

int main()
{
	
	int m,n,a;
	struct row_list* start = nullptr;
	a=create_row_list(&start, m, n);
	if (a)
	{
		std::cout << "Incorrect data" << std::endl;
		system("pause");
		return 1;
	}
   // Display data of List of lists
	//print_LIL(start);
	std::cout << "Sourced matrix: " << std::endl;
	display_matrix(start, m, n);
	std::cout << "Resulted matrix: " << std::endl;
	result(start, m, n);
	display_matrix(start, m, n);
	system("pause");
	return 0;
}