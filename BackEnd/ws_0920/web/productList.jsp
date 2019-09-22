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
            width: 115px;
        }
        h3{
            float: right;
            margin: auto;
        }
        table {
            float: left;
        }

        #list_viewer {
            width: 55%;
            margin: auto;
        }
    </style>
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
                <option value="tag">태그</option>
            </select>
            <input type="text" name="value">
            <input type="hidden" name="action" value="list">
            <input type="submit" value="검색">
            <h3><a href="addProduct.html">상품 추가</a></h3>
        </form>
    </fieldset>
    <c:if test="${list eq null}">
        <h2>등록된 상품이 없습니다.</h2>
    </c:if>
    <c:forEach items="${list}" var="product">
        <table>
            <tr>
                <td>상품 번호</td>
                <td>${product.id}</td>
            </tr>
            <tr>
                <td>상품명</td>
                <td><a href="main.do?action=find&name=${product.name}">${product.name}</a></td>
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

</body>
</html>
