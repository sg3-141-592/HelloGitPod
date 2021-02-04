#include <iostream>
#include <memory>
#include <string>
#include <string_view>
#include <variant>
using namespace std;

#include "include/keyval.h"

int main()
{
    auto cache = make_unique<keyval>(10);
    for (int i = 0; i < 100; i++) {
        cache->add("Int" + to_string(i), i);
        cache->add("String" + to_string(i), to_string(i));
    }
    cache->print();
    return 0;
}
