#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

/**
 * * 중복 체크 필수! 중복위치의 몬스터의 위치가 같은 직선좌표에 있을 수 있음
 */

bool visit[100000]; //총알을 썻는지 안썻는지 판별

int solution(vector<vector<int>> monsters, vector<vector<int>> bullets)
{
    int answer = 0;
    int monSize = monsters.size();
    int bulSize = bullets.size();

    //슬라이딩 윈도 기법을 이용하여 체크를 하면 좋을듯
    for (int j = 0; j < bulSize; j++)
    {
        for (int i = 0; i < monSize; i++)
        {
            if (bullets[j][0] != 0 && monsters[i][0] != 0)
            {
                double tmp1 = bullets[j][1] / bullets[j][0];
                double tmp2 = monsters[i][1] / monsters[i][0];

                if (!visit[j] && (tmp1 == tmp2))
                {
                    if (monsters[i][1] == 0)
                    {
                        visit[j] = true;
                        answer++;
                    }
                }
                if(tmp1 != tmp2)
                {
                    double aa = tmp1*monsters[i][0] - monsters[i][1];
                    if(aa == 0)
                    {
                        visit[j]=true;
                        answer++;
                    }
                }
            }
            else
            {
                if (!visit[j] && (bullets[j][0] == 0))
                {
                    if (((1 * monsters[i][0]) - monsters[i][1]) == 0)
                    {
                        visit[j] = true;
                        answer++;
                    }
                }

                if (!visit[j] && (bullets[j][1] == 0))
                {
                    if (monsters[i][1] == 0)
                    {
                        visit[j] = true;
                        answer++;
                    }
                }
            }
        }
    }

    if (answer < 1)
    {
        return (-1);
    }
    return answer;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> monsters = {{2, 3}, {4, 5}, {3, -3}, {2, -4}, {3, -6}, {-3, -3}, {-5, 0}, {-4, 4}};
    vector<vector<int>> bullets = {{4, 1}, {4, 6}, {1, -2}, {-4, -4}, {-3, 0}};

    cout << solution(monsters, bullets) << endl;
    return 0;
}