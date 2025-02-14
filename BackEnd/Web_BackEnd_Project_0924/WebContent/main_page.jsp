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
    <title>WHAT WE PROVIDE</title>
    <style>
        .ml-auto .dropdown-menu {
            left: auto !important;
            right: 0px;
        }

        #test_btn1 {
            margin-right: 0px;
        }

        #test_btn2 {
            margin-left: -2px;
        }

        #test_btn2, #test_btn1 {
            border: 0px black;
            background-color: rgba(0, 0, 0, 0);
            color: white;
            padding: 5px;
        }

        #test_btn3, #test_btn4 {
            background-color: rgba(0, 0, 0, 0);
            color: black;
            padding: 5px;
        }

        .the-legend {
            border-style: none;
            border-width: 0;
            font-size: 14px;
            line-height: 20px;
            margin-bottom: 0;
            width: auto;
            padding: 0 10px;
            border: 1px solid #e0e0e0;
        }

        .the-fieldset {
            border: 1px solid #e0e0e0;
            padding: 10px;
        }

        legend.scheduler-border {
            width: inherit; /* Or auto */
            padding: 0 10px; /* To give a bit of padding on the left and right */
            border-bottom: none;
        }

        body > div > div > div > ul ul { /*서브메뉴 선택시 서브메뉴화면  */
            display: none;
            background: white;
            box-shadow: 1px 1px 5px black;
        }

        #modal {
            position: relative;
            width: 100%;
            height: 100%;
            z-index: 1;
        }

        #modal h2 {
            margin: 0;
        }

        #modal button {
            display: inline-block;
            width: 100px;
            margin-left: calc(100% - 100px - 10px);
        }

        #modal .modal_content {
            width: 300px;
            margin: 100px auto;
            padding: 20px 10px;
            background: #fff;
            border: 2px solid #666;
        }

        #modal .modal_layer {
            position: fixed;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            background: rgba(0, 0, 0, 0.5);
            z-index: -1;
        }

        #dropdown-box {
            dispaly: none;
        }

        body > nav > div > ul > div > ul {
            background-color: black;
        }

        .card-text {
            display: inline-block;
            width: 100%;
            white-space: nowrap;
            overflow: hidden;
            text-overflow: ellipsis;
            white-space: normal;
            line-height: 1.2;
            height: 100%;
            text-align: left;
            word-wrap: break-word;
            display: -webkit-box;
            -webkit-line-clamp: 3;
            -webkit-box-orient: vertical;
        }

        body > nav > div > ul > div > ul {
            background-color: black;
        }
    </style>
    <script type="text/javascript">
        $(function () {
            $("#test_btn1").click(function () {
                $("#modal").fadeToggle();
            });

            $("#modal_close_btn").click(function () {
                $("#modal").fadeOut();
            });

        });

        function myFunction() {
            document.getElementById("dropdown-box").classList.toggle("show");
        }
    </script>

</head>
<body>
<jsp:include page="menu_bar.jsp"></jsp:include>
<jsp:include page="nav_bar.jsp"></jsp:include>
<jsp:include page="jumbtron.jsp"></jsp:include>
<!-- search result section -->
<section class='main-container' id="results">
    <c:forEach items="${list}" var="product">
        <div class="container">
            <div class="row">
                <div class="col-sm"><img src="${product.img}"></div>
                <div class="col-sm">
                    <h4><a
                        href='./main.do?action=detail&pname=${product.name}'>${product.name}</a></h4>
                    <div>${product.material}</div>
                    <div class="separator-2"></div>
                    <div class="btn-group" role="group">
                        <button type="button" class="btn btn-primary btn-sm">추가</button>
                        <button type="button" class="btn btn-primary btn-sm">찜</button>
                    </div>
                </div>
            </div>
        </div>
    </c:forEach>
</section>

<!-- footer contacts -->
<jsp:include page="footer.jsp"/>
</body>
</html>