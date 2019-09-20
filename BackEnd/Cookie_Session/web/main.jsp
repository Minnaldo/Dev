<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%-- jstl을 쓰기 위한 선언 --%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
<head>
    <title>Main Page</title>
</head>
<body>
<%-- 로그인 되어있을땐 로그아웃 버튼 --%>
<%-- 로그아웃 되어있을땐 로그인 버튼을 --%>

<c:choose>
    <c:when test="${id eq null}">
        <form action="member.do">
            아이디 : <input name='userid' type="text"><br>
            패스워드 : <input name='pwd' type="text"><br>
            <input type="hidden" name="action" value="login">
            <input type="submit" value="로그인">
        </form>
    </c:when>
    <c:otherwise>
        <input type="button" value="로그아웃" onclick="location.href='member.do?action=logout'">
    </c:otherwise>
</c:choose>

<%-- 회원 목록을 보여준다 --%>
<table>
    <tr>
        <td width="200px">이름</td>
        <td width="200px">아이디</td>
        <td width="200px">이메일</td>
    </tr>
    <tr>
        <td colspan="3" bgcolor="#ffc0cb"></td>
    </tr>
    <c:forEach items="${list}" var="member">
        <tr>
            <td><a href="member.do?action=viewMember&id=${member.userid}">${member.name}</a></td>
            <td>${member.userid}</td>
            <td>${member.email}</td>
        </tr>
        <br>
    </c:forEach>
    <tr>
        <td colspan="3">
            <input onclick="location.href='./member.do?action=addMemberForm'" type="button" value="회원가입">
        </td>
    </tr>
</table>
</body>
</html>
