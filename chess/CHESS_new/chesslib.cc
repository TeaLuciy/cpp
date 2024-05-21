
#include "chesslib.h"

int Plus::attack(char* p) {
if(deskout(p) > 0)      
  return(0);           
int x = p[0] - pos[0];  
int y = p[1] - pos[1];  
if(x < 0) x = -x;       
if(y < 0) y = -y;       
if((x ==2) && (y == 2))       
  return(1);           
return(0);              
} 


int Cros::attack(char* p) {
if(deskout(p) > 0)      
  return(0);            
int x = p[0] - pos[0];  
int y = p[1] - pos[1];  
if(x < 0) x = -x;       
if(y < 0) y = -y;       
if((x ==1 && y == 3) || ( x == 3 && y ==1))  
 return(1);            
return(0);              
} 

int King::attack(char* s) {
if(Plus::attack(s) > 0) 
  return(2);
if(Cros::attack(s) > 0) 
  return(1);
return(0);               
} 
