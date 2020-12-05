#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include "Vector_3.h"

using namespace std;

namespace Prog3_3
{
	int getInt(int &a)
	{
		while (!(std::cin >> a))
		{
			std::cerr << "Enter integer please!\n";
			cin.clear(); //бросить failbit of cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // удалить лишние символы, оставшиеся в cin
		}
		return 1;
	}
	Vector::Vector(int a):n(1), vt(new int[1])
	{
		vt[0] = a;
	}
	Vector::Vector(int a[], int m)
	{
		vt = new int[m];
		for (int i = 0; i < m; ++i)
			vt[i] = a[i];
			
		n = m;
	}
	Vector::Vector(const Vector& v1)
	{

		n = v1.size();
		vt = new int[n];
		for (int i = 0; i < n; i++)
		{
			vt[i] = v1.vt[i];
		}
	}
	Vector::Vector(Vector&& v1)
	{
		n = v1.size();
		vt = v1.vt;
		v1.vt = nullptr;
		v1.n=0;
	}
	void Vector::input()	
	{
		int a;
		const char *pr = "";
		do
		{
			cout << pr << endl;
			cout << "Enter size of vector: ";
			getInt(n);
			pr = "You are wrong! Repeat please!";
		} while (n<0);
		pr = "";
		vt = new int[n];
		cout << "\nEnter value of element of the vector:\n";

		for (int i = 0; i < n; i++)
		{
			cout << "Value of element " << i << ":";
			getInt(a);
			vt[i] = a;
		}
	}

	int Vector::value(int i)
	{
		if (i < 0 || i >= n) throw exception("This index doesn't exit!");
		else return vt[i];
	}
	void Vector::push(int item)
	{
		int *old = vt;
		vt = new int[n+1];  
		for (int i = 0; i < n; ++i)  
		vt[i] = old[i];   
		delete[] old;  
		vt[n] = item;
		n++;
	}

	int Vector::findMax()
	{
		int max = vt[0];
		for (int i = 0; i < n; i++)
		{
			if (vt[i] > max)
				max = vt[i];
		}
		return max;
	}

	void Vector::Ordering_Vector_Ascending()
	{
		int i, tg, x;
		for (i = 1; i < n; i++)
		{
			tg = vt[i];
			x = i - 1;
			while ((x >= 0) && (vt[x] > tg))
			{
				vt[x + 1] = vt[x];
				x--;
			}
			vt[x + 1] = tg;
		}

	}

	Vector& Vector::operator+(Vector& vt1)
	{
		if (vt1.size() != n) throw exception("Different sizes. Can not add!");
		else
		{
			for (int i = 0; i < n; i++)
			{
				vt[i] = vt[i] + vt1.value(i);
			}
		}
		return *this;
	}
	Vector& Vector::operator=(const Vector& v1)
	{
		if (this != &v1)
		{
			n = v1.n;
			delete[] vt;
			vt = new int[n];
			for (int i = 0; i < n; i++)
				vt[i] = v1.vt[i];
		}
		return *this;
	}
	Vector & Vector::remove(int index, int l)
	{
		if (index < 0 || index >= n) throw exception("This index doesn't exit!");
		else
		{
			for (int i = index; i < n - 1; i++)
			{
				vt[i] = vt[i + l];
			}
			n = n - l;
		}
		if (n == 0) vt = nullptr;
		else
		{
			int *old = vt;
			vt = new int[n];
			for (int i = 0; i < n; ++i)
				vt[i] = old[i];
			delete[] old;
		}
		return *this;
	}
	Vector Vector::part_of_vector(int l, int i)
	{
		Vector vector;
		if (l < 0 || i < 0)  throw exception("Incorrect data!");
		if (l > n || (i + l) > n)  throw exception("Incorrect data!");
		else
		{
			for (int j = i; j < l + i; j++)
			{
				vector.push(vt[j]);
			}
			this->remove(i, l);
		}
		return vector;
	}
	ostream & operator <<(ostream &s, const Vector &vector)
	{
		if (vector.n == 0)
			s << "Vector is empty";
		else
			for (int i = 0; i < vector.size(); i++)
				s << vector.vt[i] << ' ';

		s << std::endl;
		return s;
	}

}