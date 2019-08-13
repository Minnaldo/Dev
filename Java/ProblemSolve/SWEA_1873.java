import java.io.FileInputStream;
import java.util.Scanner;

public class SWEA_1873 {
    public static void main(String[] args) {
        try (FileInputStream fis = new FileInputStream("input.txt")) {
            Scanner sc = new Scanner(fis);
            int t = sc.nextInt();

            for (int tc = 1; tc <= t; tc++) {
                int ans = 0;

                int h = sc.nextInt(), w = sc.nextInt();
                int[][] map = new int[w][h];

                // 맵 입력
                for (int i = 0; i < w; i++) {
                    for (int j = 0; j < h; j++) {
                        char tmp = sc.next().charAt(0);
                        if(tmp == '.'){
                            map[i][j] = 0;  // 평지
                        }else if(tmp == '#'){
                            map[i][j] = -1; // 강철 벽
                        }else if( tmp == '*' ){

                        }else if(tmp == '-'){

                        }else if(tmp == '^'){

                        }else if(tmp == '>'){

                        }else if(tmp == '<'){

                        }else if(tmp == 'v'){

                        }
                    }
                }

                int n = sc.nextInt(); // 명령어 개수
                String operation = sc.next();
                for (int i = 0; i < n; i++) {
                    // 명령 실행
                    switch(operation.charAt(i)){

                    }
                }


                System.out.println("#" + tc + " ");
                for()
            }

            sc.close();
            fis.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static class Tank {
        int y, x;
        int dir; // 1 : up, 2 : right, 3 : down, 4 : left

        Tank(int y, int x, int dir) {
            this.y = y;
            this.x = x;
            this.dir = dir;
        }
    }
}