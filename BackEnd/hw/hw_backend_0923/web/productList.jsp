<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<meta charset="UTF-8">
<head>
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

        a {
            text-overflow: ellipsis;
        }

        table {
            float: left;
            border: solid 0.7px black;

            width: 25%;
            height: 120px;
        }

        #list_viewer {
            width: 55%;
            margin: auto;
        }

        aside {
            position: absolute;
            right: 50px;
            width: 20%;
        }
    </style>
    <%-- jquery call --%>
    <script src="https://code.jquery.com/jquery-3.4.1.js"></script>
    <script>
        function add() {
            location.href = "./addProduct.html";
        }

        $(function () {
            $('.productList').hover(function () {
                var pname = $(this).children('tr:first').children(':last');
                var proval = $(this).children('.proname').text();

                console.log("get proname=="+"  proval=="+proval);
                $.ajax({
                    // xml 파일 위치
                    url: "./ProductData/products.xml",
                    data: "",
                    type: "GET",
                    dataType: "xml",
                    success: function (xml) {
                        $('product', xml).each(function () {
                            if (pname == $(this).find('name').text()) {
                                var id = $(dat).find('id').text();
                                var name = $(dat).find('name').text();
                                var price = $(dat).find('price').text();
                                var stock = $(dat).find('stock').text();
                                var description = $(dat).find('description').text();

                                $('#product_detail').append("<table>" +
                                    "<tr><td>상품 번호</td><td>id</td></tr>" +
                                    "<tr><td>상품 명</td><td>name</td></tr>" +
                                    "<tr><td>상품 가격</td><td>price</td></tr>" +
                                    "<tr><td>재고</td><td>stock</td></tr>" +
                                    "<tr><td>기타</td><td>description</td></tr>" +
                                    "</table>");
                            }
                        });
                    }
                });
            });
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
        <table class="productList">
            <tr>
                <td>상품 번호</td>
                <td>${product.id}</td>
            </tr>
            <tr>
                <td>상품명</td>
                <td class="proname"><a href="main.do?action=find&name=${product.name}">${product.name}</a></td>
            </tr>
            <tr>
                <td>가격</td>
                <td>${product.price}</td>
            </tr>
            <tr>
                <td>재고 수량</td>
                <td>${product.stock}</td>
            </tr>
        </table>
    </c:forEach>
</div>
<div id="product_detail">

</div>
</body>
</html>
