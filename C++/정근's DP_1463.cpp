#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N, memo[1000005];

int func(int num)
{
   if (num == 1)
   {
      return 0;
   }
   if (memo[num] != -1)
   {
      return memo[num];
   }
   memo[num] = 987654321;
   if (num % 3 == 0)
   {
      memo[num] = min(memo[num], func(num / 3) + 1);
   }
   if (num % 2 == 0)
   {
      memo[num] = min(memo[num], func(num / 2) + 1);
   }
   memo[num] = min(memo[num], func(num - 1) + 1);
   return memo[num];
}

int main()
{
   scanf("%d", &N);
   memset(memo, -1, sizeof memo);
   printf("%d", func(N));
}