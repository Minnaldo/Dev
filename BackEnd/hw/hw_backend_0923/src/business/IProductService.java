package business;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public interface IProductService {

    void updateProduct(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException;

    void addProduct(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException;

    void remove(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException;

    void find(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException;

    void getList(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException;
}
