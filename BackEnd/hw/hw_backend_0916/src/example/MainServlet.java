package example;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/product.do")
public class MainServlet extends HttpServlet {

    private Manager man = Manager.getInstance();

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doPost(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.setCharacterEncoding("utf-8");

        String pname = req.getParameter("pname");
        String pprice = req.getParameter("pprice");
        String pdesc = req.getParameter("pdesc");

        man.addProduct(pname, pprice, pdesc);
        req.setAttribute("pname", pname);
        req.getRequestDispatcher("./Result.jsp").forward(req, resp);
    }
}
