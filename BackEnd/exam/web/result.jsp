<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<%-- 알고리즘 문제의 결과값을 출력한다 --%>

<c:forEach items="${result}" var="result">
    <div>
        <h2>
                ${result}
        </h2>
    </div>
</c:forEach>
</body>
</html>
