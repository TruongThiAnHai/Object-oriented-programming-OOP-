
#include <iostream>
#include "stdafx.h"
#include <vector>
#include "Book.h"
#include <algorithm>

using namespace std;
using namespace Books;

namespace MyTemplate1
{
	template<class T>
	class MyMap
	{
	private:
		vector<pair<int,T>> info;
	public:
		MyMap() {};
		~MyMap() { info.clear(); }
		MyMap(const MyMap<T>& m) {*this = m;}
		MyMap(MyMap<T>&& m) { *this = m; m.info.clear(); }

		MyMap<T> operator=(const MyMap<T>&);
		int size() { return info.size(); }
		pair<int, T> getbyIndex(int i);
		void add(pair<int, T>);
		int remove(int);
		T* find(int);
		void clearAll();
		void printf();
	};
	
	class Lib
	{
	private:
		MyMap<Book*> book;
	public:
		Lib() {};      //пустой конструктор
		~Lib() { book.clearAll(); }  //деструктор
		Lib(const Lib& L);     //копирующий конструктор
		Lib(Lib&& L);         //перемещающий конструктор


		void insert(int code, Book* b);                    //добавить описатель
		void getBook(int code);                           //вернуть  информацию  издания по шифру 
		void deleteBook(int code);                        //удалить издание
		void showAll();
	};

}

namespace MyTemplate1
{
	template <class T>
	MyMap<T> MyMap<T>::operator=(const MyMap<T>& m)
	{
		MyMap<T> p;
		pair<int, T> val;
		int size = m.info.size();
		for (int i = 0; i < size; i++)
		{
			val = m.info[i];
			p.info.push_back(val);
		}
		return p;
	}

	template<class T>
	void MyMap<T>::add(pair<int, T> val)
	{
		if (info.size() == 0) info.push_back(val);
		else
		{
			int size = info.size();
			for (int i = 0; i < size; i++)
			{
				if (info[i].first == val.first)
				{
					throw exception("This key is exist!");
					return;
				}

			}
			int i = info.size();
			info.push_back(val);
			while (info[i].first < info[i - 1].first)
			{
				swap(info[i], info[i - 1]);
				i--;
				if (i == 0) break;
			}

		}
	}
	template<class T>
	pair<int, T> MyMap<T>::getbyIndex(int i)
	{
		if (i >= this->size()) throw exception("This index does not exist!");
		return info[i];
	}
	template<class T>
	int MyMap<T>::remove(int key)
	{
		bool res = false;
		int index;
		int size = info.size();
		for (int i = 0; i < size; i++)
		{
			if (info[i].first == key)
			{
				index = i;
				res = true;
				break;
			}
		}
		if (res == false)
		{
			throw exception("This key does not exist!");
			return -1;
		}
		else
		{
			for (int i = index; i < size - 1; i++)
			{
				swap(info[i], info[i + 1]);
			}
			info.pop_back();
			return 1;
		}
	}

	template<class T>
	T* MyMap<T>::find(int key)
	{
		int index;
		bool res = false;
		int size = info.size();
		for (int i = 0; i < size; i++)
		{
			if (info[i].first == key)
			{
				index = i;
				res = true;
				break;
			}
		}
		if (res == false)
		{
			throw exception("This key does not exist!");
			return nullptr;
		}
		else
		{
			T* val = new T;
			*val = info[index].second;
			return val;
		}

	}

	template<class T>
	void MyMap<T>::clearAll()
	{
		info.clear();
	}

	template<class T>
	void MyMap<T>::printf()
	{
		int size = info.size();
		for (int i = 0; i < size; i++)
		{
			cout << "Key: " << info[i].first << endl;
			cout << "Info: " << info[i].second << endl;
		}
	}

	Lib::Lib(const Lib& L)
	{
		book = L.book;
	}

	Lib::Lib(Lib&& L)
	{
		book = L.book;
		L.book.clearAll();
	}

	void Lib::insert(int code, Book* b)
	{
		if (book.find(code)) throw exception("This code is exist!");
		else
		{
			pair<int, Book*> val(code, b->clone());
			book.add(val);
		}

	}

	void Lib::getBook(int code)
	{
		Book* val = *book.find(code);

		if (!val) throw exception("This code does not exist!");
		else
		{
			cout << val << endl;
		}
	}

	void Lib::deleteBook(int code)
	{
		if (!book.find(code)) throw exception("This code  does not exist!");
		else
		{
			book.remove(code);
		}
	}

	void Lib::showAll()
	{
		book.printf();
	}
}