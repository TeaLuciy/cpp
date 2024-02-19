#include <iostream>
#include <math.h>
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
    Point(float x = 0, float y = 0) : _x(x), _y(y){};
    friend int differ(const void *pp, const void *qq);
    int differ(const Point* p)
    {
        return(p->_x-_x);
    }


};

int differ(const void *pp, const void *qq)
{
    Point **p = (Point **)pp;
    Point **q = (Point **)qq;
    return (p[0]->_y - q[0]->_y); // разименования указателя (указатель на элемент)
}

int main(int argc, char **argv)
{
    Point **p;
    int x, y;
    int i = 0;
    int j;
    int n = 0;
    if (argc < 2)
    {
        return (-1);
    }
    p = new Point *[argc - 1];

    while (++i < argc)
    {
        x = y = 0;
        sscanf(argv[i], "%d%*c%d", &x, &y);
        p[n++] = new Point(x, y);
    }

    qsort((void*)p,n, sizeof(Point*), differ);


    for (i=0; i<n; i++)
    {
        printf("(%d;%d)>", p[i]->getx(), p[i]->gety());
        for (j=0; differ(&p[j], &p[i]) <0; j++)
            if (p[i] -> differ(p[j]) < 0)
                printf("(%d;%d)>", p[j]->getx(), p[j]->gety());
        putchar('\n');

    }

    for (i =0; i<n; i++)
        delete p[i];
    delete[] p;
    return 0;
}