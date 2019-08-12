package chap10;

import com.google.gson.Gson;

public class GSonEx2 {
	public static void main(String[] args) {
		Gson gson = new Gson();

		String jsonStr = "{'num':'123456','name':'Min','age':26,'addr':'Seoul'}";
		// json 객체에 담기
		Member m = gson.fromJson(jsonStr, Member.class);
		System.out.println(m.toString());

		// 객체로 부터 json 생성
		System.out.println(gson.toJson(m));


	}
}
