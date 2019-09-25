<<<<<<< Updated upstream
<%@ page contentType="text/html;charset=UTF-8" language="java"%>
=======
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
>>>>>>> Stashed changes
<!doctype html>
<html lang="en">
<head>
<!-- Required meta tags -->
<meta charset="utf-8">
<meta name="viewport"
	content="width=device-width, initial-scale=1, shrink-to-fit=no">
<!-- Bootstrap CSS -->
<link rel="stylesheet"
	href="//maxcdn.bootstrapcdn.com/font-awesome/4.3.0/css/font-awesome.min.css">
<link rel="stylesheet"
	href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css"
	integrity="sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO"
	crossorigin="anonymous">
<title>제품 정보</title>
<style>
.ml-auto .dropdown-menu {
	left: auto !important;
	right: 0px;
}

​
        #test_btn1 {
	margin-right: 0px;
}

​
        #test_btn2 {
	margin-left: -2px;
}

​
        #test_btn2, #test_btn1 {
	border: 0px black;
	background-color: rgba(0, 0, 0, 0);
	color: white;
	padding: 5px;
}

​
        #test_btn3, #test_btn4 {
	background-color: rgba(0, 0, 0, 0);
	color: black;
	padding: 5px;
}

​
        .the-legend {
	border-style: none;
	border-width: 0;
	font-size: 14px;
	line-height: 20px;
	margin-bottom: 0;
	width: auto;
	padding: 0 10px;
	border: 1px solid #e0e0e0;
}

​
        .the-fieldset {
	border: 1px solid #e0e0e0;
	padding: 10px;
}

​
        legend.scheduler-border {
	width: inherit; /* Or auto */
	padding: 0 10px; /* To give a bit of padding on the left and right */
	border-bottom: none;
}

​
        body>div>div>div>ul ul { /*서브메뉴 선택시 서브메뉴화면  */
	display: none;
	background: white;
	box-shadow: 1px 1px 5px black;
}

​
        #modal {
	position: relative;
	width: 100%;
	height: 100%;
	z-index: 1;
}

​
        #modal h2 {
	margin: 0;
}

​
        #modal button {
	display: inline-block;
	width: 100px;
	margin-left: calc(100% - 100px - 10px);
}

​
        #modal .modal_content {
	width: 300px;
	margin: 100px auto;
	padding: 20px 10px;
	background: #fff;
	border: 2px solid #666;
}

​
        #modal .modal_layer {
	position: fixed;
	top: 0;
	left: 0;
	width: 100%;
	height: 100%;
	background: rgba(0, 0, 0, 0.5);
	z-index: -1;
}

​
        #dropdown-box {
	dispaly: none;
}

​
        body>nav>div>ul>div>ul {
	background-color: black;
}

​
        .card-text {
	overflow: hidden;
	text-overflow: ellipsis;
	white-space: nowrap;
	width: 400px;
	height: 150px;
}

​
        body>nav>div>ul>div>ul {
	background-color: black;
}
</style>
<<<<<<< Updated upstream
<script src="./js/Chart.js"></script>
=======
<script src="js/Chart.js"></script>
>>>>>>> Stashed changes
<script src="https://code.jquery.com/jquery-3.4.1.js"></script>
<script
	src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js"
	integrity="sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49"
	crossorigin="anonymous"></script>
<script
	src="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/js/bootstrap.min.js"
	integrity="sha384-ChfqqxuZUCnJSK3+MXmPNIyE6ZbWh2IMqE241rYiqJxyMiZ6OW/JmZQ5stwEULTy"
	crossorigin="anonymous"></script>
<<<<<<< Updated upstream
<script type="text/javascript">
        $(document).ready(function () {
            // this fucntion parsing the foodinfo.xml file
                            var nutr1 = ${list.calory};
                            var nutr2 = ${list.carbo};
                            var nutr3 = ${list.protein};
                            var nutr4 = ${list.fat};
                            var nutr5 = ${list.sugar};
                            var nutr6 = ${list.natrium};
                            var nutr7 = ${list.chole};                          
                            var nutr8 = ${list.fattyacid};                           
                            var nutr9 = ${list.transfat};
=======
<script>
        $(document).ready(function () {
            // this fucntion parsing the foodinfo.xml file
                            var nutr1 = ""+${list.calory};
                            var nutr2 = ""+${list.carbo};
                            var nutr3 = ""+${list.protein};
                            var nutr4 = ""+${list.fat};
                            var nutr5 = ""+${list.sugar};
                            var nutr6 = ""+${list.natrium};
                            var nutr7 = ""+${list.chole};                          
                            var nutr8 = ""+${list.fattyacid};                           
                            var nutr9 = ""+${list.transfat};                           
                            var name = ""+${list.name};
                            var maker = ""+${list.maker};
>>>>>>> Stashed changes
                            $('#calorie').text(nutr1);
                            $('#carbohydrate').text(nutr2);
                            $('#protein').text(nutr3);
                            $('#fat').text(nutr4);
                            $('#sugars').text(nutr5);
                            $('#natrium').text(nutr6);
                            $('#cholesterol').text(nutr7);
                            $('#saturatedFattyAcids').text(nutr8);
                            $('#transFats').text(nutr9);
                            var chart_data = [nutr1, nutr2, nutr3, nutr4, nutr5, nutr6, nutr7, nutr8, nutr9];
                    
                        var ctx = document.getElementById("doughnutChart").getContext("2d");
                        var myChart = new Chart(ctx, {
                            type: 'doughnut',
                            data: {
                                labels: ["칼로리", "탄수화물", "단백질", "지방", "당류", "나트륨", "콜레스테롤",
                                    "포화 지방산", "트렌스지방"],
                                datasets: [{
                                    label: '# of Votes',
                                    data: chart_data,
                                    backgroundColor: ['rgba(255, 99, 132, 0.2)',
                                        'rgba(54, 162, 235, 0.2)',
                                        'rgba(255, 206, 86, 0.2)',
                                        'rgba(75, 192, 192, 0.2)',
                                        'rgba(153, 102, 255, 0.2)',
                                        'rgba(255, 159, 64, 0.2)',
                                        'rgba(255, 153, 255, 0.2)',
                                        'rgba(102, 0, 153, 0.2)', 'rgba(51, 0, 0, 0.2)'],
                                    borderColor: ['rgba(255, 99, 132, 1)',
                                        'rgba(54, 162, 235, 1)', 'rgba(255, 206, 86, 1)',
                                        'rgba(75, 192, 192, 1)', 'rgba(153, 102, 255, 1)',
                                        'rgba(255, 159, 64, 1)', 'rgba(255, 153, 255, 1)',
                                        'rgba(102, 0, 153, 1)', 'rgba(51, 0, 0, 1)'],
                                    borderWidth: 1
                                }]
                            },
                            options: {
                                responsive: true
                            }
<<<<<<< Updated upstream
                        })
        });
</script>
</head>
<body>
	​
=======
                        });
 
    </script>
</head>
<body>​
>>>>>>> Stashed changes
	<jsp:include page="menu_bar.jsp"></jsp:include>
	<jsp:include page="nav_bar.jsp"></jsp:include>
	<h1 class="page-title text-center">제품 정보</h1>
	<div width="100" align="center">
		<img src="./img/shopping-bag.png" width="50" />
	</div>
	<div class="container">
<<<<<<< Updated upstream

=======
	
>>>>>>> Stashed changes
		<div class="table-responsive">
			<table class="table">
				<tbody>
					<tr>
<<<<<<< Updated upstream
						<td rowspan="4" width=150><img src="${list.img }"
							width="150px"></td>
=======
						<td rowspan="4" width=150><img src="${list.img }" width="150px"></td>
>>>>>>> Stashed changes
						<td width=100>제품명</td>
						<td id="product_name">${list.name}</td>
					</tr>
					<tr>
						<td width=100>제조사</td>
						<td id="manufacturer">${list.maker}</td>
					</tr>
					<tr>
						<td width=100>원재료</td>
						<td id="Material">${list.material}</td>
					</tr>
					<tr>
						<td width=100>알레르기 성분</td>
						<td id="allergy">${list.allergy}</td>
					</tr>
				</tbody>
			</table>
		</div>
		<form class="clearfix row grid-space-10">
			<div class="form-group">
				<label>Quantity</label> <input type="text" class="form-control"
					id="qnt" name="qnt" value="1">
			</div>
		</form>
		<div class="product elements-list">
			<label> </label>
			<div class="btn-group">
				<a href="#" onclick="addIntakeFood(20)"
					class="btn btn-default btn-sm"><i class="fa fa-user pr-2"></i>
					추가</a> <a href="#" onclick="addIntakePrev(20)"
					class="btn btn-default btn-sm"><i class="fa fa-user pr-2"></i>
					찜</a>
			</div>
		</div>
	</div>
	​
	<div class="container">
		<h4 class="space-top">영양 정보</h4>
		<div class="row">
			<div class="col-sm-6">
				<canvas id="doughnutChart" height="230"></canvas>
			</div>
			<div class="col-sm-6">
				<table class="table">
					<tbody>
						<tr>
							<td width='200'>일일 제공량</td>
							<td id="daily_serving">${list.supportpereat}</td>
						</tr>
						<tr>
							<td width='200'>칼로리</td>
							<td id="calorie">${list.calory}</td>
						</tr>
						<tr>
							<td width='200'>탄수화물</td>
							<td id="carbohydrate">${list.carbo}</td>
						</tr>
						<tr>
							<td width='200'>단백질</td>
							<td id="protein">${list.protein}</td>
						</tr>
						<tr>
							<td width='200'>지방</td>
							<td id="fat">${list.fat}</td>
						</tr>
						<tr>
							<td width='200'>당류</td>
							<td id="sugars">${list.sugar}</td>
						</tr>
						<tr>
							<td width='200'>나트륨</td>
							<td id="natrium">${list.natrium}</td>
						</tr>
						<tr>
							<td width='200'>콜레스테롤</td>
							<td id="cholesterol">${list.chole}</td>
						</tr>
						<tr>
							<td width='200'>포화 지방산</td>
							<td id="saturatedFattyAcids">${list.fattyacid}</td>
						</tr>
						<tr>
							<td width='200'>트렌스지방</td>
							<td id="transFats">${list.transfat}</td>
						</tr>
					</tbody>
				</table>
			</div>
		</div>
	</div>
	<jsp:include page="footer.jsp"></jsp:include>
	<!-- Optional JavaScript -->
	<!-- jQuery first, then Popper.js, then
                Bootstrap JS -->
	​
</body>
</html>
​
