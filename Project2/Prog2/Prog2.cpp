#include <iostream> 
#include <math.h>
#include "Lemniscate.h"

int main()
{
	Prog2::Lemniscate c(-2, 0, 2, 0);
	Prog2::Point a, b;
	int fl1 = 1;
	while (fl1) {
		std::cout << "     Area: " << c.area() << std::endl;
		int fl2 = 1;
		while (fl2) {
			std::cout << "________________________________________________________________________" << std::endl;
			std::cout << "Enter angle of the poler coordinate  system or precc ctrl+Z to quit:" << std::endl;//вводить угол полярного радиуса
			double x;
			const char *pr = "";
			do
			{
				std::cout << pr << std::endl;
				std::cout << "Enter value of angle (0->360): ";//угол должен = 0->360 градусов
				std::cin >> x;
				pr = "You are wrong, repet!";
			} while ((x > 360) || (x < 0));
			fl2 = std::cin.good();
			if (!fl2)     continue;
			std::cout << "" << std::endl;
			std::cout << "Distance:  " << c.Distance(x) << std::endl;
			std::cout << "Sector_area:  " << c.sector_area(x) << std::endl;
			std::cout << "Radius of curvature depending on the angle:  " << c.radius_of_curvature_angle(x) << std::endl;
		}
		std::cin.clear();
		int fl3 = 1;
		while (fl3) {
			std::cout << "________________________________________________________________________" << std::endl;
			std::cout << "Enter distance from point to ceter or precc ctrl+Z to quit:" << std::endl;//длина полярного радуса
			double a;
			std::cout << "\nEnter distance: ";
			std::cin >> a;
			fl3 = std::cin.good();
			if (!fl3)     continue;
			if (a < (c.distance()*sqrt(2)))//длина не больше чем c*(корень из 2)
			{
				std::cout << "\nRadius of curvature depending on the angle " << c.radius_of_curvature_distance(a) << std::endl;
			}
			else std::cout << "\nPoint does not belong on lemniscate" << std::endl;

		}
		std::cin.clear();
		std::cout << "************************************************************" << std::endl;
		std::cout << "Enter new f1 to continue or press ctrl+Z to quit: " << std::endl;
		std::cin >> a.x >> a.y;
		if (std::cin.good())
		{
			c.setF1(a);
			std::cin.clear();
			std::cout << "Enter new f2 to continue or press ctrl+Z to quit:" << std::endl;
			std::cin >> b.x >> b.y;
			if (std::cin.good())
			{
				c.setF2(b);
			}
			else
				fl1 = 0;
		}
		else fl1 = 0;
		std::cout << "" << std::endl;
	}
	return 0;

}

