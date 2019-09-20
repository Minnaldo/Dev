package control;

import model.ProductMgr;
import model.ProductVO;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.ArrayList;

@WebServlet("/main.do")
public class MainServlet extends HttpServlet {
    private ProductMgr mgr = ProductMgr.getInstance();

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        response.setCharacterEncoding("UTF-8");

        String action = request.getParameter("action");

        if (action.equals("") || action == null) {

        } else if (action.equals("scList")) {
            getList(request, response);
        } else if (action.equals("login")) {
            login(request, response);
        } else if (action.equals("find")) {
            find(request, response);
        } else if (action.equals("")) {
        }
    }

    private void find(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String name = request.getParameter("name");
        ProductVO p = mgr.getProduct(name);
        request.setAttribute("product", p);
        request.getRequestDispatcher("viewdetail.jsp").forward(request, response);
    }

    private void login(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        request.getRequestDispatcher("login.jsp").forward(request, response);
    }

    private void getList(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String type = request.getParameter("type");
        if (type.equals("이름")) {
            request.setAttribute("list", mgr.getProducList(request.getParameter("name")));
        } else if (type.equals("가격")) {

        }
        request.getRequestDispatcher("productList.jsp").forward(request, response);
    }


    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
