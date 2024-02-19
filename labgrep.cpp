#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>

class Point 
{
private:
    int _x;
    int _y;
public:
    Point(int x,int y): _x(x), _y(y) {};
    int getx() {return _x;};
    int gety() {return _y;};
    friend double distance(Point*, Point*);
};

double distance(Point* r, Point* q) 
{
    double d = (r->_x - q->_x)*(r->_x - q->_x) + (r->_y - q->_y)*(r->_y - q->_y);
    return sqrt(d);
}

int main(int argc, char* argv[])
{
    Point **p;
    Point *one;
    Point *two;
    int x,y;
    int i=0,j=0;
    double dist, min_dist = -1;
    if (argc < 2)
        return -1;
    p = new Point* [argc];
    while (++i < argc)
    {
        sscanf(argv[i], "%d%*c%d", &x,&y);
        p[j] = new Point(x,y);
        j++;
    }
    p[j] = NULL;
    
    for (i=0; i < argc; ++i) {
        for (j=i+1; j < argc; j++) {
            if (((p[i]->getx() * p[i]->gety()) < 0) && ((p[j]->getx() * p[j]->gety()) < 0) && ((p[i]->getx() * p[j]->getx()) < 0)) {
                dist = distance(p[i],p[j]);
                
                if (min_dist > dist || min_dist == -1) {
                    min_dist = dist;
                    one=p[i];
                    two=p[j];
                    
                }
            }
        }
    }
    
    for (i=0; i < argc; i++) 
        delete p[i]; 
    delete[] p;
    
    printf("%d;%d\n", one -> getx(), one -> gety());
    printf("%d;%d\n", two -> getx(), two -> gety());
    printf("Расстояние %f", min_dist);
    
    return 0;
}