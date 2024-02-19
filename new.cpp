#include <iostream>
#include <math.h>
#include <stdio.h>


class Point
{
	float _x;
	float _y;
	Point(float x, float y)
	{
		_x = x;
		_y = y;
	};
public:
	float getx()
	{
		return _x;
	};
	float gety()
	{
		return _y;
	};
	static Point Polar(float, float);
	Point() 
	{
		_x = 0;
		_y = 0;
	}
};




Point Point::Polar(float R, float F)
{
	Point p(R * cos(F), R * sin(F));
	return p;
};

int main(int argc, char *argv[])
{
	float edge = 1.0;
	float angle = 1.0;
	float pi;
	pi = acos(-1.0);
	float radius;
	int i = 0;
	Point vertex[3];
	if (argc > 1)
		edge = atof(argv[1]);
	radius = edge / (2 * sin(pi / 3.0));
	while (i < 3)
	{
		vertex[i] = Point::Polar(radius, angle);
		angle += ((2.0 * pi) / 3.0);
		i++;
	}
	do {
		--i;
		printf("(%f, %f)\n", vertex[i].getx(), vertex[i].gety());
	} while (i > 0);
	return 0;

}


