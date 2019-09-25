package controller;

import business.iSafeFoodServiceImpl;
import model.FoodDaoImpl;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/main.do")
public class MainServlet extends HttpServlet {
    public iSafeFoodServiceImpl service = new iSafeFoodServiceImpl();

    @Override
    public void init() throws ServletException {
        // TODO Auto-generated method stub
        FoodDaoImpl foodmgr;
        foodmgr = new FoodDaoImpl();
        foodmgr.loadData(getServletContext().getRealPath("WEB-INF/res/foodInfo.xml"),
                getServletContext().getRealPath("WEB-INF/res/FoodNutritionInfo.xml"));
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
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
        } else if (action.equals("detail")) {
            service.datail(request, response);
        } else if (action.equals("search")) {
            String scondition = request.getParameter("s_condition");
            System.out.println(scondition);
            if (scondition.equals("상품명"))
                service.searchName(request, response);
            else if (scondition.equals("제조사"))
                service.searchCompany(request, response);
            else if (scondition.equals("재료명"))
                service.searchMaterial(request, response);
        } else if (action.equals("plist")) {
            service.searchFoodAll(request, response);
        } else if (action.equals("")) {
            service.golist(request, response);
        }
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        doPost(request, response);
    }
}