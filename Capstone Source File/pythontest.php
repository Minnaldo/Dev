<?php
//환경변수내 파이썬 실행파일 경로
$python = "C:/Users/User/AppData/Local/Programs/Python/Python36/python.exe";
$pythonScript = "C:/Users/User/Desktop/CapstoneProject/classify.py";
//파이썬 실행파일 경로 + .py 파일 경로
$cmd = shell_exec($python." ".$pythonScript);
echo $cmd;
if($cmd){
    echo "<br></br>";
    echo "Success";
}else {
    echo "Fail";
}
 ?>
