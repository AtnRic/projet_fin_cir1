<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <title>retro - Maze'ltov</title>
    <link rel="stylesheet" type="text/css" href="../css/retro.css">
    <link rel='icon' href='../images/front/favicon.ico' type='image/x-icon'>
    <link rel="stylesheet" type="text/css" href="../css/overlay.css">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
</head>

<body>
<div class="two sline"></div>
<div class="global">
    <table id="container"></table>
</div>
<?php
include '../tools/_main_tools.php';
include 'popups/popup_intro_retro.php';
include 'popups/popup_win_retro.php';
include 'popups/popup_lose_retro.php';
include 'overlay.html';
?>
</body>
<div class="preload" style="display: none"><img rel="preload" loading="eager" src="../images/retro/retro.png" alt=""></div>
<script src="../js/conf.js"></script>
<script src="https://code.jquery.com/jquery-3.1.1.min.js" integrity="sha256-hVVnYaiADRTO2PzUGmuLJr8BLUSjGIZsDYGmIJLv2b8=" crossorigin="anonymous"></script>
<script src="../js/node_modules/animejs/lib/anime.min.js"></script>
<script src="../js/main.js"></script>
<script>
    SetAmbiance("Retro");
</script>
<?php
if(isset($_GET["customManuel"])){
    $custom=false;
    $idpseudo=$_GET["ID_AUTHOR"];
    $level_name=$_GET["NAME"];
    $connexion=connect();
    $resultat=mysqli_query($connexion,"SELECT DATA FROM custom_level WHERE ID_AUTHOR='$idpseudo' AND NAME='$level_name'");
    while($ligne=mysqli_fetch_assoc($resultat)){
        $data=$ligne["DATA"];
    }
    ?>
    <script>
        console.log("C'est bon");
        Manuel=true;
        PHP_Start(false, false, null);
    </script>
    <?PHP
}
else {?>
<script>console.log("La poire");</script>
<?php
    if($_GET["custo"]==1){
        $custom=true;
        $idpseudo=$_GET["ID_AUTHOR"];
        $level_name=$_GET["NAME"];
        $connexion=connect();
        $resultat=mysqli_query($connexion,"SELECT DATA FROM custom_level WHERE ID_AUTHOR='$idpseudo' AND NAME='$level_name'");
        while($ligne=mysqli_fetch_assoc($resultat)){
            $data=$ligne["DATA"];
        }
        ?>
        <script>
            PHP_Start(false, true, '<?php echo $data; ?>');
        </script>
    <?php
    }
    if($_GET["custo"]==0){
    ?>
        <script>
            PHP_Start(false, false, null);
        </script>
    <?php
    }
}
    ?>




</html>