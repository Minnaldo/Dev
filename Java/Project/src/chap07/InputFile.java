package chap07;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

class InputFile {
    FileReader fis;

    public InputFile(String filename) throws FileNotFoundException {
        fis = new FileReader("data.txt");
    }

    void readLine() throws IOException {
        String s;
        BufferedReader buf = new BufferedReader(fis);
        while ((s = buf.readLine()) != null)
            System.out.println(s);

    }

    public static void main(String[] a) {
        try {
            InputFile inputFile;
            inputFile = new InputFile("data.txt");
            inputFile.readLine();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            System.out.println("Program End...");
        }
    }
}





