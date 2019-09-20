<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>View Detail</title>
</head>
<body>
<tr>
    <td>상품 번호 :</td>
    <td>${product.id}</td>
</tr>
<tr>
    <td>상품명 :</td>
    <td>${product.name}</td>
</tr>
<tr>
    <td>가격 :</td>
    <td>${product.price}</td>
</tr>
<tr>
    <td>재고 수량</td>
    <td>${product.stock}</td>
</tr>
<input type="button" value="돌아가기">
</body>
</html>
