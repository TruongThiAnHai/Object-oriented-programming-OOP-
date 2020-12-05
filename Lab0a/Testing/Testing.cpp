#include <iostream>
#include <Header.h>
#include "gtest\gtest.h" 
#include <windows.h>
using namespace Prog1;

TEST(Array, parameters)
{
	ArraySequence<int> arr;
	ASSERT_EQ(0, arr.size());
	int a = 23;
	arr.append(a);
	ASSERT_EQ(1, arr.size());
	ASSERT_EQ(23, arr.getFirst());
	ASSERT_EQ(23, arr.getLast());
	ASSERT_EQ(23, arr.get(0));
	ASSERT_ANY_THROW(arr.get(-1));
	ASSERT_ANY_THROW(arr.get(1));
	int b = 43;
	arr.append(b);
	ASSERT_EQ(2, arr.size());
	ASSERT_EQ(23, arr.getFirst());
	ASSERT_EQ(43, arr.getLast());
	ASSERT_EQ(23, arr.get(0));
	ASSERT_EQ(43, arr.get(1));
	ASSERT_ANY_THROW(arr.get(-1));
	int c = 53;
	arr.prepend(c);
	ASSERT_EQ(3, arr.size());
	ASSERT_EQ(53, arr.getFirst());
	ASSERT_EQ(43, arr.getLast());
	ASSERT_EQ(53, arr.get(0));
	ASSERT_EQ(23, arr.get(1));
	ASSERT_ANY_THROW(arr.get(3));
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	auto a = RUN_ALL_TESTS();
	//system("pause");
	return a;
}