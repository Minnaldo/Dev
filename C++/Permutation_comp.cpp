#include <iostream>
#include <vector>

/** 순열_Permutation
 *  * nPr
 *  * 1 ~ r 자리수의 순열 구하기
 *  REVIEW
 */

using namespace std;

int cnt; // 순열 조합의 가짓수를 저장할 변수

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

// 순열을 출력
void savePermutation(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 1 ~ r 자리수 까지의 순열의 조합을 만들어낸다.,
void permutation(int *arr, int depth, int n, int r) // n : 후보군 배열 크기, depth : 현 시점에서 순열의 길이
{
    if (depth == r)
    {
        savePermutation(arr, r);
        cnt++;
        return;
    }

    for (int i = depth; i < n; i++) // 한자리수의 순열을 만들때에 배열의 크기만큼 반복해줘야 모든 원소들을 돌아다닐 수 있다.
    {
        swap(arr[depth], arr[i]);
        permutation(arr, depth + 1, n, r);
        swap(arr[depth], arr[i]); // 배열을 원래대로 만들어준다
    }
}

int main(int argc, char const *argv[])
{
    int permuCand[3] = {1, 2, 3}; // 12
    int arrSize = sizeof(permuCand) / sizeof(permuCand[0]);

    // 한자리수 ~ 세자리수 순열을 만드는 함수
    for (int i = 1; i <= 3; i++)
    {
        permutation(permuCand, 0, arrSize, i);
    }
    cout << "순열 가짓 수 :: " << cnt << endl;

    return 0;
}