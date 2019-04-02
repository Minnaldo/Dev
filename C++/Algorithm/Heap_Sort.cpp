#include <algorithm>
#include <iostream>

/** HeapSort
 *  * sort_heap & make_heap in algorithm header
 *  * std::sort 와 비교해서, 역방향 정렬에 유용하다
 */

using namespace std;

int main(int argc, char const *argv[])
{
    int arr[6] = {3, 1, 4, 1, 5, 9};

    make_heap(arr, arr + 6); // 애초에 힙으로 만들어져 있지 않다면 sort_heap은 사용 불가, --> heap으로 만들어준다
    sort_heap(arr, arr + 6); // make_heap(begin(), end()) 로 만들어진 heap트리를 정렬하는 함수, heap의 형태가 아닌 자료구조를 삽입하면 잘못된 결과가 나온다

    for (int i : arr) // arr의 원소를 하나씩 빼서 i에 저장 후 출력
        cout << i << endl;
    return 0;
}