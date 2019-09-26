package business;

import model.MemberVO;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public interface isafeFoodService {
    void login(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException;

    void logout(HttpServletRequest request, HttpServletResponse response) throws IOException;

    boolean registMember(HttpServletRequest request, HttpServletResponse response);

    void deleteMember(HttpServletRequest request, HttpServletResponse response);

    MemberVO searchMember(HttpServletRequest request, HttpServletResponse response);

    boolean modifyMember(HttpServletRequest request, HttpServletResponse response);

    void searchFoodAll(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException;

    public void searchName(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException;

    public void searchCompany(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException;

    public void searchMaterial(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException;

    public void datail(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException;


    void announce(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException;

    void announceView(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException;
}
