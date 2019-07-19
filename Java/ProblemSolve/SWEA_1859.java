import java.util.*;

public class SWEA_1859 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            ArrayList<Integer> ans = new ArrayList<>(); // 답을 저장할 배열
            ArrayList<Integer> tmpVal = new ArrayList<>();
            // data input
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }

            int pivot = arr[n - 1];
            for (int i = n - 2; i >= 0; i--) {
                if (pivot <= arr[i] || i == 0) {
                    // 나머지 빼내서 계산
                    int size = tmpVal.size();
                    if (size > 0 && i != 0) {
                        int tmpSum = 0;
                        for (int k = 0; k < size; k++) {
                            tmpSum += (pivot - tmpVal.get(k));
                        }
                        ans.add(tmpSum);
                        tmpVal.clear();
                    } else if (size > 0 && i == 0) {
                        int tmpSum = 0;
                        for (int k = 0; k < size; k++) {
                            tmpSum += (pivot - tmpVal.get(k));
                        }
                        ans.add(tmpSum);
                        tmpVal.clear();
                    }
                    pivot = arr[i];
                } else {
                    // 임시 배열에 저장
                    tmpVal.add(arr[i]);
                }
            }

            int ret = 0;
            for (int val : ans) {
                ret += val;
            }

            System.out.println("#" + tc + " " + ret);

            sc.close();
        }
    }
}