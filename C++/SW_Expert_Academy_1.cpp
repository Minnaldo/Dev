#include <vector>
#include <queue>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>>(4, vector<int>(2)) = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; //up, down, left, right check
queue<pair<int, int>> q;

int main(int argc, char const *argv[])
{
    int n, k = 0;

    vector<vector<int>> map(n, vector<int>(n));
    vector <vector <int> > check (n, nvector <int> (n));

    //check 벡터 초기화
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            check[i][j] = 0;
        }
    }
    return 0;
}

bool isInside(int a, int b)
{
    return (a >= 0 && a < n) && (b >= 0 && b < n);
}

void find(vector<vector<int>> map, int xpos, int ypos, int n)
{
    //현재 높이보단 낮지만, 주변 높이중 가장 높은걸 찾아야 길게 이어갈 수 있음
    while (true)
    {
        vector <int> tmp (4);
        for (int i = 0; i < 4; i++)
        { //상, 하, 좌, 우 모두 탐색
            int next_y = cur_y + dir[i][0];
            int next_x = cur_x + dir[i][1];

            if (isInside(next_y, next_x) && map[next_y][next_x] <= map[cur_y][cur_x])
            {
                tmp.pop_back(map[next_y][next_x]);
            }
        }

        auto itr = max_element(tmp.begin(), tmp.end());
        int tmpPos = itr - tmp.begin();

        switch(tmpPos)
        {
            case 0:
            
            break;
            case 1:
            break;
            case 2:
            break;
            case 3:
            break;
        }

    }
}