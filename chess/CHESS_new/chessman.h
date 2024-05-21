
#ifndef CHESSMAN
#define CHESSMAN

#include <iostream>

class Figure {
  protected:
    char pos[2]; 
  public:
    Figure(char*);                 
    Figure() {};                   
    virtual int attack(char*)=0;   
    virtual char isa()=0;          
    static int deskout(char*);     
    int danger();                  
    Figure& operator=(char*);      
    int operator==(char*);         
    int operator!=(char*);         
    friend std::ostream& operator<<(std::ostream&, Figure&);
    friend std::istream& operator>>(std::istream&, Figure&);
}; 
#endif
