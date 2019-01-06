#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/** * 프로그래머스 완전탐색, 소수찾기
 *  * 가능한 원소의 조합을 구해야 한다. --> 조합 이용
 *  * 가능한 수의 조합을 찾고 이것이 소수인지 판별한다.
 *  * 자리를 하나씩 바꿔가며 조합을 뽑아내는 방법은?
 *  * 에라토스테네스의 체를 이용하여 소수테이블 생성, 재귀함수를 이용한 PowerSet을 구하고 이 둘을 비교하여 카운팅
 *  ! 일부 케이스에서 segmeatation falut 발생 ==> 메모리 참조를 잘못하고 있나?
 *  TODO
 */

using namespace std;

int pNum[2][10000000];
vector<int> vec;
bool *flag;

// Generate PrimeNumber Table
void table()
{
    for (int i = 1; i <= 10000000; i++)
    {
        pNum[0][i] = i;
    }
    pNum[0][0] = 0;
    pNum[1][0] = 0;
    pNum[0][1] = 1;
    pNum[1][1] = 1;
    for (int i = 2; i <= 10000000; i++)
    {
        if (pNum[0][i] != 0)
        {
            for (int j = i * 2; j <= 10000000; j += i)
                pNum[0][j] = 0;
        }
    }
}

// ? dp를 이용하여 만들 수 있지 않을 까?
void func(int *arr, int n, int depth)
{
    if (n == depth)
    {
        string str = "";
        for (int i = 0; i < n; i++)
        {
            if (flag[i])
                str += to_string(arr[i]);
        }
        if (str != "")
            vec.push_back(stoi(str));
        return;
    }
    flag[depth] = 1;
    func(arr, n, depth + 1);
    flag[depth] = 0;
    func(arr, n, depth + 1);
}

int solution(string numbers)
{
    int answer = 0;
    int size = numbers.size();
    int *arr = new int[size];
    flag = new bool[size];
    table();

    for (int i = 0; i < size; i++)
    {
        arr[i] = (int)numbers[i] - 48;
    }

    for (int i = 0; i < size; i++)
    {
        int *temp = new int[size];
        for (int j = 0; j < size; j++)
        {
            temp[j] = arr[(i + j) % size];
        }
        func(temp, size, 0);
    }
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    int vSize = vec.size();
    int idx = 0;

    for (int i = 0; i < vSize; i++)
    {
        idx = vec[i];
        if (pNum[0][idx] != 0 && pNum[1][idx] == 0)
        {
            pNum[1][idx] = 1;
            answer++;
        }
    }
    return answer;
}

int main(int argc, char const *argv[])
{
    string str = "011";
    cout << solution(str) << endl;
    return 0;
}