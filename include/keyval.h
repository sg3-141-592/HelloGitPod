#include <iostream>
#include <map>
#include <string>
#include <variant>
using namespace std;

enum class cacheEntryType {
    Integer, String
};

struct cacheVal {
    cacheEntryType type;
    variant<int, string> value;
};

class keyval {
    public:
        keyval(unsigned int initSize);
        void add(string key, string value);
        void add(string key, int value);
        void print();
    private:
        const int size;
        map<string, cacheVal> data;
};