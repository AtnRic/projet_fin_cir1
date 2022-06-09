<!DOCTYPE html>
<html lang="en">
<head>
    <title>Concepteur manuel</title>
    <link rel="stylesheet" type="text/css" href="../css/custom.css">
    <link rel='icon' href='../images/front/favicon.ico' type='image/x-icon'>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
</head>
<body>
<?php
session_start()
?>
<?php
$_SESSION['customManuel']=true;
?>
<section class="back">
<div class="orbite-mars"></div>
<div class="orbite-earth"></div>
<div class="star1"></div>
<div class="star2"></div>
<div class="moon"></div>
<img src="../images/accueil/Piranha_Plant.gif" class="plant">
<img src="../images/accueil/mario-pipe.png" class="pipe">
<div id="right-side"></div>
<img src="../images/accueil/ground.png" id="ground">
<img src="../images/accueil/static-left-leaves.png" class="left">
<img src="../images/accueil/middle-left-leaf.png" id="middle">
<img src="../images/accueil/middle-left-leaf-bis.png" id="middlebis">
<img src="../images/accueil/upper-bottom-left-leaf.png" id="upper-bottom-left-leaf">
<img src="../images/accueil/bottom-left-leaf.png" id="bottom-left-leaf">
<img src="../" alt="" class="right">
<div class="forbis">
<h1>Concepteur Manuel</h1>
<div class="range">
    <form method="GET" action="ConcepteurManuelSuite2.php" class="builder">
        <p>Size</p>
        <input type="range" name="mazeSize" min="7" max="30" value="5">
        <br>
        <p>Theme</p>
        <br>
        <div>
            <select name="theme">
                <option>Jungle</option>
                <option>Retro</option>
                <option>Space</option>
            </select>
        </div>

        <br>
        <p><input type="submit" value="OK" class="valid validate"></p>
    </form>
</div>
</div>
</section>
</body>
