package Paser_prac.dom;

import chap11.dom.Check;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.ArrayList;

public class DomParser {


    public void getContent(String url) {
        DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
        ArrayList<Check> list = new ArrayList<>();
        try {
            DocumentBuilder builder = factory.newDocumentBuilder();
            // 파일을 받아와 dom에 저장
            Document dom = builder.parse(new URL(url).openConnection().getInputStream());
            Element root = dom.getDocumentElement();

            // 예제 xml파일에서 check 태그가 여러개가 존재함
            NodeList items = root.getElementsByTagName("Check");

            for (int i = 0; i < items.getLength(); i++) {
                // Check객체를 생성
                Check check = new Check();
                // i번째 아이템을 가져온다
                Node item = items.item(i);

                check.setCode(item.getAttributes().getNamedItem("code").getNodeValue());
                check.setDate(item.getAttributes().getNamedItem("date").getNodeValue());

                // NodeList check태그 자식노드들을 저장하는 객체
                NodeList properties = item.getChildNodes();

                // 위의 NodeList에서 각 노드들을 하나씩 가져와 처리
                for (int j = 0; j < properties.getLength(); j++) {
                    Node property = properties.item(i);
                    String name = property.getNodeName();
                    // 현재 가져온 노드의 이름에 맞는 처리를 해준다.
                    // 이 코드에서는 객체의 각 변수에 알맞게 데이터를 삽입한다
                    if (name.equalsIgnoreCase("Clean")) {
                        check.setClean(property.getFirstChild().getNodeValue());
                    } else if (name.equalsIgnoreCase("Ready")) {
                        check.setReady(property.getFirstChild().getNodeValue());
                    } else if (name.equalsIgnoreCase("Response")) {
                        check.setResponse(property.getFirstChild().getNodeValue());
                    } else if (name.equalsIgnoreCase("Request")) {
                        // 노드가 비어있지 않을 때
                        if (property.getFirstChild() != null)
                            check.setRequest(property.getFirstChild().getNodeValue());
                    }
                }
                // 리스트에 처리된 객체를 삽입
                list.add(check);
            }

        } catch (
                ParserConfigurationException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (SAXException e) {
            e.printStackTrace();
        }

        return list;
    }
}
