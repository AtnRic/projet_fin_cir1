<?php
    include "../tools/_main_tools.php";
    $functionName = $_POST['functionName'];
    $data = null;
    if(isset($_POST['functionParameters'])){
        $data = $_POST['functionParameters'];
    }
    if($functionName == 'save'){
        echo $data[0] . $data[1] .' saving...';
        $idpseudo=GetUserId($_COOKIE["login"]);
        $theme=$data[1];
        //niveau random
        if(empty($_SESSION["custom"])){
            $string_theme=GetTheme($data[1]);
            $connexion=connect();
            $random=rand(min:0,max:10001);
            $name="$string_theme#$random";
            if(!$connexion){
                echo 'ERROR';
                echo mysqli_error($connexion);
            }
            $d = $data[0];
            $resultat = mysqli_query($connexion, "INSERT INTO `custom_level` (`NAME`, `THEME`, `ID_AUTHOR`, `DATA`, `CUSTOM`) VALUES ('$name','$theme','$idpseudo','$d','0');");
            echo $resultat;
        }
        //niveau custom
        if(isset($_SESSION["custom"])){
            $connexion=connect();
            $name=$_SESSION["name"];
            $theme=$_SESSION["theme"];
            $d = $data[0];
            echo $name;
            echo $theme;
            echo $d;
            echo $idpseudo;
            $resultat = mysqli_query($connexion, "INSERT INTO `custom_level` (`NAME`, `THEME`, `ID_AUTHOR`, `DATA`, `CUSTOM`) VALUES ('$name','$theme','$idpseudo','$d','1');");
            echo "\n-_-custom true-_-\n";
            unset($_SESSION['custom']);
            unset($_SESSION['theme']);
            unset($_SESSION['name']);
        }
        //console: Save()
    }
?>