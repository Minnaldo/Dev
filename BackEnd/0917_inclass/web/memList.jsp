<%@ page import="edu.ssafy.model.MemVO" %>
<%@ page import="java.util.ArrayList" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Member List</title>
    <script src="https://code.jquery.com/jquery-3.4.1.js"></script>
</head>
<style>
    td:nth-child(odd) {
        width: 130px;
        background-color: lightgray;
        font-weight: bold;
        text-align: center;
    }

    td:nth-child(even){
        width: 130px;
    }

    table {
        border: 1px solid black;
    }
</style>
<body>
<div align="center">
    <h1>회원 목록</h1>

    <div>
        <form action="./main.do?action=search" method="post">
            <input type="search" name="val">
            <input type="submit" value="검색">
        </form>
    </div>

    <div style="margin-top: 20px;">
        <%
            ArrayList<MemVO> list = (ArrayList<MemVO>) request.getAttribute("list");
        %>
        <%
            if (list.size() > 0) {
                for (MemVO m : list) {
        %>
        <table>
            <tr>
                <td>이름</td>
                <td><a href="./main.do?action=meminfo&id=<%=m.getId()%>"><%=m.getName()%><a/>
                </td>
            </tr>
            <tr>
                <td>아이디</td>
                <td><%=m.getId()%>
                </td>
            </tr>
            <tr>
                <td>주소</td>
                <td><%=m.getAddr()%>
                </td>
            </tr>
            <tr>
                <td>나이</td>
                <td><%=m.getAge()%>
                </td>
            </tr>
            <tr>
                <td>전화번호</td>
                <td><%=m.getTel()%>
                </td>
            </tr>
        </table>
        <%
            }
        %>
        <a href="login.html" style="clear: both;">초기 화면</a>
        <%
        } else {
        %>
        <h2>등록된 회원이 없습니다</h2>
        <%
            }
        %>

    </div>
</div>
</body>
</html>