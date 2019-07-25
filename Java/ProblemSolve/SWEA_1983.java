import java.io.FileInputStream;
import java.util.*;

public class SWEA_1983 {
    public static void main(String[] args) {

        try (FileInputStream fis = new FileInputStream("input.txt")) {
            Scanner sc = new Scanner(fis);
            int t = sc.nextInt();
            String[] grade = { "A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0" };

            for (int tc = 1; tc <= t; tc++) {
                int n = sc.nextInt();
                int k = sc.nextInt();
                double[] score = new double[n];
                String[] finScore = new String[n];

                // get score
                for (int i = 0; i < n; i++) {
                    double midterm = sc.nextInt() + 0.35;
                    double fin = sc.nextInt() * 0.45;
                    double subj = sc.nextInt() * 0.2;
                    score[i] = midterm + fin + subj;
                }

                Arrays.sort(score);
                int spidx = 9;
                int mul = n / 10;
                int idx = 0;
                for (int i = 0; i < score.length; i++) {
                    if (idx == mul) {
                        spidx--;
                        idx = 0;
                    }
                    finScore[i] = grade[spidx];
                    idx++;
                }
                String ans = finScore[score.length - k - 1];

                System.out.println(Arrays.toString(finScore));

                System.out.println("#" + tc + " " + ans);
            }

            sc.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}