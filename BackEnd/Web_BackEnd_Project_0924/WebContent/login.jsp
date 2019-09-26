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
    <script type="text/javascript">
        $(function () {
            $("#test_btn1").click(function () {
                $("#modal").fadeToggle();
            });

            $("#modal_close_btn").click(function () {
                $("#modal").fadeOut();
            });

        });

        function login() {
            document.getElementById("dropdown-box").classList.toggle("show");
        }

        function logout() {
            location.href = 'main.do?action=logout'
        }
    </script>
</head>
<body>
<div class="collapse navbar-collapse flex-grow-0">
    <ul class="navbar-nav text-right">
        <div class="btn-group">
            <c:choose>
                <c:when test="${islogin eq '1'}">
                </c:when>
                <c:otherwise>
                    <button id="test_btn1" style="cursor: pointer">
                        <i class="fa fa-user form-control-feedback"></i> Sign up
                    </button>
                </c:otherwise>
            </c:choose>

        </div>
        <div class="btn-group">

            <c:choose>
                <c:when test="${islogin eq '1'}">
                    <button id="test_btn2" class="dropdown-button" onclick="logout()" style="cursor: pointer">
                        <i class="fa fa-lock form-control-feedback"></i>
                        Logout
                    </button>
                </c:when>
                <c:otherwise>
                    <button id="test_btn2" class="dropdown-button" onclick="login()" style="cursor: pointer">
                        <i class="fa fa-lock form-control-feedback"></i>
                        Login
                    </button>
                </c:otherwise>
            </c:choose>
            <ul id="dropdown-box"
                class="dropdown-menu dropdown-menu-right dropdown-animation"
                aria-labelledby="header-top-drop-2">
                <li>
                    <form class="login-form margin-clear" action="main.do?action=login" method="post">
                        <div class="form-group">
                            <label class="control-label">&nbsp;&nbsp;아이디</label>
                            <input type="text" class="form-control" placeholder="ID" name="id">
                        </div>
                        <div class="form-group">
                            <label class="control-label">&nbsp;&nbsp;비밀번호</label>
                            <input type="password" class="form-control" placeholder="PW" name="pw">
                        </div>
                        <ul class='pagination'>
                            <li>

                                <c:choose>
                                    <c:when test="${islogin eq '1'}">
                                        <button onclick="location.href='main.do?action=logout'"
                                                class="btn btn-gray btn-sm" style='margin: auto;width: 260%;'>
                                            로그아웃
                                        </button>
                                    </c:when>
                                    <c:otherwise>
                                        <button type="submit" class="btn btn-gray btn-sm"
                                                style='margin: auto;width: 260%;'>
                                            로그인
                                        </button>
                                    </c:otherwise>
                                </c:choose>
                            </li>
                        </ul>
                        <br>
                        <ul class='pagination'>
                            <li>
                                <button type="button" onclick="location.href='find_pwd.jsp'"
                                        class="btn btn-gray btn-sm" style='margin: auto;width: 148%;'>
                                    비밀번호 찾기
                                </button>
                            </li>
                        </ul>
                    </form>
                </li>
            </ul>
        </div>
    </ul>
</div>
</body>
</html>