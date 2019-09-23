<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<meta charset="UTF-8">
<head>
    <title>Login</title>
</head>
<body>
<c:choose>
    <c:when test="${id eq null}">
        <%--        로그인 페이지 --%>
        <form action="main.do?action=login" method="post">
            아이디 : <input type="text" name="id"><br>
            패스워드 : <input type="text" name="pwd"><br>
            <input type="button" value="로그인">
            <input type="button" value="회원가입">
        </form>
    </c:when>
    <c:otherwise>
        <%-- 사용자 페이지 --%>
        <%--        로그인 정보를 보여주자!! --%>
        <input type="button" value="로그아웃">
    </c:otherwise>
</c:choose>
</body>
</html>