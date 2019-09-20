<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<%
    for (Cookie cookie : request.getCookies()) {
        if (cookie.getName().equals("JSESSIONID") || cookie.getName().equals("visitedTime")) {
            out.println(cookie.getName() + " " + cookie.getValue());
            out.println("<br>");
        }
    }
%>
</body>
</html>
