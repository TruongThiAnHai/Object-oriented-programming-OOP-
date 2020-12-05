#include <iostream>
#include "stdafx.h"
#include <string>
#include "Book.h"

using namespace std;

namespace Library
{
	ostream & operator<< (ostream& s, const  Book& book)
	{
		s << "Author: ";
		s << book.author;
		s << "Name of book: " << book.name << endl;
		s << "Year: " << book.year << endl;
		s << "Publishing: " << book.publishing << endl;
		s << "Amount: " << book.amount << endl;
		s << std::endl;
		book.show(s);
		return s;
	}
}