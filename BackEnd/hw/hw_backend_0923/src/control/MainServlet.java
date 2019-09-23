package control;

import business.IProductService;
import business.ProductServiceImpl;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/main.do")
public class MainServlet extends HttpServlet {
    IProductService service = new ProductServiceImpl();

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        response.setCharacterEncoding("UTF-8");

        String action = request.getParameter("action") == null ? "" : request.getParameter("action");

        if (action.equals("list") || action.length() == 0) {
            service.getList(request, response);
        } else if (action.equals("find")) {
            service.find(request, response);
        } else if (action.equals("remove")) {
            service.remove(request, response);
        } else if (action.equals("add")) {
            service.addProduct(request, response);
        } else if (action.equals("update")) {
            service.updateProduct(request, response);
        }
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doPost(req, resp);
    }
}
