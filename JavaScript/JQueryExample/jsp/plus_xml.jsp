<%@ page language="java" contentType="text/html; charset=EUC-KR"
	pageEncoding="EUC-KR"%>
<%
<!-- getParameter()의 안에 들어갈 값은 가져올 요소의 속성중 name속성의 값 -->
	int op1 = Integer.parseInt(request.getParameter("op1"));
	int op2 = Integer.parseInt(request.getParameter("op2"));
	int result = op1 + op2;
%>
<data>
	<op1 value="<%=op1%>" />
	<op2 value="<%=op2%>" />
	<result value="<%=result%>" />
</data>