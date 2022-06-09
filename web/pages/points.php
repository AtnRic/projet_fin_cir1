<?php
    include "../tools/_main_tools.php";
    $functionName = $_POST['functionName'];
    $data = null;
    if(isset($_POST['functionParameters'])){
        $data = $_POST['functionParameters'];
    }
    //si la fonction finish est appeler en js (utilisateur finie arrive sur la case de fin) on rajoute en php (taille du labyrinthe x 10) points a l'utilisateur connectée
    if($functionName == 'finish'){
        $connexion=connect();
        $username=$_COOKIE["login"];
        $points=GetUserPoints($_COOKIE["login"]);
        echo"\npoints de départ user :\n";
        echo $points;
        $points=$points+($data*10);
        echo"\npoints de fin user :\n";
        echo $points;
        //si l'utilisateur effectue le chemin le plus court il reçoit 300 points en plus que les points de base
        if($functionName == 'short'){
            $points+=300;
            echo"\nSHORT !!!\n";
        }
        //si l'utilisateur effectue le chemin le plus long il reçoit 300 points en plus que les points de base
        if($functionName == 'long'){
            $points+=300;
            echo"\nLONG !!!\n";
        }
        $resultat=mysqli_query($connexion,"UPDATE users SET Nbr_Points='$points' WHERE Pseudo='$username'");
    }
    
    /*if($functionName == 'short'){
        $connexion=connect();
        $username=$_COOKIE["login"];
        //récupére dans la base les points de l'utilisateur
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
        //récupére dans la base les points de l'utilisateur
        $points=GetUserPoints($_COOKIE["login"]);
        $points=$points+($data*10)+300;
        echo"\npoints de départ user :\n";
        echo $points;
        echo"\npoints de fin user :\n";
        echo $points;
        echo"\nLONG !!!\n";
        $resultat=mysqli_query($connexion,"UPDATE users SET Nbr_Points='$points' WHERE Pseudo='$username'");
    }*/
?>