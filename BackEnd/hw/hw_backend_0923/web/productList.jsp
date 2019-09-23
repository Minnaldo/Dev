<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<head>
    <meta charset="UTF-8">
    <title>List</title>
    <style>
        td:nth-child(odd) {
            background-color: lightgray;
            text-align: center;
            font-weight: bold;
        }

        td {
            width: 50%;
            text-overflow: ellipsis;
        }

        table {
            border: solid 0.7px black;
            width: 25%;
            height: 120px;
        }

        .productList {
            /*z-index: 3;*/
            border: solid 1px gray;
        }

        #list_viewer {
            width: 55%;
            margin: auto;
        }

        .detail_popup {
            position: fixed;
            bottom: 30px;
            width: 300px;
            margin: auto;
            float: none;
        }

        .plist {
            display: inline-block;
        }
    </style>
    <%-- jquery call --%>
    <script src="https://code.jquery.com/jquery-3.4.1.js"></script>
    <script>
        function add() {
            location.href = "./addProduct.html";
        }

        function leave_event() {
            $('#product_detail').children().remove();
        }

        function over_event(event) {
            $('#product_detail').remove();
            var productName = $(this).find('a').text();
            $.ajax({
                // xml 파일 위치
                url: "./ProductData/products.xml",
                data: "",
                type: "GET",
                dataType: "xml",
                success: function (xml) {
                    $('product', xml).each(function () {
                        if (productName == $(this).find('name').text()) {
                            var id = $(this).find('id').text();
                            var name = $(this).find('name').text();
                            var price = $(this).find('price').text();
                            var stock = $(this).find('stock').text();
                            var description = $(this).find('description').text();

                            $('#product_detail').append("<table class='detail_popup'>" +
                                "<tr><td>상품 번호</td><td>" + id + "</td></tr>" +
                                "<tr><td>상품 명</td><td>" + name + "</td></tr>" +
                                "<tr><td>상품 가격</td><td>" + price + "</td></tr>" +
                                "<tr><td>재고</td><td>" + stock + "</td></tr>" +
                                "<tr><td>기타</td><td>" + description + "</td></tr>" +
                                "</table>");
                        }
                    });
                }
            });
        }

        $(function () {
            $('.productList').hover(over_event, leave_event);
        });
    </script>
</head>
<body>
<h1 align="center">상품 목록</h1>
<div id="list_viewer">
    <fieldset>
        <legend>상품 검색</legend>
        <form action="/main.do" method="post">
            <select name="type">
                <option value="name">이름</option>
                <option value="price">가격</option>
            </select>
            <input type="text" name="value">
            <input type="hidden" name="action" value="list">
            <input type="submit" value="검색">
            <a href="addProduct.html">상품 추가</a>
        </form>
    </fieldset>
    <c:if test="${list eq null}">
        <h2>등록된 상품이 없습니다.</h2>
    </c:if>
    <c:forEach items="${list}" var="product">
        <div class="productList">
            <div>
                <div class="plist">상품 번호</div>
                <div class="plist">${product.id}</div>
            </div>
            <div>
                <div class="plist">상품명</div>
                <div class="plist"><a href="main.do?action=find&name=${product.name}">${product.name}</a></div>
            </div>
        </div>
    </c:forEach>
</div>
<div id="product_detail"></div>
</body>
</html>
