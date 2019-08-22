package Paser_prac.sax;

import org.xml.sax.SAXException;

import javax.xml.parsers.*;
import java.io.File;
import java.io.IOException;

public class XmlSaxParserMain {
    public static void main(String[] args) {
        // 파일의 경로를 지정
        try {
            SAXParserFactory factory = SAXParserFactory.newInstance();
            SAXParser parser = factory.newSAXParser();

            XMLParserHandler handler = new XMLParserHandler();
            parser.parse(new File("test.xml"), handler);  // start parsing

        } catch (SAXException e) {
            e.printStackTrace();
        } catch (ParserConfigurationException | IOException e) {
            e.printStackTrace();
        }
    }
}
