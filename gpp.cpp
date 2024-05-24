#include <iostream>
#include <sstream>
#include <iomanip>
#include <sys/ioctl.h>//размер экрана
#include <termios.h>// интерфейс терминала
#include <fcntl.h>//перенапрвление потока
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>//обработка сигнала
#include <unistd.h>// get of

static int done=0;

using namespace std;

namespace con {
    int comax(){//определние ширины экрана
        struct winsize w;
        ioctl(0,TIOCGWINSZ,&w);
        return (w.ws_col);
    }
    int romax(){//определине длины экрана
        struct winsize w;
        ioctl(0,TIOCGWINSZ,&w);
        return (w.ws_row);
    }
    ostream& ED(ostream& s){
        return s << string("\033[2J");
    }
    ostream& EL(ostream& s){
        return s << string("\033[K");
    }
    class estream{
    private:
        string escape;
    public:
        estream(string e): escape(e) {};
        friend ostream& operator<<(ostream&,estream);
    };
    ostream& operator<<(ostream& s,estream e){
        s<<e.escape<<flush;
        return s;
    }

    estream CUP(int y,int x){
        ostringstream sout;
        sout<<"\033["<<y<<";"<<x<<"H";
        return estream(sout.str());
    }
    estream SGR(int r){
        ostringstream sout;
        sout<<"\033["<<r<<"m";
        return estream(sout.str());
    }

}

using con::SGR;
using con::CUP;


void interruptor(int signo){
    done=signo;
}

int kbin(){
    char buf[512];
    int n=0;
    int flags=fcntl(0,F_GETFL);
    fcntl(0,F_SETFL,flags | O_NONBLOCK);
    usleep(1);
    n=read(0,buf,512);
    fcntl(0,F_SETFL,flags /* & ~NONBLOCK */);
    return n;
}


int main(int argc, char** argv) {
    int x, y, x1, y1;
    int f = 40;
    int mid1 = con::comax();
    int mid2 = con::romax();
    
signal(SIGINT, interruptor);
    while(done < 1) {
        for (y = 1, x1 = 1; y <= mid2 / 2; ++x1, ++y) { 
            for (x = 1, y1 = 1; x <= mid1; y1++, x++) {
                cout << SGR(f) << CUP(y, x) << " " << SGR(f) << CUP(mid2 - y + 1, x) << " " << SGR(f) << CUP(y1, x1) << " " << SGR(f) << CUP(y1, mid1 - x1 + 1) << " ";;
                usleep(5000); 
            }
            if (f < 47) f++; else f = 40; 
            if (kbin() > 0) exit(-1); 
        
    }} 

    cout << CUP(1, 1) << SGR(0) <<con::ED;
    return 0;
}