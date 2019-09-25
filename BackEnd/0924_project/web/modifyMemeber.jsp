<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
<head>
    <link rel="stylesheet"
          href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css"
          integrity="sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO"
          crossorigin="anonymous">
    <link rel="stylesheet"
          href="//maxcdn.bootstrapcdn.com/font-awesome/4.3.0/css/font-awesome.min.css">
    <script
            src="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/js/bootstrap.min.js"
            integrity="sha384-ChfqqxuZUCnJSK3+MXmPNIyE6ZbWh2IMqE241rYiqJxyMiZ6OW/JmZQ5stwEULTy"
            crossorigin="anonymous"></script>
    <script src="https://code.jquery.com/jquery-3.4.1.js"></script>
</head>
<body>

<jsp:include page="menu_bar.jsp"/>
<jsp:include page="nav_bar.jsp"/>
<jsp:include page="jumbtron.jsp"/>

<%--content--%>
<div>

    <table>
        <thead>
        <h2>${person.name}님의 정보</h2>
        </thead>
        <form action="main.do?action=modifyMember" method="post">
            <tbody>
            <tr>
                <td>아이디</td>
                <td><input type="text" name="id" readonly></td>
            </tr>
            <tr>
                <td>이름</td>
                <td><input type="text" name="name" required></td>
            </tr>
            <tr>
                <td>비밀번호</td>
                <td><input type="password" name="pw" required></td>
            </tr>
            <tr>
                <td>주소</td>
                <td><input type="text" name="addr"></td>
            </tr>
            <tr>
                <td>전화</td>
                <td><input type="text" name="tel"></td>
            </tr>
            <tr>
                <td>알러지</td>
                <td><input type="text" name="allergy" required></td>
            </tr>
            </tbody>
            <input class="btn btn-info" type="submit" value="정보 수정">
            <button class="btn btn-info" onclick="location.href='main.do?action='">홈으로</button>
        </form>
    </table>
</div>

<jsp:include page="footer.jsp"/>
</body>
</html>
