

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Calendar;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/hello.do")
public class HelloServlet extends HttpServlet {
	/**
	 * @param : req - 클라이언트가 보낸 요청에 대한 정보들이 들어있음
	 * @param : resp - 서블릿이 응답할 내용이나, 정책에 대해서 정해줄 수 있다.
	 */
	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		resp.setCharacterEncoding("UTF-8");	// 응답자가 받을 캐릭터 인코딩, 가장 먼저 해주어야 함
		PrintWriter out = resp.getWriter();
		
		out.print("<!DOCTYPE html>");
		out.print("<html>");
		out.print("<head>");
		out.print("<meta charset='UTF-8'");
		out.print("<title>Insert Title here</title>");
		out.print("</head>");
		out.print("<body>");
		out.print("<h1>Hello world</h1>"
				+ "<p><p>현재 시간 - ");
		Calendar today = Calendar.getInstance();
		out.print(today.get(Calendar.HOUR_OF_DAY));
		out.print(":");
		out.print(today.get(Calendar.SECOND));
		out.print("</p></body>");
		out.print("</html>");
		out.close();
	}
}
