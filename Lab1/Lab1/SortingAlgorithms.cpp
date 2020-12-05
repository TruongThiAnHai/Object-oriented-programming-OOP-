#include<iostream>
#include<cstdlib>
#include"Header1.h"


namespace Prog1
{
	void bubbleSort(int a[], int n)
	{
		int i, j;
		bool haveSwap = true;
		for (i = 0; i < n; i++)
		{
			haveSwap = false;
			for (j = 0; j < n - i; j++)
			{
				if (a[j] > a[j + 1])
				{
					swap(a[j], a[j + 1]);
					haveSwap = true; 
				}
			}
			if (haveSwap == false) break;
			
		}
	}
	void insertionSort(int a[], int n)
	{
		int i, tg, x;
		for (i = 1; i < n; i++)
		{
			tg = a[i];
			x = i - 1;
			while ((x >= 0) && (a[x] > tg))
			{
				a[x + 1] = a[x];
				x--;
			}
			a[x + 1] = tg;
		}
	}
	void selectionSort(int a[], int n)
	{
		for (int i = 0; i < n - 1; i++)
		{
			int iMin = i;
			for (int j = i + 1; j < n; j++)
			{
				if (a[iMin] > a[j])
					iMin = j;
			}
			if (i != iMin)
				swap(a[i], a[iMin]);
		}
	}
	void shakerSort(int a[], int n)
	{
		int i;
		int Left = 0;
		int Right = n - 1;
		int k = 0;
		while (Left < Right)
		{
			for (int i = Left; i < Right; i++)
			{
				if (a[i] > a[i + 1])
				{
					swap(a[i], a[i + 1]);
					k = i;
				}
			}
			Right = k;
			for (i = Right; i > Left; i--)
			{
				if (a[i] < a[i - 1])
				{
					swap(a[i], a[i - 1]);
					k = i;
				}
			}
			Left = k;
		}
	}
	int randint()
	{
		return rand();
	};
	void swap(int x, int y)
	{
		int swapInt;

		swapInt = x;
		x = y;
		y = swapInt;
	};
	
	
}
