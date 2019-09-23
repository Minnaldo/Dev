package edu.ssafy.controller;

import javax.servlet.*;
import javax.servlet.annotation.WebFilter;
import java.io.IOException;

@WebFilter(filterName = "KorCharsetFilter")
public class KorCharsetFilter implements Filter {
    //    필터가 소멸될때 실행되는 코드
    public void destroy() {
    }

    //    필터가 처음 호출될 때 실행하는 코드
    public void init(FilterConfig config) throws ServletException {

    }


    public void doFilter(ServletRequest req, ServletResponse resp, FilterChain chain) throws ServletException, IOException {
//        브라우저 -> 서블릿
        req.setCharacterEncoding("utf-8");
        resp.setCharacterEncoding("utf-8");
        resp.setContentType("text/html; charset=utf-8");
        chain.doFilter(req, resp);
//        서블릿 -> 브라우저
    }

}
