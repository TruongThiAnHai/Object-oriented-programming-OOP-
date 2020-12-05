#include<iostream>
#include <ctime>
#include "Header1.h"
#include "Header.h"
#include <windows.h>
using namespace std;
using namespace Prog2;
void RandomNumber(int a)////массив не отсортирован
{
	std::cout << "\n-------------------Array not sorted----------------\n\n";
	int  i;
	
	int *arr;
	arr = new int[a];
	for (i = 0; i < a; i++)
	{
		arr[i] = Prog1::randint();
	}

	int *arr1;
	arr1 = new int[a];
	for (i = 0; i < a; i++)
	{
		arr1[i] = *(arr + i);
	}
	std::cout << "Insertion Sort\t";
	int b1, b2;
	b1 = clock();
	Prog1::insertionSort(arr1, a);
	b2 = clock();
	std::cout << "Time= " << b2 - b1 << std::endl;

	int *arr2;
	arr2 = new int[a];
	for (i = 0; i < a; i++)
	{
		arr2[i] = *(arr + i);
	}
	std::cout << "Selection Sort\t";
	int c1, c2;
	c1 = clock();
	Prog1::selectionSort(arr2, a);
	c2 = clock();
	std::cout << "Time= " << c2 - c1 << std::endl;

	int *arr3;
	arr3 = new int[a];
	for (i = 0; i < a; i++)
	{
		arr3[i] = *(arr + i);
	}
	std::cout << "Shaker Sort\t";
	int d1, d2;
	d1 = clock();
	Prog1::shakerSort(arr3, a);
	d2 = clock();
	std::cout << "Time= " << d2 - d1 << std::endl;

	int *arr4;
	arr4 = new int[a];
	for (i = 0; i < a; i++)
	{
		arr4[i] = *(arr + i);
	}
	std::cout << "Bubble Sort\t";
	int a1, a2;
	a1 = clock();
	Prog1::bubbleSort(arr4, a);
	a2 = clock();
	std::cout << "Time= " << a2 - a1 << std::endl;
}
void SortedArray(int n)////массив уже отсортирован в нужном направлении
{
	std::cout << "\n------------------Array already sorted in the right direction--------------\n\n";
	int  i;

	int *arr;
	arr = new int[n];
	for (i = 0; i < n; i++)
	{
		arr[i] = Prog1::randint();
	}
	Prog1::insertionSort(arr, n);
	std::cout << "Insertion Sort\t";
	int b1, b2;
	b1 = clock();
	Prog1::insertionSort(arr, n);
	b2 = clock();
	std::cout << "Time= " << b2 - b1 << std::endl;

	std::cout << "Selection Sort\t";
	int c1, c2;
	c1 = clock();
	Prog1::selectionSort(arr, n);
	c2 = clock();
	std::cout << "Time= " << c2 - c1 << std::endl;

	std::cout << "Shaker Sort\t";
	int d1, d2;
	d1 = clock();
	Prog1::shakerSort(arr, n);
	d2 = clock();
	std::cout << "Time= " << d2 - d1 << std::endl;

	std::cout << "Bubble Sort\t";
	int a1, a2;
	a1 = clock();
	Prog1::bubbleSort(arr, n);
	a2 = clock();
	std::cout << "Time= " << a2 - a1 << std::endl;


}
void Array_sorted_in_reverse(int n)//массив отсортирован в обратном направлении
{
	std::cout << "\n-----------------Array sorted in reverse-----------------\n\n";
	int  i;

	int *a;
	a = new int[n];
	for (i = 0; i < n; i++)
	{
		a[i] = Prog1::randint();
	}
	Prog1::insertionSort(a, n);
	int *arr;
	arr = new int[n];
	for (i = 0; i < n; i++)
	{
		arr[i] = a[n-1-i];
	}
	int *arr1;
	arr1 = new int[n];
	for (i = 0; i < n; i++)
	{
		arr1[i] = *(arr + i);
	}
	std::cout << "Insertion Sort\t";
	int b1, b2;
	b1 = clock();
	Prog1::insertionSort(arr1, n);
	b2 = clock();
	std::cout << "Time= " << b2 - b1 << std::endl;

	int *arr2;
	arr2 = new int[n];
	for (i = 0; i < n; i++)
	{
		arr2[i] = *(arr + i);
	}
	std::cout << "Selection Sort\t";
	int c1, c2;
	c1 = clock();
	Prog1::selectionSort(arr2, n);
	c2 = clock();
	std::cout << "Time= " << c2 - c1 << std::endl;

	int *arr3;
	arr3 = new int[n];
	for (i = 0; i <n; i++)
	{
		arr3[i] = *(arr + i);
	}
	std::cout << "Shaker Sort\t";
	int d1, d2;
	d1 = clock();
	Prog1::shakerSort(arr3, n);
	d2 = clock();
	std::cout << "Time= " << d2 - d1 << std::endl;

	int *arr4;
	arr4 = new int[n];
	for (i = 0; i < n; i++)
	{
		arr4[i] = *(arr + i);
	}
	std::cout << "Bubble Sort\t";
	int a1, a2;
	a1 = clock();
	Prog1::bubbleSort(arr4, n);
	a2 = clock();
	std::cout << "Time= " << a2 - a1 << std::endl;
}
void SortArray()
{
	system("cls");
	int n;
	std::cout << "Enter number of element in array: ";
	std::cin >> n;
	RandomNumber(n);
	SortedArray(n);
	Array_sorted_in_reverse(n);
	system("pause");
}
void main()
{
	int a;
	do
	{
		system("cls");
		std::cout << "1. Comparison of various sorting algorithms \n";//сравнение различных алгоритмов сортировки
		std::cout << "2. The Sequence\n";//Абстрактный тип данных «Последовательность». 
		std::cout << "3. Quit\n";
		std::cout << "Your chose:";
		std::cin >> a;
		switch (a)
		{
			case 1: SortArray(); break;
			case 2: Prog3::the_sequence(); break;
		}
	} while (a != 3);
	
}