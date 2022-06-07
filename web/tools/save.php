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
    //niveau custom
    if($custom==true){
        $connexion=connect();
        $idpseudo=GetUserId($_COOKIE["login"]);
        $resultat=mysqli_query($connexion,"INSERT INTO custom_level VALUES (".$name.",".$theme.",".$idpseudo.",".$data.",".$custom.")");
    }
    //niveau random
    if($custom==false){
        $theme=$_GET['theme'];
        $custom=$_GET['custom'];
        $connexion=connect();
        $random=rand(min:0,max:10001);
        $idpseudo=GetUserId($_COOKIE["login"]);
        $name="$string_theme#$random";
        $resultat=mysqli_query($connexion,"INSERT INTO custom_level VALUES (".$name.",".$theme.",".$idpseudo.",".$data.",".$custom.")");
    }
    //console: Save()
?>