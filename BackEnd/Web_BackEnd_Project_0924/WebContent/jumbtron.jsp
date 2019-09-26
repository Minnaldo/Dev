<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<!-- title -->
<div class="jumbotron jumbotron-fluid bg-secondary" style='margin-bottom:0%'>
    <div class="container text-center" style="color:white">
        <h1>WHAT WE PROVIDE</h1>
        <div class="seperator"></div>
        <p>건강한 삶을 위한 먹거리 프로젝트</p>
    </div>
</div>
<!-- search bar -->
<div class="jumbotron jumbotron-fluid bg-dark">
    <div class="container bg-dark">
        <form action = "main.do">
            <div class="row">
                <div class="col-md-3">
                    <div class="row">
                    </div>
                    <div class="row">
                        <label style='color : #aaa; margin-left:2%'>검색 조건</label>
                        <select name ="s_condition" class="form-control"
                                style='background-color : #555; color : #ddd; margin-left:3%; margin-right:3%'>
                            <option>상품명</option>
                            <option>제조사</option>
                            <option>재료명</option>
                        </select>
                    </div>
                </div>
                <div class="col-md-9">
                    <div class="row">
                        <label style='color : #aaa; margin-left:2%'>검색 단어</label>
                    </div>
                    <div class="row">
                        <div class="col-md-11">
                            <input name="search" class="form-control mr-sm-2" type="search"
                                   placeholder="Search" aria-label="Search"
                                   style='background-color : #555; color : #ddd'>
                        </div>
                        <div class="col-md-1">
                            <input value="search" name="action" style="display:none;">
                            <button type="submit" class="btn btn-outline-secondary my-2 my-sm-0">Search</button>
                        </div>

                    </div>
                </div>
            </div>
        </form>
    </div>
</div>
<div class="container-fluid bg-3 text-center"></div>

</body>
</html>
