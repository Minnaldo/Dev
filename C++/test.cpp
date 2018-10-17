<<<<<<< HEAD
#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

int main()
{
    int length;
    for (int i = 1; i <= 10; i++)
    {
        scanf("%d", &length);
        char *a = new char[length];
        scanf("%s", a);
        // string str;
        // getline(cin, str);
        stack<char> s;

        for (int k = 0; k < length; k++)
        {
            if (a[k] == '(' || a[k] == '{' || a[k] == '[')
            {
                s.push(a[k]);
            }
            else
            {
                if (s.top() == '(')
                {
                    if (a[k] != ')')
                    {
                        printf("#%d %d\n", i, 0);
                        break;
                    }
                    else
                    {
                        s.pop();
                    }
                }
                else if (s.top() == '{')
                {
                    if (a[k] != '}')
                    {
                        printf("#%d %d\n", i, 0);
                        break;
                    }
                    else
                    {
                        s.pop();
                    }
                }
                else
                {
                    if (a[k] != ']')
                    {
                        printf("#%d %d\n", i, 0);
                        break;
                    }
                    else
                    {
                        s.pop();
                    }
                }
            }
        }

        if (s.empty())
        {
            printf("#%d %d\n", i, 1);
        }
        else
        {
            printf("#%d %d\n", i, 0);
        }
    }
    return 0;
}
=======
#include <cstdio>
#include <iostream>
#include <fstream>

#define size 10

using namespace std;

int n, k, heighest, ans;
int map[size][size];
int visit[size][size];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

typedef struct info
{
    int h, w;
    int height;
    int usedk;
    int len;
};

void sol(info cur)
{
    //길이가 더 길어졌을 때만 정답으로 저장
    ans = ans > cur.len ? ans : cur.len;

    for (int d = 0; d < 4; d++)
    {
        info nxt = cur;
        nxt.h += dir[d][0];
        nxt.w += dir[d][1];
        nxt.height = map[nxt.h][nxt.w];

        //방문 에정 위치가 맵 안에 있고, 방문하지 않은경우
        if (visit[nxt.h][nxt.w] && (nxt.h >= 0 && nxt.w >= 0 && nxt.h < n && nxt.w < n))
        {
            if (nxt.height < cur.height)
            {
                //방문 표시
                visit[nxt.h][nxt.w] = 1;
                //등산로 길이 1 증가
                nxt.len++;
                //nxt를 기점으로 다음 탐색을 위해 함수 호출
                sol(nxt);
                //다시 방문 표시를 해제
                visit[nxt.h][nxt.w] = 0;
            }
            else
            {
                //현재까지 공사가 이루어 지지 않았고
                // 다음 높이에 대해 K만큼 공사를 했을 때 현재보다 작을 경우
                if (!cur.usedk && nxt.height - k < cur.height)
                {
                    visit[nxt.h][nxt.w] = 1;     //방문 표시
                    nxt.len++;                   //등산로 길이 증가
                    nxt.usedk = 1;               //공사 했음 표시
                    nxt.height = cur.height - 1; //현재높이보다 1만 작게 깎아야 가장 긴 등산로를 만들 수 있다.
                    sol(nxt);
                    visit[nxt.h][nxt.w] = 0;
                }
            }
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++)
    {
        scanf("%d %d", &n, &k);

        heighest = ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &map[i][j]);
                //3항연산자를 이용 가장 높은 지점 구하기
                heighest = heighest > map[i][j] ? heighest : map[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                //가장 높은 봉우리일 경우에만 탐색을 시작
                if (heighest == map[i][j])
                {
                    //방문 표시
                    visit[i][j] = 1;
                    //위치 (i,j), 높이, 공사 진행하지 않음(0), 현재 등산로 길이(1)
                    info cur = {i, j, map[i][j], 0, 1};
                    //cur를 기점으로 탐색하기 위해 함수 호출
                    sol(cur);
                    //다시 방문 표시 해제
                    visit[i][j] = 0;
                }
            }
        }

        printf("#%d %d\n", t, ans);
    }

    return 0;
}
>>>>>>> 3a86120b2d86ab7f9f845dd874e1487398d2c167
