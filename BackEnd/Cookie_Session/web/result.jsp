<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
<head>
    <title>Title</title>
    <script>
        var msg = "<c:out value='${msg}'/>";
        alert(msg);
    </script>
</head>
<body>
<div>
    <h2><a href="./member.do?action=signin">회원 가입</a></h2>
    <h2><a href="./login.html">로그인 화면으로</a></h2>
</div>
</body>
</html>
