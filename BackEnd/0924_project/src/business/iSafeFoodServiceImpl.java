package business;

<<<<<<< Updated upstream:BackEnd/0924_project/src/business/iSafeFoodServiceImpl.java
import model.*;
=======
import model.Food;
import model.FoodDaoImpl;
import model.MemberVO;
import model.safeFoodMgrImpl;
>>>>>>> Stashed changes:BackEnd/0924_project/src/business/safeFoodServiceImpl.java

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
<<<<<<< Updated upstream:BackEnd/0924_project/src/business/iSafeFoodServiceImpl.java
import java.sql.SQLException;
import java.util.List;

public class iSafeFoodServiceImpl implements iSafeFoodService {

=======
import java.util.List;

public class safeFoodServiceImpl implements isafeFoodService {

>>>>>>> Stashed changes:BackEnd/0924_project/src/business/safeFoodServiceImpl.java
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
<<<<<<< Updated upstream:BackEnd/0924_project/src/business/iSafeFoodServiceImpl.java
            response.sendRedirect("main_page.jsp");
        } else {
            response.sendRedirect("main_page.jsp");
=======
            response.sendRedirect("main.do?action=");
        } else {
            response.sendRedirect("main.do?action=");
>>>>>>> Stashed changes:BackEnd/0924_project/src/business/safeFoodServiceImpl.java
        }
    }

    @Override
    public void logout(HttpServletRequest request, HttpServletResponse response) throws IOException {
        request.getSession().invalidate();
<<<<<<< Updated upstream:BackEnd/0924_project/src/business/iSafeFoodServiceImpl.java
        response.sendRedirect("main_page.jsp");
=======
        response.sendRedirect("main.do?action=");
>>>>>>> Stashed changes:BackEnd/0924_project/src/business/safeFoodServiceImpl.java
    }

    @Override
    public void registMember(HttpServletRequest request, HttpServletResponse response) throws IOException {
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
<<<<<<< Updated upstream:BackEnd/0924_project/src/business/iSafeFoodServiceImpl.java
        ret = mgr.addMember(id, pw, name, addr, tel, allergy.substring(0, allergy.length() - 2));
        return ret;
=======
        mgr.addMember(id, pw, name, addr, tel, allergy.substring(0, allergy.length() - 2));

        response.sendRedirect("main.do");
>>>>>>> Stashed changes:BackEnd/0924_project/src/business/safeFoodServiceImpl.java
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
<<<<<<< Updated upstream:BackEnd/0924_project/src/business/iSafeFoodServiceImpl.java
        // TODO Auto-generated method stub
=======
>>>>>>> Stashed changes:BackEnd/0924_project/src/business/safeFoodServiceImpl.java
        List<Food> finds = foodmgr.search_name(request.getParameter("search"));
        request.setAttribute("list", finds);
        request.getRequestDispatcher("list.jsp").forward(request, response);
    }

    public void searchCompany(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
<<<<<<< Updated upstream:BackEnd/0924_project/src/business/iSafeFoodServiceImpl.java
        // TODO Auto-generated method stub
=======
>>>>>>> Stashed changes:BackEnd/0924_project/src/business/safeFoodServiceImpl.java
        List<Food> finds = foodmgr.search_company(request.getParameter("search"));
        request.setAttribute("list", finds);
        request.getRequestDispatcher("list.jsp").forward(request, response);
    }

    public void searchMaterial(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
<<<<<<< Updated upstream:BackEnd/0924_project/src/business/iSafeFoodServiceImpl.java
        // TODO Auto-generated method stub
=======
>>>>>>> Stashed changes:BackEnd/0924_project/src/business/safeFoodServiceImpl.java
        List<Food> finds = foodmgr.search_material(request.getParameter("search"));
        request.setAttribute("list", finds);
        request.getRequestDispatcher("list.jsp").forward(request, response);
    }

<<<<<<< Updated upstream:BackEnd/0924_project/src/business/iSafeFoodServiceImpl.java
    public void datail(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // TODO Auto-generated method stub
        iFoodServiceImpl manager;
        try {
            manager = new iFoodServiceImpl();
            Food find = manager.search(request.getParameter("pname"));
            request.setAttribute("list", find);
            request.getRequestDispatcher("detail.jsp").forward(request, response);
        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
=======
    public void detail(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        Food finds = foodmgr.search_name(request.getParameter("pname")).get(0);
        request.setAttribute("list", finds);
        request.getRequestDispatcher("detail.jsp").forward(request, response);
>>>>>>> Stashed changes:BackEnd/0924_project/src/business/safeFoodServiceImpl.java
    }

    @Override
    public void searchFoodAll(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        List<Food> list = foodmgr.searchAll();
<<<<<<< Updated upstream:BackEnd/0924_project/src/business/iSafeFoodServiceImpl.java
        request.setAttribute("list", list);
        request.getRequestDispatcher("list.jsp").forward(request, response);

    }

    public void golist(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // TODO Auto-generated method stub
        List<Food> list = foodmgr.searchAll();

        request.setAttribute("list", list);

=======

        request.setAttribute("list", list);
        request.getRequestDispatcher("list.jsp").forward(request, response);
    }

    public void golist(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        List<Food> list = foodmgr.searchAll();
        request.setAttribute("list", list);
>>>>>>> Stashed changes:BackEnd/0924_project/src/business/safeFoodServiceImpl.java
        request.getRequestDispatcher("main_page.jsp").forward(request, response);
    }
}
