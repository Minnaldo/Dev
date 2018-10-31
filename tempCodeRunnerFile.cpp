#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

/** 인구이동 (https://www.acmicpc.net/problem/16234)
 * * BFS이용해 탐색, 더이상 조건에 맞는 셀이 없을경우 카운트 1 증가
 * * 인구수를 P 라 할때,  L <= p[1] - p[2] <= R 이면 국경선 오픈
 * * 연합인 각 나라의 인구수는 (연합의인구수)/(연합인 나라 수), 소수점 버림
 * * 하루가 지난후(인구이동이 완료되면) 모든 국경선 폐쇄
 */

bool visit[50][50];

int BFS(vector<int> region)
{

}

int main(int argc, char const *argv[])
{
    int N, L, R;
    scanf("%d %d %d", &N, &L, &R);
    int **arr = new int *[N];    
    for(int i=0; i<N; i++)
    {
        arr[i] = new int [N];
        for(int j = 0; j<N; j++)
        {
            int tmp;
            scanf("%d", &tmp);
            arr[i][j] = tmp;
        }
    }
}