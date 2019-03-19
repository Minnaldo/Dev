#include <iostream>

/* Mini Fantasy War 백준_12790 ( https://www.acmicpc.net/problem/12790 ) */

using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        int bhp, bmp, back, bdef, hp, mp, ack, def;
        scanf("%d %d %d %d %d %d %d %d", &bhp, &bmp, &back, &bdef, &hp, &mp, &ack, &def);

        int anshp = (bhp + hp) < 1 ? 1 : (bhp + hp);
        int ansmp = (bmp + mp) < 1 ? 1 : (bmp + mp);
        int ansack = (back + ack) < 0 ? 0 : (back + ack);
        int ansdef = bdef + def;

        int ans = anshp + (5 * ansmp) + (2 * ansack) + (2 * ansdef);
        printf("%d\n",ans);
    }
    return 0;
}