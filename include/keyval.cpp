#include "keyval.h"
#include <string>

// You can initialize constants in the constructor
keyval::keyval(unsigned int _initSize) : size(_initSize) {

};

// Add a new string value
void keyval::add(string key, string value) {
    // Check if the cache is full
    if (data.size() + 1 >= size) {
        cout << "Cache full";
    }
    data[key] = cacheVal {cacheEntryType::String, value};
};

void keyval::add(string key, int value) {
    data[key] = cacheVal {cacheEntryType::Integer, value};
};

void keyval::print() {
    for (auto item : data) {
        switch (item.second.type) {
            case cacheEntryType::Integer:
                cout << item.first << " - "
                    << get<int>(item.second.value) << endl;
                break;
            case cacheEntryType::String:
                cout << item.first << " - "
                    << get<string>(item.second.value) << endl;
                break;
        }
    }
}
