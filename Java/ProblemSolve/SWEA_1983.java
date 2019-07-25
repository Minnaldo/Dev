import java.io.FileInputStream;
import java.util.*;

public class SWEA_1983 {

    public class Pair implements Comparable<Pair> {
        double score;
        int number;

        Pair(double score, int number) {
            this.score = score;
            this.number = number;
        }

        /**
         * @return the score
         */
        public double getScore() {
            return score;
        }

        @Override
        public int compareTo(Pair o) {
            return score.compareTo(o.score);
        }
    }

    public static void main(String[] args) {

        try (FileInputStream fis = new FileInputStream("input.txt")) {
            Scanner sc = new Scanner(fis);
            int t = sc.nextInt();
            String[] sp = { "A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0" };
            for (int tc = 1; tc <= t; tc++) {
                int n = sc.nextInt();
                int k = sc.nextInt();
                double[] score = new double[n];
                String[] finScore = new String[n];
                Pair[] score2 = new Pair[n];

                // get score
                for (int i = 0; i < n; i++) {
                    double midterm = sc.nextInt() + 0.35;
                    double fin = sc.nextInt() * 0.45;
                    double subj = sc.nextInt() * 0.2;
                    score[i] = midterm + fin + subj;
                    score2[i] = new Pair(midterm + fin + subj, i);
                }

                Collections.sort(score2, new Comparator<Pair>() {
                    @Override
                    public int compare(Pair p1, Pair p2) {
                        if (p1.score > p2.score) {
                            return 1;
                        } else if (p1.getScore() < p2.getScore()) {
                            return -1;
                        } else {
                            return 0;
                        }
                    }
                });

                // Arrays.sort(score);
                Arrays.sort(score2);
                int spidx = 9;
                int mul = n / 10;
                int idx = 0;
                for (int i = 0; i < score.length; i++) {
                    if (idx == mul) {
                        spidx--;
                        idx = 0;
                    }
                    finScore[i] = sp[spidx];
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