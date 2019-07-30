import java.util.Scanner;
import java.io.*;

public class SWEA_1216 {
    public static void main(String[] args) {
        try (FileInputStream fis = new FileInputStream("input.txt")) {
            Scanner sc = new Scanner(fis);

            for (int tc = 1; tc <= 10; tc++) {
                int ans = 0;
                int tmpTc = sc.nextInt();
                String[] str = new String[100];

                for (int i = 0; i < 100; i++) {
                    str[i] = sc.next();
                }

                System.out.println("start!");
                for (int a = 0; a < 100; a++) {
                    int len = 0;
                    int start = 0;
                    int end = 99;

                    for (int i = 0; i < 100; i++) {
                        start = i;
                        end = 99;
                        len = 0;
                        while (start <= end) {
                            if (str[a].charAt(start) == str[a].charAt(end)) {
                                start++;
                                end--;
                                len += 2;
                            } else {
                                if (end - start > 1) {
                                    break;
                                } else {
                                    ans = ans > len ? ans : len;
                                }
                            }
                        }
                    }

                }

                System.out.println("#" + tc + " " + ans);
            }

            sc.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
}