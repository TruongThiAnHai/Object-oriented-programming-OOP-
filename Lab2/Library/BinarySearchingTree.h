#pragma once
#include <iostream>
#include "stdafx.h"

using namespace std;

namespace Search2
{
	template < class TKey, class TElement>
	struct Node
	{
		Node *Left;
		Node *Right;
		TElement info;
		TKey key;
		Node() : Left(nullptr), Right(nullptr) {}
	};

	template < class TKey, class TElement>
	class BinaryTree
	{
	protected:
		Node<TKey, TElement> *Root;
	public:
		BinaryTree() : Root(nullptr) {}
		~BinaryTree() { this->deleteTree(Root); }

		bool isEmpty() const { return Root == nullptr; }
		int insert(TKey key, TElement); //добавить новый элемент
		TElement getFirst();//Получить первый элемент 
		TElement getLast();//Получить последний элемент
		TElement find(TKey key); // найти элемент по ключ
		void print_inorder(); //показать BinaryTree
		void inorder(Node<TKey, TElement>*); //Обходы: Left->Root->Right
		TElement findMax(Node<TKey, TElement> *t);
		TElement findMin(Node<TKey, TElement> *t);
		void deleteTree(Node<TKey, TElement>*&);

	};

	template < class TKey, class TElement>
	int BinaryTree<TKey, TElement>::insert(TKey key, TElement info)
	{
		Node<TKey, TElement> *t = new Node<TKey, TElement>;
		t->info = info;
		t->key = key;
		Node<TKey, TElement>* parent;
		parent = nullptr;

		if (isEmpty()) Root = t;// это новое дерево
		else
		{
			// Примечание: ВСЕ вставки являются листовыми узлами
			Node<TKey, TElement>* curr;
			curr = Root;
			// Найти родителя узла
			while (curr)
			{
				parent = curr;
				if (t->key==curr->key)
				{
					throw exception("This key is exist!");
					return -1;
				}
				else if (t->key > curr->key) curr = curr->Right;
				else curr = curr->Left;
			}

			if (t->key < parent->key)
				parent->Left = t;
			else
				parent->Right = t;
		}
		return 1;
	}

	template < class TKey, class TElement>
	TElement BinaryTree<TKey, TElement>::find(TKey key)
	{
		bool found = false;
		if (isEmpty()) throw exception("This Tree is empty!");

		Node<TKey, TElement>* curr;
		Node<TKey, TElement>* parent;
		curr = Root;
		parent = nullptr;
		while (curr != nullptr)
		{
			if (curr->key == key)
			{
				found = true;
				break;
			}
			else
			{
				parent = curr;
				if (key > curr->key) curr = curr->Right;
				else curr = curr->Left;
			}
		}
		if (found == false) throw exception("This key does not exist!");
		return curr->info;
	}

	template <class TKey, class TElement>
	TElement BinaryTree<TKey, TElement>::findMax(Node<TKey, TElement> *t)
	{
		if (t->Right == nullptr)
				return t->info;
			else
				return findMax(t->Right);
	}
	template <class TKey, class TElement>
	TElement BinaryTree<TKey, TElement>::getLast()
	{
		TElement last;
		last = this->findMax(Root);
		return last;
	}
	template <class TKey, class TElement>
	TElement BinaryTree<TKey, TElement>::findMin(Node<TKey, TElement> *t)
	{
		if (t->Left == nullptr)
			return t->info;
		else
			return findMin(t->Left);
	}
	template <class TKey, class TElement>
	TElement BinaryTree<TKey, TElement>::getFirst()
	{
		TElement first;
		first = this->findMin(Root);
		return first;
	}

	template <class TKey, class TElement>
	void BinaryTree<TKey, TElement>::print_inorder()
	{
		inorder(Root);
	}

	template <class TKey, class TElement>
	void BinaryTree<TKey, TElement>::inorder(Node<TKey, TElement>* p)
	{
		if (p != nullptr)
		{
			if (p->Left) inorder(p->Left);
			cout << "Key: " << p->key << endl;
			cout << p->info << endl;
			if (p->Right) inorder(p->Right);
		}
		else return;
	}

	template <class TKey, class TElement>
	void BinaryTree<TKey, TElement>::deleteTree(Node<TKey, TElement>*& t)
	{
		if (t == nullptr)
		{
			return;
		}
		if (t->Left)
		{
			deleteTree(t->Left);
		}
		if (t->Right)
		{
			deleteTree(t->Right);
		}
		delete t;
		t = nullptr;
	}

}

