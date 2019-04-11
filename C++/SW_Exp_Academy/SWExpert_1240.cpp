#include <iostream>
#include <fstream>

using namespace std;

/**
 *  * 검증코드가 잘못된경우 0 반환
 *  * 1~9, 전부 0으로 시작 1로 종료
 *  * 0 1 0 1 비율
 */

int solution(int **arr)
{
}

int main(int argc, char const *argv[])
{
    ifstream fs("input.txt");

    int x, y, T;
    cin >> T;

    for (int k = 0; k < T; k++)
    {
        cin >> y >> x;
        int **arr = new int *[y];

        for (int i = 0; i < y; i++)
        {
            arr[i] = new int[x];
            for (int j = 0; j < x; j++)
            {
                int tmp;
                cin >> tmp;
                arr[i][j] = tmp;
            }
        }

        cout << "#" << k + 1 << " ";
        cout << solution(arr) << endl;
    }

    return 0;
}