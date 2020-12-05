#ifndef _LEMNISCATE_
#define __LEMNISCATE_H_
#include <math.h>

namespace Prog2
{


	struct Point
	{
		double x, y;
		Point(double x0 = 0, double y0 = 0) :x(x0), y(y0) {}
	};
	class Lemniscate
	{
	private:
		Point f1; //координаты фокусы F1
		Point f2;//координаты фокусы F2
	public:
		Lemniscate();////конструктор без аргументов: F1,F2 лежат на Ox и OF1=OF2=1 
		Lemniscate(const Point &f10, const Point &f20);//конструктор с 2 аргументами-типа структуры Точка
		Lemniscate(const Point &f10, double x0, double y0);//конструктор с 3 аргументами-первый типа структуры Точка, второ и третий- типа вещ. числа определяют коорднаты второй фокусы
		Lemniscate(double x10, double y10, double x20, double y20);//конструктор с 4 аргументами типа вещ. числа определяет лемнискату с 2 заданными фокусами
		Lemniscate& setF1(const Point &f10) { f1 = f10; return *this; }
		Lemniscate& setF2(const Point &f20) { f2 = f20; return *this; }
		Point getF1() const { return f1; }
		Point getF2() const { return f2; }
		Point center();//координаты центра
		double distance();//расстояние от фокусы до центра
		double sector_area(double angle); //площадь полярного сектора лемнискаты в зав.от угла
		double area();//площадь лемнискаты
		double radius_of_curvature_distance(double r); //радиус кривизны в зав. от длины полярного радиуса
		double radius_of_curvature_angle(double angle);//радиус кривизны в зав. от угла полярного радиуса
		double Distance(double angle);//расстояние до центра в полярной системе координат в зависимости от угла для точки принадлежащей лемнискате
	};
}
#endif
#pragma once
