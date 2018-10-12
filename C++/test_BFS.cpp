#include <vector>
#include <iostream>

using namespace std;

vector<int> xq, yq, lq;
int cnt;

void enqueue(int _x, int _y, int _l)
{
    xq.push_back(_x);
    yq.push_back(_y);
    lq.push_back(_l);
    cnt++;
}

// -1 리턴 조건 : 모든지점을 방문하였는데 최종점에 도달하지 못했을 경우
int BFS(vector<vector<int>> maps, int xpos, int ypos, int xlen, int ylen)
{
    int pos = 0; // Queue 포지션

    enqueue(xpos, ypos, 1);

    //FIXME: condition
    while (pos < cnt && (xq[pos] != xlen - 1 || yq[pos] != ylen - 1))
    {
        cout<<"Go\t";
        maps[yq[pos]][xq[pos]] = 0; //지나갔다는 표시

        //갈수 있을 경우 다음 위치의 좌표를 큐에 삽입
        if (yq[pos] > 0 && maps[yq[pos] - 1][xq[pos]] == 1) //UP 가능할경우 이동할 지점 좌표를 큐에 삽입
        {
            enqueue(xq[pos], yq[pos] - 1, lq[pos] + 1);
        }
        if (yq[pos] < ylen - 1 && maps[yq[pos] + 1][xq[pos]] == 1) //Down
        {
            enqueue(xq[pos], yq[pos] + 1, lq[pos] + 1);
        }
        if (xq[pos] > 0 && maps[yq[pos]][xq[pos] - 1] == 1) //Left
        {
            enqueue(xq[pos] - 1, yq[pos], lq[pos] + 1);
        }
        if (xq[pos] < xlen - 1 && maps[yq[pos]][xq[pos] + 1] == 1) //Right
        {
            enqueue(xq[pos] + 1, yq[pos], lq[pos] + 1);
        }
        //큐의 다음 인덱스로 이동 == 좌표로 이동
        pos++;

        cout << xq[pos] << " ";
        cout << yq[pos] << " ";
        cout << lq[pos] << " " << endl;
    }

    // //queue 프린트
    // for (int i = 0; i < xq.size(); i++)
    // {
    //     cout << xq[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < yq.size(); i++)
    // {
    //     cout << yq[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < lq.size(); i++)
    // {
    //     cout << lq[i] << " ";
    // }
    // cout << endl;

    //pos : queue의 인덱스, cnt : 큐에 집어 넣을때마다 1씩 증가
    if (pos < cnt)
    {
        cout << "arrived at the Final spot" << endl;
        return lq[pos];
    }
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> maps = {{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}};
    vector<vector<int>> maps2 = {{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 0}, {0, 0, 0, 0, 1}};

    int ylen = maps.size();
    int xlen = maps.at(0).size();
    int result1 = BFS(maps, 0, 0, xlen, ylen);
    int result2 = BFS(maps2, 0, 0, xlen, ylen);
    cout << "Map 1 최단 경로 길이 : " << result1 << endl;
    cout << "Map 2 최단 경로 길이 : " << result2 << endl;

    return 0;
}