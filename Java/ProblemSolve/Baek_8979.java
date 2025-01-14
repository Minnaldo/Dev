import java.io.*;
import java.util.*;

// TODO
// 공동 처리를 어떻게 할까?

public class Baek_8979 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int ans = 0;
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            Tuple[] arr = new Tuple[n];

            int score = 0;
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                arr[i] = new Tuple(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()),
                        Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));

                arr[i].score = arr[i].gold * 100 + arr[i].silver * 10 + arr[i].bronze;

                if (k - 1 == i) {
                    score = arr[i].score;
                }
            }

            for (int i = 0; i < n; i++) {
                if(arr[i].score > score){
                    ans++;
                }
            }

            System.out.println(ans+1);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static class Tuple {
        int gold, silver, bronze, number, score;

        Tuple(int gold, int silver, int bronze, int number) {
            this.gold = gold;
            this.silver = silver;
            this.bronze = bronze;
            this.number = number;
        }
    }
}