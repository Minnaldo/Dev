package business;

<<<<<<< Updated upstream
import model.MemberVO;

=======
>>>>>>> Stashed changes
import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import model.MemberVO;

import java.io.IOException;

<<<<<<< Updated upstream
public interface iSafeFoodService {
=======
public interface isafeFoodService {
>>>>>>> Stashed changes
    void login(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException;

    void logout(HttpServletRequest request, HttpServletResponse response) throws IOException;

    void registMember(HttpServletRequest request, HttpServletResponse response) throws IOException;

    void deleteMember(HttpServletRequest request, HttpServletResponse response);

    MemberVO searchMember(HttpServletRequest request, HttpServletResponse response);

    boolean modifyMember(HttpServletRequest request, HttpServletResponse response);
<<<<<<< Updated upstream

    void searchFoodAll(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException;

    void searchName(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException;

    void searchCompany(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException;

    void searchMaterial(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException;

    void datail(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException;
=======
    
    void searchFoodAll(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException;
    
    public void searchName(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException;

	public void searchCompany(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException;

	public void searchMaterial(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException;

	public void detail(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException;
>>>>>>> Stashed changes
}
