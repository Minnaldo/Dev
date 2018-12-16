<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8"/>
    <title>Private Page</title>
</head>
<body>
    <?php
        $python = "C:/Users/alban/AppData/Local/Programs/Python/Python36/python.exe";
        $pythonScript = "C:/Bitnami/wampstack-7.1.11-0/apache2/htdocs/test.py";
if(isset($_POST['user_token'])){
        $usertoken = $_POST['user_token'];
}else {
    echo "failed, check token seding";
}


        $file_path = "C:/Users/User/Desktop/CapstoneProject/uploads/";
        $file_path2 = $file_path;

        $file_path = $file_path . basename( $_FILES['uploaded_file']['name']);

        $tokenfile = fopen($file_path2."userToken.txt","w");
        fwrite($tokenfile,$usertoken);
        fclose($tokenfile);
        //move_uploaded_file -> 리턴값 boolean
        if(move_uploaded_file($_FILES['uploaded_file']['tmp_name'], $file_path)) {
            //파일 업로드 및 이동 성공
            $cmd = shell_exec($python." ".$pythonScript);
            if($cmd){
                print_r($cmd);
            }
        } else{
            //파일 업로드 및 이동 실패
            echo "fail";
        }
     ?>
</body>
</html>
