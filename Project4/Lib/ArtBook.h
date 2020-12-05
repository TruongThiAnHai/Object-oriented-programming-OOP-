#pragma once
#include<iostream>
#include "stdafx.h"
#include "Book.h"
#include <string>

using namespace std;

namespace Library
{

	class ArtBook : public Book
	{
	private:
		string subject;
	protected:
		virtual ostream& show(ostream& s) const { s << "Type of book" << this->getType() << endl; s << "Subject: " << this->subject; return s; }

	public:
		ArtBook() : ArtBook("", "", 0, "", 0, "") {}
		ArtBook(string author, string name, int year, string publishing, int amount, string subject) : Book(author, name, year, publishing, amount), subject(subject) {}

		//создание копии издания
		virtual ArtBook* clone() const { return new ArtBook(*this); }

		virtual string getType() const { return "Art publication"; }
		string getSubject() const { return subject; }   //вернуть тематику литературного прроизведения        
	};
}