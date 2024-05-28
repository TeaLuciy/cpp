#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>


using namespace std;


int main(int argc, char* argv[])
{
    if (argc <3)
        return 0;
    
    ifstream input;
    input.open(argv[1]);
    /*if (input == NULL)
    {
        cout << "erroe link 1" << endl;
        return -1;
    }*/

    int count = 0;
    char b[100];
    char c;;

    input.seekg(0, input.end);
    count = input.tellg();
    input.seekg(0, input.beg);


    int fc;
    fc=count/atoi(argv[2]);
    int n =1;
    char* name = argv[1];
    while(n < atoi(argv[2])+1)
    {
        char b[100] = "";
        strcpy (b, argv[1]);
        sprintf(b+strlen(argv[1]),"%d", n);
        ofstream output(b);
        char buff[1024];
        input.read(buff, fc);
        output.write(buff, fc);
        output.close();
        n++;
    }
    

    /*if (output == NULL)
    {
        cout << "error link 2" << endl;
        return -1;
    }*/
    
    input.close();

}