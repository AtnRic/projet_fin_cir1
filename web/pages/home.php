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
<div class="header">
    <h1 class="title">Welcome to Jungle Survival</h1>
    <h2 class="title sub">Choose your level</h2>
</div>
<div class="center">
<div class="container level">
    <div class="easy but">
        <div class="tuile"></div>
        <h3>Welcome to the jungle</h3>
        <p>Easy</p>
    </div>
    <div class="medium but">
        <div class="tuile"></div>
        <h3>????</h3>
        <p>Medium</p>
    </div>
    <div class="hard but">
        <div class="tuile"></div>
        <h3>A space journey</h3>
        <p>Hard</p>
    </div>
</div>
<h2 class="title sub own">Or create your own !</h2>
<div class="container ">
    <div class="create but">
        <div class="tuile"></div>
        <h3>Your own template</h3>
    </div>
</div>
</div>

</body>