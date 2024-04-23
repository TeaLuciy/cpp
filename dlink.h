#ifndef DLINK
#define DLINK
class Dlink {
protected:
    Dlink* next;  // адрес следующей записи
    Dlink* prev;  // адрес предыдущей записи
public:
    Dlink();     // инициализация ссылок
    Dlink* append(Dlink*);  // добавить новую запись
    Dlink* incr();          // получить адрес следующей записи
    Dlink* decr();          // получить адрес предыдущей записи
    void excluse();         // исключить запись
    Dlink* after(Dlink*);   // вставить запись после текущей
    Dlink* before(Dlink*);  // вставить запись перед текущей
    Dlink* tohead(void);    // адрес начала списка
    Dlink* tohead(int);     // сдвиг в направлении начала списка
    Dlink* totail(void);    // адрес конца списка
    Dlink* totail(int);     // сдвиг в направлении конца списка
}; // Dlink  
#endif   
