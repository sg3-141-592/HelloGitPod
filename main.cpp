#include <iostream>
#include <string>
#include <string_view>
using namespace std;

#include "keyval.h"

int main()
{
    string_view text{ "hello" };
    string_view str{ text };
    string_view more{ str };
    

    cout << text << str << more << endl;

    auto myStore = new keyval();

    cout << myStore->a << endl;

    return 0;
}
