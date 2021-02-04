#include <iostream>
#include <string>
#include <string_view>
#include <variant>
using namespace std;

#include "include/keyval.h"

int main()
{
    auto cache = new keyval(1024);
    cache->add("Hello", "World");
    cache->add("Hi", "Billy");
    cache->add("NumberA", 123);
    cache->add("NumberB", 98765);
    cache->print();
    return 0;
}
