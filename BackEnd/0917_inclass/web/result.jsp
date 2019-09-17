<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%--   Attribute에 값이 없으면 Parameter에서 값을 가져온다 --%>
<%
    request.setCharacterEncoding("utf-8");
    String msg = (String) request.getAttribute("msg");
    if(msg == null){
        msg = request.getParameter("msg");
    }
%>
<html>
<head>
    <title>결과 화면</title>
</head>
<body>
<div align="center">
    <h1>결과 내용</h1>
    <h2><%= msg%></h2>
    <a href="./main.do?action=listmem">회원 목록</a>
    <a href="./index.html">초기 화면</a>
</div>
</body>
</html>
