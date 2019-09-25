import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import java.io.IOException;

@WebServlet("main.do")
public class MainServlet extends HttpServlet {
    protected void doPost(javax.servlet.http.HttpServletRequest request, javax.servlet.http.HttpServletResponse response) throws javax.servlet.ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        response.setCharacterEncoding("UTF-8");

        String action = request.getParameter("action");
        if (action.equals("algo")) {
            char[] num = request.getParameter("num").toCharArray();
            int[] arr = new int[num.length];

            for (int i = 0; i < num.length; i++) {
                arr[i] = Character.digit(num[i], 10);
            }

            String[] result = new Problem().solution(arr);

            request.setAttribute("result", result);
            request.getRequestDispatcher("result.jsp").forward(request, response);
        }
    }

    protected void doGet(javax.servlet.http.HttpServletRequest request, javax.servlet.http.HttpServletResponse response) throws javax.servlet.ServletException, IOException {
        doPost(request, response);
    }
}
