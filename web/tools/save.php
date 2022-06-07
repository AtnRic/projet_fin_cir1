<?php
    include "_main_tools.php";
    $functionName = $_POST['functionName'];
    $data = null;
    if(isset($_POST['functionParameters'])){
        $data = $_POST['functionParameters'];
    }
    if($functionName == 'save'){
        echo $data[0] . $data[1] .' saving...';
    }
    $idpseudo=GetUserId($_SESSION['login']);
    $theme=$data[1];
    //niveau random
    if($custom=='false'){
        $string_theme=GetTheme($theme);
        $connexion=connect();
        $random=rand(min:0,max:10001);
        $name="$string_theme#$random";
        echo $data;
        echo $name;
        echo $idpseudo;
        echo $theme;
        echo $custom;
        $resultat=mysqli_query($connexion,"INSERT INTO custom_level VALUES (".$name.",".$theme.",".$idpseudo.",".$data.",".$custom.")");
    }
    //niveau custom
    if($custom=='true'){
        $connexion=connect();
        $resultat=mysqli_query($connexion,"INSERT INTO custom_level VALUES (".$name.",".$theme.",".$idpseudo.",".$data.",".$custom.")");
        }
    //console: Save()
?>