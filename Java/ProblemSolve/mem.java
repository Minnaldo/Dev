import java.util.Scanner;

class mem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        for (int tc = 1; tc <= t; tc++) {
            String str = sc.next();
            char[] arr = new char[str.length()];
            int ans = 0;
            int size = arr.length;

            for (int i = 0; i < size; i++) {
                char tmpChar = str.charAt(i);
                if (tmpChar != arr[i]) {
                    tmpChar = arr[i] == '0' ? '1' : '0';
                    for (int j = i; j < size; j++) {
                        arr[i] = tmpChar;
                    }
                    ans++;
                }
                // String tmpString = String.valueOf(tmpChar);
                if (str.equals(String.valueOf(arr))) {
                    break;
                }
            }
            System.out.println("#" + tc + " " + ans);
        }
    }
}