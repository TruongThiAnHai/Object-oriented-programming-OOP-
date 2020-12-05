#include<iostream>
#include "Vector_3.h"
#include <windows.h>
using namespace Prog3_3;
using namespace std;

void DisplayMatrix(Vector vt, int m, int n)
{
	if (m == 0 && n==0)
		cout << "Matrix is empty";
	else
		for (int i = 0; i < m*n; i++)
		{
			cout <<"  "<<vt.value(i) << "\t";
			if ( (i + 1) % n == 0)
				cout << endl;

		}
	cout <<endl;
}

int main()
{
	int x, m, n;
	Vector vt1, vt2;
	
	int f1 = 1;
	while (f1)
	{
		cout << "===================================================" << endl;
		cout << "Enter number lines of matrix to continue or precc any key except numbers to quit:";
		cin >> m;
		f1 = cin.good();
		if (!f1) continue;
		cout << "Enter number columns of matrix: ";
		getInt(n);
		cout << "\nInput elements of matrix A: " << endl;
		for (int i = 0; i < m*n; i++)
		{
			getInt(x);
			vt1.push(x);
		}
		cout << "\nMatrix A: \n";
		DisplayMatrix(vt1, m, n);

		cout << "\nInput elements of matrix B: " << endl;
		for (int i = 0; i < m*n; i++)
		{
			getInt(x);
			vt2.push(x);
		}
		cout << "\nMatrix B: \n";
		DisplayMatrix(vt2, m, n);

		cout << "\nMatrix A + Matrix B: "<<endl;
		Vector vt3;
		vt3 = vt2 + vt1;
		DisplayMatrix(vt3, m, n);
		vt1.remove(0, m*n);//удалить все элементы в векторе
		vt2.remove(0, m*n);
	} 
	cout << "===============That's all!=================\n";
	system("pause");
	return 0;
}