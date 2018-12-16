<?php

    if(isset($_POST["Token"]) ){

        $token = $_POST["Token"];

        include_once 'config.php';

        $query = "INSERT INTO users VALUES ('$token') ON DUPLICATE KEY UPDATE Token = '$token';";

        $conn = mysqli_connect(DB_HOST, DB_USER, DB_PSW, DB_NAME);

        mysqli_query($conn, $query) or die (mysqli_error($conn));

        mysqli_close($conn);
        echo "=========================Success==========================";
    }else {
        echo "failed";
    }
 ?>
