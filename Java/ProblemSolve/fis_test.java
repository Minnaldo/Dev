import java.io.*;

public class fis_test {
    public static void main(String[] args) {

        try (FileInputStream fis = new FileInputStream("input.txt")) {

            int aa = 0;
            int idx = 0;
            while ((aa = fis.read()) != -1 && idx < 20) {
                System.out.print(aa + " ");
                idx++;
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}