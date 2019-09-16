package example;

import model.Book;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/book.do")
public class MainServlet extends HttpServlet {
    private Manager man = Manager.getInstance();

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        String chk = request.getParameter("chk");
        String id = request.getParameter("id");
        String pw = request.getParameter("pw");

        if (chk.equals("login")) {
            if (id.equals("ssafy") && pw.equals("1111")) {
                // 로그인 성공
                request.setAttribute("suc_id", id);
                request.getRequestDispatcher("./LoginSuccess.jsp").forward(request, response);
            } else {
                // 로그인 실패
                // 에러화면 띄우기
                response.sendRedirect("./Error.jsp");
            }
        } else {
            // 도서 등록 정보
            // result.jsp 부르기
            String title = request.getParameter("title");
            String isbn0 = request.getParameter("isbn");
            String isbn1 = request.getParameter("isbn1");
            String isbn2 = request.getParameter("isbn2");

            String isbn = isbn0 + "-" + isbn1 + "-" + isbn2;

            String catalogue = request.getParameter("catalogue");
            String nation = request.getParameter("nation");
            String publisheDate = request.getParameter("publisheDate");
            String publisher = request.getParameter("publisher");
            String author = request.getParameter("author");
            String price1 = request.getParameter("price");
            String currency = request.getParameter("currency");
            String price = price1 + currency;
            String desc = request.getParameter("description");

            man.add(isbn, title, catalogue, nation, publisheDate, publisher, author, price, desc);
            request.setAttribute("isbn",isbn);
            request.setAttribute("title",title);
            request.getRequestDispatcher("./Result.jsp").forward(request, response);
        }

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
