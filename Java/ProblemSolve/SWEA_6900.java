import java.io.*;
import java.util.StringTokenizer;

public class SWEA_6900 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            int t = Integer.parseInt(br.readLine());
            for (int tc = 1; tc <= t; tc++) {
                int ans = 0;
                StringTokenizer st = new StringTokenizer(br.readLine());
                int n = Integer.parseInt(st.nextToken());
                int m = Integer.parseInt(st.nextToken());

                Pair[] arr = new Pair[n];
                String[] numbers = new String[m];

                for (int i = 0; i < n; i++) {
                    st = new StringTokenizer(br.readLine());
                    arr[i] = new Pair(st.nextToken(), Integer.parseInt(st.nextToken()));
                    System.out.println(arr[i].number + "     " + arr[i].price);
                }

                for (int i = 0; i < m; i++) {
                    numbers[i] = br.readLine();
                }

                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        String tmpStr = numbers[j];
                        boolean flag = false;
                        for (int k = 0; k < 8; k++) {
                            if (arr[i].number.charAt(k) == '*') {
                                continue;
                            } else if (arr[i].number.charAt(k) == tmpStr.charAt(k)) {
                                continue;
                            } else {
                                flag = true;
                            }
                        }

                        if (!flag) {
                            ans += arr[i].price;
                        }
                    }
                }

                System.out.println("#" + tc + " " + ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static class Pair {
        String number;
        int price;

        Pair(String number, int price) {
            this.number = number;
            this.price = price;
        }
    }
}