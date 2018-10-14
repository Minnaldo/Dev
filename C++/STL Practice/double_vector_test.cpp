#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix(3, vector<int>(3));

    vector<vector<int>>::iterator citr = matrix.begin();
    vector<int>::iterator ritr = citr->begin();
    int a = 0;
    // for (size_t i = 0; i < count; i++)
    // {
    //     matrix.at()
    // }

    // for(vector <vector <int> >::iterator i = matrix.begin(); i != matrix.end(); i++)
    // {
    //     for(vector <int>::iterator j = i->begin(); j != i->end(); j++)
    //     {
    //         *j = a;
    //         a++;
    //     }
    // }

    //FIXME: munmap_chunk(): invalid pointer      Aborted (core dumped)              에러 발생
    for (citr; citr != matrix.end(); citr++)
    {
        for (ritr; ritr != citr->end(); ritr++)
        {
            *ritr = a;
            a++;
        }
    }

    // for (int q = 0; q < matrix.size(); q++)
    // {
    //     for (int w = 0; w < matrix.size(); w++)
    //     {
    //         cout << matrix.at(q).at(w) << "  ";
    //     }
    //     cout << endl;
    // }

    // cout<< *(i->begin())<<endl;

    cout << endl
         << "matrix Size : " << matrix.size() << endl;

    return 0;
}
