#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include "Binary_search_by_sorted-sequence.h"
#include "BinarySearchingTree.h"
#include "HashTable.h"
#include "Header.h"

using namespace std;
namespace App
{
	const string Menu[] = { "1.Binary_search_by_sorted-sequence ", "2. BinarySearchingTree", "3. HashTable", "4. Compare","0. Quit" };
	const int Num = sizeof(Menu) / sizeof(Menu[0]);
	void SortedSequence();
	void BinaryTree();
	void HashTable();
	void Compare();

	int main()
	{
		int c;
		const char *msg = "";
		do
		{
			system("cls");
			for (int i = 0; i < Num; i++)
			{
				cout << Menu[i].c_str() << endl;
			}
			cout << "Your choice:------>";
			do
			{
				cout << msg;
				prog::getInt(c);
				msg = "Error! Repeat, please!";

			} while (c > 4);
			switch (c)
			{
			case 1: SortedSequence(); break;
			case 2: BinaryTree(); break;
			case 3: HashTable(); break;
			case 4: Compare(); break;
			}
			msg = "";
		} while (c != 0);

		cout << "\n\n" << endl;
		cout << "--------------That's all! Bye!--------------------------";
		return 0;
	}

	void SortedSequence()
	{
		int c, key;
		Search1::SortedSequence<prog::Student> Seq;
		do
		{
			system("cls");
			std::cout << "1. getFirst  element  of sequence \n";
			std::cout << "2. getLast  element  of sequence\n";
			std::cout << "3. getElement by key\n";
			std::cout << "4. Add element  by key\n";
			std::cout << "5.Show sequence\n";
			std::cout << "0. Quit\n";
			std::cout << "Your chose:";
			prog::getInt(c);
			switch (c)
			{
			case 1:
			{
				system("cls");
				if (Seq.size() == 0) std::cout << "sequence empty\n";
				else
				{
					cout << Seq.getFirst() << endl;
				}

				system("pause");
				break;
			};
			case 2:
			{
				system("cls");
				if (Seq.size() == 0) std::cout << "sequence empty\n";
				else
				{
					cout << Seq.getLast() << endl;
				}

				system("pause");
				break;
			};
			case 3:
			{
				system("cls");
				std::cout << "Enter key: ";
				prog::getInt(key);
				if (Seq.size() == 0) std::cout << "sequence empty\n";
				try
				{
					cout << Seq.search(key) << endl;
				}
				catch (const std::exception &er)
				{
					std::cout << er.what() << std::endl;
				}
				system("pause");
				break;
			};
			case 4:
			{
				system("cls");
				cout << "Enter key: ";
				prog::getInt(key);
				prog::Student info;
				cin >> info;
				try
				{
					Seq.add(key, info);
					cout << "Added!" << endl;
				}
				catch (const std::exception &er)
				{
					std::cout << er.what() << std::endl;
				}

				system("pause");
				break;
			};
			case 5:
			{
				system("cls");
				std::cout << "Sequence:\t";
				Seq.Display();
				system("pause");
				break;
			};

			}
		} while (c != 0);
	}

	void BinaryTree()
	{
		int c, key;
		Search2::BinaryTree<prog::Student> Tree;
		do
		{
			system("cls");
			std::cout << "1. getFirst  element  of Tree \n";
			std::cout << "2. getLast  element  of Tree\n";
			std::cout << "3. getElement by key\n";
			std::cout << "4. Add element  by key\n";
			std::cout << "5.Show Tree\n";
			std::cout << "0. Quit\n";
			std::cout << "Your chose:";
			prog::getInt(c);
			switch (c)
			{
			case 1:
			{
				system("cls");
				if (!Tree.isEmpty()) std::cout << "Tree empty\n";
				else
				{
					cout << Tree.getFirst() << endl;
				}

				system("pause");
				break;
			};
			case 2:
			{
				system("cls");
				if (!Tree.isEmpty()) std::cout << "Tree empty\n";
				else
				{
					cout << Tree.getLast() << endl;
				}

				system("pause");
				break;
			};
			case 3:
			{
				system("cls");
				std::cout << "Enter key: ";
				prog::getInt(key);
				if (!Tree.isEmpty()) std::cout << "Tree empty\n";
				try
				{
					cout << Tree.find(key) << endl;
				}
				catch (const std::exception &er)
				{
					std::cout << er.what() << std::endl;
				}
				system("pause");
				break;
			};
			case 4:
			{
				system("cls");
				cout << "Enter key: ";
				prog::getInt(key);
				prog::Student info;
				cin >> info;
				try
				{
					Tree.insert(key, info);
					cout << "Added!";
				}
				catch (const std::exception &er)
				{
					std::cout << er.what() << std::endl;
				}

				system("pause");
				break;
			};
			case 5:
			{
				system("cls");
				Tree.print_inorder();
				system("pause");
				break;
			};

			}
		} while (c != 0);
	}

	void HashTable()
	{
		int c, key;
		Search3::HashTable<prog::Student> Tab;
		do
		{
			system("cls");
			std::cout << "1. getElement by key\n";
			std::cout << "2. Add element  by key\n";
			std::cout << "0. Quit\n";
			std::cout << "Your chose:";
			prog::getInt(c);
			switch (c)
			{
			case 1:
			{
				system("cls");
				std::cout << "Enter key: ";
				prog::getInt(key);
				try
				{
					cout << Tab.get(key) << endl;
				}
				catch (const std::exception &er)
				{
					std::cout << er.what() << std::endl;
				}
				system("pause");
				break;
			};
			case 2:
			{
				system("cls");
				cout << "Enter key: ";
				prog::getInt(key);
				prog::Student info;
				cin >> info;
				try
				{
					Tab.Add(key, info);
					cout << "Added!";
				}
				catch (const std::exception &er)
				{
					std::cout << er.what() << std::endl;
				}

				system("pause");
				break;
			};


			}
		} while (c != 0);
	}

	void Compare()
	{

	}
}
