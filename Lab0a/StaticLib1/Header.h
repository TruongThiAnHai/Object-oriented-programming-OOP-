#ifndef _LIB_H_
#define _LIB_H_ 

#include <iostream>
#include "stdafx.h" 

using namespace std;
namespace Prog1
{
	template <class T>
	class ArraySequence
	{
	private:
		T *seq;
		int n = 0;

	public:
		ArraySequence() : n(0), seq(nullptr) {};
		int size();//Длина последовательности 
		T getFirst();//Получить первый элемент последовательности
		T getLast();//Получить последний элемент последовательности
		T get(int i);//Получение элемента по индексу
		bool empty();//проверить, что является ли последовательность пустой
		void append(T& item);//Добавить элемент в конец последовательности
		void prepend(T& item);//Добавить элемент в начало последовательности
		void insertat(T& item, int idx);//Добавить элемент по индексу
		void remove(int idx);//Удаляет элемент из последовательности. Если элемента не было, ничего не происходит.
		void Display();
	};
	template <class T>
	int  ArraySequence<T>::size()
	{
		return n;
	}

	template <class T>
	bool  ArraySequence<T>::empty()
	{
		return n == 0;
	}

	template <class T>
	T  ArraySequence<T>::getFirst()
	{
		return seq[0];
	}

	template <class T>
	T  ArraySequence<T>::getLast()
	{
		return seq[n - 1];
	}

	template <class T>
	T  ArraySequence<T>::get(int i)
	{
		if ((i < 0) || (i >= n)) throw exception("This index doesn't exit!");
		return seq[i];
	}

	template <class T>
	void  ArraySequence<T>::append(T& item)
	{
		if (n == 0) seq = new T;
		seq[n] = item;
		n++;
	}

	template <class T>
	void ArraySequence<T>::prepend(T& item)
	{
		if (n == 0) seq = new T;
		for (int i = n; i > 0; i--)
			seq[i] = seq[i - 1];
		seq[0] = item;
		n++;
	}
	template <class T>
	void  ArraySequence<T>::insertat(T& item, int idx)
	{
		if (idx >= 0 && idx <= n)
		{
			n++;
			for (int i = n - 1; i > idx; i--)
				seq[i] = seq[i - 1];
			seq[idx] = item;

		}
	}

	template <class T>
	void  ArraySequence<T>::remove(int idx)
	{
		if (idx >= 0 && idx < n)
		{
			for (int i = idx; i < n - 1; i++)
				seq[i] = seq[i + 1];
			n--;
		}

	}

	template <class T>
	void  ArraySequence<T>::Display()
	{
		for (int i = 0; i < n; i++)
			std::cout << seq[i] << "  ";
		std::cout << std::endl;
	}
}

#endif

