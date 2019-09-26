<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
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
<jsp:include page="menu_bar.jsp"></jsp:include>
<jsp:include page="nav_bar.jsp"></jsp:include>
<jsp:include page="jumbtron.jsp"></jsp:include>
<c:forEach items="${list}" var="product">
    <div class='card'
         style='width: 640px; height: 300px; float: left; margin-left:auto; margin-top:15px; margin-right:10px;margin-bottom:15px;'>
        <div class='row no-gutters'>
            <div class='col-md-4'><img src="${product.img}" class='card-img' alt="${product.img}"></div>
            <div class='col-md-8'>
                <div class='card-body'><h5 class='card-title'><a
                        href='./main.do?action=detail&pname=${product.name}'>${product.name}</a></h5>
                    <div class='separator-2'></div>
                    <p class='card-text'>${product.material}</p>
                    <div class='separator-2'></div>
                    <div class='btn-group' role='group'>
                        <button type='button' class='btn btn-default btn-sm'>추가</button>
                        <button type='button' class='btn btn-default btn-sm'>찜</button>
                    </div>
                </div>
            </div>
        </div>
    </div>
</c:forEach>
<jsp:include page="footer.jsp"></jsp:include>
</body>
</html>
