<%@ page import="model.Book" %>
<%@ page import="example.Manager" %><%--
  Created by IntelliJ IDEA.
  User: student
  Date: 2019-09-16
  Time: 오후 5:02
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<style>
    tr:first-child, tr:last-child {
        background-color: lightgray;
    }

    td:nth-child(odd) {
        text-align: center;
    }

    table {
        width: 400px;
        margin: auto;
    }

</style>
<body>
<%
    Manager man = Manager.getInstance();

    String isbn = (String) request.getAttribute("isbn");
    String title = (String) request.getAttribute("title");
    Book b = man.find(isbn, title);
%>
<div>
    <table>
        <tr style="text-align: center; ">
            <td colspan="2">등록된 정보는 다음과 같습니다</td>
        </tr>
        <tr>
            <td>도서번호</td>
            <td><%= b.getIsbn() %>
            </td>
        </tr>
        <tr>
            <td>도서제목</td>
            <td><%= b.getTitle()%>
            </td>
        </tr>
        <tr>
            <td>도서종류</td>
            <td><%= b.getCatalogue()%>
            </td>
        </tr>
        <tr>
            <td>출판국가</td>
            <td><%=b.getNation()%>
            </td>
        </tr>
        <tr>
            <td>출판일</td>
            <td><%=b.getPublishDate()%>
            </td>
        </tr>
        <tr>
            <td>출판사</td>
            <td><%=b.getPublisher()%>
            </td>
        </tr>
        <tr>
            <td>저자</td>
            <td><%=b.getAuthor()%>
            </td>
        </tr>
        <tr>
            <td>도서가격</td>
            <td><%=b.getPrice()%>
            </td>
        </tr>
        <tr>
            <td>요약내용</td>
            <td><%=b.getDesc()%>
            </td>
        </tr>
        <tr>
            <td colspan="2">
                <a href="./Book.html">추가 등록</a>
            </td>
        </tr>
    </table>
</div>
</body>
</html>
