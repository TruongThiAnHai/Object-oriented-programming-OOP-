#pragma once
namespace Prog1
{
	struct value_list
	{
		int column_index;
		double value;
		struct value_list *next;
	};
	// Node для представления списка строк
	struct row_list
	{
		int row_number;
		struct row_list *link_down;
		struct value_list *link_right;
	};
	template <class T>
	int getNum(T &a)
	{
		std::cin >> a;
		if (!std::cin.good()) return -1;
		return 1;
	};
	int erase(int **a, int m, int n);
	void print_LIL(struct row_list *start);
	int create_row_list(struct row_list **start, int& row, int& column);
	void create_value_node(double data, int j, struct row_list **z);
	void display_matrix(struct row_list *start, int m, int n);
	void result(struct row_list *start, int m, int n);
	int find_max_PositiveNum(struct row_list *start, int m, int n);
	int find_max_NegativeNum(struct row_list *start, int m, int n);
	void change_rows(struct row_list *start, int i, int j);
}