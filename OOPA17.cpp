#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <ctype.h>

class Alpha
{
private:
    unsigned int _bin[2];
    friend std::ostream& operator<<(std::ostream& os, const Alpha& a);

public:
    Alpha( const char* sw = "")
     {
        _bin[0] = 0;
        _bin[1] = 0;
        while (*sw)
        {
            if (isupper(*sw))
                _bin[0] |= (1 << ((*sw) - 'A'));
            if (islower(*sw))
                _bin[1] |= (1 << ((*sw) - 'a'));
        sw++;
        }
    }

    int operator,(Alpha a);
    Alpha operator&(Alpha a);
};



Alpha Alpha::operator&(Alpha a)
{
    Alpha result;
    result._bin[0] = _bin[0] & a._bin[0];
    result._bin[1] = _bin[1] & a._bin[1];
    return result;
}

int Alpha::operator,(Alpha a)
{
    unsigned int c =0, x;
    x = _bin[0] & a._bin[0];
    while (x)
    {
        c += (int)(x&1);
        x>>=1;
    }
    x = _bin[1] & a._bin[1];
    while (x)
    {
        c+=(int)(x & 1);
        x>>=1;
    }
    return c;
}



std::ostream& operator<<(std::ostream& os, const Alpha& a) {
    for (int i = 0; i<=25; ++i) {
        if (a._bin[0] & (1 << i)) {
            os << (char)('A' + i);
        }
        if (a._bin[1] & (1 << i)) {
            os << (char)('a' + i);
        }
    }
    return os;
}

int main(int argc, char *argv[])
{
    if (argc < 3)
        return -1;
    Alpha a(argv[1]);
    Alpha b(argv[2]);
    Alpha ma, mb;
    Alpha mask("AEIOU");
    std::cout << "First set:  " << (a) << std::endl;
    std::cout << "Second set:  " << (b) << std::endl;
    std::cout << "First masked:  " << (ma = a.operator&(mask)) << std::endl;
    std::cout << "Second masked:  " << (mb = b & mask ) << std::endl;
    std::cout << ((ma,mb)) << std::endl;

    return 0;
}


