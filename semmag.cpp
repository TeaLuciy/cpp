#include <stdlib.h>
#include <stdio.h>

class Quadrat
{
protected:
    unsigned** tab;         
    int row;               
    int col;                
    int degree;            

public:
    Quadrat(int);           
    ~Quadrat();             
};

class Magic : public Quadrat
{
public:
    Magic(int);                        
    void print();           
    void horse3();                 
    void control();         
private:
    int reflect(int);       
    int width();            
    int linechk(int, int);  
    int diagchk();          
};

Quadrat::Quadrat(int n)
{
    degree = n;                                 
    tab = new unsigned* [degree];               
    for (row = 0; row < degree; row++)           
        tab[row] = new unsigned[degree];
    for (row = 0; row < degree; row++)           
        for (col = 0; col < degree; col++)
            tab[row][col] = 0;
    puts("Quadrat Constructor: Alloc & 0-init"); 
}

Quadrat::~Quadrat()
{
    for (row = 0; row < degree; row++)           
        delete[] tab[row];
    delete[] tab;                              
    puts("Quadrat Destructor: Memory Free");   
}

Magic::Magic(int n) : Quadrat(n)
{
    puts("Magic constructor");                 
}

int Magic::width()
{
    int degree2 = (degree * degree);             
    int len = 0;                                 
    while (degree2 > 0)                          
    {
        degree2 /= 10;
        len++;
    }
    return len;                                  
}

void Magic::print()
{
    int len = width();                           
    putchar('\n');
    for (row = 0; row < degree; row++)           
    {
        for (col = 0; col < degree; col++)
            printf("%0*d ", len, tab[row][col]);
        putchar('\n');
    }
    putchar('\n');
}

int Magic::reflect(int k)
{
    if (k < 0)                                   
        return (k + degree);
    if (k > (degree - 1))                        
        return (k - degree);
    return k;                                    
}

void Magic::horse3()
{
    int i, j;
    int degree2 = (degree * degree);             
    int z = 1;                                   
    row = (degree - 1);                          
    col = (degree / 2);                          
    tab[row][col] = z;                           
    while (z < degree2)                          
    {
        i = reflect(row - 2);                    
        j = reflect(col - 1);                    
        if (tab[i][j] > 0)                       
        {
            i = reflect(row-4);                
            j = reflect(col);
        }
        row = i;
        col = j;
        ++z;
        tab[row][col] = z;                      
    }
}

int Magic::linechk(int i, int j)
{
    int s;
    for (i = 0; i < degree; i++)                
    {
        s = 0;
        for (j = 0; j < degree; j++)
            s += tab[i][j];
        printf("%d ", s);
    }
    return s;                                   
}

int Magic::diagchk()
{
    int s[2] = { 0, 0 };                         
    int loc = (degree - 1);                      
    for (row = col = 0; row < degree; row++, col++, loc--)
    {
        s[0] += tab[row][col];                  
        s[1] += tab[row][loc];                  
    }
    printf("%d %d", s[0], s[1]);
    return s[0];                                
}

void Magic::control()
{
    puts("Magic constant checking for row");     
    linechk(row, col);
    putchar('\n');
    puts("Magic constant checking for column");  
    linechk(col, row);
    putchar('\n');
    puts("Magic constant diagonal control");     
    diagchk();
    putchar('\n');
    putchar('\n');
}

int main(int argc, char* argv[])
{
    if (argc != 2)
        return puts("Usage: magic degree");     
    int n = atoi(argv[1]);
    n = (n < 0) ? -n : n;                       
    if ((n % 2) == 0) {
        puts("Usage: magic 5 (or 7, 11, 17, 19, 23, ...)");
        return n;                                
    }
    Magic mag(n);                                
    mag.horse3();                                
    mag.print();                                 
    mag.control();                               
    return n;                                    
}
