#include <vector>
#include <algorithm>
#include <chrono>
#include <iostream>

using namespace std;

int BFS(vector<vector<int>>);
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
    int pos = 0; //좌표 포지션
    int ylen = maps.size();
    int xlen = maps.at(0).size();

    vector<pair<int, int>> cur_pos;
    vector<int> length;
    cur_pos.reserve(xlen*ylen);
    cur_pos.push_back(make_pair(0, 0));
    length.push_back(1);

    while ((cur_pos.at(pos).first != ylen - 1 || cur_pos.at(pos).second != xlen - 1))
    {
        //현재위치 밟은것 표시
        maps[cur_pos.at(pos).first][cur_pos.at(pos).second] = 0;

        for (int i = 0; i < 4; i++)
        {
            int next_ypos = cur_pos.at(pos).first + dir[i][0];
            int next_xpos = cur_pos.at(pos).second + dir[i][1];

            //맵 안에 있는가?
            if ((next_ypos >= 0 && next_xpos >= 0 && next_ypos < ylen && next_xpos < xlen) && maps[next_ypos][next_xpos] == 1)
            {
                cur_pos.push_back(make_pair(next_ypos, next_xpos));
                length.push_back(length.at(pos) + 1);
            }
        }

        cout << "Pos : " << pos << "  ypos : " << cur_pos.at(pos).first << " xpos : " << cur_pos.at(pos).second << "   length : " << length.at(pos) << endl;

        if ((cur_pos.begin() + pos == cur_pos.end() - 1) && (cur_pos.at(pos).first != (ylen - 1) || cur_pos.at(pos).second != (xlen - 1)))
        {
            return (-1);
        }

        pos++;
    }

    if ((cur_pos.at(pos).first == (ylen - 1) && cur_pos.at(pos).second == (xlen - 1))) //4,4지점 (도착점)에 도착했을 때
    {
        return length.at(pos);
    }
}