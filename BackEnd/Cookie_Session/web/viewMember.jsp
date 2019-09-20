<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
<head>
    <title>view detail</title>
</head>
<body>
<table>
    아이디 : ${member.name}<br>
    이메일 : ${member.userid}<br>
    번호 : ${member.phone}<br>
    관리자 : ${member.admin}<br>
    <input type="button" value="메인으로" onclick="location.href='member.do?action=main'" >
</table>
</body>
</html>
