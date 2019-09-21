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

@WebServlet("/main.do")
public class MainServlet extends HttpServlet {
    private ProductMgr mgr = ProductMgr.getInstance();

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        response.setCharacterEncoding("UTF-8");

        String action = request.getParameter("action") == null ? "" : request.getParameter("action");

        System.out.println("test: " + action + " size=" + action.length());
        if (action.equals("list") || action.length() == 0) {
            getList(request, response);
        } else if (action.equals("login")) {
            login(request, response);
        } else if (action.equals("find")) {
            find(request, response);
        } else if (action.equals("remove")) {
            remove(request, response);
        } else if (action.equals("add")) {
            addProduct(request, response);
        }
    }

    private void addProduct(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String id = request.getParameter("id");
        String name = request.getParameter("name");
        String price = request.getParameter("price");
        String stock = request.getParameter("stock");
        String description = request.getParameter("description");
        boolean ret = mgr.addProduct(id, name, price, stock, description);
//        TODO alert

        request.getRequestDispatcher("main.do?action=list").forward(request, response);
    }

    private void remove(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
        mgr.removeProduct(request.getParameter("item"));
        request.getRequestDispatcher("main.do?action=scList").forward(request, response);
    }

    private void find(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String name = request.getParameter("name");
        String type = "name";
        ProductVO p = mgr.getProduct(type, name);
        request.setAttribute("product", p);
        request.getRequestDispatcher("viewDetail.jsp").forward(request, response);
    }

    private void login(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        // TODO
        request.getRequestDispatcher("login.jsp").forward(request, response);
    }

    private void getList(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        if (request.getParameter("type") == null || request.getParameter("value") == null) {
            request.setAttribute("list", mgr.getProductList());
        } else {
            String type = request.getParameter("type");
            String value = request.getParameter("value");

            if (type.equals("name"))
                request.setAttribute("list", mgr.getProductList("name", value));
            if (type.equals("price"))
                request.setAttribute("list", mgr.getProductList("price", value));
        }
        request.getRequestDispatcher("productList.jsp").forward(request, response);

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws
            ServletException, IOException {
        doPost(request, response);
    }
}
