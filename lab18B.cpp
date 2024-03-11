#include <iostream>

class Alpha
{
private:
    unsigned _bin;

public:
    Alpha() : _bin(0) {}
    Alpha operator+(Alpha a);
    Alpha operator-(Alpha a);
    Alpha operator~();
    Alpha(char *);
    operator char *();
};

Alpha Alpha::operator+(Alpha a)
{
    Alpha result;
    result._bin = a._bin | _bin;
    return result;
}

Alpha Alpha::operator-(Alpha a)
{
    Alpha result;
    result._bin = a._bin ^ _bin;
    return result;
}

Alpha Alpha::operator~()
{
    Alpha result;
    result._bin = ~_bin;
    return result;
}

Alpha::Alpha(char *s)
{
    _bin = 0;
    while (*s)
    {
        _bin |= (1 << (tolower(*s) - 'a'));
        s++;
    }
}

Alpha::operator char *()
{
    static char s[32];
    unsigned w = _bin;
    int i = 0, j = 0;
    while (w > 0)
    {
        if ((w & 1) && ('a'+i <= 122))
                s[j++] = 'a' + i;
        i++;
        w = w >> 1;
    }
    s[j++] = '\n';
    s[j++] = '\0';
    return s;
}

int main(int argc, char **argv)
{
    if (argc < 3)
        return -1;
    Alpha a(argv[1]);
    Alpha b(argv[2]);
    Alpha res = ~(a - b);
    std::cout << (char *)res << std::endl;
    return 0;
}