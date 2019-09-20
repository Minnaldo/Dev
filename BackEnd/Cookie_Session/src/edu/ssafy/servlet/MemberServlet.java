package edu.ssafy.servlet;

import edu.ssafy.model.Manager;
import edu.ssafy.model.MemberVO;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.ArrayList;

@WebServlet("/member.do")
public class MemberServlet extends HttpServlet {

    private Manager man = Manager.getInstance();

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        response.setCharacterEncoding("UTF-8");

        String action = request.getParameter("action");

        if (action == null || action.equals("main")) {
            // go main page
            // 메인페이지에는 모든 회원 리스트를
            ArrayList<MemberVO> list = man.getMemberList();
            request.setAttribute("list", list);
            request.getRequestDispatcher("main.jsp").forward(request, response);
        } else if (action.equals("addMember")) {
//            회원추가 작업 -> main
            boolean ret = addMember(request, response);
            if (ret) {
                request.getRequestDispatcher("member.do?action=main");
            } else {
                request.setAttribute("msg", "회원가입 실패");
                request.getRequestDispatcher("result.jsp").forward(request, response);
            }

        } else if (action.equals("addMemberForm")) {

        } else if (action.equals("viewMember")) {
//            회원 상세보기 페이지 (로그인 된것만 볼수 있게)
            viewMember(request, response);
        } else if (action.equals("login")) {
            login(request, response);

        } else if (action.equals("logout")) {
            logout(request, response);
        }
    }

    private boolean addMember(HttpServletRequest request, HttpServletResponse response) {
        String name = request.getParameter("name");
        String userid = request.getParameter("userid");
        String pwd = request.getParameter("pwd");
        String email = request.getParameter("phone");
        int admin = Integer.parseInt(request.getParameter("admin"));
        MemberVO m = new MemberVO(name, userid, pwd, email, email, admin);
        return man.addMember(m);
    }

    private void addMemberForm(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.getRequestDispatcher("addMember.jsp").forward(request, response);
    }

    private void viewMember(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        if (request.getSession().getAttribute("id") == null) {
            response.sendRedirect("member.do?action=main");
//            리다이렉트 이후 코드가 끝나야 함
            return;
        }
        String id = request.getParameter("id");
        MemberVO m = man.getMember(id);
        request.setAttribute("member", m);
        request.getRequestDispatcher("viewMember.jsp").forward(request, response);
    }

    private void login(HttpServletRequest request, HttpServletResponse response) throws IOException {
        // 세션을 새로 생성한다
//        아이디가 존재하는지 확인
        String id = request.getParameter("userid");
        String pwd = request.getParameter("pwd");
        System.out.println("uid = " + id + "  pwd = " + pwd);
        if (pwd.equals(man.getMember(id).getPwd())) {
            //로그인 성공
            request.getSession().setAttribute("id", id);
        }
        response.sendRedirect("member.do?action=main");
    }

    private void logout(HttpServletRequest request, HttpServletResponse response) throws IOException {
        request.getSession().setAttribute("id", null);
        response.sendRedirect("member.do?action=main");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        response.setCharacterEncoding("UTF-8");
        doPost(request, response);
    }
}
