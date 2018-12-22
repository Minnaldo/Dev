#include <iostream>
#include <string>

using namespace std;

void over(int arg)
{
    cout << "Integer function overloading  " << arg << endl;
}
void over(string arg)
{
    cout << "string function overloading  " << arg << endl;
}
void over()
{
    cout << "Call void function overloading" << endl;
}

int main(int argc, char const *argv[])
{
    over();
    over("call the string function");
    over(111);
    return 0;
}