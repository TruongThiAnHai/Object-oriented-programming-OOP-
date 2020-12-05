#ifndef _LIB2_H_
#define _LIB2_H_ 

#include <iostream>
#include "stdafx.h" 

using namespace std;
namespace Prog1
{
	template <class N>
	class Node
	{
	public:
		N value;
		Node<N> *next;
		
	};
	template <class T>
	class ListSequence
	{
	private:
		Node<T> *seq;
		int n = 0;

	public:
		ListSequence();
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
	template<class T>
	ListSequence<T>::ListSequence()
	{
		this->seq = nullptr;
		this->n = 0;
	}
	template <class T>
	int ListSequence<T>::size()
	{
		return n;
	}

	template <class T>
	bool ListSequence<T>::empty()
	{
		return n == 0;
	}

	template <class T>
	T ListSequence<T>::getFirst()
	{
		Node<T> *P = this->seq;
		return P->value;
	}

	template <class T>
	T ListSequence<T>::getLast()
	{
		Node<T> *P = this->seq;
		while (P->next != 0)
		{
			P = P->next;
		}
		return P->value;
	}

	template <class T>
	T ListSequence<T>::get(int i)
	{
		int j = 0;
		if ((i < 0) || (i >= n)) throw exception("This index doesn't exit!");
		Node<T> *Q = this->seq;
		while (Q != nullptr && j != i)
		{
			j++;
			Q = Q->next;
		}
		return Q->value;
	}

	template <class T>
	void ListSequence<T>::append(T& item)
	{
		if (n == 0) prepend(item);
		else
		{
			int i = 0;
			Node<T>* newnode = new Node<T>;
			Node<T>* Q = this->seq;
			newnode->value = item;
			newnode->next = nullptr;
			while (Q != nullptr && i != n - 1)
			{
				i++;
				Q = Q->next;
			}
			Q->next = newnode;
			n++;
		}
		
	}

	template <class T>
	void ListSequence<T>::prepend(T& item)
	{
		Node<T>* newnode = new Node<T>;
		newnode->value = item;
		newnode->next = this->seq;
		this->seq = newnode;
		n++;
	}
	template <class T>
	void ListSequence<T>::insertat(T& item, int idx)
	{
		Node<T>* newnode = new Node<T>;
		Node<T>* Q = this->seq;
		int i = 0;
		if (idx<0 || idx>= n) throw exception ("This index doesn't exit!");
		else
		{
			newnode->value = item;
			newnode->next = nullptr;
			if (idx == 0) prepend(item);
			else 
			{
				while (Q != nullptr && i != idx - 1) 
				{
					i++;
					Q = Q->next;
				}
				newnode->next = Q->next;
				Q->next = newnode;
			}
		}
		n++;
	}

	template <class T>
	void ListSequence<T>::remove(int idx)
	{
		Node<T> *P = this->seq;
		int i = 0;
		if (idx < 0 || idx >= n) throw exception("This index doesn't exit!");
		else
		{
			if (idx == 0)
			{
				P = P->next;
			}
			else
			{
				while (P != nullptr && i != idx - 1)
				{
					P = P->next;
					i++;
				}
				P->next = P->next->next; 
			}
		}
		n--;

	}

	template <class T>
	void ListSequence<T>::Display()
	{
		Node<T>* newnode = this->seq;
		while (newnode != nullptr)
		{
			std::cout << newnode->value << "  ";

			newnode = newnode->next;
		}
		std::cout << std::endl;
	}
}

#endif


