#include "gtest\gtest.h" 
#include "MyMap1.h"
#include <vector>
#include <math.h>
#include <windows.h>

using namespace std;
using namespace MyTemplate1;


TEST(MyMapTest, testMethods)
{
	MyMap<int> m;
	for (int i = 0; i < 5; i++)
	{
		m.add(make_pair(i, i * 2 + 2));
	}
	ASSERT_EQ(5, m.size());

	ASSERT_EQ(2, *m.find(0));
	ASSERT_EQ(4, *m.find(1));
	ASSERT_EQ(6, *m.find(2));
	ASSERT_EQ(8, *m.find(3));
	ASSERT_EQ(10, *m.find(4));

	ASSERT_EQ(1, m.remove(0));	
	ASSERT_EQ(1, m.remove(1));
	ASSERT_EQ(1, m.remove(4));

	m.add(make_pair(0, 0));
	m.add(make_pair(5, 5));

	ASSERT_EQ(0, m.getbyIndex(0).first);
	ASSERT_EQ(2, m.getbyIndex(1).first);
	ASSERT_EQ(3, m.getbyIndex(2).first);
	ASSERT_EQ(5, m.getbyIndex(3).first);

	ASSERT_EQ(4, m.size());
}

TEST(MyMapTest, testexceptions)
{
	MyMap<int> m1;
	for (int i = 0; i < 5; i++)
	{
		m1.add(make_pair(i, i * 2 + 2));
	}
	ASSERT_ANY_THROW(m1.find(6));
	ASSERT_ANY_THROW(m1.find(-1));

	ASSERT_ANY_THROW(m1.remove(6));

	ASSERT_ANY_THROW(m1.getbyIndex(10));
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	auto a = RUN_ALL_TESTS();
	system("pause");
	return a;
}