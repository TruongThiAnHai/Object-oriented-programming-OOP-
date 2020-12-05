#include <strstream> 
#include <iostream> 
#include "stdafx.h"
#include <stdio.h> 
#include <math.h>
#include "Lemniscate.h" 

namespace Prog2 {

	Point Lemniscate::center()//координаты центра Лемнискаты
	{
		Point res;
		double a, b;
		a = (f1.x + f2.x) / 2;
		b = (f1.y + f2.y) / 2;
		res.x = a;
		res.y = b;
		return res;
	}
	double Lemniscate::distance()//расстояние от фокусы до центра
	{
		double c;
		c = (sqrt((f1.x - f2.x)*(f1.x - f2.x) + (f1.y - f2.y)*(f1.y - f2.y))) / 2;
		return c;
	}
	double Lemniscate::area()
	{
		double c = distance();
		return 2 * c*c;

	}
	double Lemniscate::radius_of_curvature_distance(double r)
	{
		double c = distance();
		return ((2 * c*c) / (3 * r));
	}
	double Lemniscate::sector_area(double angle)
	{
		double c = distance();
		return fabs(((c*c)*sin(2 * angle)) / 2);
	}
	double Lemniscate::Distance(double angle)
	{
		double c = distance();
		return sqrt(fabs(2 * c*c*cos(2 * angle)));
	}
	double Lemniscate::radius_of_curvature_angle(double angle)
	{
		double c = distance();
		return ((2 * c*c) / (3 * sqrt(fabs(2 * c*c*cos(2 * angle)))));
	}
	Lemniscate::Lemniscate(const Point &f10, double x0, double y0)
	{
		f1 = f10;
		f2.x = x0;
		f2.y = y0;
	}
	Lemniscate::Lemniscate(const Point &f10, const Point &f20)
	{
		f1 = f10;
		f2 = f20;
	}
	Lemniscate::Lemniscate(double x10, double y10, double x20, double y20)
	{
		f1.x = x10;
		f1.y = y10;

		f2.x = x20;
		f2.y = y20;
	}
	Lemniscate::Lemniscate()
	{
		f1.x = 1;
		f1.y = 0;

		f2.x = -1;
		f2.y = 0;
	}
}

