#include <queue>
#include <vector>
#include <chrono>
#include <iostream>

using namespace std;

int BFS(vector<vector<int>> maps);
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main(int argc, char const *argv[])
{
    auto start1 = chrono::high_resolution_clock::now();
    vector<vector<int>> maps = {{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}};
    auto end1 = chrono::high_resolution_clock::now();

    auto start2 = chrono::high_resolution_clock::now();
    vector<vector<int>> maps2 = {{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 0}, {0, 0, 0, 0, 1}};
    auto end2 = chrono::high_resolution_clock::now();

    int result1 = BFS(maps);
    cout << "Result 1 : " << result1 << "\tDuration : " << (float)(end1 - start1).count() / CLOCKS_PER_SEC << endl;

    int result2 = BFS(maps2);
    cout << "Result 2 : " << result2 << "\tDuration : " << (float)(end2 - start2).count() / CLOCKS_PER_SEC << endl;
    return 0;
}

int BFS(vector<vector<int>> maps)
{
    int ylen = maps.size();
    int xlen = maps.at(0).size();

    queue<int> cur_ypos, cur_xpos, length;

    cur_ypos.push(0);
    cur_xpos.push(0);
    length.push(1);

    while ((cur_ypos.front() != ylen - 1 || cur_xpos.front() != xlen - 1))
    {

        int y = cur_ypos.front();
        int x = cur_xpos.front();
        int distance = length.front();
        maps[y][x] = 0;

        for (int i = 0; i < 4; i++)
        {
            int next_ypos = y + dir[i][0];
            int next_xpos = x + dir[i][1];

            if ((next_ypos >= 0 && next_xpos >= 0 && next_ypos < ylen && next_xpos < xlen) && maps[next_ypos][next_xpos] == 1)
            {
                cur_ypos.push(next_ypos);
                cur_xpos.push(next_xpos);
                length.push(distance + 1);
            }
        }

        cout << " Y : " << y << "   X : " << x << "  length : " << length.front() << " Q ysize: " << cur_ypos.size() << " Q xsize: " << cur_xpos.size() << endl;

        if ((cur_ypos.size() <= 1) && (y != (ylen - 1) || x != (xlen - 1)))
        {
            return (-1);
        }

        cur_ypos.pop();
        cur_xpos.pop();
        length.pop();
    }

    if (cur_ypos.front() == ylen - 1 && cur_xpos.front() == xlen - 1)
    {
        return length.front();
    }
}