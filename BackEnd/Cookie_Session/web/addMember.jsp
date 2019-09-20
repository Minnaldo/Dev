<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
<head>
    <title>Sign In</title>
</head>
<body>
<form action="./member.do?action=addMember" method="post">
    이름 : <input type="text" name="name" id="name"><br>
    아이디 : <input type="text" name="id" id="id"><br>
    비밀번호 : <input type="text" name="pwd" id="pwd"><br>
    이메일 : <input type="text" name="email" id="email"><br>
    연락처 : <input type="text" name="phone" id="phone"><br>
    관리자 :
    <select>
        <option value="1">관리자</option>
        <option value="0">일반사용자</option>
    </select>
    <input type="submit" value="제출">
</form>
</body>
</html>
