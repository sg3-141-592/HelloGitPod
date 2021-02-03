#include <iostream>
#include <string>
#include <string_view>

using namespace std;

int main()
{
    string_view text{ "hello" };
    string_view str{ text };
    string_view more{ str };
    

    cout << text << str << more << endl;

    return 0;
}
