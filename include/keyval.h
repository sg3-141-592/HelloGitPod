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
    unsigned int counter = 0;
};

class keyval {
    public:
        keyval(unsigned int initSize);
        void add(string key, variant<int, string> value);
        variant<int, string> getEntry(string key);
        void print();
        string findLRU();
    private:
        const int size;
        map<string, cacheVal> data;
        void incrementCount(string lastKey);
};