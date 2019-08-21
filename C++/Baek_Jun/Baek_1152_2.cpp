#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[])
{
    stringstream ss;
    string str;
    getline(cin, str);
    ss.str(str);
    int cnt = 0;
    while(ss>>str){
        cnt++;
    }
    printf("%d", cnt);

    return 0;
}