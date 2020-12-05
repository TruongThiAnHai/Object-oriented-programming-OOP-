
#include "gtest\gtest.h" 
#include  "Lemniscate.h" 
#include <math.h>
#include <windows.h>

TEST(LemniscateConstructor, DefaultConstructor)
{
	Prog2::Lemniscate l1;
	ASSERT_EQ(1, l1.getF1().x);
	ASSERT_EQ(0, l1.getF1().y);
	ASSERT_EQ(-1, l1.getF2().x);
	ASSERT_EQ(0, l1.getF2().y);
}

TEST(LemniscateConstructor, InitConstructors)
{

	Prog2::Point f1(1, 3), f2(3, 2);
	Prog2::Lemniscate l2(f1, f2);
	ASSERT_EQ(1, l2.getF1().x);
	ASSERT_EQ(3, l2.getF1().y);
	ASSERT_EQ(3, l2.getF2().x);
	ASSERT_EQ(2, l2.getF2().y);

	Prog2::Point f(2, 5);
	Prog2::Lemniscate l3(f, 4, 1);
	ASSERT_EQ(2, l3.getF1().x);
	ASSERT_EQ(5, l3.getF1().y);
	ASSERT_EQ(4, l3.getF2().x);
	ASSERT_EQ(1, l3.getF2().y);

	Prog2::Lemniscate l4(1, -2, 3, -4);
	ASSERT_EQ(1, l4.getF1().x);
	ASSERT_EQ(-2, l4.getF1().y);
	ASSERT_EQ(3, l4.getF2().x);
	ASSERT_EQ(-4, l4.getF2().y);
}

TEST(LemniscateConstructor, TestException)
{
	Prog2::Point f1, f2;
	//ASSERT_ANY_THROW(Prog2::Lemniscate(2, 5, -5, 7));
	//ASSERT_ANY_THROW(Prog2::Lemniscate(f1, f2));
	//ASSERT_ANY_THROW(Prog2::Lemniscate(f1, 3, -4));
}

TEST(LemniscateMethods, Setters)
{
	Prog2::Lemniscate l;
	Prog2::Point f1(3, 2), f2(4, -5);
	l.setF1(f1);
	ASSERT_EQ(3, l.getF1().x);
	ASSERT_EQ(2, l.getF1().y);
	l.setF2(f2);
	ASSERT_EQ(4, l.getF2().x);
	ASSERT_EQ(-5, l.getF2().y);

}

TEST(LemniscateMethods, Parameters)
{
	Prog2::Lemniscate a1;
	const double err = 0.00001;
	ASSERT_NEAR ((2*1*1), a1.area(), err);
	ASSERT_NEAR(sin(2*0)/2, a1.sector_area(0), err);
//	ASSERT_NEAR(2/(3*2), a1.radius_of_curvature_distance(2), err);
	ASSERT_NEAR(2/(3 * sqrt(fabs(2 *cos(2 *0)))), a1.radius_of_curvature_angle(0), err);
	ASSERT_NEAR(sqrt(fabs(2 *cos(2 * 0))), a1.Distance(0), err);
	ASSERT_EQ(0, a1.center().x);
	ASSERT_EQ(0, a1.center().y);

	Prog2::Lemniscate a2(-2, 0, 2, 0);
	ASSERT_NEAR((2 * 2 * 2), a2.area(), err);
	ASSERT_NEAR(sin(2 * 0) / 2, a2.sector_area(0), err);
	ASSERT_NEAR(double(2*2*2)/ double(3 * 1), a2.radius_of_curvature_distance(1), err);
	ASSERT_NEAR((2*2*2) / (3 * sqrt(fabs(2*2*2 * cos(2 * 0)))), a2.radius_of_curvature_angle(0), err);
	ASSERT_NEAR(sqrt(fabs(2 *2*2* cos(2 * 0))), a2.Distance(0), err);
	ASSERT_EQ(0, a2.center().x);
	ASSERT_EQ(0, a2.center().y);
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	
	auto a = RUN_ALL_TESTS();
	system("pause");
	return a;
}