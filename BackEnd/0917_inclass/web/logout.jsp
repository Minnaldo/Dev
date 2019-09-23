<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
    <style>
        #loginid {
            position: fixed;
            right: 30px;
            top: 30px;
            border: solid 1px black;
            padding: 5px;
        }
    </style>
    <script>
        function logout() {
            location.href = "main.do?action=logout";
        }
    </script>
</head>
<body>
<div id="loginid">
    <h3>현재 사용자 - ${loginid}</h3>
    <button onclick="logout()">로그아웃</button>
</div>
</body>
</html>
