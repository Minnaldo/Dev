<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<!DOCTYPE html>
<meta charset="UTF-8">
<head>
    <title>View Detail</title>
    <style>
        h1 {
            text-align: center;
        }

        div {
            width: 50%;
            margin: auto;
        }

        .ccc {
            width: 40%;
            margin: auto;
            text-align: center;
        }

        .aaa {
            width: 25%;
            margin: auto;
            background-color: lightgray;
            text-align: center;
            font-weight: bold;
            display: inline-block;
        }

        #upfrm {
            width: 50%;
            margin: auto;
        }
    </style>
    <script>
        function update() {
            upfrm.submit();
        }

        function back() {
            location.href = 'main.do?action=list'
        }

        function remove() {
            location.href = 'main.do?action=remove&id=${product.id}'
        }
    </script>
</head>
<body>
<div class="bbb">
    <div><h1>${product.name}</h1></div>

    <form action="main.do?action=update" method="post" id="upfrm">
        <div class="aaa">상품 번호</div>
        <input value="${product.id}" name="id" readonly><br>
        <div class="aaa">상품 명</div>
        <input value="${product.name}" name="name"><br>
        <div class="aaa">상품가 격</div>
        <input value="${product.price}" name="price"><br>
        <div class="aaa">상품 재고</div>
        <input value="${product.stock}" name="stock"><br>
        <div class="aaa">기타</div>
        <input value="${product.description}" name="description"><br>
    </form>

</div>
<br>
<div class="ccc">
    <input type="button" value="돌아가기" onclick="back()">
    <input type="button" value="상품 삭제" onclick="remove()">
    <input type="button" value="상품 수정" onclick="update()">
</div>
</body>
</html>
