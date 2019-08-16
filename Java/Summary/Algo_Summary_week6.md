# Algorithm Summary Week 6

## 재귀함수 (Recursion)
재귀함수의 기본 패턴
```java
public class recursion{

    public static void main(String[ ] args){
        int[] arr= {3,5,1,2,4,7,9,8,0,6};
        recur(10,0,arr);
    }

    static void recur(int n, int idx, int[] arr){
        // 기저파트 (재귀 함수가 종료되는 조건)
        if(dix == n){
            return ;
        }

        // do Something( 실행하고 싶은 코드 )
        // System.out.println(idx);
        System.out.println(arr[idx]);

        // 재귀 호출
        recur(n, idx+1, arr);
    }
}
```

### 부분집합 (Powerset)
```java

public static void main(String[] args) {
    int[] arr = {3,5,1};
    powerSet(arr, 0, new boolean[arr.length]);
}

static void powerSet(int[] arr, int idx, boolean[] visit){
    if(idx == arr.length){
        // 지금까지 체크한 원소 출력
        for(int i = 0; i<arr.length; i++){
            if(visit[i])
            System.out.print(arr[i]+", ");
        }
        return;
    }

    // idx가 지나면서 idx번째 원소를 선택 할지 안할지를 체크하는 배열 visit을 이용해
    // 넣었는지 안넣었는지를 체크한다.
    visit[idx] = true;
    powerSet(arr, idx+1, visit);
    visit[idx] = false;
    powerSet(arr, idx+1, visit);
}
```

### 조합 (Combination)
```java
// sel은 현재까지 뽑은 원소들을 저장할 변수
    // n은 계속 늘어나면서, arr의 n인덱스에 해당하는 원소를 선택해, sel[idx]에 넣을지 선택을 한다
    static void combination(int[] arr, int n, int r, int[] sel, int idx) {
        if (idx == r) {
            // 다 고른 것
            System.out.println(Arrays.toString(sel));
            return;
        }
        if (n == arr.length) {
            // 끝난 것
            return;
        }

        // 현재 단계(n)에 해당하는 원소를 선택한 경우
        // n번째 원소든 선택을 하든 안하든 다음번째 원소를 선택해야하므로 항상 늘려간다.
        sel[idx] = arr[n];
        // n번째에 대해서 sel에 담고 지나가기
        combination(arr, n + 1, r, sel, idx + 1);
        // n번째에 대해서 sel에 안담고 지나가기
        // idx를 늘리지 않아도 덮어씌워지기 때문에 상관 없다
        combination(arr, n + 1, r, sel, idx);
    }
```