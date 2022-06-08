<?php
    include "../tools/_main_tools.php";
    $functionName = $_POST['functionName'];
    $data = null;
    if(isset($_POST['functionParameters'])){
        $data = $_POST['functionParameters'];
    }
    if($functionName == 'finish'){
        $connexion=connect();
        $username=$_COOKIE["login"];
        $points=GetUserPoints($_COOKIE["login"]);
        echo"\npoints de départ user :\n";
        echo $points;
        $points=$points+($data*10);
        echo"\npoints de fin user :\n";
        echo $points;
        /*if($functionName == 'short'){
            $points+=300;
            echo"\nSHORT !!!\n";
        }
        if($functionName == 'long'){
            $points+=300;
            echo"\nLONG !!!\n";
        }*/
        $resultat=mysqli_query($connexion,"UPDATE users SET Nbr_Points='$points' WHERE Pseudo='$username'");
    }
    if($functionName == 'short'){
        $connexion=connect();
        $username=$_COOKIE["login"];
        $points=GetUserPoints($_COOKIE["login"]);
        $points=$points+($data*10)+300;
        echo"\npoints de départ user :\n";
        echo $points;
        echo"\npoints de fin user :\n";
        echo $points;
        echo"\nSHORT !!!\n";
        $resultat=mysqli_query($connexion,"UPDATE users SET Nbr_Points='$points' WHERE Pseudo='$username'");
    }
    if($functionName == 'long'){
        $connexion=connect();
        $username=$_COOKIE["login"];
        $points=GetUserPoints($_COOKIE["login"]);
        $points=$points+($data*10)+300;
        echo"\npoints de départ user :\n";
        echo $points;
        echo"\npoints de fin user :\n";
        echo $points;
        echo"\nLONG !!!\n";
        $resultat=mysqli_query($connexion,"UPDATE users SET Nbr_Points='$points' WHERE Pseudo='$username'");
    }
?>