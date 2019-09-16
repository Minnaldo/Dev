<%@ page import="example.Manager" %>
<%@ page import="java.util.ArrayList" %>
<%@ page import="example.Product" %><%--
  Created by IntelliJ IDEA.
  User: alban
  Date: 2019-09-17
  Time: 오전 12:46
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Product List</title>
    <script src="https://code.jquery.com/jquery-3.4.1.js"></script>
    <style>
        div{
            margin: auto;
            width: 500px;
        }
        td{
            width: 150px;
        }
        td:nth-child(odd){
            text-align: right;
            width: 130px;
        }
    </style>
</head>
<%
    Manager man = Manager.getInstance();
    for (Product p : man.search()) {
%>
<script>
    $(function () {
        $('#pro_list').append("<tbody><tr><td>상품 번호</td><td><%= p.getNumber()%></td></tr><tr><td>상 품 명</td><td><%= p.getName()%></td></tr><tr><td>상품 가격</td><td><%= p.getPrice()%></td></tr><tr><td>상품 설명</td><td><%= p.getDesc()%></td></tr></tbody><br>");
    });
</script>
<%
    }
%>
<body>
<div>
    <h1>상품 목록</h1>
</div>
<div id="pro_list">

</div>
<div style="margin-top: 20px;">
    <a href="ProductReg.html">상품 등록</a>
</div>
</body>
</html>
