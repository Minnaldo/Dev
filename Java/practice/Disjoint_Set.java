import java.util.Arrays;

/**
 * 상호 배타 집합 (Disjoint Set)
 */

public class Disjoint_Set {

    static int[] parents; // 부모노드의 정보를 저장

    public static void main(String[] args) {
        parents = new int[10];
        for (int i = 0; i < parents.length; i++) {
            makeSet(i);
        }
        printSet();
        union(0, 1);
        printSet();
        union(2, 3);
        printSet();
        union(0, 3);
        printSet();
        union(4, 5);
        printSet();
        union(6, 7);
        printSet();
        union(4, 7);
        printSet();
        union(3, 5);
        printSet();
        union(1, 8);
        printSet();
        union(0, 9);
        printSet();
    }

    // 현재 부모 배열(parents)을 출력하는 함수
    static void printSet() {
        System.out.println(Arrays.toString(parents));
    }

    static void printPresentative() {
        for (int i = 0; i < parents.length; i++) {
            System.out.print(findSet(i) + " ");
        }
    }

    static void makeSet(int x) {
        // 자기 자신을 부모로 지정
        parents[x] = x;
    }

    // x를 포함하는 집합의 대표자를 리턴
    // 재귀적으로 부모를 찾아 올라가 루트를 반환
    // 기저 영역 : 자신의 부모가 자기 자신인 경우
    // 재귀호출은 자신의 부모에 대해서 다시 findSet
    static int findSet(int x) {
        if (parents[x] == x) {
            return x;
        }
        // 효율성 향상을 위한 코드
        // 매번 findset을 하는것보다 효율적이다
        // path compression
        parents[x] = findSet(parents[x]);
        return parents[x];
    }

    // 아무나 부모가 되면 되는데, 우린 뒤엣놈이 부모가 됨
    static void union(int x, int y) {
        // y의 대표자로 x 의 대표자를 넣어준다
        // 최종 대표자를 찾는 코드
        int tmp = parents[findSet(y)];
        for (int i = 0; i < parents.length; i++) {
            if (parents[i] == tmp) {
                parents[i] = findSet(x);
            }
        }

        // 강사님 코드
        // 부모 노드만 누군지를 찾는 코드
        // parents[findSet(y)] = findSet(x);
    }
}