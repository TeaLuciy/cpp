
#include <iostream>
using namespace std;



class Line;

class Dot
{
    friend class Line;
    friend istream& operator>>(istream&, Dot&);
    friend ostream& operator<<(ostream&, Dot&);
private:
    float x;
    float y;
public:
    Dot(float xx=0.0, float yy=0.0) : x(xx), y(yy) { };
    float getx() { return x; };
    float gety() { return y; };
};


istream& operator>>(istream& input, Dot& p)
{
    char semicolon=';';
    input >> p.x >> semicolon >> p.y;
    return input;
}

ostream& operator<<(ostream& output, Dot& p)
{
    char semicolon = ';';
    output << p.x << semicolon << p.y;
    return output;
}

class Line
{
    private:
        Dot a1;
        Dot a2;

    public:
        Line (float x1 = 0, float y1= 0, float x2= 0, float y2= 0) : a1(x1, y1), a2(x2, y2){};
        Line (Dot& p, Dot& c): a1(p), a2(c){};
        float Koef();
        float Free();
        
}; 


float Line::Koef()
{
    float m;
    m = (a2.y - a1.y) / (a2.x - a1.x);
    if (((a2.x - a1.x ) == 0 )|| ((a2.y - a1.y)== 0))
    {

        //printf("Не определенно");
        return 0;
    }
    return m;
}


float Line::Free()
{
    return (a1.y - Koef() * a1.x);

}


int main()
{
    
    Dot  A, B;

    while (std::cin >> A >> B)
    {
        Line Ln(A,B);

        std::cout << "Коэффициент углового наклона: " << Ln.Koef()<< "\n" << "След: 0;" << Ln.Free() << endl;
        printf("уравнение прямой: y = %.2f * x + %.2f\n", Ln.Koef(), Ln.Free());
        


    }
    
    return 0;
}
