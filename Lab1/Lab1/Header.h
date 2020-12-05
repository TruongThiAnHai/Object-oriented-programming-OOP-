#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
namespace Prog2
{
	template <class T>
	class Sequence
	{
	private:
		T *seq;
		int n = 0;

	public:
		int size();//Длина последовательности 
		T getFirst();//Получить первый элемент последовательности
		T getLast();//Получить последний элемент последовательности
		T get(int i);//Получение элемента по индексу
		bool empty();//проверить, что является ли последовательность пустой
		void append(T& item);//Добавить элемент в конец последовательности
		void prepend(T& item);//Добавить элемент в начало последовательности
		void insertat(T& item, int idx);//Добавить элемент по индексу
		void remove(int idx);//Удаляет элемент из последовательности. Если элемента не было, ничего не происходит.
		void Display();
		Sequence* Sort();////Упорядочить последовательности в порядке возрастания
	};
}
namespace Prog3
{
	void the_sequence();
}



