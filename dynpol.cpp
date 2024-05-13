//указатель на таблицу виртуальных функций               метод класса, деструкторы - могут быть виртуальными
// в классе наследнике не обязательно указывать virtual


#include <iostream>
#include <stdlib.h>


using namespace std;


class Heap
{
    int size;
public:

    Heap (int s) : size(s) {};
    int get(int m = 0)
    {
        size -=m;
        return size;
    };
};


class Gambler
{
protected:
    const int limit;
    Heap* heap;
    const char* name;
public:
    Gambler (int l, Heap &h) : limit(l) {heap = &h;};
    int query();
    virtual int move() = 0;
    virtual ~Gambler(){};
};



class Man: public Gambler
{
    public:
    Man(int l, Heap &h, const char *n): Gambler(l,h) {name = n;};
    virtual int move();

};


class Pen: public Gambler
{
    public:
    Pen(int l, Heap &h, const char *n): Gambler(l,h) {name = n;};
    virtual int move();

};

int Pen::move()
{
    int rest = 0, x = 0;
    int h = heap->get();
    if(h == 1 )
    {

        h = heap->get(1);
        cout << "1" << endl;
        return h;
    }

    while ((rest = x*limit+x+1) < h)
        x++;
    
    if (rest > h)
    {
        x--;
        rest = x * limit + x + 1;
        heap ->get(h - rest);
        cout << h-rest << endl;

    }

    else
    {
        heap -> get(1);
        cout << "1" << endl;
    }

    return heap -> get();


}



int Man::move()
{
    int g;
    cin >> g;
    if ((g  <= 0) || (g > limit) || (g > heap->get()))
        g = 1;
    return heap->get(g);
}


int Gambler::query()
{
    cout << "Heap = " << heap->get() << " " << name << " > ";
    return heap->get();
}




int main(int argc, char* argv[])
{
    int i = 0;
    Heap h (atoi(argv[1]));
    Gambler* g [2] {new Pen(atoi(argv[2]), h, "pen"),  new Man(atoi(argv[2]), h, "man")};

    while (g[i]->query() != 0)
    {
        g[i]->move();
        if (++i > 1)
        i = 0;

    }
    cout << "Winner" << endl;
    delete g[0];
    delete g[1];

    return(0);
}