

#include <iostream>
#include "chesslib.h"


int main(int argc, char* argv[]) {
if(argc < 2)         
  argv[1] = (char*)("nil");   
if(Figure::deskout(argv[1])) {
  std::cout << "Correct " << argv[1];
  std::cout << " to " << (argv[1] = (char*)"a1") << " Default\n";
} 
King f(argv[1]);    
do {                
  f.danger();           
  std::cout << f << '-' << f.isa(); 
} while (std::cin >> f); 
return(0);
} 