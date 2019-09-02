
import java.io.*;
import java.util.*;

public class Baek_11650 {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")))) {

            int n = Integer.parseInt(br.readLine());
            Pair[] arr = new Pair[n];
            StringTokenizer st = null;
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                arr[i] = new Pair(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
            }

            Arrays.sort(arr, new Comparator<Pair>() {

                @Override
                public int compare(Pair p1, Pair p2) {
                    if (p1.first < p2.first) {
                        return -1;
                    } else if (p1.first == p2.first) {
                        if (p1.second < p2.second) {
                            return -1;
                        }
                    }
                    return 1;
                }
            });

            for (int i = 0; i < n; i++) {
                System.out.println(arr[i].first + " " + arr[i].second);
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static class Pair {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}