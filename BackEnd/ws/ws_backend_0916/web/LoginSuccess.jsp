<%--
  Created by IntelliJ IDEA.
  User: student
  Date: 2019-09-16
  Time: 오후 4:59
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<%
    String id = (String)request.getAttribute("suc_id");
%>
<div>
    <div><%=id %>님 로그인 되었습니다.!!!</div>
    <a href="./Book.html">도서 등록</a>
    <a href="./Login.html">로그아웃</a>
</div>

</body>
</html>
