
#include  <stdio.h>
#include  <stdlib.h>
#include  "dlink.h"
#include  "dlink.cc"

class SymLink : public Dlink {
private:
    unsigned char sym; 
public:
  
    SymLink(unsigned char c) : Dlink(), sym(c) {};
    
    SymLink* incr() {return((SymLink*) Dlink::incr());};
  
    SymLink* decr() {return((SymLink*) Dlink::decr());};
    SymLink* seek(int); 
    int print();	
    SymLink* fn(char);
    int mn();
    void pos(char);
    int mx();
}; 
SymLink* SymLink::seek(int n) {
    if(n > 0) 
        return((SymLink* ) Dlink::totail(n));
    if(n < 0) 
        return((SymLink* ) Dlink::tohead(abs(n))); 
    return(this);  
} 
int SymLink::print() {
    SymLink* p = this;
    SymLink* q; 
    int n= 0; 
    while(p != NULL){ 
        putchar(p->sym); 
        q = p->incr();
        p = q; 
        n++;
    }

    return(n); 
} 


    int SymLink::mn()
{
    SymLink* p = this;
    SymLink* q;
    SymLink* l = NULL;
    int min = 10000;                             
    
    while(p != NULL)
    {
        if ((p->sym < min) && (p->sym != '\n'))
        {
            min = p->sym;
            l = p;
        }
        q=p->incr();
        p=q;
    }
    return min;
}





SymLink* SymLink::fn(char s)
{
    SymLink* p = this;
    SymLink* q;
    while (p!= NULL)
    {
        if (p->sym == s)
        {
            return p;
        }
        q=p->incr();
        p=q;
    }
    return NULL;
}

void SymLink::pos(char s)
{
    SymLink* p = this;
    SymLink* q;
    int pose = 0;
    while (p!= NULL)
    {
        if (p->sym == s)
        {
            printf("%*c\n", pose, '^');
            //return pose;
        }
        q=p->incr();
        p=q;
        pose+=1;
    }
    //return NULL;
}





int main() {
    int ch;
    int length; 
    unsigned pos; 
    int side; 
    SymLink* watch[2]; 
    SymLink* head; 
    SymLink* tail; 
    SymLink* watchBuf[2];
    SymLink* headBuf;
    SymLink* tailBuf;
    SymLink* p;
    SymLink* q; 
    char minim;
    
    Dlink* (Dlink::*insert[])(Dlink*) = {&Dlink::after, &Dlink::before};

    
    watch[0] = head = new  SymLink('\n');
    watch[1] = tail = new  SymLink('\n');
    tail ->before(head);

    watchBuf[0] = headBuf = new  SymLink(' ');
    watchBuf[1] = tailBuf = new  SymLink(' ');
    tailBuf ->before(headBuf);

    
    while((ch = getchar()) != '\n') { 
        q = new SymLink(ch); 
        tail->before(q); 
    } 
   
    minim = head->mn();
    printf("min = %c\n", (head->mn()));
    while (head->fn(minim))
    {
        head->print();
        p = head->fn(minim);
        head->pos(minim);
        p->excluse();
        headBuf->after(p);
    }
    length = head->print ( ) - 2;
    //printf("len=%d\n", length);
    //headBuf->print();

    p = head->seek(length/2);
    q = p->incr();
    headBuf->append(p);
    headBuf->excluse();
    delete headBuf;
    q->append(tailBuf);
    tailBuf->excluse();
    delete tailBuf;
    head->print();

    

    p = tail;
    while(p != NULL) { 
        q = p->decr(); 
        p->excluse(); 
        delete p; 
        p = q; 
    }
    return(length+1);
} 
