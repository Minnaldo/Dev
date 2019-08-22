package chap11.sax;


import java.net.URL;
import java.util.ArrayList;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;

import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

public class MySAXParser {
    // 데이터를 저장할 변수
    ArrayList<Check> list;

    public ArrayList<Check> getContent(String url) {
        SAXParserFactory factory = SAXParserFactory.newInstance();
        try {
            // SAXParserFactory에서 SAXParser를 가져온다
            // SAXParser 할당
            SAXParser parser = factory.newSAXParser();
            // 핵심

            MyHandler handler = new MyHandler();
            // 주소로 접속해 inputstream을 가져온다 ==> 서버에서 데이터를 가져와 파싱을 한다.
            // 예제에서, result.xml을 가져와 파싱을 하는 것
            // xml파일과 핸들러를 할당
            // 핸들러는 DefaultHandler 클래스를 상속받는다
            parser.parse(new URL(url).openConnection().getInputStream(), handler);
            // xml 파싱 후 처리된 데이터를 리턴해준다.
            return list;
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    // 추상 클래스인 DefaultHandler를 상속받아 메소드를 오버라이딩 하였음
    public class MyHandler extends DefaultHandler {
        private StringBuilder sb;
        Check ch;

        @Override
        public void characters(char[] ch, int start, int length)
                throws SAXException {
            super.characters(ch, start, length);
            sb.append(ch, start, length);
        }

        @Override
        public void endElement(String uri, String localName, String name)
                throws SAXException {
            super.endElement(uri, localName, name);
            if (this.ch != null) {
                if (name.equalsIgnoreCase("Clean")) {
                    ch.setClean(sb.toString().trim());
                } else if (name.equalsIgnoreCase("Ready")) {
                    ch.setReady(sb.toString().trim());
                } else if (name.equalsIgnoreCase("Response")) {
                    ch.setResponse(sb.toString().trim());
                } else if (name.equalsIgnoreCase("Request")) {
                    sb.trimToSize();
                    if (sb.length() > 0)
                        ch.setRequest(sb.toString().trim());
                } else if (name.equalsIgnoreCase("Check")) {
                    list.add(ch);
                }
                // 하나의 end태그가 나올때마다 Stringbuilder의 값을 0으로 초기화
                // 하지 않으면 이전에 값들이 들어가 있게 된다.
                sb.setLength(0);
            }
        }

        @Override
        public void startDocument() throws SAXException {
            super.startDocument();
            // 문서 시작시 데이터를 저장할 객체를 선언해준다
            list = new ArrayList<Check>();
            sb = new StringBuilder();
        }

		// stat태그에는 속성값이 들어 갈 수 있다.
        // start태그가 끝나기전에 속성값을 읽어야 함
        @Override
        public void startElement(String uri, String localName, String name,
                                 Attributes attributes) throws SAXException {
            super.startElement(uri, localName, name, attributes);
            if (name.equalsIgnoreCase("Check")) {
                ch = new Check();
                // 속성을 인덱스로 받아온다
                ch.setCode(attributes.getValue(0));
                ch.setDate(attributes.getValue(1));
            }
        }
    }
}