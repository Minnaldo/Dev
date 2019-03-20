#include <fstream>
#include <iostream>

using namespace std;

int arr[101][101];

int main(int argc, char const *argv[])
{
    fstream fs("input.txt");
    int n, cnt = 0;
    fs >> n;

    for (int a = 0; a < n; a++)
    {
        int x, y;
        fs >> x >> y;

        int xend = x + 10, yend = y + 10;

        for (int i = x; i <= xend; i++)
        {
            for (int j = y; j <= yend; j++)
            {
                if (arr[i][j] == 1)
                {
                    arr[i][j] = 0;
                    cnt--;
                }
                else
                {
                    arr[i][j] = 1;
                    cnt++;
                }
            }
        }
    }

    printf("%d\n", cnt);
    return 0;
}