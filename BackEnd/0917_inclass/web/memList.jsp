<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Member List</title>
    <script src="https://code.jquery.com/jquery-3.4.1.js"></script>
    <style>
        td:nth-child(odd) {
            width: 130px;
            background-color: lightgray;
            font-weight: bold;
            text-align: center;
        }

        td:nth-child(even) {
            width: 130px;
        }

        table {
            border: 1px solid black;
        }
    </style>
</head>
<body>
<jsp:include page="logout.jsp"></jsp:include>
<div align="center">
    <h1>회원 목록</h1>

    <div>
        <form action="./main.do?action=search" method="post">
            <input type="search" name="val">
            <input type="submit" value="검색">
        </form>
    </div>

    <div style="margin-top: 20px;">
        <c:choose>
            <c:when test="${empty list}">
                <h2>등록된 회원이 없습니다</h2>
            </c:when>
            <c:otherwise>
                <c:forEach items="${list}" var="m">
                    <table>
                        <tr>
                            <td>이름</td>
                            <td><a href="./main.do?action=meminfo&id=${m.id}">${m.name}<a/>
                            </td>
                        </tr>
                        <tr>
                            <td>아이디</td>
                            <td>
                                    ${m.id}
                            </td>
                        </tr>
                        <tr>
                            <td>주소</td>
                            <td>
                                    ${m.addr}
                            </td>
                        </tr>
                        <tr>
                            <td>나이</td>
                            <td>
                                    ${m.age}
                            </td>
                        </tr>
                        <tr>
                            <td>전화번호</td>
                            <td>
                                    ${m.tel}
                            </td>
                        </tr>
                    </table>
                </c:forEach>
                <a href="login.html" style="clear: both;">초기 화면</a>
            </c:otherwise>
        </c:choose>
    </div>
</div>
</body>
</html>