<%@ page import="edu.ssafy.model.MemVO" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<!DOCTYPE html>
<%
    MemVO m = (MemVO) request.getAttribute("mem");
%>
<html>
<head>
    <title>회원 정보 조회</title>
    <script>
        function updateMem() {
            frm.submit();
        }

        function deleteMem() {
            var id = document.getElementById("id").value;
            location.href = "./main.do?action=deletemem&id=" + id;
        }
    </script>
</head>
<body>
<div align="center">
    <h1>회원 정보</h1>
    <form action="./main.do?action=updatemem" method="post" id="frm">
        <table>
            <tr>
                <td>이름 :</td>
                <td><input type="text" name="name" id="name" readonly="readonly" value="<%=m.getName()%>"></td>
            </tr>
            <tr>
                <td>아이디 :</td>
                <td><input type="text" name="id" id="id" value="<%=m.getId()%>"></td>
            </tr>
            <tr>
                <td>주소 :</td>
                <td><input type="text" name="addr" id="addr" value="<%=m.getAddr()%>"></td>
            </tr>
            <tr>
                <td>나이 :</td>
                <td><input type="number" name="age" id="age" value="<%=m.getAge()%>"></td>
            </tr>
            <tr>
                <td>전화번호 :</td>
                <td><input type="tel" name="tel" id="tel" value="<%=m.getTel()%>"></td>
            </tr>
            <tr>
                <td colspan="2" style="text-align: center">
                    <input type="button" value="수정" onclick="updateMem()">
                    <input type="button" value="삭제" onclick="deleteMem()">
                </td>
            </tr>
        </table>
    </form>
</div>
</body>
</html>
