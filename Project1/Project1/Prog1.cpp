#include <iostream>
#include "Prog1.h"

namespace Prog1
{
	// Функция для создания Node для ненулевых элементов
	void create_value_node(double data, int j, struct row_list **z)
	{
		struct value_list *temp, *d;

		// Создать новый node динамически
		temp = new value_list;
		temp->column_index = j;
		temp->value = data;
		temp->next = nullptr;

		// Подключение к списку строк
		if ((*z)->link_right == nullptr)
			(*z)->link_right = temp;
		else
		{
			// d указывает to data list node
			d = (*z)->link_right;
			while (d->next != nullptr)
				d = d->next;
			d->next = temp;
		}
	}

	// Функция создания списка строк
	//Вводиться только ненулевые элементы
	int create_row_list(struct row_list **start, int& row, int& column)
	{
		const char *pr = "";
		double a;
		int m,n,k,b;
		do
		{
			std::cout << pr << std::endl;
			std::cout << "Enter number of rows: ";
			pr = "You are wrong, repet!";
			if (getNum(m) < 0) return 1;
		} while (m < 1);
		row = m;
		pr = "";
		do
		{
			std::cout << pr << std::endl;
			std::cout << "Enter number of columns: ";
			pr = "You are wrong, repet!";
			if (getNum(n) < 0) return 1;
		} while (n < 1);
		column = n;
		// Для каждой строки создается node
		for (int i = 0; i < row; i++)
		{
			struct row_list *z, *r;

			// Создать новый node динамически
			z = new row_list;
			z->row_number = i;
			z->link_down = nullptr;
			z->link_right = nullptr;
			if (i == 0)
				*start = z;
			else
			{
				r = *start;
				while (r->link_down != nullptr)
					r = r->link_down;
				r->link_down = z;
			}
			// Создается первый node для строки,
			std::cout << "\nEnter number of non-zero in row " << i << ":";//количество ненулевых чисел
			getNum(k);
			while ((k >= n) || (k < 0))

			{
				std::cout << "Error! Repet!";
				getNum(k);
			}
			for (int j = 0; j < k; j++)
			{
				std::cout << "column=";
				getNum(b);
				while ((b >= n)||(b<0))

				{
					std::cout << "Error! Repet!";
					getNum(b);
				}
				std::cout << "value=";
				if (getNum(a) < 0)
				{
					return 1;
				}
				create_value_node(a, b, &z);
			} 
			
		}

		return 0;
	}
	int find_max_PositiveNum(struct row_list *start, int m, int n)
	{
		struct row_list *r;
		struct value_list *z;
		int i;
		r = start;
		int *a = new int[m];
		for ( i = 0; i < m; i++)
		{
			a[i] = 0;
		}
		for (i = 0; i < m; i++)
		{
			z = r->link_right;
			if (z == nullptr) a[i] = 0;
			else while (z != nullptr)
			{
				if ((z->value) > 0) a[i]++;
				z = z->next;
			}
			r = r->link_down;
		}
		int max = 0;
		for ( i = 0; i < m; i++)
		{
			if (a[i] > a[max]) max = i;
		}
		return max;
	}
	int find_max_NegativeNum(struct row_list *start, int m, int n)
	{
		struct row_list *r;
		struct value_list *z;
		int i;
		r = start;
		int *a = new int[m];
		for (i = 0; i < m; i++)
		{
			a[i] = 0;
		}
		for (i = 0; i < m; i++)
		{
			z = r->link_right;
			if (z == nullptr) a[i] = 0;
			else while (z != nullptr)
			{
				if ((z->value) < 0) a[i]++;
				z = z->next;
			}
			r = r->link_down;
		}
		int max = m-1;
		for (i = 0; i < m; i++)
		{
			if (a[i] > a[max]) max = i;
		}
		return max;
	}
	void change_rows(struct row_list *start, int i, int j)
	{
	
		struct value_list *z1,*z2;
		struct row_list *r;
		while (start->row_number != i)
			start = start->link_down;
		z1 = start->link_right;
		r = start;
		while (start->row_number != j)
			start = start->link_down;
		z2 = start->link_right;
		start->link_right= z1; 
		r->link_right = z2;
	
	}
	void change_rows(struct row_list *start, int j)
	{

		struct value_list *z1, *z2;
		struct row_list *r;
		r = start;
		z1 = start->link_right;
		while (start->row_number != j)
			start = start->link_down;
		z2 = start->link_right;
		start->link_right = z1;
		r->link_right = z2;

	}
	void result(struct row_list *start, int m, int n)
	{
		int a = find_max_PositiveNum(start, m, n);
		int b= find_max_NegativeNum(start, m, n);
		change_rows(start, 0, a);
		change_rows(start, b, m-1);
	}

	void display_matrix(struct row_list *start, int m, int n)
	{
		struct row_list *r;
		struct value_list *z;
		r = start;
		while (r != nullptr)
		{
			z = r->link_right;
			for (int i = 0; i < n; i++)
			{
				if (z == nullptr) std::cout << "0 ";
				else if ((z->column_index) == i)
				{
					std::cout <<z->value<<" ";
					z = z->next;
				}
				else std::cout << "0 ";
			}
			std::cout << std::endl;
			r = r->link_down;

		}
	}
	void print_LIL(struct row_list *start)
	{
		struct row_list *r;
		struct value_list *z;
		r = start;

		while (r != nullptr)
		{
			if (r->link_right != nullptr)
			{
				std::cout << "row= " << r->row_number << std::endl;
				z = r->link_right;
				while (z != nullptr)
				{
					std::cout << "column=" << z->column_index << " value=" << z->value << std::endl;
					z = z->next;
				}
			}
			r = r->link_down;
		}
	}

	int erase(int **a, int m, int n)
	{
		for (int i = 0; i < m; i++)
			delete[]a[i];
		delete[]a;
		return 0;
	}
	
}