<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!doctype html>
<html>
<head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport"
          content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <!-- Bootstrap CSS -->
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
    <style>
        .announce_table {
            width: 60%;
            margin: auto;
            border: solid 0.3px lightgray;
        }

        .announce_table > thead {
            height: 80px;
            border: solid 0.3px lightgray;
        }

        .announce_table > tbody * {
            height: 60px;
        }
    </style>
<body>
<jsp:include page="menu_bar.jsp"></jsp:include>
<jsp:include page="nav_bar.jsp"></jsp:include>
<jsp:include page="jumbtron.jsp"></jsp:include>
<table class="announce_table">
    <thead class="bg-warning">
    <th scope="col">#</th>
    <th scope="col">제목</th>
    <th scope="col">조회수</th>
    <th scope="col">게시자</th>
    </thead>
    <tbody>
    <%--    TODO DB에서 불러오자!--%>
    <tr style="cursor: pointer"
        onClick="location.href='./view_announce.html'">
        <th scope="row">1</th>
        <td>오늘의 공지(2019.09.10)</td>
        <td>10</td>
        <td>SSAFY</td>
    </tr>
    <tr style="cursor: pointer"
        onClick="location.href='./view_announce2.html'">
        <th scope="row">2</th>
        <td>오늘의 공지(2019.09.11)</td>
        <td>8</td>
        <td>SSAFY</td>
    </tr>
    </tbody>
</table>
<jsp:include page="footer.jsp"></jsp:include>
</body>
</html>