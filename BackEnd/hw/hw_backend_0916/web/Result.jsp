<%@ page import="example.Product" %>
<%@ page import="example.Manager" %>

<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Product Result</title>
    <style>
        td{
            width: 150px;
        }
        td:nth-child(odd) {
            text-align: center;
            font-weight: bold;
            width: 130px;
        }


        div, h1 {
            margin: auto;
            width: 500px;
        }
    </style>
</head>
<body>
<%
    Manager man = Manager.getInstance();
    String name = (String) request.getAttribute("pname");
    Product p = man.find(name);
%>
<h1>상품이 저장되었습니다.</h1>
<div>
    <table>
        <tbody>
        <tr>
            <td>상품 번호</td>
            <td><%= p.getNumber()%>
            </td>
        </tr>
        <tr>
            <td>상 품 명</td>
            <td><%= p.getName()%>
            </td>
        </tr>
        <tr>
            <td>상품 가격</td>
            <td><%= p.getPrice()%>
            </td>
        </tr>
        <tr>
            <td>상품 설명</td>
            <td><%= p.getDesc()%>
            </td>
        </tr>
        <tr>
            <td colspan="2">
                <a href="./ProductReg.html">상품 등록</a>
                <a href="./ProductList.jsp">상품 목록</a>
            </td>
        </tr>
        </tbody>
    </table>
</div>
</body>
</html>
