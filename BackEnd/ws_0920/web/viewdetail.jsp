<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>View Detail</title>
    <style>
        td:nth-child(odd) {
            background-color: lightgray;
            text-align: center;
        }

        thead {
            text-align: center;
        }
    </style>
</head>
<body>
<table align="center">
    <thead>
    <h3>${product.name}</h3>
    </thead>
    <tbody>
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
    <tr>
        <td>상세 설명</td>
        <td>${product.description}</td>
    </tr>
    </tbody>
</table>
<input type="button" value="돌아가기" onclick="location.href='main.do?action=list'">
<input type="button" value="상품 삭제" name="remove" onclick="location.href='main.do?action=remove&item=${product.id}'">
</body>
</html>
