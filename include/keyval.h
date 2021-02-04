#include <iostream>
#include <map>
#include <string>
using namespace std;

class keyval {
    public:
        keyval(unsigned int initSize);
    private:
        const int size;
        map<string, string> data;
};