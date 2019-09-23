package edu.ssafy.controller;

import javax.servlet.*;
import javax.servlet.annotation.WebFilter;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebFilter(filterName = "LoginChkFilter")
public class LoginChkFilter implements Filter {
    public void destroy() {
    }

//    로그인처리 : 로그인이 되지 않으면 다른페이지에 접근하지못하게함 (어떠한 방법이든 다 안되게)
    public void doFilter(ServletRequest req, ServletResponse resp, FilterChain chain) throws ServletException, IOException {
        String action = req.getParameter("action");
        HttpServletRequest request = (HttpServletRequest) req;
        HttpServletResponse response = (HttpServletResponse) resp;
        String islogin = (String) request.getSession().getAttribute("islogin");
        String id = (String) request.getSession().getAttribute("id");

        System.out.println(islogin + ",  " + id);

//        로그인이 되어있지 않으면, 서블릿까지 접근하지 못함
        if(islogin == null && id == null && !action.equals("registmem") && !action.equals("login")){
            response.sendRedirect("login.html");
            return;
        }

        chain.doFilter(req, resp);
    }

    public void init(FilterConfig config) throws ServletException {

    }

}
