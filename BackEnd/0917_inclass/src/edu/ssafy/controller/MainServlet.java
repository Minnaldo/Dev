package edu.ssafy.controller;

import edu.ssafy.model.MemManager;
import edu.ssafy.model.MemVO;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.net.URLEncoder;
import java.util.ArrayList;

// front servlet
//@WebServlet("/main.do")
public class MainServlet extends HttpServlet {
    private MemManager man = MemManager.getInstance();

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        response.setCharacterEncoding("UTF-8");
        String action = request.getParameter("action");

        if (action.equals("registmem")) {
            registMem(request, response);
        } else if (action.equals("listmem")) {
            listMem(request, response);
        } else if (action.equals("meminfo")) {
            memInfo(request, response);
        } else if (action.equals("updatemem")) {
            updateMem(request, response);
        } else if (action.equals("deletemem")) {
            deleteMem(request, response);
        } else if (action.equals("login")) {
            loginMem(request, response);
        } else if (action.equals("search")) {
            searchMem(request, response);
        }
    }

    private void searchMem(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String val = request.getParameter("val");
        System.out.println(val);
        ArrayList<MemVO> list = man.searchMem(val.trim());
        if (list.size() > 0) {
            request.setAttribute("list", list);
            request.getRequestDispatcher("./memList.jsp").forward(request, response);
        } else {
            request.setAttribute("msg", "회원 조회 실패");
            request.getRequestDispatcher("./result.jsp").forward(request, response);
        }
    }

    private void loginMem(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {

        String id = request.getParameter("id");
        String pw = request.getParameter("pw");
        MemVO ret = man.memInfo(id);

        if (ret != null) {
            // 비밀번호 체크
            if (man.memberChk(id, pw)) {
                request.getRequestDispatcher("./main.do?action=listmem").forward(request, response);
            }
        } else {
            // 회원가입 페이지로
            response.sendRedirect("./registerMem.html");
        }

    }

    private void deleteMem(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String id = request.getParameter("id");
        if (man.delMem(id)) {
            // 삭제 완료
            request.setAttribute("msg", "성공적으로 삭제하였습니다");
            request.getRequestDispatcher("./main.do?action=listmem").forward(request, response);
        } else {
            // 삭제 불가
            request.setAttribute("msg", id + " 삭제에 실패했습니다");
            request.getRequestDispatcher("./result.jsp").forward(request, response);
        }
    }

    private void updateMem(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String name = request.getParameter("name");
        String id = request.getParameter("id");
        String ppwd = request.getParameter("pwd");
        String addr = request.getParameter("addr");
        String age = request.getParameter("age");
        String tel = request.getParameter("tel");
        boolean ret = man.updateMem(name, id, ppwd, addr, age, tel);
        if (ret) {
            request.setAttribute("msg", "성공적으로 업데이트 하였습니다");
            request.getRequestDispatcher("./main.do?action=listmem").forward(request, response);
        } else {
            request.setAttribute("msg", id + " 업데이트에 실패했습니다");
            request.getRequestDispatcher("./result.jsp").forward(request, response);
        }
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }

    private void registMem(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String pname = request.getParameter("name");
        String pid = request.getParameter("id");
        String ppwd = request.getParameter("pwd");
        String paddr = request.getParameter("addr");
        String page = request.getParameter("age");
        String ptel = request.getParameter("tel");
        // 3. business 처리
        boolean ret = man.addMem(pname, pid, ppwd, paddr, page, ptel);
        // 4
        if (ret) {
            // 로직이 성공적으로 끝났을 때
//            request.setAttribute("msg", pid + " 등록에 성공하였습니다");
//            request.getSession().setAttribute("msg",pid+"등록에 성공하였습니다.");
            String msg = URLEncoder.encode(" 등록성공", "UTF-8");
            response.sendRedirect("./result.jsp?msg=" + pid + msg);
        } else {
            // 로직이 성공적으로 끝나지 않았을 때
//            request.setAttribute("msg", pid + " 등록에 실패하였습니다");
            String msg = URLEncoder.encode(" 등록실패", "UTF-8");
            response.sendRedirect("./result.jsp?msg=" + pid + msg);
        }
//        request.getRequestDispatcher("./result.jsp").forward(request, response);
    }

    private void listMem(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        ArrayList<MemVO> list = man.searchAll();
        if (list.size() > 0) {
//            list가 들어간다?
//            setAttribute는 Object형태로 넘어가기 때문에!
            request.setAttribute("list", list);
            request.getRequestDispatcher("./memList.jsp").forward(request, response);
        } else {
            request.setAttribute("msg", "회원 조회 실패");
            request.getRequestDispatcher("./result.jsp").forward(request, response);
        }
    }

    private void memInfo(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String id = request.getParameter("id");
        MemVO mem = man.memInfo(id);
        if (mem != null) {
            request.setAttribute("mem", mem);
            request.getRequestDispatcher("./meminfo.jsp").forward(request, response);
        } else {
            request.setAttribute("msg", "회원 정보 조회 실패");
            request.getRequestDispatcher("./result.jsp").forward(request, response);
        }
    }
}

