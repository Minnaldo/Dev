<%@page import="java.util.*"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	현재시간 :
	<%=new Date().getHours()%>
	<!-- 표현식, 자바코드의 결과값을 웹에서 보여줌 -->

	<%
		// 스크립틀릿 : 자바코드를 수행할 수 있는 영역
		if (new Date().getHours() == 12) {
	%>
	밥시간
	<%
		} else {
	%>
	밥시간 아님
	<%
		}
	%>

</body>
</html>