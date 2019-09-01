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

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                arr[i] = new Tuple(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()),
                        Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
            }

            Arrays.sort(arr, new Comparator<Tuple>() {

                @Override
                public int compare(Tuple t1, Tuple t2) {
                    if (t1.gold > t2.gold) {
                        return -1;
                    } else if (t1.gold == t2.gold) {
                        if (t1.silver > t2.silver) {
                            return -1;
                        } else if (t1.silver == t2.silver) {
                            if (t1.bronze > t2.bronze) {
                                return -1;
                            }
                        }
                    }
                    return 1;
                }
            });



            for (int i = 0; i < n; i++) {
                if (arr[i].number != k) {
                    ans++;
                } else {
                    break;
                }
            }

            System.out.println(ans);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static class Tuple {
        int gold, silver, bronze, number;

        Tuple(int gold, int silver, int bronze, int number) {
            this.gold = gold;
            this.silver = silver;
            this.bronze = bronze;
            this.number = number;
        }
    }
}