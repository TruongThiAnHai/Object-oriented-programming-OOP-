#pragma once
#ifndef _BOOK1_H
#define _BOOK1_H
#pragma once
#include <iostream>
#include "stdafx.h"
#include <string>


using namespace std;

namespace Books
{
	class publication
	{
	private:
		string author;     //фамилия автора
		string name;       //название издания
		int year;          //год    
		string publishing; //издательство
		int amount;        // количество
	public:
		publication() : publication("", "", 0, "", 0) {}
		publication(string author, string name, int year, string publishing, int amount) : author(author), name(name), year(year), publishing(publishing), amount(amount) {}
		virtual ~publication() {}
		friend ostream& operator<< (ostream&, const publication&);
		string GetAuthor() { return author; }
		string GetName() { return name; }
		int GetYear() { return year; }
		string GetPublishing() { return publishing; }
		int GetAmount() { return amount; }            // вернуть текущее количество   
		publication& getAuthor(string a) { author = a; return *this; }
		publication& getName(string n) { name = n; return *this; }
		publication& getYear(int y) { year = y; return *this; }
		publication& getPublishing(string p) { publishing = p; return *this; }
		publication& getAmount(int am) { amount = am; return *this; }
	};
	class Book
	{

	protected:
		virtual ostream& show(ostream&) const = 0;
	public:
		virtual ~Book() {}

		virtual Book* clone() const = 0;
		friend ostream& operator<< (ostream&, const  Book&);
		virtual string getType() const = 0;
		virtual void changeAmount(int newAmount) = 0;
	};

	class ArtBook : public Book
	{
	private:
		publication book;
		string subject;
	protected:
		virtual ostream& show(ostream& s) const;
	public:

		ArtBook() : book(), subject("") {}
		ArtBook(string author, string name, int year, string publishing, int amount, string subject) : book(author, name, year, publishing, amount), subject(subject) {}
		ArtBook(const publication& p, string subject) : book(p), subject(subject) {}

		//создание копии издания
		virtual ArtBook* clone() const { return new ArtBook(*this); }
		string GetSubject() { return subject; } //вернуть тематику 
		virtual string getType() const { return "Art publication"; }
		virtual void changeAmount(int newAmount);
	};

	class EducationalBook : public Book
	{
	private:
		publication book;
		string course;    //название курса
		int count;        //количество групп         
		string groups[8]; //группы

	protected:
		virtual ostream& show(ostream&) const;
	public:
		EducationalBook() : EducationalBook("", "", 0, "", 0, "", 0, NULL) {}
		EducationalBook(string author, string name, int year, string publishing, int amount, string course, int count, string* groups);
		EducationalBook(const publication& p, string course, int count, string* groups);
		virtual ~EducationalBook() { }

		string GetCourse() { return course; } //вернуть название курса
		string GetGroup(int i) { return groups[i]; }
		//создание копии издания
		virtual EducationalBook* clone() const { return new  EducationalBook(*this); }
		virtual string getType() const { return "Educational publication"; }
		virtual void changeAmount(int newAmount);
	};

	class ScientificBook : public Book
	{
	private:
		publication book;
		string courses[3]; //названия курсов
		int count;         //  количество курсов      

	protected:
		virtual ostream& show(ostream&) const;

	public:
		ScientificBook() : ScientificBook("", "", 0, "", 0, 0, NULL) {}
		ScientificBook(string author, string name, int year, string publishing, int amount, int count, string* courses);
		ScientificBook(const publication& p, int count, string* courses);
		//создание копии издания
		virtual ScientificBook* clone() const { return new  ScientificBook(*this); }

		string GetCourse(int i) { return courses[i]; }
		virtual string getType() const { return "Scientific publication"; }
		virtual void changeAmount(int newAmount);

	};

}
#endif