#ifndef _VECTOR_1_H_
#define _VECTOR_1_H_

#include <iostream>
#include <vector>

using namespace std;

namespace Prog3_1
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
		Vector(int const a[], int m);
		void input();
		void output();
		void push(int item);//включение в вектор нового элемента
		int findMax();//найти максимальный элемент
		int value(int i);//значение элемента index i
		int size() const { return n; }
		void Ordering_Vector_Ascending();//упорядочение вектора по возрастанию
		Vector& addition(Vector &vt1);//сложение двух векторов
		Vector part_of_vector(int l, int i);//выделение части вектора
		Vector & remove(int index, int l);//удалить часть вектора

	};

}
#endif
