#include <typeinfo>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    string str1 = "FRANCE";

    cout<<typeid(str1[1]).name()<<endl;
    return 0;
}
