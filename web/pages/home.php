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
        <a href="?MazeSize=15&nbrTP=4&nbrGuard=4&theme=2">
        <?php
            if(isset($_SESSION["custom"])){
              $_SESSION["custom"]=false;
            }
            if(isset($_GET['MazeSize']) && isset($_GET['nbrTP']) && isset($_GET['nbrGuard']) && isset($_GET['theme'])){
                $mazeSize = $_GET['MazeSize'];
                $nbrTP = $_GET['nbrTP'];
                $nbrGuard = $_GET['nbrGuard'];
                $theme = $_GET['theme'];
                $customMaze = array(
                    array($mazeSize),
                    array($nbrTP),
                    array($nbrGuard),
                    array($theme)
                  );
               
                  $path = './dataCustomMaze.csv';
                  if ($file = @fopen('../tools/DonneesLabyrinthe.csv', 'w')) {
                    foreach ($customMaze as $ligne) {
                      fputcsv($file, $ligne);
                    }
                    fclose($file);
                    header("Location:jungle.php?custo=0");
                  }
                  else header("Location:home.php");

            }
            ?>
            <div class="button" id="jungle-but">
                <h3 class="name">Welcome to the jungle</h3>
                <p class="level">Easy</p>
            </div>
        </a>
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
        <a href="?MAzeSize=20&nbrTP=4&nbrGuard=4&theme=2">
            <?php
            if(isset($_GET['MAzeSize']) && isset($_GET['nbrTP']) && isset($_GET['nbrGuard']) && isset($_GET['theme'])){
                $mazeSize = $_GET['MAzeSize'];
                $nbrTP = $_GET['nbrTP'];
                $nbrGuard = $_GET['nbrGuard'];
                $theme = $_GET['theme'];
                $customMaze = array(
                    array($mazeSize),
                    array($nbrTP),
                    array($nbrGuard),
                    array($theme)
                  );
               
                  $path = './dataCustomMaze.csv';
                  if ($file = @fopen('../tools/DonneesLabyrinthe.csv', 'w')) {
                    foreach ($customMaze as $ligne) {
                      fputcsv($file, $ligne);
                    }
                    fclose($file);
                    header("Location:retro.php?custo=0");
                  }
                  else header("Location:home.php");

            }
            ?>
            <div class="button" id="but-mar">
                <h3 class="name">Tartaros fantasy</h3>
                <p class="level">Medium</p>
        </div>
        </a>
        <a href="#space" id="to-space">Next level</a>
    </section>
    <section id="space">
        <div class="star1"></div>
        <div class="star2"></div>
        <div class="star3"></div>
        <div class="orbite_earth"></div>
        <div class="orbite_mars"></div>
        <div id="iss"></div>
        <div class="ufo"></div>
        <a href="?mazeSize=35&nbrTP=10&nbrGuard=10&theme=3">
        <?php
            if(isset($_GET['mazeSize']) && isset($_GET['nbrTP']) && isset($_GET['nbrGuard']) && isset($_GET['theme'])){
                $mazeSize = $_GET['mazeSize'];
                $nbrTP = $_GET['nbrTP'];
                $nbrGuard = $_GET['nbrGuard'];
                $theme = $_GET['theme'];
                $customMaze = array(
                    array($mazeSize),
                    array($nbrTP),
                    array($nbrGuard),
                    array($theme)
                  );
               
                  $path = './dataCustomMaze.csv';
                  if ($file = @fopen('../tools/DonneesLabyrinthe.csv', 'w')) {
                    foreach ($customMaze as $ligne) {
                      fputcsv($file, $ligne);
                    }
                    fclose($file);
                    header("Location:space.php?custo=0");
                  }
                  else header("Location:home.php");
            }
            ?>
        <div class="button" id="but-space">
                <h3 class="name">A Grand Day Out</h3>
                <p class="level">Hard</p>
        </div>
        </a>
    </section>
    <div class="title">
        <h1>Welcome to Maze'ltov</h1>
        <p>Choose your level</p>
    </div>
    <a href="custom.php" id="to-custom">Custom</a>
<!-- <h2 class="title sub own">Or create your own !</h2> -->
</body>
</html>