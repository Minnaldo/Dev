package ws_java_0822;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 * DAO : Data Access Object
 */

public class WeatherDAO {
    static private List<Weather> list;

    static private WeatherDAO instace = new WeatherDAO();

    static public WeatherDAO getInstance() {
        return instace;
    }

    private WeatherDAO() {

    }

    private void connectXML() {

    }

    public List<Weather> getWeatherList() {
        list = new ArrayList<>();
        DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();

        try {
            DocumentBuilder builder = factory.newDocumentBuilder();
            Document dom = builder.parse(new File("weather.xml"));// xml파일 경로를 인자로 받는다. 웹 주소도 가능하다
            Element root = dom.getDocumentElement();
            System.out.println("Tag Name : " + root.getTagName() + "  Local Name : " + root.getLocalName());
            // 태그 이름으로 노드들을 가져오는데, 노드의 갯수가 여러개일 수 있으므로, NodeList형태로 가져온다
            NodeList items = root.getElementsByTagName("body");

            for (int i = 0; i < items.getLength(); i++) {

                // node list의 i번째 아이템(즉, 노드) 를 가져와 item 변수에 저장
                Node item = items.item(i);

                NodeList properties = item.getChildNodes();
                for (int j = 0; j < properties.getLength(); j++) {
                    Weather weather = new Weather();
                    Node property1 = properties.item(j);

// #text의 처리는 어떻게?

                    if (property1.getNodeType() == Node.ELEMENT_NODE) {
                        NodeList dataChild = property1.getChildNodes();
                        for (int k = 0; k < dataChild.getLength(); k++) {
                            Node property = dataChild.item(k);
                            String nodeName = property.getNodeName();
                            if (nodeName.equalsIgnoreCase("hour")) {
                                weather.setHour(Integer.parseInt(property.getFirstChild().getNodeValue()));
                            } else if (nodeName.equalsIgnoreCase("temp")) {
                                weather.setTemp(Double.parseDouble(property.getFirstChild().getNodeValue()));
                            } else if (nodeName.equalsIgnoreCase("wfKor")) {
                                weather.setWfKor(property.getFirstChild().getNodeValue());
                            } else if (nodeName.equalsIgnoreCase("reh")) {
                                weather.setReh(Integer.parseInt(property.getFirstChild().getNodeValue()));
                            }
                        }
                        list.add(weather);
                    }
                }

            }
        } catch (ParserConfigurationException | SAXException |
                IOException e) {
            e.printStackTrace();
        }

        return list;
    }
}
