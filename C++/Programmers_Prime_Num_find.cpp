#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/** * 프로그래머스 완전탐색, 소수찾기 (https://programmers.co.kr/learn/courses/30/lessons/42839)
 *  * 자리를 하나씩 바꿔가며 조합을 뽑아내는 방법은?    ==> permutation(순열) 을 이용한다
 *  @param pNum : 소수 테이블, vec : 숫자 조합 케이스 저장
 *  REVIEW
 *  * 순열의 경우를 구한다. nP1 ~ nPn 까지, 이를 vec배열에 넣고, 중복 제거, 그리고 소수테이블과 비교하여 카운팅
 */

using namespace std;

int pNum[2][10000000];
vector<int> vec;

// Generate PrimeNumber Table
void table()
{
    for (int i = 2; i <= 10000000; i++)
    {
        pNum[0][i] = i;
    }

    for (int i = 2; i <= 10000000; i++)
    {
        if (pNum[0][i] != 0)
        {
            for (int j = i * 2; j <= 10000000; j += i)
                pNum[0][j] = 0;
        }
    }
}

void swap(int *i, int *j)
{
    int tmp = *i;
    *i = *j;
    *j = tmp;
}

// nPk를 구하는 함수
void perm(int *arr, int depth, int n, int r)
{
    if (depth == r)
    {
        string str = "";
        for (int i = 0; i < r; i++)
        {
            str += (arr[i] + '0');
        }
        vec.push_back(stoi(str));
        return;
    }

    for (int i = depth; i < n; i++)
    {
        swap(&arr[i], &arr[depth]);
        perm(arr, depth + 1, n, r);
        swap(&arr[i], &arr[depth]);
    }
}

int solution(string numbers)
{
    int answer = 0;
    int size = numbers.size();
    int *arr = new int[size];

    table();

    for (int i = 0; i < size; i++)
    {
        arr[i] = numbers[i] - '0';
    }

    for (int i = 1; i <= size; i++)
    {
        perm(arr, 0, size, i);
    }

    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end()); // 정렬 후에 사용해야 제대로 적용 됨, unique() is in the algorithm header

    int vSize = vec.size();
    int idx = 0;

    for (int i = 0; i < vSize; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < vSize; i++)
    {
        idx = vec[i];
        if (idx > 1 && pNum[0][idx] != 0 && pNum[1][idx] == 0)
        {
            pNum[1][idx] = 1;
            answer++;
        }
    }
    return answer;
}

int main(int argc, char const *argv[])
{
    string str = "017";
    cout << solution(str) << endl;
    return 0;
}