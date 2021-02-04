#include <iostream>
#include <string>
#include <string_view>
#include <variant>
using namespace std;

#include "include/keyval.h"

int main()
{
    auto cache = new keyval(4);
    for (int i = 0; i < 10; i++) {
        cache->add("Int" + to_string(i), i);
        cache->add("String" + to_string(i), to_string(i));
    }
    cache->print();
    return 0;
}
