package business;

import model.MemberVO;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public interface isafeFoodService {
    void login(HttpServletRequest request, HttpServletResponse response) throws IOException;

    void logout(HttpServletRequest request, HttpServletResponse response) throws IOException;

    boolean registMember(HttpServletRequest request, HttpServletResponse response);

    void deleteMember(HttpServletRequest request, HttpServletResponse response);

    MemberVO searchMember(HttpServletRequest request, HttpServletResponse response);

    boolean modifyMember(HttpServletRequest request, HttpServletResponse response);
}
