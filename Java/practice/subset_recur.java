import java.util.*;

public class Powerset_recur {

    static void powerset(boolean[] sel, int idx) {

        // * 재귀함수는 각 함수 루틴에서의 변수가 저장되는것을 항상 생각해야 한다!
        // idx 는 기저 변수로써, 재귀함수를 종료하게 만들 때 쓰임
        if (idx == sel.length) {
            System.out.println(Arrays.toString(sel));
            return;
        }

        sel[idx] = true;
        powerset(sel, idx + 1);
        sel[idx] = false;
        powerset(sel, idx + 1);
    }

    public static void main(String[] args) {
        boolean[] sel = new boolean[3];
        powerset(sel, 0);
    }
}