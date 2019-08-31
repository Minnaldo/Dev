package ws_java_0822;

import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

import javax.xml.parsers.*;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 * WeatherDAO ver. SAXParser
 */

public class WeatherDAO2 {

    static List<Weather> list;


    public static WeatherDAO2 instance = new WeatherDAO2();

    public static WeatherDAO2 getInstance() {
        return instance;
    }

    private WeatherDAO2() {
    }

    public List<Weather> getWeatherList() {
        SAXParserFactory sFactory = SAXParserFactory.newInstance();
        try {
            SAXParser parser = sFactory.newSAXParser();
            MyHandler handler = new MyHandler();
            parser.parse(new File("weather.xml"), handler);

            return list;
        } catch (ParserConfigurationException | SAXException | IOException e) {
            e.printStackTrace();
        }
        return null;
    }

    public class MyHandler extends DefaultHandler {

        private StringBuilder sb;
        Weather w;

        @Override
        public void startDocument() throws SAXException {
            super.startDocument();
            list = new ArrayList<Weather>();
            sb = new StringBuilder();
        }

        @Override
        public void endDocument() throws SAXException {
            super.endDocument();
        }

        @Override
        public void startElement(String uri, String localName, String qName, Attributes attributes) throws SAXException {
            super.startElement(uri, localName, qName, attributes);
            // 시작 태그를 찾으면 데이터 저장 객체를 초기화 해주고
            // 태그의 attribute를 저장하려면 저장해준다
            // 태그의 속성값을 가져오려면, attributes.getValue(input the index value)를 하면 된다
            if (qName.equalsIgnoreCase("data")) {
                w = new Weather();
                // 속성중 seq를 이름으로 갖는 속성의 값을 가져온다
                w.setSeq(Integer.parseInt(attributes.getValue(0)));
            }
        }

        @Override
        public void endElement(String uri, String localName, String qName) throws SAXException {
            super.endElement(uri, localName, qName);
            // 예제에서는 객체에 저장을 해야 하므로, 객체가 생성 되엇는지를 확인
            if (this.w != null) {
                // 데이터 삽입하는 코드가 들어가면 된다
                if (qName.equalsIgnoreCase("hour")) {
                    w.setHour(Integer.parseInt(sb.toString().trim()));
                } else if (qName.equalsIgnoreCase("reh")) {
                    w.setReh(Integer.parseInt(sb.toString().trim()));
                } else if (qName.equalsIgnoreCase("temp")) {
                    w.setTemp(Double.parseDouble(sb.toString().trim()));
                } else if (qName.equalsIgnoreCase("wfKor")) {
                    w.setWfKor(sb.toString().trim());
                } else if (qName.equalsIgnoreCase("data")) {
                    // 실데이터 노드들을 담고 있는  태그의 닫는태그가 호출되면
                    // 지금까지 저장한 데이터를 저장하고 종료한다
                    list.add(w);
                }
                // stringBuilder는 매번 초기화를 해준다.
                // 위의 코드에서 weather객체에 데이터를 삽입했으므로 초기화 해줘도 상관 없다.
                sb.setLength(0);
            }
        }

        @Override
        public void characters(char[] ch, int start, int length) throws SAXException {
            super.characters(ch, start, length);
            // TEXT노드의 값을 가져온다
            // 즉, <hour>24</hour>라는 태그가 있으면
            // 태그 사이의 실제 값인 24를 가져오게 된다
            // 시작점(start) 부터 길이(length)만큼 가져와서 StringBuilder에 저장
            // ch가 실제 데이터를 갖고있는 객체
            sb.append(ch, start, length);
        }
    }
}
