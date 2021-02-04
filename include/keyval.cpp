#include "keyval.h"

// You can initialize constants in the constructor
keyval::keyval(unsigned int _initSize) : size(_initSize) {
    cout << "Hi" << std::endl;
}

// Add a new key
void keyval::add(string key, string value) {
    data[key] = value;
}

void keyval::print() {
    for (auto item : data) {
        cout << item.first << " - " << item.second << endl;
    }
}
