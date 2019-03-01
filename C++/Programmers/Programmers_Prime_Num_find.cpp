#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/** * 프로그래머스 완전탐색, 소수찾기 (https://programmers.co.kr/learn/courses/30/lessons/42839)
 *  * 자리를 하나씩 바꿔가며 조합을 뽑아내는 방법은?    ==> permutation(순열) 을 이용한다
 *  @param pNum : 소수 테이블, vec : 숫자 조합 케이스 저장
 *  REVIEW
 *  * 순열의 경우를 구한다. nP1 ~ nPn 까지, 이를 vec배열에 넣고, 중복 제거, 그리고 소수테이블과 비교하여 카운팅
 *  NOTE 1 정수 N이 소수인지 판별할 때, N을 2부터 sqrt(N)까지 나눠서 나누어 떨어지는지 확인한다.
 *  NOTE 2 소수 테이블을 만들때 가장 좋은 방법은 에라토스테네스의 체를 이용하는 것
 */

using namespace std;

int pNum[10000000];
vector<int> vec;

// Generate PrimeNumber Table
void table(int max)
{
    for (int i = 2; i <= max; i++)
    {
        pNum[i] = i;
    }

    for (int i = 2; i <= max; i++)
    {
        if (pNum[i] != 0)
        {
            for (int j = i * 2; j <= max; j += i) //i만큼 증가하며 0으로 치환, 각 단계마다 i만큼 증가한다 -> i의 배수
                pNum[j] = 0;
        }
    }
}

void swap(int &i, int &j)
{
    int tmp = i;
    i = j;
    j = tmp;
}

// nPk를 구하는 함수
void perm(int *arr, int depth, int n, int r)
{
    if (depth == r)
    {
        string str = "";

        // ! 범위를 r까지 해주어야 제대로 나옴
        // 순열 구하기 참조 : http://swlock.blogspot.com/2016/03/permutation-algorithm.html
        for (int i = 0; i < r; i++)
        {
            str += (arr[i] + '0');
        }
        vec.push_back(stoi(str));
        return;
    }

    for (int i = depth; i < n; i++)
    {
        swap(arr[i], arr[depth]);
        perm(arr, depth + 1, n, r);
        swap(arr[i], arr[depth]);
    }
}

int solution(string numbers)
{
    int answer = 0;
    int size = numbers.size();
    int *arr = new int[size];

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

    cout << "vec : ";
    for (int i = 0; i < vSize; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    table(vec[vSize - 1]);

    for (int i = 0; i < vSize; i++)
    {
        idx = vec[i];
        if (idx > 1 && pNum[idx] != 0)
        {
            answer++;
        }
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    string str = "17";
    int answer = solution(str);

    cout << "Answer : " << answer << endl;
    return 0;
}