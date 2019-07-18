
/**
 *  * practice file input stream & buffered stream
 */

import java.io.*;

class prac_fis {
    public static void main(String[] args) {

        try (FileInputStream fis = new FileInputStream("input.txt")) {

            // Byte[] buffer = new Byte[512];
            int len = 0;

            while ((len = fis.read()) != -1) {
                // System.out.write(i);
                System.out.print((char) len);
            }
            System.out.println();
            System.out.println("입력 종료");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}