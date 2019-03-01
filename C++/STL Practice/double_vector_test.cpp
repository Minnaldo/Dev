#include <iostream>
#include <vector>

/**
 *  NOTE  2차원 벡터에서 행/렬 이터레이터 사용법
 */

using namespace std;

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix(3, vector<int>(3));

    vector<vector<int>>::iterator citr = matrix.begin();
    vector<int>::iterator ritr = citr->begin();
    int a = 1;

    for (citr = matrix.begin(); citr != matrix.end(); citr++)
    {
        for (ritr = citr->begin(); ritr != citr->end(); ritr++)
        {
            *ritr = a;
            a++;
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl
         << "matrix Size : " << matrix.size() << endl;

    return 0;
}
