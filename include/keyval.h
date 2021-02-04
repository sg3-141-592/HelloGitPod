#include <iostream>
#include <map>
#include <string>
using namespace std;

class keyval {
    public:
        keyval(unsigned int initSize);
        void add(string key, string value);
        void print();
    private:
        const int size;
        map<string, string> data;
};