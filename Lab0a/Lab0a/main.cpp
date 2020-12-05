#include <iostream>
#include "Header.h"
#include <windows.h>
using namespace std;
using namespace Prog1;

void main()
{
	int c;
	Prog1::ArraySequence<int> Seq;

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
		std::cout << "8. Show sequence\n";
		std::cout << "9. Quit\n";
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
				Seq.insertat(a, i);
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
			std::cout << "Sequence:\t";
			Seq.Display();
			system("pause");
			break;
		};

		}
	} while (c != 9);
}
