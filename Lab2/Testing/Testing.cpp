#include "gtest\gtest.h" 
#include <string>
#include <windows.h>
#include <vector>
#include "Binary_search_by_sorted-sequence.h"
#include "BinarySearchingTree.h"
#include "HashTable.h"
#include "Header.h"


using namespace std;
using namespace Search1;
using namespace  Search2;
using namespace Search3;
using namespace prog;

TEST(TestSortedSequence, TestMethod)
{
	Search1::SortedSequence<int,int> seq;
	for (int i = 0; i < 5; i++)
	{
		seq.add(i, i);
	}
	ASSERT_EQ(5, seq.size());
	ASSERT_EQ(0, seq.getFirst());
	ASSERT_EQ(4, seq.getLast());
	ASSERT_EQ(0, seq.search(0));

	seq.add(10, 10);
	seq.add(6, 6);
	ASSERT_EQ(7, seq.size());
	ASSERT_EQ(10,seq.getLast());

}
TEST(TestSortedSequence, TestException)
{
	Search1::SortedSequence<int,int> seq;
	for (int i = 0; i < 5; i++)
	{
		seq.add(i, i);
	}
	ASSERT_ANY_THROW(seq.add(0, 3));
	ASSERT_ANY_THROW(seq.search(6));
}

TEST(TestBinaryTree, TestMethod)
{
	Search2::BinaryTree<int,int> tree;
	for (int i = 0; i < 5; i++)
	{
		tree.insert(i, i);
	}
	ASSERT_EQ(1, tree.isEmpty() == false);
	ASSERT_EQ(0, tree.getFirst());
	ASSERT_EQ(4, tree.getLast());
	ASSERT_EQ(3, tree.find(3));

}

TEST(TestBinaryTree, TestException)
{
	Search2::BinaryTree<int,int> tree;
	for (int i = 0; i < 5; i++)
	{
		tree.insert(i, i);
	}
	ASSERT_ANY_THROW(tree.insert(3, 3));
	ASSERT_ANY_THROW(tree.find(6));
}

TEST(TestHashTable, TestMethod)
{
	Search3::HashTable<int,int> Tab;
	for (int i = 0; i <100;i++)
	{
		Tab.Add(i, i);
	}
	ASSERT_EQ(100, Tab.GetCount());
	ASSERT_EQ(0, Tab.get(0));

	ASSERT_EQ(4, Tab.get(4));
	ASSERT_EQ(15, Tab.get(15));
}
TEST(TestHashTable, TestException)
{
	Search3::HashTable<int,int> Tab;
	for (int i = 0; i < 100; i++)
	{
		Tab.Add(i, i);
	}
	ASSERT_ANY_THROW(Tab.Add(5, 3));
	ASSERT_ANY_THROW(Tab.get(101));
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	auto a = RUN_ALL_TESTS();
	system("pause");
	return a;
}