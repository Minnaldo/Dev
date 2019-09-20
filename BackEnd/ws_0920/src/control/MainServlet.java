package control;

import model.ProductMgr;
import model.ProductVO;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
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

        } else if (action.equals("list")) {
            getList(request, response);
        } else if (action.equals("login")) {
            login(request, response);
        } else if (action.equals("find")) {
            find(request, response);
        } else if (action.equals("remove")) {
            remove(request,response);
        } else if(action.equals("add")){
            addProduct(request,response);
        }
    }

    private void addProduct(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String id = request.getParameter("id");
        String name = request.getParameter("name");
        String price = request.getParameter("price");
        String stock = request.getParameter("stock");
        String description = request.getParameter("description");
        boolean ret = mgr.addProduct(id,name,price,stock,description);
//        TODO alert

        request.getRequestDispatcher("main.do?action=list").forward(request,response);
    }

    private void remove(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
        mgr.removeProduct(request.getParameter("item"));
        request.getRequestDispatcher("main.do?action=scList").forward(request,response);
    }

    private void find(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String name = request.getParameter("name");
        ProductVO p = mgr.getProduct(name);
        request.setAttribute("product", p);
        request.getRequestDispatcher("viewdetail.jsp").forward(request, response);
    }

    private void login(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        // TODO
        request.getRequestDispatcher("login.jsp").forward(request, response);
    }

    private void getList(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String type = request.getParameter("type");
        if (type.equals("이름")) {
//            이름이 같은 요소만 찾기
            request.setAttribute("list", mgr.getProducList("name",request.getParameter("value")));
        } else if (type.equals("가격")) {
//            가격 이하의 요소만 찾기
            request.setAttribute("list", mgr.getProducList("price",request.getParameter("value")));
        }
        request.getRequestDispatcher("productList.jsp").forward(request, response);
    }


    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }
}
