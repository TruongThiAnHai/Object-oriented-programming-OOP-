#pragma once
#include <iostream>
#include "stdafx.h"
#include <string>


using namespace std;

namespace Library
{
	class Book
	{

	protected:
		string author;     //фамилия автора
		string name;       //название издания
		int year;          //год    
		string publishing; //издательство
		int amount;        // количество

	public:
		Book() : Book("", "", 0, "", 0) {}
		Book(string author, string name, int year, string publishing, int amount) : author(author), name(name), year(year), publishing(publishing), amount(amount) {}
		virtual ~Book() {}

		virtual Book* clone() const = 0;

		friend ostream& operator<< (ostream&, const  Book&);
		virtual ostream& show(ostream&) const = 0;
		int getAmount() const { return amount; }                      // вернуть текущее количество                            
		void setAmount(int newAmount) { this->amount = newAmount; }   //вводить новое количество       
		void decrement() { (amount == 0 ? 0 : amount--); }            //умешение количества           
		void increment() { amount++; }                                // увеличение количества                                   
		virtual string getType() const = 0;
	};
}