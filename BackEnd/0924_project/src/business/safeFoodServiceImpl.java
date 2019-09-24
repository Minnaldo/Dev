package business;

import model.MemberVO;
import model.safeFoodMgrImpl;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public class safeFoodServiceImpl implements isafeFoodService {
    private safeFoodMgrImpl mgr = new safeFoodMgrImpl();

    @Override
    public void login(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String id = request.getParameter("id");
        String pw = request.getParameter("pw");

        boolean isLogin = mgr.loginMemeber(id, pw);

        if (isLogin) {
            request.getSession().setAttribute("id", id);
            request.getSession().setAttribute("islogin", "1");
//     TODO 메인페이지로?
        } else {
//            TODO 회원등록 페이지로
            response.sendRedirect("");
        }
    }

    @Override
    public void logout(HttpServletRequest request, HttpServletResponse response) throws IOException {
        request.getSession().invalidate();
//       TODO 메인 페이지로
        response.sendRedirect("");
    }

    @Override
    public boolean registMember(HttpServletRequest request, HttpServletResponse response) {
        boolean ret = false;
        String id = request.getParameter("id");
        String pw = request.getParameter("pw");
        String name = request.getParameter("name");
        String addr = request.getParameter("addr");
        String tel = request.getParameter("tel");
        String[] tmp = request.getParameterValues("allergy");

        String allergy = "";
        for (String str : tmp)
            allergy += str + ", ";

        ret = mgr.addMember(id, pw, name, addr, tel, allergy);
//        TODO 회원가입 성공/ 실패 메시지?
        return ret;
    }

    @Override
    public void deleteMember(HttpServletRequest request, HttpServletResponse response) {
        String id = request.getParameter("id");
        mgr.deleteMember(id);
    }

    @Override
    public MemberVO searchMember(HttpServletRequest request, HttpServletResponse response) {
        String id = request.getParameter("id");
        return mgr.searchMember(id);
    }

    @Override
    public boolean modifyMember(HttpServletRequest request, HttpServletResponse response) {
        String id = request.getParameter("id");
        String pw = request.getParameter("pw");
        String name = request.getParameter("name");
        String addr = request.getParameter("addr");
        String tel = request.getParameter("tel");
        String[] tmp = request.getParameterValues("allergy");
        String allergy = "";
        for (String str : tmp)
            allergy += str + ", ";
        return mgr.modifyMember(id, pw, name, addr, tel, allergy.substring(0, allergy.length() - 2));
    }
}
