#include <queue>
#include <vector>
#include <algorithm>
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
    int pos = 0;
    int ylen = maps.size();
    int xlen = maps.at(0).size();

    queue<pair<int, int>> cur_pos;
    queue<int> length;

    cur_pos.push(make_pair(0, 0));
    length.push(1);

    while ((cur_pos.front().first != ylen - 1 || cur_pos.front().second != xlen - 1))
    {

        int y = cur_pos.front().first;
        int x = cur_pos.front().second;
        int distance = length.front();
        maps[y][x] = 0;

        for (int i = 0; i < 4; i++)
        {
            int next_ypos = y + dir[i][0];
            int next_xpos = x + dir[i][1];

            if ((next_ypos >= 0 && next_xpos >= 0 && next_ypos < ylen && next_xpos < xlen) && maps[next_ypos][next_xpos] == 1)
            {
                cur_pos.push(make_pair(next_ypos, next_xpos));
                length.push(distance + 1);
            }
        }

        cout<< " Y : "<< y<<"   X : "<<x<<"  length : "<<length.front()<<"    POS : "<<pos<<" Q size: "<<cur_pos.size()<<endl;

        if ((cur_pos.size() <= 1) && (y != (ylen - 1) || x != (xlen - 1)))
        {
            return (-1);
        }
        
        cur_pos.pop();
        length.pop();
    }

    if (cur_pos.front().first == ylen - 1 && cur_pos.front().second == xlen - 1)
    {
        return length.front();
    }
}