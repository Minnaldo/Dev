// 너비 우선 탐색 (Breadth  First SEarch) 구현
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int BFS(int v);
bool isInside(int a, int b);

vector < vector<int> > maps(100, vector<int> (100));
int check[100][100];
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}}; //up, down, left, right check.

int n;  //row
int m;  //column

int main(int argc, char const *argv[])
{

    vector<vector<int>> maps = {{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}};
    maps.resize(maps.size());
    maps.shrink_to_fit();
    int start = maps[0][0]; //시작 정점
    
    cout << BFS(start)<<endl; //BFS 시작
    return 0;
}

//input
void In(vector <vector <int> > maps){
    n = maps.size();
    m = maps[0].size();
 
    for(int i=0; i<n; i++){
        for(int j=0; j<m ;j++) {
            int b;
            scanf("%1d", &b);
 
            if(b==1){
                maps[i][j] = true;
            }
        }
    }
}

//check [y, x] is in or not
bool isInside(int a, int b){
    return (a >= 0 && a < n) && (b >=0 && b < m);
}


int BFS(int start)
{
    int cur_y =0 , cur_x = 0;   //current X, Y

    queue<pair<int, int> > q;
    q.push(pair<int,int>(cur_y,cur_x));
    check[cur_y][cur_y] = 1;    //bfs가 지나가면서 몇번째만에 그 점에 접근했는지

    while(!q.empty()){

        cur_y = q.front().first;
        cur_x = q.front().second;
        q.pop();

        if((cur_y== n-1) && (cur_x == m-1)) break;  //도착지점

        for(int i = 0; i<4; i++){
            //up, down, left, right
            int next_y = cur_y+dir[i][0];
            int next_x = cur_x+dir[i][1];

            //next y, x가 배열 내부에 있고, check 2차원 배열에 기록된적 없고, map에 true로 되어있으면
            if(isInside(next_y,next_x) && check[next_y][next_x] == 0 && maps[next_y][next_x])
            {
                check[next_y][next_x] = check[cur_y][cur_x] +1; //이전 방문값 +1 = 다음 방문
                q.push(pair<int,int>(next_y,next_x));   //방문한곡 push push
            }
        }
    }

     //  bfs로 만든 check 배열 출력해보기
    for(int i=0;i<n; i++){
        for(int j=0; j<m ; j++){
            cout << check[i][j];
        }
        cout << endl;
    }
    

    return check[n-1][m-1];

}