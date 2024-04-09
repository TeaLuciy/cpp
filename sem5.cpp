/*

композиция  ---  агрегация    (как часть инкапсуляции)


конструкторы \ деструкторы




наследование 
в каком порядке конструкторы  деструкторы производного класса

виды наследования privat public, protected


вместо базового производный можно, вместо производного базовый низя

конструкторы, деструкторы, дружественности не наследуются

*/

#include <iostream>

class Dot
{
    private:
        float _x, _y;

    public:
        friend class Line;
        friend std::istream& operator>>(std::istream&, const Dot&);
        friend std::ostream& operator<<(std::ostream&, const Dot&) ;
        Dot(float x = 0, float y = 0):_x(x), _y(y){};
        float getx() {return _x;};
        float gety() {return _y;};
        Dot mirrorx() {return Dot(-_x, _y);};
        Dot mirrory() {return Dot(_x, -_y);};


};

std::istream& operator>>(std::istream& is, const Dot& a) {

    char s;
    is >> a._x >> s >> a._y; 
    return is;
}


std::ostream& operator<<(std::ostream& os, const Dot& a) {

    os << a._x << ";" << a._y; 
    return os;
}

class Line
{
    private:
        Dot a1;
        Dot a2;

    public:
        Line (float x1, float y1, float x2, float y2) : a1(x1, y1), a2(x2, y2){};
        Line (Dot& p, Dot& c): a1(p), a2(c){};
        Dot clipx();
        Dot clipy();
};

Dot Line::clipx()
{
float dx = a2._x - a1._x;
float dy = a2._y - a1._y;
float x0 = -1*a1._y * dx / dy + a1._x ; 
return Dot(x0, 0.0);
}

Dot Line::clipy()
{
float dx = a2._y - a1._y;
float dy = a2._x - a1._x;
float y0 = -1*a1._x * dx / dy + a1._y ; 
return Dot(0.0, y0);
}



int main(int argc, char const *argv[])
{
    float ya, yb, xa, xb, _x;
    Dot A, B, _A, C;
    while (std::cin >> A >> B)
    {
        ya = A.gety();
        yb = B.gety();
        _A = (ya*yb) > 0 ? A.mirrory() : A;
        Line lx(_A, B);
        C = lx.clipx();
        std::cout<< C << std::endl;


        xa = A.getx();
        xb = B.getx();
        _x = (xa*xb) > 0 ? -xb : xb;
        Line ly(xa, ya, _x, yb);
        C = ly.clipy();
        std::cout<< C << std::endl;
    }
    
    return 0;
}
