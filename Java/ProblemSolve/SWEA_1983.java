import java.io.FileInputStream;
import java.util.*;

public class SWEA_1983 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        String[] gradeChart = { "A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0" };

        for (int tc = 1; tc <= t; tc++) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            String ans = "";

            double kscore = 0.0;
            double[] score = new double[n];
            String[] grade = new String[n];

            // get score
            for (int i = 0; i < n; i++) {
                double midterm = sc.nextInt() * 0.35;
                double fin = sc.nextInt() * 0.45;
                double subj = sc.nextInt() * 0.2;
                score[i] = midterm + fin + subj;

                if (i + 1 == k) {
                    kscore = score[i];
                }
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

                if (score[i] == kscore) {
                    ans = gradeChart[spidx];
                    break;
                }
                grade[i] = gradeChart[spidx];
                idx++;
            }

            System.out.println("#" + tc + " " + ans);
        }

        sc.close();
    }
}