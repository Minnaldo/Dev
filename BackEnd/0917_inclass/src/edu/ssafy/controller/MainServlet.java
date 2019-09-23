package edu.ssafy.controller;

import edu.ssafy.business.IMemService;
import edu.ssafy.business.MemServiceImpl;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

// front servlet
@WebServlet("/main.do")
public class MainServlet extends HttpServlet {
    IMemService service = new MemServiceImpl();

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        response.setCharacterEncoding("UTF-8");
        String action = request.getParameter("action");

        if (action.equals("l")) {
            service.registMem(request, response);
        } else if (action.equals("listmem")) {
            service.listMem(request, response);
        } else if (action.equals("meminfo")) {
            service.memInfo(request, response);
        } else if (action.equals("updatemem")) {
            service.updateMem(request, response);
        } else if (action.equals("deletemem")) {
            service.deleteMem(request, response);
        } else if (action.equals("login")) {
            service.loginMem(request, response);
        } else if (action.equals("logout")) {
            service.logout(request, response);
        } else if (action.equals("search")) {
            service.searchMem(request, response);
        }
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}

