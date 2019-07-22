import java.io.*;

public class Sum_test {
    public static void main(String[] args) {
        try {
            File file = new File("Sum_test.txt");
            FileWriter writer = new FileWriter(file);

            // 파일 출력, 1~10000 까지의 숫자를 파일로 출력함
            for (int i = 1; i <= 100000; i++) {
                writer.write(Integer.toString(i) + " ");
            }
            writer.flush();

            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}