#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

time_t gettime(char *argv)
{
    time_t t=0;  // время с начала дня в секундах

    char* p = strchr(argv,':');
    if(p != NULL)
    {
        *p = '\0';
        *p++;
    if( strchr(p, ':'))
        {
                    char* k = strchr(p,':');
                    if(k != NULL)
                    {
                        *k = '\0';
                        *k++;
                        t += atoi(k); // секунда

                    }  
        }

        t+= atoi(p) * 60; //минуты
    }
    t += atoi(argv) * 3600; // часы
    return t - (3 * 3600);

}



int main(int argc,char** argv)
{
    struct tm *tm1, *tm2, *tmres;
    time_t t1, t2, tres;
    char str_t[128]=""; 
    if (argc != 3)
    {
        return 1;
    }
    
    t1 = gettime(argv[1]);
    tm1 = localtime(&t1);
    //printf("%s\n", asctime(tm1));
    strftime (str_t, 128, "Первое время: %H:%M:%S", tm1 );
    printf("%s\n", str_t);


    t2 = gettime(argv[2]);
    tm2 = localtime(&t2);
    //printf("%s\n", asctime(tm2));
    strftime (str_t, 128, "Второе время: %H:%M:%S", tm2 );
    printf("%s\n", str_t);



    tres = abs(t1 - t2) - 3* 3600;
    tmres = localtime(&tres);
    //printf("%s\n", asctime(tmres));                     // результат
    strftime (str_t, 128, "Разница: %H:%M:%S", tmres );
    printf("%s\n", str_t);

    return 0;
    
}