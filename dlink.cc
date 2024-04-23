#include "dlink.h"
#include  <stdio.h>
// init linked references
Dlink::Dlink() {
    next=prev=NULL;
}

// инициализация адресов записей
Dlink* Dlink::incr() {
    return(next);
}
// получить адрес предыдущей записи
Dlink* Dlink::decr() {
    return(prev);
}
// добавить новую запись
Dlink* Dlink::append(Dlink* p) {
    p->next=this;
    if(this != NULL)
        prev = p;
    return(p);
}
// исключить следующую запись
void Dlink::excluse() {
    if(next != NULL)
        next->prev=prev;
    if(prev != NULL)
        prev->next=next;
    return;
}
// вставить запись после текущей
Dlink* Dlink::after(Dlink* p) {
    p->next = next;
    p->prev = this;
    if(next != NULL)
        next->prev = p;
    next = p;
    return(p->next);
}
// вставить запись перед текущей
Dlink* Dlink::before(Dlink* p) {
    p->next = this;
    p->prev = prev;
    if(prev != NULL)
        prev->next = p;
    prev = p;
    return(p->prev);
}
// получить адрес начала списка
Dlink* Dlink::tohead() {
    Dlink* p = this;
    Dlink* q = NULL;
    while(p != NULL) {
        q = p;
        p = p->prev;
    } // while
    return(q);
}
// перейти на n записей в направлении начала списка
Dlink* Dlink::tohead(int n) {
    Dlink* p = this;
    Dlink* q = this;
    int i = 0;
    while(p != NULL) {
        q = p;
        if(i == n)
            break;
        p = p->prev;
        i++;
    }
    return(q);
}
// получить адрес конца списка
Dlink* Dlink::totail() {
    Dlink* p = this;
    Dlink* q = NULL;
    while(p != NULL) {
        q = p;
        p = p->next;
    } // while
    return(q);
}
// перейти на n записей в направлении конца списка
Dlink* Dlink::totail(int n) {
    Dlink* p = this;
    Dlink* q = this;
    int i = 0;
    while(p != NULL) {
        q = p;
        if(i == n)
            break;
        p = p->next;
        i++;
    } // while
    return(q);
}

