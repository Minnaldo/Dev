import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class MainServlet extends HttpServlet {

	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		doPost(req, resp);
	}

	@Override
	protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		req.setCharacterEncoding("UTF-8");
		resp.setCharacterEncoding("UTF-8");
		PrintWriter out = resp.getWriter();

		String title = req.getParameter("title");
		String isbn = req.getParameter("isbn");
		String isbn1 = req.getParameter("isbn1");
		String isbn2 = req.getParameter("isbn2");
		String catalogue = req.getParameter("catalogue");
		String nation = req.getParameter("nation");
		String publisheDate = req.getParameter("publisheDate");
		String publisher = req.getParameter("publisher");
		String author = req.getParameter("author");
		String price = req.getParameter("price");
		String currency = req.getParameter("currency");
		String desc = req.getParameter("description");

		out.print("<!DOCTYPE html>" + "<html>" + "<head>"
				+ "<meta charset='UTF-8'>"
				+ "<title>도서 상세 정보 페이지</title>"
				+ "<script src=\"https://code.jquery.com/jquery-3.4.1.js\"></script>" + "<script>" + "$(function(){"
				+ "$('th').css('border','1').css('bgcolor','gray');" + "$('.index').css('bgcolor','gray');" + "});"
				+ "</script>" + "</head>" + "<body>" + "<h1>입력된 도서 정보</h1>" + "<table>" + "<th>도서정보</th>" + "<tr>"
				+ "<td>도서명</td><td>" + title + "</td>" + "<tr><td class='index'>도서번호</td><td>" + isbn + "-" + isbn1 + "-"
				+ isbn2 + "</td></tr>" + "<tr><td class='index'>도서분류</td><td>" + catalogue + "</td></tr>"
				+ "<tr><td class='index'>도서국가</td><td>" + nation + "</td></tr>" + "<tr><td class='index'>출판일</td><td>" + publisheDate
				+ "</td></tr>" + "<tr><td class='index'>출판사</td><td>" + publisher + "</td></tr>" + "<tr><td class='index'>저 자</td><td>"
				+ author + "</td></tr>" + "<tr><td class='index'>도서가격</td><td>" + price + currency + "</td></tr>"
				+ "<tr><td class='index'>도서설명</td><td>" + desc + "</td>" + "</tr>" + "</table>" + "</body>" + "</html>");
	}

}
