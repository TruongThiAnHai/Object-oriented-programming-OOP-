#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "stdafx.h"

using namespace std;

namespace Search1
{
	template  < class TKey, class TElement>
	struct Node
	{
		TKey key;
		TElement info;
	};

	template  < class TKey, class TElement>
	class SortedSequence // отсортированная последовательность
	{
	private:
		vector<Node<TKey, TElement>> seq;
	
	public:
		SortedSequence() {}
		~SortedSequence() { seq.clear(); }
		int size() {return seq.size();}//Длина последовательности 
		TElement getFirst();//Получить первый элемент последовательности
		TElement getLast();//Получить последний элемент последовательности
		TElement search(TKey key);//найти элемент по ключу
		int add(TKey key, TElement info);//добавить новый элемент, не нарушая упорядоченности
		void Display();//показать последовательность
	};

	template  < class TKey, class TElement>
	TElement SortedSequence<TKey, TElement>::getFirst()
	{
		return seq[0].info;
	}

	template  < class TKey, class TElement>
	TElement SortedSequence<TKey, TElement>::getLast()
	{
		int n = seq.size() - 1;
		return seq[n].info;
		
	}
	template  < class TKey, class TElement>
	int SortedSequence<TKey, TElement>::add(TKey key, TElement info)
	{
		Node<TKey, TElement> newNode;
		newNode.key = key;
		newNode.info = info;
		if (seq.size() == 0)
		{
			seq.push_back(newNode);
		}
		else
		{
			int size = seq.size();
			for (int i = 0; i < size; i++)
			{
				if (seq[i].key ==key)
				{
					throw exception("This key is exist!");
					return -1;
				}

			}
			int i = seq.size();
			seq.push_back(newNode);
			while (seq[i].key < seq[i - 1].key)
			{
				swap(seq[i], seq[i - 1]);
				i--;
				if (i == 0) break;
			}
					
		}
		return 1;
	}
		


	template < class TKey, class TElement>
	TElement SortedSequence<TKey, TElement>::search(TKey key)
	{
		bool res = false;
		int mid;
		int min = 0;
		int max = seq.size() - 1;
		while (min <= max)
		{
			mid = (min + max) / 2;

			if (seq[mid].key == key)
			{
				return seq[mid].info;
			}

			else if (seq[mid].key > key)
				max = mid - 1;
			else
				min = mid + 1;
		}

		if (res==false) throw exception("This key does not exist!");
	}


	template  < class TKey, class TElement>
	void SortedSequence<TKey, TElement>::Display()
	{
		int n = seq.size();
		for (int i=0;i<n;i++)
		{
			cout << "Key: " << seq[i].key << endl;
			cout << seq[i].info <<endl;
		}
		std::cout << std::endl;
	}

}