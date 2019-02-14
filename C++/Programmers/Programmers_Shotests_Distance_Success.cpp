#include <queue>
#include <utility>
#include <chrono>
#include <iostream>

using namespace std;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int check[101][101];

int BFS(vector<vector<int>> maps)
{
    int ylen = maps.size();
    int xlen = maps[0].size();
    queue<pair<int, int>> cur_pos;
    cur_pos.push(make_pair(0, 0));

    while (!cur_pos.empty())
    {
        int y = cur_pos.front().first;
        int x = cur_pos.front().second;
        check[y][x] = true;

        for (int i = 0; i < 4; i++)
        {
            int next_y = y + dir[i][0];
            int next_x = x + dir[i][1];

            if ((next_y >= 0 && next_x >= 0 && next_y < ylen && next_x < xlen))
            {
                if (maps[next_y][next_x] > 0 && check[next_y][next_x] == false)
                {
                    cur_pos.push(make_pair(next_y, next_x));
                    check[next_y][next_x] = true;
                    maps[next_y][next_x] = maps[y][x] + 1;
                }
            }
        }
        cur_pos.pop();
    }

    if (maps[ylen - 1][xlen - 1] != 1)
    {
        return maps[ylen - 1][xlen - 1];
    }
    else
    {
        return -1;
    }
}

int main(int argc, char const *argv[])
{
    auto start1 = chrono::high_resolution_clock::now();
    vector<vector<int>> maps = {{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}};
    auto end1 = chrono::high_resolution_clock::now();

    auto start2 = chrono::high_resolution_clock::now();
    vector<vector<int>> maps2 = {{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 0}, {0, 0, 0, 0, 1}};
    auto end2 = chrono::high_resolution_clock::now();

    int result1 = BFS(maps);
    cout << "Result 1 : " << result1 << endl;

    int result2 = BFS(maps2);
    cout << "Result 2 : " << result2 << endl;
    return 0;
}