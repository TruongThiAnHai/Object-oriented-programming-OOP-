

#include <iostream>
#include "Book.h"
#include "Library.h"
#include <string>
#include <windows.h>

using namespace std;
using namespace Books;
using namespace Table;

const string Name[] = {"Unknow", "Art Books","Educational Books", "Scientific Books" };
const string Menu[] = { "1. Add books", "2. Find books by cod", "3. Delete books", "4. Show all", "5.Change Amount of books", "0. Quit" };

int Add(Library &), Find(Library &), Delete(Library &), ShowAll(Library &), ChangeAmount(Library&);
int(*Funcs[])(Library &) = { nullptr, Add, Find, Delete, ShowAll, ChangeAmount };

const int Num = sizeof(Menu) / sizeof(Menu[0]);
int main()
{
	Library lib;
	int c;  
	const char *msg ="";
	do
	{
		system("cls");
		for (int i = 0; i < Num; i++)
		{
			cout << Menu[i].c_str() <<endl;
		}
		cout << "Your choice:------>";
		do 
		{
			cout << msg;
			getInt(c);
			msg ="Error! Repeat, please!";

		} while (c > 5);
		if (c!=0) Funcs[c](lib);
		msg = "";
	} while (c != 0);

	cout << "\n\n" << endl;
	cout << "--------------That's all! Bye!--------------------------";
	return 0;
}

const string Bk[] = { "1. ArtBooks", "2. EducationalBooks", "3. ScientificBooks", "0. Quit" }; 
const int NumBook = sizeof(Bk) / sizeof(Bk[0]);

ArtBook addArtbook(string author, string name, int year, string publishing, int amount)
{
	string subject;
	cout << "Enter subject of artbooks:";
	cin >> subject;
	ArtBook ab(author, name, year, publishing, amount, subject);
	return ab;
}
EducationalBook addEducationalbook(string author, string name, int year, string publishing, int amount)
{
	string course;    //название курса
	int count;        //количество групп         
	string groups[8]; //группы
	const char *msg = "";
	cout << "Enter  course:---->";
	cin >> course;
	do
	{
		cout << msg;
		cout << "Enter number of groups:----->";
		getInt(count);
		msg = "Error! Repeat, please!";
	} while (count > 8 || count < 1);
	
	cout << "Enter groups:" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << "Enter course number " << i+1 << ":---->";
		cin >> groups[i];
	}

	EducationalBook ed( author,name, year,publishing, amount,course, count,groups);
	return ed;
}

ScientificBook addScientificbook(string author, string name, int year, string publishing, int amount)
{
	string courses[3]; //названия курсов
	int count;         //  количество курсов  
	const char *msg = "";
	cout << "Enter number of courses:----->";
	cin >> count;
	cout << "Enter course:" << endl;
	do
	{
		cout << msg;
		cout << "Enter number of groups:----->";
		getInt(count);
		msg = "Error! Repeat, please!";
	} while (count > 3 || count < 1);
	for (int i = 0; i < count; i++)
	{
		cout << "Enter course number "<<i+1 << ":--->";
		cin >> courses[i];
	}
	ScientificBook sb(author, name, year, publishing, amount, count, courses);
	return sb;
}
int Add(Library &lib)
{
	system("cls");
	Book *ptr = nullptr;
	ArtBook A;
	EducationalBook B;
	ScientificBook C;
	string author;     //фамилия автора
	string name;       //название издания
	int year;          //год    
	string publishing; //издательство
	int amount;			 // количество экземпляров
	int c, code;
	const char *msg = "";
	do
	{
		cout << endl;
		for (int i = 0; i < NumBook; i++)
		{
			cout << Bk[i].c_str() << endl;
		}
		cout << "Your choice:------>";
		do
		{
			cout << msg;
			getInt(c);
			msg = "Error! Repeat, please!";

		} while (c > 3);
		if (c != 0)
		{
			cout << endl;
			cout << "Enter author:---->";
			cin >> author;
			cout << "Enter name of books:---->";
			cin >> name;
			cout << "Enter year of publication:---->";
			getInt(year);
			cout << "Enter publishing:---->";
			cin >> publishing;
			cout << "Enter  amount:---->";
			getInt(amount);
			switch (c)
			{
			case 1:
				A = addArtbook(author, name, year, publishing, amount);
				ptr = new ArtBook(A);
				break;
			case 2:
				B = addEducationalbook(author, name, year, publishing, amount);
				ptr = new EducationalBook(B);
				break;
			case 3:
				C = addScientificbook(author, name, year, publishing, amount);
				ptr = new ScientificBook(C);
				break;
			}
			msg = "";
			cout << "Enter code of books:------>";
			getInt(code);
			cout << endl;
			try
			{
				lib.insert(code, ptr);
				cout << "Ok. Books are added!" << endl;
			}
			catch (const exception &er)
			{
				cout << "Can not add!" << " ";
				cout << er.what() <<endl;
			}
		}

	} while (c != 0);
	system("pause");
	return 0;
}

int Find(Library &lib)
{
	system("cls");
	int code;
	cout << "Enter code of book you want to find:------>";
	getInt(code);
	try
	{
		lib.getBook(code);
	}
	catch (const std::exception &er)
	{ 
		std::cout << er.what() << std::endl;
	}
	system("pause");
	return 0;
}

int Delete(Library &lib)
{
	system("cls");
	int code;
	cout << "Enter code of book you want to delete:------>";
	getInt(code);
	try
	{
		lib.deleteBook(code);
		cout << "Deleted!" << endl;
	}
	catch (const std::exception &er)
	{
		std::cout << er.what() << std::endl;
	}
	system("pause");
	return 0;
}

int ShowAll(Library &lib)
{
	system("cls");
	cout << lib << endl;
	system("pause");
	return 0;
}

int ChangeAmount(Library &lib)
{
	system("cls");
	int code,n;
	cout << "Enter code of books you want to change amount:------>";
	getInt(code);
	try
	{
		cout << "Enter new amount:---->";
		getInt(n);
		lib.change_Amount(code,n);
		cout << "\tChanged! New information:" << endl;
		 lib.getBook(code);
	}
	catch (const std::exception &er)
	{
		std::cout << er.what() << std::endl;
	}
	system("pause");
	return 0;
}