#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

/**
 * * [x,y]로 저장된 이진트리 형태
 * * 전위순회(Preorder) ==> Parent - Left - Right 순서
 * * 후위순회(Postorder) ==> Left - Right - Parent 순서
 */

struct{
    int value;

};

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    vector<vector<int>> answer;

    //root 노드 구하기
    int rootVal = nodeinfo[0][1];
    int rootLv;
    int size = nodeinfo.size();
    for (int i = 1; i < size; i++)
    {
        if (rootVal < nodeinfo[i][1])
        {
            rootVal = nodeinfo[i][1];
            rootLv = i;
        }
    }
    answer.push_back(rootVal);
    for (int i = rootLv-1; i < 0; i--)
    {
        nodeinfo[i][1]
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> nodeinfo = {{5, 3}, {11, 5}, {13, 3}, {3, 5}, {6, 1}, {1, 3}, {8, 6}, {7, 2}, {2, 2}};
    vector<vector<int>> result;

    result = solution(nodeinfo);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
        }
        cout << endl;
    }
}