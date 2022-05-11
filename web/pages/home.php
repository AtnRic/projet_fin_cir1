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
<h1>Welcome to the Super Labyrinth 3000 deluxe !</h1>
<h2>Choose your level</h2>
<div class="container">
    <div class="easy">
        <div class="tuile"></div>
        <h3>Welcome to the jungle</h3>
        <p>Easy</p>
    </div>
    <div class="medium">
        <div class="tuile"></div>
        <h3>????</h3>
        <p>Medium</p>
    </div>
    <div class="hard">
        <div class="tuile"></div>
        <h3>A space journey</h3>
        <p>Hard</p>
    </div>
</div>
<h2>Or create your own !</h2>
<div class="container">
    <div class="create">
        <div class="tuile"></div>
        <h3>Your own template</h3>
    </div>
</div>

</body>