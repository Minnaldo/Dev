package main;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Date;

@WebServlet("/session.do")
public class SessionTest extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        response.setCharacterEncoding("utf-8");

        PrintWriter out = response.getWriter();
        HttpSession session = request.getSession();
        out.println("<html>");
        out.println("<meta charset='UTF-8'>");
        out.println("<body>");
        if (session.isNew()) {
            out.println("NEW <br/>");
            out.println("Session ID:" + session.getId());
            out.println("<br>");
            out.println("생성시간 : " + new Date(session.getCreationTime()));
            out.println("<br>");
            out.println("최근접근시간 : " + new Date(session.getLastAccessedTime()));
            out.println("<br>");

//            세션 타임아웃 시간 조회
            out.println("Max Inactive Interval : " + session.getMaxInactiveInterval());

            // 세션 타임아웃 시간을 1200초로 설정
            session.setMaxInactiveInterval(1200);
        } else {
            // 세션 생성후의 요청일때 호출
            out.println("OLD Session <br/>");
            out.println("Session ID : " + session.getId());
            out.println("<br>");
            out.println("생성시간 : " + new Date(session.getCreationTime()));
            out.println("<br>");
            out.println("최근 접근 시간 : " + new Date(session.getLastAccessedTime()));
            out.println("<br>");
            out.println("Max Inactive Interval : " + session.getMaxInactiveInterval());
        }
        out.println("</body>");
        out.println("</html>");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
