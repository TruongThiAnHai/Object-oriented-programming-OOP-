#include <iostream>
#include "Header.h"
#include "Header1.h"
#include <windows.h>
using namespace std;

namespace Prog2
{
	template <class T> 
	int Sequence<T>::size()
	{
		return n;
	}

	template <class T>
	bool Sequence<T>::empty()
	{
			return n == 0;
	}

	template <class T>
	T Sequence<T>::getFirst()
	{
		return seq[0];
	}

	template <class T>
	T Sequence<T>::getLast()
	{
		return seq[n - 1];
	}

	template <class T>
	T Sequence<T>::get(int i)
	{
		return seq[i];
	}

	template <class T>
	void Sequence<T>::append(T& item)
	{
		if (n==0) seq = new T;
		seq[n] = item;
		n++;
	}

	template <class T>
	void Sequence<T>::prepend(T& item)
	{
		if (n == 0) seq = new T;
		for (int i = n; i > 0; i--)
			seq[i] = seq[i - 1];
		seq[0] = item;
		n++;
	}
	template <class T>
	void Sequence<T>::insertat(T& item, int idx)
	{
		if (idx >= 0 && idx <= n)
		{
			n++;
			for (int i = n-1; i > idx; i--)
				seq[i] = seq[i - 1];
			seq[idx] = item;
			
		}
	}

	template <class T>
	void Sequence<T>::remove(int idx)
	{
		if (idx >= 0 && idx < n)
		{
			for (int i = idx; i < n - 1; i++)
				seq[i] = seq[i + 1];
			n--;
		}
		
	}

	template <class T>
	void Sequence<T>::Display()
	{
		for (int i = 0; i < n; i++)
			std::cout <<seq[i]<<"  ";
		std::cout << std::endl;
	}

	template<class T>
	Sequence<T>* Sequence<T>::Sort()
	{
		Prog1::insertionSort(seq, n);
		return this;
	}
	
}
namespace Prog3
{
	void the_sequence()
	{
		int c;
		Prog2::Sequence<int> Seq;
	
		do
		{
			system("cls");
			std::cout << "1. getFirst  element  of sequence \n";
			std::cout << "2. getLast  element  of sequence\n"; 
			std::cout << "3. getElement\n";
			std::cout << "4. Insert element in the last of sequence\n";
			std::cout << "5. Insert element in the first of sequence\n";
			std::cout << "6. Insert element by index\n";
			std::cout << "7. Remove\n";
			std::cout << "8. Arrange the sequences in ascending order\n";//Упорядочить последовательности в порядке возрастания
			std::cout << "9. Show sequence\n";
			std::cout << "10. Quit\n";
			std::cout << "Your chose:";
			std::cin >> c;
			switch (c)
			{
			case 1:
			{
				system("cls");
				if (Seq.size() == 0) std::cout << "Array empty\n";
				else
				{
					int a = Seq.getFirst();
					std::cout << "Sequence:\t";
					Seq.Display();
					std::cout << "\nFirst element =" << a << std::endl;
				}
				
				system("pause");
				break;
			};
			case 2:
			{
				system("cls");
				if (Seq.size() == 0) std::cout << "Array empty\n";
				else
				{
					int a = Seq.getLast();
					std::cout << "Sequence:\t";
					Seq.Display();
					std::cout << "\nLast element =" << a << std::endl;
				}
				
				system("pause");
				break;
			};
			case 3:
			{
				system("cls");
				int i;
				std::cout << "Sequence:\t";
				Seq.Display();
				std::cout << "Enter index element: ";
				std::cin >> i;
				if (Seq.size() == 0) std::cout << "Array empty\n";
				else if (i >= Seq.size()) std::cout << "Erorr! This index doesn't exit\n";
				else
				{
					int a = Seq.get(i);
					std::cout << "\nValue element =" << a << std::endl;
				}
				
				system("pause");
				break;
			};
			case 4:
			{
				system("cls");
				std::cout << "Sequence:\t";
				Seq.Display();
				int a;
				std::cout << "\nEnter value of element: ";
				std::cin >> a;
				Seq.append(a);
				std::cout << "New sequence: ";
				Seq.Display();
				system("pause");
				break;
			};
			case 5:
			{
				system("cls");
				std::cout << "Sequence:\t";
				Seq.Display();
				int a;
				std::cout << "\nEnter value of element: ";
				std::cin >> a;
				Seq.prepend(a);
				std::cout << "New sequence: ";
				Seq.Display();
				system("pause");
				break;
			};
			case 6:
			{
				system("cls");
				std::cout << "Sequence:\t";
				Seq.Display();
				int i;
				std::cout << "\nEnter index: ";
				std::cin >> i;
				if (i >= Seq.size()) std::cout << "This index doesn't exit\n";
				else
				{
					int a;
					std::cout << "\nEnter value of element: ";
					std::cin >> a;
					Seq.insertat(a,i);
					std::cout << "New sequence: ";
					Seq.Display();
				}
				
				system("pause");
				break;
			};

			case 7:
			{
				system("cls");
				std::cout << "Sequence:\t";
				Seq.Display();
				int i;
				std::cout << "\nEnter index of element want to delete: ";
				std::cin >> i;
				if (i >= Seq.size()) std::cout << "Erorr! This index doesn't exit\n";
				else
				{
					Seq.remove(i);
				std::cout << "New sequence: ";
				Seq.Display();

				}
				
				system("pause");
				break;
			};
			case 8:
			{
				system("cls");
				if (Seq.size() == 0) std::cout << "Array empty\n";
				else
				{
					std::cout << "Sequence:\t";
					Seq.Display();
					Seq.Sort();
					std::cout << "New sequence: ";
					Seq.Display();
				}

				system("pause");
				break;
			};
			case 9:
			{
				system("cls");
				std::cout << "Sequence:\t";
				Seq.Display();
				system("pause");
				break;
			};

			}
		} while (c != 10);
	}
}