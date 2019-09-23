package edu.ssafy.business;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public interface IMemService {


    void logout(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException;

    void searchMem(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException;

    void loginMem(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException;

    void deleteMem(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException;

    void updateMem(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException;


    void registMem(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException;

    void listMem(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException;

    void memInfo(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException;
}
