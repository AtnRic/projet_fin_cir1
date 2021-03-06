<!DOCTYPE html>
<html lang='fr'>

<!--le header se trouve dans le fichier header.php-->
<?php
$pageName="Home"; //le nom de la page
$cssPath = "home.css";

require '../tools/header.php';
require '../tools/_main_tools.php';
?>
<body>
<section id="jungle">
        <!-- Left Side -->
        <img src="../images/accueil/ground.png" id="ground">
        <img src="../images/accueil/static-left-leaves.png" id="left-leaves">
        <img src="../images/accueil/middle-left-leaf.png" id="middle">
        <img src="../images/accueil/middle-left-leaf-bis.png" id="middlebis">
        <img src="../images/accueil/upper-bottom-left-leaf.png" id="upper-bottom-left-leaf">
        <img src="../images/accueil/bottom-left-leaf.png" id="bottom-left-leaf">
        <!-- Sun Object -->
        <div id="sun"></div>
        <!-- Right Side -->
        <img src="../images/accueil/right-leaves-static.png" id="right-leaves">
        <img src="../images/accueil/bottom-right-leaf-bis.png" alt="" id="bottom-right-leaf-bis">
        <img src="../images/accueil/bottom-right-leaves.png" id="bottom-right-leaf">
        <img src="../images/accueil/middle-right-leaf-bis.png" id="middle-right-leaf-bis">
        <img src="../images/accueil/middle-right-leaf.png" id="middle-right-leaf">
        <img src="../images/accueil/side-palm-right.png" id="palm-right">
        <img src="../images/accueil/left-palm.png" id="palm-left">
        <img src="../images/accueil/top-palm.png" id="top-palm">
        <div class="button" id="jungle-but">
            <h3 class="name">Welcome to the jungle</h3>
            <p class="level">Easy</p>
        </div>
        <a href="#mario" class="next 8bit">Next level</a>
    </section>
    <section id="mario">
        <div id="mario-cloud1"></div>
        <div id="mario-cloud2"></div>
        <div class="marioground"></div>
        <div id="mario-animated"></div>
        <img src="../images/accueil/mario-mystery-box.gif" id="mystery-boxe">
        <div class="upper-roof"></div>
        <img src="../images/accueil/mario-pipe.png" id="mario-pipe1">
        <img src="../images/accueil/mario-pipe.png" id="mario-pipe2">
        <img src="../images/accueil/mario-coin.gif" id="mario-coin">
        <div class="button" id="but-mar">
            <h3 class="name">The amazing Spider-man</h3>
            <p class="level">Medium</p>
        </div>
        <!-- <a href="#craft" class=""></a> -->
    </section>
    <section id="space">
        <div class="orbite_earth"></div>
        <div class="orbite_mars"></div>
        <div class="iss"></div>
        <!-- <img src="../images/accueil/ISS.png" id="iss"> -->
        <!-- <img src="../images/accueil/earth.png" id="earth"> -->
    </section>
    <div class="title">
        <h1>Welcome to Maze'ltov</h1>
        <p>Choose your level</p>
    </div>
<!-- <h2 class="title sub own">Or create your own !</h2> -->
</body>
</html>