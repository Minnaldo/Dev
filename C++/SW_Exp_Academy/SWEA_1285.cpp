#include <iostream>

/** 아름이의 돌 던지기
 *
 */

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);

    for (int tc = 1; tc <= t; tc++)
    {
        int closer = 987654321, people = 0;
        int n;
        scanf("%d", &n);

        int *arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            arr[i] = abs(arr[i]);
            closer = closer < arr[i] ? closer : arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (closer == arr[i])
            {
                people++;
            }
        }

        printf("#%d %d %d\n", tc, closer, people);
    }
    return 0;
}
