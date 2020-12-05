#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include "Vector_2.h"

using namespace std;

namespace Prog3_2
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
	Vector::Vector(int const a)
	{
		vt[0] = a;
		n = 1;
	}
	Vector::Vector(int const a[],const int m)
	{
		if (m > MaxSize) throw exception("Vector overflow!");
		else
		{
			for (int i = 0; i < m; ++i)
			vt[i] = a[i];
			n = m;
		}
		
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
			if (n > MaxSize)
			{
				cout << "Vector overflow";
			}
			pr = "You are wrong! Repeat please!";
		} while (n<0 || n>MaxSize);
		pr = "";
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

	void Vector::Ordering_Vector_Ascending()//Сортировка вставками
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
	
		return *this;
	}
	Vector Vector::part_of_vector(int l, int i)
	{
		Vector v2;
		if (l < 0 || i < 0)  throw exception("Incorrect data!");
		if (l > n || (i + l) > n)  throw exception("Incorrect data!");
		else
		{
			for (int j = i; j < l + i; j++)
			{
				v2.push(vt[j]);
			}
			this->remove(i, l);
		}
		return v2;
	}
	ostream & operator <<(ostream &s, const Vector &vector)
	{
		if (vector.n == 0)  
			s << "Vector is empty"; 
		else  
			for (int i = 0; i <vector.size() ; i++)  
				s << vector.vt[i] << ' ';

		s << std::endl;  
		return s; 
	}

}