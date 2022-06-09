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
        echo $_COOKIE["login"];
        $theme=$data[1];
        $pseudo = $_COOKIE["login"];
        //niveau random
        if(empty($_SESSION["custom"])){
            $string_theme=GetTheme($data[1]);
            echo $string_theme;
            $connexion=connect();
            $random=rand(min:0,max:10001);
            $name="$string_theme#$random";
            $custom=0;
            echo "\nid pseudo\n";
            echo $idpseudo;
            echo "\nnom level\n";
            echo $name;
            echo "\ntheme:\n";
            echo $theme;
            echo "\ndata\n";
            echo $data[0];
            echo "\ncustom\n";
            if($custom==false){
                echo"nono";
            }
            else{
                echo"yesyes";
            }
            if(!$connexion){
                echo 'ERROR';
                echo mysqli_error($connexion);
            }
            $d = $data[0];
            $resultat = mysqli_query($connexion, "INSERT INTO `custom_level` (`NAME`, `THEME`, `ID_AUTHOR`, `DATA`, `CUSTOM`, `AUTHOR`) VALUES ('$name','$theme','$idpseudo','$d','0', '$pseudo');");
            echo $resultat;
        }
        //niveau custom
        if(isset($_SESSION["custom"])){
            $connexion=connect();
            $custom=true;
            $name = $_SESSION['name'];
            $sessionCustom = $_SESSION["custom"];
            $resultat = mysqli_query($connexion, "INSERT INTO `custom_level` (`NAME`, `THEME`, `ID_AUTHOR`, `DATA`, `CUSTOM`, `AUTHOR`) VALUES ('$name','$theme','$idpseudo','$data[0]','$sessionCustom', '$pseudo');");
            echo "-_-custom true-_-";
            unset($_SESSION['custom']);
        }
        //console: Save()
    }
?>