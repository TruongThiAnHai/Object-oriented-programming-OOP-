#include <iostream>
#include <string>
#include <fstream>
//#include <windows.h>
#include <map>

using namespace std;


int main()
{
	
		//вставляемая строка
		string insertString;
		cout << "Enter the insertion string: ";
		getline(cin, insertString);
		string decTo2;
		cout << insertString.size() << endl;
		//преобразование ascii кода вставляемой строки в двоичный вид
		for (size_t ind = 0; ind <insertString.size(); ++ind) {
			int ascii = (int)insertString[ind];
			cout << ascii << endl;
			string binary;
			do {
				binary = to_string(ascii % 2).c_str() + binary;
				ascii = (int)ascii / 2;
			} while (ascii > 0);
			decTo2 += binary;
		}
		cout << decTo2<<endl;
	system("pause");
	return 0;
}