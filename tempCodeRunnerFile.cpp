#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    String str ;
    getline(cin, str);
    int size = str.size();
    int cnt = 0;
    for(int i = 0; i<size; i++){
        if(str[i] == ' '){
            cnt++;
        }
    }

    printf("%d", cnt-1);
    
    return 0;
}