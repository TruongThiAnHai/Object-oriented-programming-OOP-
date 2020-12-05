#include <iostream>
#include <windows.h>
#include "Vector_2.h"

using namespace std;
using namespace Prog3_2;

int main()
{
	Vector vt;
	cout << "1. Input vector vt:" << endl;
	vt.input();
	cout << "\nVector vt: "<<vt;
	cout << "\n\n2. Find max element in the vector vt:" << endl;
	cout << "Max element = " << vt.findMax() << endl;
	Vector vt1(vt);
	cout << "\n\n3. Ordering vector vt ascending: " << endl;
	vt1.Ordering_Vector_Ascending();
	cout << "\nVector: "<<vt1;
	cout << "\n\n4. Selection of part of the vector: " << endl;
	Vector vt2(vt);
	int l, i;
	const char *pr = "";
	cout << "\nEnter distance: ";
	do
	{
		cout << pr;
		getInt(l);
		pr = "You are wrong! Repeat please!\n";
	} while (l > vt2.size());
	pr = "";
	cout << "Enter index of element: ";
	do
	{
		cout << pr;
		getInt(i);
		pr = "You are wrong! Repeat please!\n";
	} while (i + l > vt2.size());
	pr = "";
	Vector v2;
	v2=vt2.part_of_vector(l, i);
	cout << endl;
	cout << "Vector new: "<<v2;
	cout << "\nVector vt:" << vt2;
	cout << "\n\n5. Addition of two vectors: " << endl;
	Vector vt3, vt4(vt);
	for (i = 0; i < vt.size(); i++)
	{
		vt3.push(3 * i + 10);
	}
	cout << "\nVector new: ";
	cout << vt3;
	cout << "\nSum of vector vt and vector new:  vt+new= " << vt4+vt3;//перегруженный оператор
	cout << "\n\n6. Add new element to the vector: " << endl;
	int item;
	cout << "\nEnter value of new element:";
	getInt(item);
	vt.push(item);
	cout << "\nVector vt: "<<vt<<endl;
	system("pause");
	return 1;
}