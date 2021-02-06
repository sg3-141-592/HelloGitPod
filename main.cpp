#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <regex>
#include <string>
#include <string_view>
#include <variant>
using namespace std;

#include "include/wildcardsearch.h"
#include "include/keyval.h"

int main()
{
    // auto cache = make_unique<keyval>(10);
    // for (int i = 0; i < 100; i++) {
    //     cache->add("Int" + to_string(i), i);
    //     cache->add("String" + to_string(i), to_string(i));
    // }
    // cache->print();

    string textA = "HelloWorldMyNameIsSean";
    string textB = "thisdoesn'tcontainthatword";
    regex self_regex("hello",
        regex_constants::icase);
    if (regex_search(textA, self_regex)) {
         cout << "Match";
    }
    else {
        cout << "No Match";
    }
    if (regex_search(textB, self_regex)) {
         cout << "Match";
    }
    else {
        cout << "No Match";
    }

    return 0;
}
