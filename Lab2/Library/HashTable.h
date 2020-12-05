#pragma once
#include <iostream>
#include "stdafx.h"
#include <vector>
#include <map>

#define SIZE 1000
using namespace std;

namespace Search3
{
	template < class TKey, class TElement>
	struct cell
	{
		TKey key;
		TElement info;
		cell* next;
		cell(): next(nullptr) {}
	};

	template < class TKey, class TElement>
	class HashTable //Разрешение коллизий с помощью списков
	{
	private:
		cell<TKey, TElement> *val[SIZE];
		int n = 0;
	public:
		HashTable()
		{ 
			for (int i = 0; i < SIZE; i++)
			{
				val[i] = nullptr;
			}
		}
		~HashTable()
		{
			for (int i = 0; i < SIZE; i++)
			{
				if (val[i])
				{
					delete val[i];
					val[i] = nullptr;
				}
			}
		}

		int GetCount() {return n;}// Количество элементов
		int getHash(TKey key) { return key % SIZE; } //Hash Function
		int Add(TKey key, TElement info); //Добавить элемент с заданным	ключом.
		TElement get(TKey key); // Получение элемента по ключу.
		bool ContainsKey(TKey key); //Проверка, что в таблице уже есть элемент с заданным ключом.
		void print();
	
	};
	template <class TKey, class TElement>
	bool HashTable<TKey, TElement>::ContainsKey(TKey key)
	{
		int hkey = getHash(key);
		bool res = false;
		for (cell<TKey, TElement> *curr = val[hkey]; curr != nullptr; curr = curr->next)
		{
			if (curr->key == key)
			{
				res = true;
				break;
			}
		}
		return res;
	}

	template <class TKey, class TElement>
	int HashTable<TKey, TElement>::Add(TKey key, TElement info)
	{
		int hkey = getHash(key);
		if (ContainsKey(key) == true)
		{
			throw exception("This key is exist");
			return -1;
		}
			
		else
		{
			if (val[hkey] == nullptr)
			{
				val[hkey] = new cell<TKey, TElement>;
				val[hkey]->key = key;
				val[hkey]->info = info;
				n++;
			}
			else
			{
				cell<TKey, TElement> *x= new cell<TKey, TElement>;
				x->key = key;
				x->info = info;
				x->next = val[hkey];
				val[hkey] = x;
				n++;

			}
			
		}
		return 1;
	}

	template <class TKey, class TElement>
	TElement HashTable<TKey, TElement>::get(TKey key)
	{
		bool res = false;
		int hkey = getHash(key);
		for (cell<TKey, TElement> *curr = val[hkey]; curr != nullptr; curr = curr->next)
		{
			if (curr->key == key)
			{
				res = true;
				return curr->info;
			}
		}
		if (res==false)
			throw exception("This key does not exist!");
	}

	template <class TKey, class TElement>
	void  HashTable<TKey, TElement>::print()
	{
		for (int i = 0; i < SIZE; i++)
		{
			if (val[i])
			{
				cout << "Slot: " << i << endl;

				for (cell<TKey, TElement> *curr = val[i]; curr != nullptr; curr = curr->next)
				{
					cout << "Key: " << curr->key << endl;
					cout << curr->info << endl;
				}
			}
		}
	}

}