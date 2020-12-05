#include<gtest\gtest.h>
#include "Vector_3.h"
#include <windows.h>
using namespace Prog3_3;

TEST(VectorConstructor, Constructor)
{
	Vector vt;
	ASSERT_EQ(0, vt.size());

	Vector vt2(2);
	ASSERT_EQ(1, vt2.size());
	ASSERT_EQ(2, vt2.value(0));

	int a[5] = { 1,2,3 };
	Vector vt3(a, 3);
	ASSERT_EQ(3, vt3.size());
	ASSERT_EQ(1, vt3.value(0));
	ASSERT_EQ(2, vt3.value(1));
	ASSERT_EQ(3, vt3.value(2));

	Vector vt4(vt3);
	ASSERT_EQ(3, vt4.size());
	ASSERT_EQ(1, vt4.value(0));
	ASSERT_EQ(2, vt4.value(1));
	ASSERT_EQ(3, vt4.value(2));

}

TEST(VectorMethods, TestAll)
{
	int a[5] = { 5,3,9,10,2 };
	Vector vt(a, 5);
	ASSERT_EQ(5, vt.size()); //Проверить, что длина = 5
	ASSERT_EQ(5, vt.value(0)); //Проверить, что value(0) возвращает 5
	ASSERT_EQ(2, vt.value(4)); //Проверить, что value(4) возвращает 2
	ASSERT_ANY_THROW(vt.value(-1)); //Проверить, что value(-1) – выбрасывают исключение.
	ASSERT_ANY_THROW(vt.value(10)); //Проверить, что value(10) – выбрасывают исключение.
	ASSERT_EQ(10, vt.findMax()); //роверить, что findMax() возвращает 10

	//Добавить элемент «7»
	vt.push(7);
	ASSERT_EQ(6, vt.size()); //Проверить, что длина = 6
	ASSERT_EQ(7, vt.value(5)); //Проверить, что value(5) возвращает 7


	Vector vt1(vt); //копирующий конструктор
	vt1.Ordering_Vector_Ascending();//упорядочение вектора по возрастанию
	ASSERT_EQ(2, vt1.value(0));
	ASSERT_EQ(3, vt1.value(1));
	ASSERT_EQ(5, vt1.value(2));
	ASSERT_EQ(7, vt1.value(3));
	ASSERT_EQ(9, vt1.value(4));
	ASSERT_EQ(10, vt1.value(5));

	int b[6] = { 1,2,3,4,5,6 };
	Vector v2(vt), vt2(b, 6);
	Vector vt3 = v2 + vt2;//сложение двух векторов v2=vt={ 5,3,9,10,2,7} и vt2= { 1,2,3,4,5,6 }
	ASSERT_EQ(6, vt3.value(0));
	ASSERT_EQ(5, vt3.value(1));
	ASSERT_EQ(12, vt3.value(2));
	ASSERT_EQ(14, vt3.value(3));
	ASSERT_EQ(7, vt3.value(4));
	ASSERT_EQ(13, vt3.value(5));

	int c[3] = { 1,2,3 };
	Vector v3(c, 3);
	ASSERT_ANY_THROW(vt + v3);// test exception: v3 и vt не имеют одинаковых рамеров

	//test выделение части вектора
	ASSERT_ANY_THROW(vt.part_of_vector(7, 0));
	ASSERT_ANY_THROW(vt.part_of_vector(3, 4));
	ASSERT_ANY_THROW(vt.part_of_vector(3, -1));

	Vector v4;
	v4 = vt.part_of_vector(3, 1);
	ASSERT_EQ(3, v4.size());
	ASSERT_EQ(3, v4.value(0));
	ASSERT_EQ(9, v4.value(1));
	ASSERT_EQ(10, v4.value(2));

	ASSERT_EQ(3, vt.size());
	ASSERT_EQ(5, vt.value(0));
	ASSERT_EQ(2, vt.value(1));
	ASSERT_EQ(7, vt.value(2));
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);

	auto a = RUN_ALL_TESTS();
	system("pause");
	return a;
}

