public class bitOper {
    public static void main(String[] args) {
        // 사과 오렌지 배를 뽑는 경우의 수
        // 총 8개의 방법이 있음
        // 8 : (1<<3)

        String[] fruits = { "사과", "오렌지", "배" };
        String[] tmp = new String[1 << fruits.length];

        // ! 2의 배수는 각 자리가 1인지 아닌지 판단이 가능함
        // ! 이는 비트연산시 해당자리에 해당하는 값을 포함할지 말지 고르는데 매우 편하고 좋음

        // ! 비트연산자는 비트단위로 연산을 하게 됨. 즉, int형 정수 (4byte : 32 bit)의 32bit 모두에 대하여 각각 자리에 맞게
        // bit연산을 수행함
        // ! 그러므로 따로 변한해주지 않아도 bit연산을 하므로 신경쓸게 줄어든다

        for (int i = 0; i < 8; i++) {
            // 0~ 7로 변하는 i를 검사해서
            // 맨 오른쪽 비트가 1이면 사과 포함
            // 오른쪽 두번째 비트가 1 이면 오렌지 포함
            // 맨 오른쪽 세번째 비트가 2이면 배 포함

            if ((1 & i) != 0) {
                // 사과 먹음
                System.out.print("사과 ");
            }

            if ((2 & i) != 0) {
                // 오렌지 먹음
                System.out.print("오렌지 ");
            }

            if ((4 & i) != 0) {
                // 배 먹음
                System.out.print("배 ");
            }

            System.out.println();
        }

        // System.out.println(3l & 2l); // long 형 bit operator long형도 정수형이므로 비트연산이 가능하다

        for (int i = 0; i < (1 << 3); i++) {
            for (int j = 0; j < 3; j++) {
                if (((1 << j) & i) != 0) {
                    System.out.print(fruits[j] + " ");
                }
            }
            System.out.println();
        }
    }
}