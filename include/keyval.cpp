#include "keyval.h"
#include <string>
#include <variant>

// You can initialize constants in the constructor
keyval::keyval(unsigned int _initSize) : size(_initSize) {

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

void keyval::add(string key, variant<int, string> value) {
    // Check if the cache is full
    if (data.size() + 1 >= size) {
        string lru = findLRU();
        data.erase(lru);
    }
    cacheEntryType entryType;
    if(holds_alternative<string>(value) == 1) {
        entryType = cacheEntryType::String;
    } else if(holds_alternative<int>(value) == 1) {
        entryType = cacheEntryType::Integer;
    }
    data[key] = cacheVal {entryType, value};
    incrementCount(key);
}

variant<int, string> keyval::getEntry(string key) {
    return data[key].value;
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
