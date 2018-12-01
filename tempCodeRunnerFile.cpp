#include <cstdio>

using namespace std;

int main()
{
    int n,num,ans;
    scanf("%d", &n);
    scanf("%d", &num);
    while(true)
    {
        ans = ans + (num%10);
        num /= 10;
        
        if(num<0)
        {
            printf("%d", ans);
        }
    }
    // printf("%d\n", num);
    return 0;
}