<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<head>
</head>
<body>
<div id="modal" style='display: none'>
    <div class="container">
        <div class="overlay" style="width: 100%; padding-top: 10px; border-radius: 22px 22px;">
            <form action="main.do?action=regist" method="post">
                <article class="container bg-light" style="max-width: 640px; border-radius: 10px 10px;">
                    <div class="page-header">
                        <div class="col-md-6 col-md-offset-3">
                            <br>
                            <h3>회원가입</h3>
                        </div>
                    </div>
                    <div class="form-group has-feedback row">
                        <label for="inputName" class="col-md-3 control-label text-md-right col-form-label">아이디
                            <span class="text-danger small">*</span>
                        </label>
                        <div class="col-md-8">
                            <input type="text" class="form-control" id="inputName" placeholder="" required name="id">
                        </div>
                    </div>
                    <div class="form-group has-feedback row">
                        <label for="inputLastName" class="col-md-3 control-label text-md-right col-form-label">비밀번호
                            <span class="text-danger small">*</span>
                        </label>
                        <div class="col-md-8">
                            <input type="text" class="form-control" id="inputLastName" placeholder="영문 숫자 포함 6자리 이상"
                                   required name="pw">
                        </div>
                    </div>
                    <div class="form-group has-feedback row">
                        <label for="inputUserName" class="col-md-3 control-label text-md-right col-form-label">이름
                            <span class="text-danger small">*</span>
                        </label>
                        <div class="col-md-8">
                            <input type="text" class="form-control" id="inputUserName" placeholder="User Name" required
                                   name="name">
                        </div>
                    </div>
                    <div class="form-group has-feedback row">
                        <label for="inputEmail" class="col-md-3 control-label text-md-right col-form-label">주소
                            <span class="text-danger small">*</span>
                        </label>
                        <div class="col-md-8">
                            <input type="text" class="form-control" id="inputEmail" placeholder="address" required
                                   name="addr">
                        </div>
                    </div>
                    <div class="form-group has-feedback row">
                        <label for="inputPassword" class="col-md-3 control-label text-md-right col-form-label">전화번호
                            <span class="text-danger small">*</span>
                        </label>
                        <div class="col-md-8">
                            <input type="text" class="form-control" id="inputPassword" placeholder="010-xxx-xxxx"
                                   required
                                   name="tel">
                        </div>
                    </div>
                    <div class="form-group has-feedback row">
                        <label for="inputPassword" class="col-md-3 control-label text-md-right col-form-label">알레르기
                            <span class="text-danger small">*</span>
                        </label>

                        <div class="col-md-8">
                            <fieldset class="the-fieldset">
                                <legend class="the-legend"> Check</legend>
                                <div class="row">
                                    <div class="col-sm-10">
                                        <div class="form-check form-check-inline">
                                            <input name="allergy" class="form-check-input"
                                                   type="checkbox" value="대두"> <label
                                                class="form-check-label">대두 </label>
                                        </div>
                                        <div class="form-check form-check-inline">
                                            <input name="allergy" class="form-check-input"
                                                   type="checkbox" value="땅콩"> <label
                                                class="form-check-label">땅콩 </label>
                                        </div>
                                        <div class="form-check form-check-inline">
                                            <input name="allergy" class="form-check-input"
                                                   type="checkbox" value="우유"> <label
                                                class="form-check-label">우유 </label>
                                        </div>
                                        <div class="form-check form-check-inline">
                                            <input name="allergy" class="form-check-input"
                                                   type="checkbox" value="게"> <label class="form-check-label">게</label>
                                        </div>
                                        <div class="form-check form-check-inline">
                                            <input name="allergy" class="form-check-input"
                                                   type="checkbox" value="새우"> <label
                                                class="form-check-label">새우</label>
                                        </div>
                                        <div class="form-check form-check-inline">
                                            <input name="allergy" class="form-check-input"
                                                   type="checkbox" value="참치"> <label
                                                class="form-check-label">참치</label>
                                        </div>
                                        <div class="form-check form-check-inline">
                                            <input name="allergy" class="form-check-input"
                                                   type="checkbox" value="연어"> <label
                                                class="form-check-label">연어</label>
                                        </div>
                                        <div class="form-check form-check-inline">
                                            <input name="allergy" class="form-check-input"
                                                   type="checkbox" value="쑥"> <label class="form-check-label">쑥 </label>
                                        </div>
                                        <div class="form-check form-check-inline">
                                            <input name="allergy" class="form-check-input"
                                                   type="checkbox" value="소고기"> <label
                                                class="form-check-label">소고기</label>
                                        </div>
                                        <div class="form-check form-check-inline">
                                            <input name="allergy" class="form-check-input"
                                                   type="checkbox" value="닭고기"> <label
                                                class="form-check-label">닭고기 </label>
                                        </div>
                                        <div class="form-check form-check-inline">
                                            <input name="allergy" class="form-check-input"
                                                   type="checkbox" value="돼지고기"> <label
                                                class="form-check-label">돼지고기</label>
                                        </div>
                                        <div class="form-check form-check-inline">
                                            <input name="allergy" class="form-check-input"
                                                   type="checkbox" value="복숭아"> <label
                                                class="form-check-label">복숭아 </label>
                                        </div>
                                        <div class="form-check form-check-inline">
                                            <input name="allergy" class="form-check-input"
                                                   type="checkbox" value="민들레"> <label
                                                class="form-check-label">민들레</label>
                                        </div>

                                        <div class="form-check form-check-inline">
                                            <input name="allergy" class="form-check-input"
                                                   type="checkbox" value="계란흰자"> <label
                                                class="form-check-label">계란흰자 </label>
                                        </div>
                                    </div>
                                    <br>
                                </div>
                            </fieldset>
                        </div>
                    </div>
                    <div class="form-group text-center">
                        <button type="submit" id="modal_close_btn" class="btn btn-primary">
                            등록<i class="fa fa-check spaceLeft"></i>
                        </button>
                        <br>
                    </div>
            </form>
            <br>
            </article>
        </div>
        <br>
    </div>
</div>
</body>