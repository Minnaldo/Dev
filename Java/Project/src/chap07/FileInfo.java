package chap07;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.IOException;

// Intellij는 Project폴더에서 찾는다.
public class FileInfo {
    public static void main(String[] args) throws IOException {
        if (args.length != 1) {
            System.out.println("using : java FileInfo input filename plz");
            System.exit(0);
        }

        // File은 io가 아니다
        File f = new File("hello.txt");
//        if (f.exists()) {
//            System.out.println("파일 이름 : " + f.getName());
//            System.out.println("파일 경로 : " + f.getPath());
//            System.out.println("파일 전체 경로 : " + f.getAbsolutePath());
//            System.out.println("쓰기 여부 : " + f.canWrite());
//            System.out.println("읽기 여부 : " + f.canRead());
//            System.out.println("파일 길이 : " + f.length());
//        } else {
//            System.out.println(args[0] + " 파일은 존재하지 않습니다.");
//        }

        FileInputStream fis = new FileInputStream("hello.txt");
        int a = 0;
        while ((a = fis.read()) != -1) {
            System.out.println(a);
        }

        // char는 2바이트 처리 문자이기 때문에
        FileReader fr = new FileReader(f);
        while ((a = fr.read()) != -1) {
            System.out.print((char) a);
        }

        fis.close();
        fr.close();

    }
}
