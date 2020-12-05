#ifndef _VECTOR_2_H_
#define _VECTOR_2_H_

#include <iostream>

using namespace std;

namespace Prog3_2
{
	int getInt(int &a);
	class Vector
	{
	private:
		static const int MaxSize = 100;
		int vt[MaxSize];
		int n;
	public:
		Vector() :n(0) {}
		Vector(int const a);
		Vector(int const a[], const int m);
		void input();
		void push(int item);//включение в вектор нового элемента
		int findMax();//найти максимальный элемент
		int value(int i);//значение элемента index i
		int size() const { return n; }
		void Ordering_Vector_Ascending();//упорядочение вектора по возрастанию
		Vector & remove(int index, int l);//удалить часть вектора
		Vector& operator +(Vector &vt1);//сложение двух векторов
		Vector part_of_vector(int l, int i);//выделение части вектора
		friend ostream& operator <<(ostream &s, const Vector &vector);
	};

}
#endif

