#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

int BFS(vector<vector<int>>, int, int);
bool lookAround(vector<vector<int>>, int, int, int, int);

int main(int argc, char const *argv[])
{
    vector<vector<int>> maps = {{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}};
    vector<vector<int>> maps2 = {{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 0}, {0, 0, 0, 0, 1}};

    // int result1 = BFS(maps, 0, 0);
    // cout << "Result 1 : " << result1 << endl;

    int result2 = BFS(maps2, 0, 0);
    cout << "Result 2 : " << result2 << endl;
    return 0;
}

bool lookAround(vector<vector<int>> map, int cur_xpos, int cur_ypos, int ylen, int xlen)
{
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<bool> tmp = {true, true, true, true};

    for (int i = 0; i < 4; i++)
    {
        int tmp_ypos = cur_ypos + dir[i][0];
        int tmp_xpos = cur_xpos + dir[i][1];
        if (tmp_ypos >= 0 && tmp_xpos >= 0 && tmp_ypos < ylen - 1 && tmp_xpos < xlen - 1)
        {
            if (map[tmp_ypos][tmp_xpos] == 0)
            {
                tmp[i] = false;
            }
            else
            {
                tmp[i] = true;
            }
        }
    }

    if (find(tmp.begin(), tmp.end(), true) == tmp.end()) // tmp원소 모두 false
    {
        //갈 수 있는 길 존재, tmp내 원소 모두 false
        // cout << "True in Look Around" << endl;
        return true;
    }
    else
    {
        //갈수 있는 길 존재 하지 않음, tmp내 원소 중 하나가 true
        // cout << "False in Look Around" << endl;
        return false;
    }
}

int BFS(vector<vector<int>> maps, int xpos, int ypos)
{
    int pos = 0; //좌표 포지션
    int cnt = 1; //지나간 거리 길이
    int ylen = maps.size();
    int xlen = maps.at(0).size();

    vector<pair<int, int>> cur_pos;
    vector<int> length;
    cur_pos.push_back(make_pair(ypos, xpos));
    length.push_back(cnt);

    //first = y axious, second = x axious
    // TODO:
    while ((cur_pos.at(pos).first != ylen - 1 || cur_pos.at(pos).second != xlen - 1))
    {
        // cout << "Go\t";
        //현재위치 밟은것 표시
        maps[cur_pos.at(pos).first][cur_pos.at(pos).second] = 0;
        //UP
        if (cur_pos.at(pos).first > 0 && maps[cur_pos.at(pos).first - 1][cur_pos.at(pos).second] == 1)
        {
            cur_pos.push_back(make_pair(cur_pos.at(pos).first - 1, cur_pos.at(pos).second));
            length.push_back(length.at(pos) + 1);
        }
        //Down
        if (cur_pos.at(pos).first < ylen - 1 && maps[cur_pos.at(pos).first + 1][cur_pos.at(pos).second] == 1)
        {
            cur_pos.push_back(make_pair(cur_pos.at(pos).first + 1, cur_pos.at(pos).second));
            length.push_back(length.at(pos) + 1);
        }
        //Left
        if (cur_pos.at(pos).second > 0 && maps[cur_pos.at(pos).first][cur_pos.at(pos).second - 1] == 1)
        {
            cur_pos.push_back(make_pair(cur_pos.at(pos).first, cur_pos.at(pos).second - 1));
            length.push_back(length.at(pos) + 1);
        }
        //Right
        if (cur_pos.at(pos).second < xlen - 1 && maps[cur_pos.at(pos).first][cur_pos.at(pos).second + 1] == 1)
        {
            cur_pos.push_back(make_pair(cur_pos.at(pos).first, cur_pos.at(pos).second + 1));
            length.push_back(length.at(pos) + 1);
        }

        cout << "pos : " << pos << " first : " << cur_pos.at(pos).first << " cecond : " << cur_pos.at(pos).second << " size :  " << cur_pos.size() << " length : " << length.at(pos) << endl;

        if (lookAround(maps, cur_pos.at(pos).first, cur_pos.at(pos).second, ylen, xlen) && pos != pos-1)
        {
            if (cur_pos.at(pos - 1).first == cur_pos.at(pos).first && cur_pos.at(pos - 1).second == cur_pos.at(pos).second)
            {
                return (-1);
            }
        }

        pos++;
    }

    // cout<<pos<<"  "<<cur_pos.at(pos).first<<"  "<<cur_pos.at(pos).second<<endl;
    // cout<<"ASDF : " << pos << "  " << cur_pos.at(pos).first << "  " << cur_pos.at(pos).second << "  " << cur_pos.at(pos)<< endl;

    // end condition
    if ((cur_pos.at(pos).first == (ylen - 1) && cur_pos.at(pos).second == (xlen - 1))) //4,4지점 (도착점)에 도착했을 때
    {
        cout << "End of Maps" << endl;
        return length.at(pos);
    }
    else
    {
        if (cur_pos.at(pos - 1).first == cur_pos.at(pos).first && cur_pos.at(pos - 1).second == cur_pos.at(pos).second)
            return (-1);
    }
}