<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
<head>
    <title>List</title>
</head>
<body>
<h1>상품 목록</h1>
<form action="/main.do" method="post">
    <select name="type">
        <option value="이름"></option>
        <option value="가격"></option>
    </select>
    <input type="text" name="name">
    <input type="hidden" name="action" value="scList">
    <input type="hidden" name="value" value="scName">
    <input type="submit">
</form>

<c:forEach items="${list}" var="product">
    <tr>
        <td>상품 번호 : </td>
        <td>${list.id}</td>
    </tr>
    <tr>
        <td>상품명 : </td>
        <td><a href="main.do?action=find&name=${list.name}">${list.name}</a></td>
    </tr>
    <tr>
        <td>가격 : </td>
        <td>${list.price}</td>
    </tr>
    <tr>
        <td>재고 수량</td>
        <td>${list.stock}</td>
    </tr>
    <br>
</c:forEach>
<h2><a href=""></a></h2>
</body>
</html>
