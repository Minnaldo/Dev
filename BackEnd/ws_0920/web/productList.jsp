<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
<head>
    <title>List</title>
</head>
<body>
<h1>상품 목록</h1>
<h3>find Product</h3>
<form action="/main.do" method="post">
    <select name="type">
        <option value="이름"></option>
        <option value="가격"></option>
    </select>
    <input type="text" name="value">
    <input type="hidden" name="action" value="list">
    <input type="submit">
</form>

<c:forEach items="${list}" var="product">
    <tr>
        <td>상품 번호 : </td>
        <td>${product.id}</td>
    </tr>
    <tr>
        <td>상품명 : </td>
        <td><a href="main.do?action=find&name=${product.name}">${product.name}</a></td>
    </tr>
    <tr>
        <td>가격 : </td>
        <td>${product.price}</td>
    </tr>
    <tr>
        <td>재고 수량</td>
        <td>${product.stock}</td>
    </tr>
    <br>
</c:forEach>

<input type="button" value="add Product" name="add" onclick="location.href='main.do?action='">
</body>
</html>
