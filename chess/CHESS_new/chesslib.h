

#ifndef CHESSLIB
#define CHESSLIB

#include "chessman.h"


class Plus : virtual public Figure {
  public:
    Plus(char* p) : Figure(p) {};    
    Plus() {};                       
    virtual char isa() { return 'A'; };      
    virtual int attack(char*);               
}; 



class Cros : virtual public Figure {
  public:
    Cros(char* p) : Figure(p) {};    
    Cros() {};                       
    char isa() { return 'C'; };      
    int attack(char*);              
}; 

class King : public Plus, public Cros {
  public:
    King(char* p) : Figure(p) {};       
    char isa() { return 'D'; };        
    int attack(char*);                  
}; 

#endif
