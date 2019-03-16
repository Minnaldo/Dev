#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int max(int &a, int &b)
{
    return a > b ? a : b;
}

int solution(vector<int> pobi, vector<int> crong)
{
    int answer = 0;
    int pobiVal = 0, crongVal = 0;

    if (pobi[1] - pobi[0] != 1 || crong[1] - crong[0] != 1)
    {
        answer = -1;
    }
    else
    {
        int pobiMax = 0, crongMax = 0;

        for (int i = 0; i < 2; i++)
        {
            int tmpPobi = pobi[i], tmpCrong = crong[i];

            int tmpPobiHap = 0, tmpPobiGop = 1, tmpCrongHap = 0, tmpCrongGop = 1;
            for (int k = 2; k >= 0; k--)
            {
                int div = pow(10, k);
                tmpPobiHap += tmpPobi / div;
                tmpCrongHap += tmpCrong / div;
                tmpPobi = tmpPobi % div;
                tmpCrong = tmpCrong % div;
            }
            tmpPobi = pobi[i], tmpCrong = crong[i];
            for (int k = 2; k >= 0; k--)
            {
                int div = pow(10, k);

                if (tmpPobi >= div)
                {
                    tmpPobiGop *= tmpPobi / div;
                }
                tmpPobi = tmpPobi % div;
                if (tmpCrong >= div)
                {
                    tmpCrongGop *= tmpCrong / div;
                }
                tmpCrong = tmpCrong % div;
            }
            pobiVal = max(tmpPobiGop, tmpPobiHap);
            crongVal = max(tmpCrongHap, tmpCrongGop);
        }

        if (pobiVal == crongVal)
        {
            answer = 0;
        }
        else
        {
            if (pobiVal > crongVal)
                answer = 1;
            else
                answer = 2;
        }
    }
    return answer;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {97, 98};
    vector<int> arr2 = {197, 198};

    cout << solution(arr, arr2) << endl;
    return 0;
}