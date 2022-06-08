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
        echo $points;
        echo"\n";    
        $points=$points+($data*10);
        $resultat=mysqli_query($connexion,"UPDATE Nbr_Points='$points' FROM users WHERE Pseudo='$username'");
        echo $points;
    }
    //short
    //long
?>