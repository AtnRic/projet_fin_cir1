<?php
    include "_main_tools.php";
    $functionName = $_POST['functionName'];
    $data = null;
    if(isset($_POST['functionParameters'])){
        $data = $_POST['functionParameters'];
    }
    if($functionName == 'save'){
        echo $data . ' saving...';
    }
    if($custom==true){
        $connexion=connect();
        $idpseudo=GetUserId($_COOKIE["login"]);
        $resultat=mysqli_query($connexion,"INSERT INTO custom_level VALUES (".$name.",".$theme.",".$idpseudo.",".$data.",".$custom.")");
    }
    if($custom!=true){
        $connexion=connect();
        $string_theme=GetTheme($theme);
        $random=rand(min:0,max:10001);
        $idpseudo=GetUserId($_COOKIE["login"]);
        $name="$string_theme#$random";
        $resultat=mysqli_query($connexion,"INSERT INTO custom_level VALUES (".$name.",".$theme.",".$idpseudo.",".$data.",".$custom.")");
    }
    //console: Save()
?>