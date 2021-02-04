#include "keyval.h"
#include <string>

// You can initialize constants in the constructor
keyval::keyval(unsigned int _initSize) : size(_initSize) {

};

// Add a new string value
void keyval::add(string key, string value) {
    // Check if the cache is full
    if (data.size() + 1 >= size) {
        string lru = findLRU();
        data.erase(lru);
    }
    data[key] = cacheVal {cacheEntryType::String, value};
    incrementCount(key);
};

void keyval::add(string key, int value) {
    // Check if the cache is full
    if (data.size() + 1 >= size) {
        string lru = findLRU();
        data.erase(lru);
    }
    data[key] = cacheVal {cacheEntryType::Integer, value};
    incrementCount(key);
};

// Increment the counters used to 
void keyval::incrementCount(string lastKey) {
    for (auto item : data) {
        // Skip the current item
        if (item.first.compare(lastKey) != 0) {
            data[item.first].counter++;
        }
    }
}

// Find the least recently used cache entry
string keyval::findLRU() {
    unsigned largestFound = 0;
    string largestKey;
    for (auto item : data) {
        if (item.second.counter >= largestFound) {
            largestFound = item.second.counter;
            largestKey = item.first;
        }
    }
    return largestKey;
}

void keyval::print() {
    for (auto item : data) {
        string strVal;
        switch (item.second.type) {
            case cacheEntryType::Integer:
                strVal = to_string(get<int>(item.second.value));
                break;
            case cacheEntryType::String:
                strVal = get<string>(item.second.value);
                break;
        }
        cout << item.first << " - "  << strVal
            << " - " << item.second.counter << endl;
    }
}
