package chap07;

import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;

public class IOTest2 {
    public static void main(String[] args) throws IOException {
        // File 클래스 없이 가능
        // 그냥 파일 명만 적어도 자동으로 파일명의 파일이 생긴다
        FileOutputStream fos = new FileOutputStream("Sample.txt");
        String str = "Hello";
        // 하나씩 줄 수도 있지만, 배열 전체로 줄 수 도 있다.
        byte[] word = str.getBytes();   // 문자열을 Byte[] 로 변환
        fos.write(word);    // 바이트 배열을 출력 문자열로 넣을 수 있다.
        fos.close();

        FileWriter fw = new FileWriter("FileWriter.txt");
        str = "File Writer test\n";
        String str2 = "파일 출력 테스트";
        fw.write(str.toCharArray());
        fw.write(str2.toCharArray());
        fw.close();
    }
}
