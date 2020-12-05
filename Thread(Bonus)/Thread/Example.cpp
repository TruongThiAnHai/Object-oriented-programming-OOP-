#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <windows.h>
#include <time.h>

using namespace std;

void foo()
{
	cout << "foo" << endl;
}

void bar(int x)
{
	cout << "bar: " << x << endl;

}

int main()
{
	std::thread first(foo);     // spawn new thread that calls foo()
	std::thread second(bar, 0);  // spawn new thread that calls bar(0)
	clock_t t1, t2;
	std::cout << "main, foo and bar now execute concurrently...\n";

	// synchronize threads:
	t1 = clock();
	first.join();                // pauses until first finishes
	second.join();               // pauses until second finishes
	t2 = clock();

	cout << " Time: " << t2 - t1<<endl;

	t1 = clock();
	foo();
	bar(0);
	t2 = clock();

	cout << " Time: " << t2 - t1<<endl;

	std::cout << "foo and bar completed.\n";
	system("pause");

	return 0;
}