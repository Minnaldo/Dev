package chap10;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

public class SimpleJSonParser {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		JSONParser parser = new JSONParser();
		try {
			JSONObject parse = (JSONObject) parser
					.parse(new BufferedReader(new InputStreamReader(new FileInputStream("object.json"))));
			parse.size();

			JSONArray objs = (JSONArray) parse.get("persons");
			for (int i = 0; i < objs.size(); i++) {
				JSONObject p = (JSONObject) objs.get(i);
				System.out.println(p.get("gender"));
				System.out.println(p.get("name"));
				System.out.println(p.get("nickname"));
				System.out.println(p.get("age"));
			}
			objs = (JSONArray) parse.get("books");
			for (int i = 0; i < objs.size(); i++) {
				JSONObject p = (JSONObject) objs.get(i);
				System.out.println(p.get("price"));
				System.out.println(p.get("name"));
				System.out.println(p.get("genre"));
				System.out.println(p.get("publisher"));
				System.out.println(p.get("writer"));
			}

		} catch (IOException | ParseException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

}
