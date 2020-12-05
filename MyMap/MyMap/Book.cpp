#include <iostream>
#include "stdafx.h"
#include <string>
#include "Book.h"

using namespace std;

namespace Books
{
	ostream & operator<< (ostream& s, const publication& p)
	{
		s << "Author: " << p.author << endl;
		s << "Name of book: " << p.name << endl;
		s << "Year: " << p.year << endl;
		s << "Publishing: " << p.publishing << endl;
		s << "Amount: " << p.amount << endl;
		return s;
	}
	ostream & operator<< (ostream& os, const  Book& book)
	{
		return book.show(os);
	}

	EducationalBook::EducationalBook(string author, string name, int year, string publishing, int amount, string course, int count, string* groups) :book(author, name, year, publishing, amount), course(course)
	{
		if (count < 0 || count >8) throw exception("Data error!");
		else
		{
			this->count = count;
			for (int i = 0; i < count; i++)
			{
				this->groups[i] = groups[i];

			}
		}
	}
	EducationalBook::EducationalBook(const publication& p, string course, int count, string* groups) :book(p), course(course)
	{
		if (count < 0 || count >8) throw exception("Data error!");
		else
		{
			this->count = count;
			for (int i = 0; i < count; i++)
			{
				this->groups[i] = groups[i];

			}
		}
	}
	ostream& EducationalBook::show(ostream& s) const
	{
		s << "Type of book: " << this->getType() << endl;
		s << book;

		s << "Course: " << course << endl;
		s << "Groups:  ";
		for (int i = 0; i < count; i++)
		{
			s << "Course number " << i + 1 << ": " << groups[i] << endl;
		}
		return s;
	}
	void EducationalBook::changeAmount(int newAmount)
	{
		book.getAmount(newAmount);
	}
	ScientificBook::ScientificBook(string author, string name, int year, string publishing, int amount, int count, string* courses) :book(author, name, year, publishing, amount)
	{
		if (count < 0 || count >3) throw exception("Data error!");
		else
		{
			this->count = count;
			for (int i = 0; i < count; i++)
			{
				this->courses[i] = courses[i];

			}
		}
	}
	ScientificBook::ScientificBook(const publication& p, int count, string* courses) :book(p)
	{
		if (count < 0 || count >3) throw exception("Data error!");
		else
		{
			this->count = count;
			for (int i = 0; i < count; i++)
			{
				this->courses[i] = courses[i];

			}
		}
	}
	ostream& ScientificBook::show(ostream& s) const
	{
		s << "Type of book" << this->getType() << endl;
		s << book;

		s << "Courses:  ";
		for (int i = 0; i < count; i++)
		{
			s << "Course number " << i + 1 << ": " << courses[i] << " " << endl;
		}
		return s;
	}
	void ScientificBook::changeAmount(int newAmount)
	{
		book.getAmount(newAmount);
	}
	ostream& ArtBook::show(ostream& s) const
	{
		s << "Type of book:" << this->getType() << endl;
		s << book;

		s << "Subject: " << subject;
		return s;
	}
	void ArtBook::changeAmount(int newAmount)
	{
		book.getAmount(newAmount);
	}
}