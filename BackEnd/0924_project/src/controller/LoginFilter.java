package controller;

import javax.servlet.*;
import javax.servlet.annotation.WebFilter;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebFilter(filterName = "LoginFilter")
public class LoginFilter implements Filter {
    public void destroy() {
    }

    public void doFilter(ServletRequest req, ServletResponse resp, FilterChain chain) throws ServletException, IOException {
        String action = req.getParameter("action") == null ? "" : req.getParameter("action");
        HttpServletResponse response = (HttpServletResponse) resp;
        HttpServletRequest request = (HttpServletRequest) req;

        String id = (String) request.getSession().getAttribute("id");

        if (id == null && action.equals("modifyMember") && action.equals("delete") && action.equals("logout")) {
            response.sendRedirect("main.do?action=");
            return;
        }

        request.setAttribute("loginChk", "1");
        chain.doFilter(req, resp);
    }

    public void init(FilterConfig config) throws ServletException {

    }

}
