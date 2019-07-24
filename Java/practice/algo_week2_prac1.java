public class algo_week2_prac1 {
    public static void main(String[] args) {
        int[][] map = new int[5][5];
        int[][] dir = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

        // init
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                map[i][j] = (int)(Math.random() * 100); // 1~100의 랜덤값으로 초기화
            }
        }
        int[][] answer = new int[5][5];

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 4; k++) {
                    int ny = i + dir[k][0];
                    int nx = j + dir[k][1];
                    if (ny >= 0 && nx >= 0 && ny < 5 && nx < 5)
                        answer[i][j] += Math.abs(map[i][j] - map[ny][nx]);
                }
            }
        }

        // print the answer
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                System.out.print(answer[i][j] + " ");
            }
            System.out.println();
        }

    }
}