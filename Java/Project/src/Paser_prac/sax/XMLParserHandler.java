package Paser_prac.sax;

import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

public class XMLParserHandler extends DefaultHandler {

    private String elementName;
    private StringBuilder sb;

    @Override
    public void startDocument() throws SAXException {
        super.startDocument();
    }

    @Override
    public void endDocument() throws SAXException {
        super.endDocument();
    }

    // 엘리먼트의 시작을 인색했을 때 발생하는 이벤트 처리
    @Override
    public void startElement(String uri, String localName, String qName, Attributes attributes) throws SAXException {
//        super.startElement(uri, localName, qName, attributes);
        // 문서 시작시 데이터를 저장할 객체를 선언
        sb = new StringBuilder();
//        System.out.println("Start element, Name : " + qName);

    }

    // 엘리먼트의 끝을 인식했을 때 발생하는 이벤트 처리
    @Override
    public void endElement(String uri, String localName, String qName) throws SAXException {
//        super.endElement(uri, localName, qName);
        System.out.println("End element Name : " + qName);
    }

    // 각 element의 값 ( 인식된 문자의 각 세그먼트에 대해서 호출)
    @Override
    public void characters(char[] ch, int start, int length) throws SAXException {
        super.characters(ch, start, length);
        // StringBuilder에 데이터를 저장해 나간다
        sb.append(new String(ch, start, length));

    }


}
