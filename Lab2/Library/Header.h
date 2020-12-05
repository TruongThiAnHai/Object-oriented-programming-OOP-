
#include <iostream>
#include "stdafx.h"
#include <string>
#include <algorithm>

using namespace std;

namespace prog
{
	int getInt(int &a)
	{
		while (!(std::cin >> a))
		{
			std::cerr << "Enter integer please!\n";
			cin.clear(); //бросить failbit of cin
		}
		return 1;
	}
	class Student
	{
	private:
		string name_of_student;
		float score;
	public:
		Student() : Student("", 0) {}
		Student(string name,  float score) : name_of_student(name), score(score) {}
		~Student() {}

		friend ostream& operator<< (ostream&, const  Student&);
		friend istream& operator>>(istream&,  Student&);
	};
	ostream & operator<< (ostream& s, const Student& st)
	{
		s << "Name of student: " << st.name_of_student << endl;
		s << "Score: " << st.score << endl;
		return s;
	}
	istream& operator>>(istream&c, Student& st)
	{
		cout << "Name of student : ";
		c >> st.name_of_student;
		cout << "Score: ";
		c >> st.score;
		return c;

	}
}