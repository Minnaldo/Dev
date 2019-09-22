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
import java.io.PrintWriter;

@WebServlet("/main.do")
public class MainServlet extends HttpServlet {
    private ProductMgr mgr = ProductMgr.getInstance();

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        response.setCharacterEncoding("UTF-8");

        String action = request.getParameter("action") == null ? "" : request.getParameter("action");

        if (action.equals("list") || action.length() == 0) {
            getList(request, response);
        } else if (action.equals("find")) {
            find(request, response);
        } else if (action.equals("remove")) {
            remove(request, response);
        } else if (action.equals("add")) {
            addProduct(request, response);
        } else if (action.equals("update")) {
            updateProduct(request, response);
        }
    }

    private void updateProduct(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String id = request.getParameter("id"); // 전체 데이터를 받아서 모두를 업데이트 한다
        String name = request.getParameter("name");
        String price = request.getParameter("price");
        String stock = request.getParameter("stock");
        String description = request.getParameter("description");
        ProductVO p = mgr.update(id, name, price, stock, description);
        response.sendRedirect("main.do?action=list");
    }

    private void addProduct(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String id = request.getParameter("id");
        String name = request.getParameter("name");
        String price = request.getParameter("price");
        String stock = request.getParameter("stock");
        String description = request.getParameter("description");
        String url = null;
        ProductVO p = mgr.getProduct("id", id);
        if (p == null) {
            mgr.addProduct(id, name, price, stock, description);
            response.sendRedirect("main.do?action=list");
        } else {
            response.setContentType("text/html;charset=utf-8");
            PrintWriter out = response.getWriter();
            out.println("<script>");
            out.println("alert('이미 존재하는 상품번호 입니다.')");
            out.println("location.href='main.do?action=list'");
            out.println("</script>");
        }
    }

    private void remove(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
        String id = request.getParameter("id");
        ProductVO p = mgr.getProduct("id", id);
        mgr.removeProduct(p.getId());
        response.sendRedirect("main.do?action=list");
    }

    private void find(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String name = request.getParameter("name");
        ProductVO p = mgr.search(name);
        request.setAttribute("product", p);
        request.getRequestDispatcher("viewDetail.jsp").forward(request, response);
    }

    private void getList(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        if (request.getParameter("type") == null || request.getParameter("value") == null || request.getParameter("value").length() == 0) {
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
