<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
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
</head>
<body>
<!-- menu nav bar -->
<nav class="navbar navbar-expand-lg navbar-light bg-light">
    <a class="navbar-brand" href="main.do"><img alt="ssafy"
                                                src="./img/header-logo.jpg"></a>
    <button class="navbar-toggler" type="button" data-toggle="collapse"
            data-target="#navbarSupportedContent"
            aria-controls="navbarSupportedContent" aria-expanded="false"
            aria-label="Toggle navigation">
        <span class="navbar-toggler-icon"></span>
    </button>
    <div class="navbar collapse navbar-collapse"
         id="navbarSupportedContent">
        <ul class="nav navbar-nav ml-auto">
            <li class="nav-item"><a class="nav-link" href="main.do?action=announce">공지사항</a></li>
            <li class="nav-item"><a class="nav-link" href="main.do?action=plist">상품정보</a></li>
            <li class="nav-item"><a class="nav-link" href="main.do?action=detail">베스트 섭취 정보</a>
            </li>
            <c:if test="${islogin eq '1'}">
            <li class="nav-item"><a class="nav-link" href="#">내 섭취 정보</a></li> <!-- 미구현 -->
            <li class="nav-item"><a class="nav-link" href="#">예상 섭취 정보</a> <!-- 미구현 -->
            </li>
            </c:if>
            <li>
                <form class="form-inline my-2 my-lg-0">
                    <input class="form-control mr-sm-2" type="search"
                           placeholder="Search" aria-label="Search">
                    <button class="btn btn-outline-success my-2 my-sm-0">
                        <span class="fa fa-search"></span></button>
                </form>
            </li>
        </ul>
    </div>
</nav>
</body>
</html>
