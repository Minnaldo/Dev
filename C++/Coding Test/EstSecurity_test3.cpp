#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int dir[2][2] = {{-1, -1}, {-1, 1}};
bool chk[31][31];
int beatQuan[31][31];

int max(int &a, int &b)
{
    return a > b ? a : b;
}

int BFS(vector<vector<int>> &B, queue<pair<int, int>> &qq, int N)
{
    int count = 0;
    queue<pair<int, int>> q;
    q = qq;
    int cur_y = q.front().first, cur_x = q.front().second;
    chk[cur_y][cur_x] = true;
    beatQuan[cur_y][cur_x] = 0;
    int y, x;

    while (!q.empty())
    {
        cur_y = q.front().first;
        cur_x = q.front().second;

        for (int i = 0; i < 2; i++)
        {
            int nxt_y = cur_y + dir[i][0], nxt_x = cur_x + dir[i][1];
            int bey_y = nxt_y + dir[i][0], bey_x = nxt_x + dir[i][1]; // 알라딘의 폰 너머에 공간의 좌표

            // 알라딘 폰의 좌표
            if (B[nxt_y][nxt_x] == 2 && nxt_y >= 0 && nxt_y < N && nxt_x >= 0 && nxt_x < N)
            {
                if (!chk[bey_y][bey_x] && bey_y >= 0 && bey_y < N && bey_x >= 0 && bey_x < N)
                {
                    if (B[bey_y][bey_x] == 0)
                    {

                        q.push(make_pair(bey_y, bey_x));
                        beatQuan[bey_y][bey_x] = max(beatQuan[bey_y][bey_x], beatQuan[cur_y][cur_x] + 1);
                        chk[bey_x][bey_x] = true;
                    }
                }
            }
        }

        y = q.front().first;
        x = q.front().second;

        if (count < beatQuan[y][x])
        {
            count = beatQuan[y][x];
        }

        q.pop();
    }

    return count;
}

int solution(vector<string> &B)
{
    queue<pair<int, int>> q;
    int N = B.size();

    vector<vector<int>> boder(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (B[i][j] == '.')
                boder[i][j] = 0;
            else if (B[i][j] == 'X') // aladdin's pwan
                boder[i][j] = 2;
            else // jafar's pwan
            {
                boder[i][j] = -1;
                q.push(make_pair(i, j));
            }
        }
    }

    int answer = BFS(boder, q, N);

    return answer;
}

int main(int argc, char const *argv[])
{
    vector<string> B = {"..X...", "......", "....X.", ".X....", "..X.X.", "...O.."};                                                                                  // 2
    vector<string> B2 = {".........X", "..........", ".......X..", "..........", ".....X....", "..........", "...X......", "..........", ".X........", "O........."}; // 4
    vector<string> B3 = {"....", ".X..", "....", "...O"};                                                                                                             // 0
    vector<string> B4 = {"......", "....X.", ".....X", "..X...", ".X.X..", "..O..."};                                                                                 // 1




    int answer = solution(B4);
    cout << "Answer ::: " << answer << endl;

    return 0;
}