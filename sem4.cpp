// функцианальный класс(функтор) класс с перегрузкой скобок
// функциональная форма записи (вызов оператора через метод)
// у оператора , очень малый приоритет
// оператор  [] (индексация)


#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <stdio.h>

class Fraction
{
    public:
        Fraction(int nom = 0, int den = 1): _nom(nom), _den(den){};
        Fraction(char* s);
        operator char*();
        Fraction operator~();
        void reduce();

    private:
        int _nom, _den;


    friend std::ostream& operator<<(std::ostream& os, Fraction a);  
};


std::ostream&operator<<(std::ostream& os, Fraction a)
{
    os << a._nom << '/' << a._den; 
    return os;
}

int euclide(int, int);

void Fraction::reduce()
{
    int gcd;
    gcd = euclide(abs(_nom), _den);
    _nom /= gcd;
    _den /= gcd;
}

Fraction::Fraction(char* s)
{
    char* p = strchr(s,'/');
    _den = 1;
    if(p != NULL)
    {
        *p++;
        _den = atoi(p);
    }
    _nom = atoi(s);
}


Fraction Fraction::operator~()
{
    int k =0;
    int sign = (_nom<0) ? -1  : 1;
    int n = sign * _nom;
    while (k<n)
    {
        k+=_den;
    }
    n=k-n;
    return Fraction(n*sign, _den);
}


Fraction::operator char *()
{
    static char s[32];
    sprintf(s, "%d/%d", _nom, _den);
    return s;
}

int euclide(int n ,int m)
{
    int r = 1; 
    while (n!=0)
    {
        r = m%n;
        m = n;
        n = r;
    }
    return m;
}


int main(int argc, char** argv)
{
    if (argc < 2)
    {
        return 1;
    }

    Fraction x(argv[1]);
    x.reduce();
    Fraction y = ~x;
    std::cout<<(char*)x<<std::endl;
    std::cout<<(char*)y<<std::endl;
}
