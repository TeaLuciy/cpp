#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

class Point
{
    int _x;
    int _y;

public:


    int getx()
    {
        return _x;
    };


    int gety()
    {
        return _y;
    };


    Point(int x = 0, int y = 0) : _x(x), _y(y){};


    int sign()
    {
        int a =_y -_x ; //y-x
        return ((a>0) - (a<0));
    };


    double dist(Point* p)
    {
        double d;
        d = sqrt((p->getx()-_x)*(p->getx()-_x) + (p->gety()-_y)*(p->gety()-_y));
        return d;
    }

};


int main(int argc, char **argv)
{
    Point **p;
    int x, y;
    int i = 0;
    int j;
    int n = 0;
    double max = 0;
    double dist;
    Point m1;
    Point m2;



    if (argc < 3)
    {
        return (-1);
    }
    p = new Point *[argc - 1];

    while (++i < argc)
    {
        x = y = 0;
        sscanf(argv[i], "%d%*c%d", &x, &y);
        p[n++] = new Point(x, y);
        std::cout << x << ";" << y << std::endl;
    }

    for(i = 0; i<argc-1; i++)
    {
         for(j = i+1; j<argc-1; j++)
        {
            if ((p[i]->sign() == p[j]->sign()) || (p[i]->sign() == 0) || (p[j]->sign() == 0))
            {
                    continue;
            }
            //maxv = std::max(maxv, (p[i]->dist(p[j])));
            dist = p[i]->dist(p[j]);
            if ( dist > max)
            {
                m1=*p[i];
                m2=*p[j];
                max = dist;
            }
        }
    }


    for (i =0; i<n; i++)
        delete p[i];
    delete[] p;


    printf("\n%d;%d -> %d;%d\n%f\n",m1.getx(), m1.gety(), m2.getx(), m2.gety(), max);

    return 0;
}