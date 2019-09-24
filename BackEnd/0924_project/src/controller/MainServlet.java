package controller;

import business.safeFoodServiceImpl;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/main.do")
public class MainServlet extends HttpServlet {

    public safeFoodServiceImpl service = new safeFoodServiceImpl();

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        response.setCharacterEncoding("UTF-8");
        String action = request.getParameter("action") == null ? "" : request.getParameter("action");

        // TODO 서비스 접근 기능 구현
        if (action.equals("login")) {
            service.login(request, response);
        } else if (action.equals("logout")) {
            service.logout(request, response);
        } else if (action.equals("regist")) {
            service.registMember(request, response);
        } else if (action.equals("delete")) {
            service.deleteMember(request, response);
        } else if (action.equals("searchMember")) {
            service.searchMember(request, response);
        } else if (action.equals("modifyMember")) {
            service.modifyMember(request, response);
        }
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
