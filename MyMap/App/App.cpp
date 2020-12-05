#include<iostream>
#include <map>
#include "Book.h"
#include "MyMap.h"
#include <windows.h>


using namespace std;
using namespace MyTemplate;

int main()
{
		BinaryTree<int> T;
		int key,info,c;
		Node<int>* p,*k;

		for (int i = 0; i < 5; i++)
		{
			cout << "Enter key: ";
			cin >> key;
			cout << "Enter info: ";
			cin >> info;
			p=new Node<int>;
			pair<int, int> value(key, info);
			p->info = value;
			T.insert(p);
		}

		cout << endl;
		T.print_inorder();
		cout << endl;
		cout << "Node has key=5: ";
		k=T.find(5);
		cout << k->info.second;
		cout << "Node want to clear: ";
		cin >> c;
		T.remove(c);
		cout << endl;
		T.print_inorder();
		BinaryTree<int> T2;
		T2 = T;
		cout << endl;
		T2.print_inorder();
		system("pause");
		return 1;
		
}
	
