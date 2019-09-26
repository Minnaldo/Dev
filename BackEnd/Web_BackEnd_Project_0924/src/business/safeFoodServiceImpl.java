package business;

import model.*;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class safeFoodServiceImpl implements isafeFoodService {

    private safeFoodMgrImpl mgr = new safeFoodMgrImpl();
    private FoodDaoImpl foodmgr = new FoodDaoImpl();

    @Override
    public void login(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
        String id = request.getParameter("id");
        String pw = request.getParameter("pw");
        System.out.println(getClass().getName() + " id=" + id + "pw=" + pw);
        boolean isLogin = mgr.loginMemeber(id, pw);

        if (isLogin) {
            request.getSession().setAttribute("id", id);
            request.getSession().setAttribute("islogin", "1");
            response.sendRedirect("main_page.jsp");
        } else {
            response.sendRedirect("main_page.jsp");
        }
    }

    @Override
    public void logout(HttpServletRequest request, HttpServletResponse response) throws IOException {
        request.getSession().invalidate();
        response.sendRedirect("main_page.jsp");
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
        ret = mgr.addMember(id, pw, name, addr, tel, allergy.substring(0, allergy.length() - 2));
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

    public void searchName(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        List<Food> finds = foodmgr.search_name(request.getParameter("search"));
        request.setAttribute("list", finds);
        request.getRequestDispatcher("list.jsp").forward(request, response);
    }

    public void searchCompany(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        List<Food> finds = foodmgr.search_company(request.getParameter("search"));
        request.setAttribute("list", finds);
        request.getRequestDispatcher("list.jsp").forward(request, response);
    }

    public void searchMaterial(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        List<Food> finds = foodmgr.search_material(request.getParameter("search"));
        request.setAttribute("list", finds);
        request.getRequestDispatcher("list.jsp").forward(request, response);
    }

    public void datail(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {


        Food find = foodmgr.search(request.getParameter("pname"));
        request.setAttribute("list", find);
        request.getRequestDispatcher("detail.jsp").forward(request, response);
    }

    @Override
    public void searchFoodAll(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        List<Food> list = foodmgr.searchAll();
        request.setAttribute("list", list);
        request.getRequestDispatcher("list.jsp").forward(request, response);

    }

    public void golist(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        List<Food> list = foodmgr.searchAll();

        request.setAttribute("list", list);

        request.getRequestDispatcher("main_page.jsp").forward(request, response);
    }

    @Override
    public void announce(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        ArrayList<AnnounceVO> list = mgr.announceList();
        request.setAttribute("list", list);
        request.getRequestDispatcher("announce.jsp").forward(request, response);
    }

    @Override
    public void announceView(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        int number = Integer.parseInt(request.getParameter("number"));
        AnnounceVO an = mgr.announce(number);
        request.setAttribute("announce", an);
        request.getRequestDispatcher("announceView.jsp").forward(request, response);
    }
}
