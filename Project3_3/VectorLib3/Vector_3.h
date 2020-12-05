#ifndef _VECTOR_3_H_
#define _VECTOR_3_H_

#include <iostream>

using namespace std;

namespace Prog3_3
{
	int getInt(int &a);
	class Vector
	{
	private:
		int *vt;
		int n;//текущий размер
	public:
		Vector() :n(0), vt(nullptr) {}
		Vector(int a);
		Vector(int a[], int m);
		Vector(Vector&& v1);//перемешаюший конструктор
		Vector(const Vector& v1);//копирующий конструктор
		~Vector() { delete[] vt;}//деструктор
		void input();//ввод экземляра класса из входного потока
		Vector &operator =(const Vector &v1);//перегруженный оператор присваивания
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


