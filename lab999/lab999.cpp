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

    cout << count << endl;

    int fc;
    fc=count/atoi(argv[2]);
    cout << fc << endl;
    string name = argv[1];
    while(fc)
    {
        int n = 1;
        string ind  =  to_string(n);
        ofstream output(name + to_string(n));
        char buff[1024];
        input.read(buff, atoi(argv[2]));
        output.write(buff, atoi(argv[2]));
        output.close();
        fc--;
    }
    

    /*if (output == NULL)
    {
        cout << "error link 2" << endl;
        return -1;
    }*/
    
    input.close();

}