package main;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Date;

@WebServlet("/hello.do")
public class MainServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {



    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        request.setCharacterEncoding("UTF-8");
        response.setCharacterEncoding("UTF-8");

        // 쿠키를 굽자!
        // 쿠키 객체 생성
        Cookie cookie = new Cookie("visitedTime", new Date().getTime() + "");
        // 생성된 쿠키를 응답 데이터에 추가
        response.addCookie(cookie);
        request.getRequestDispatcher("viewCookie.jsp").forward(request,response);

        // 연산 로직
//        request.setAttribute("greeting", "Hello World Welcome to hell");
//        request.getRequestDispatcher("hello.jsp").forward(request, response);
    }
}
