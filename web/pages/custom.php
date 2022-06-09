<?php
session_start()
?>
<!DOCTYPE html>
<html lang='fr'>

<?php
$pageName="Custom Page"; //le nom de la page
$cssPath = "custom.css";

require '../tools/header.php';
require '../tools/_main_tools.php';
?>

<body>
  <?php
  //&& isset($_POST["Maze_Name"])
    $_SESSION['custom']=true;
    if (isset($_POST['mazeSize']) && isset($_POST['nbrGuard']) && isset($_POST['nbrTP']) && isset($_POST['theme'])){
        echo Console("<p>Erreur d'exécution de la requete </p>");
        $_SESSION["name"]=$_POST["levelname"];
        $_SESSION["mazeSize"] = $_POST['mazeSize'];
        $_SESSION["nbrGuard"] = $_POST['nbrGuard'];
        $_SESSION["nbrTP"] = $_POST['nbrTP'];
        $_SESSION["theme"] = $_POST['theme'];
        switch($_SESSION["theme"]){
            case('Jungle'): $_SESSION["theme"] = 1; break;
            case('Retro'): $_SESSION["theme"] = 2; break;
            case('Space'): $_SESSION["theme"] = 3; break;
        }

        $customMaze = array(
            array($_SESSION["mazeSize"]),
            array($_SESSION["nbrTP"]),
            array($_SESSION["nbrGuard"]),
            array($_SESSION["theme"])
        );

        $path = './dataCustomMaze.csv';
        if ($file = @fopen('../tools/DonneesLabyrinthe.csv', 'w')) {
            foreach ($customMaze as $ligne) {
                fputcsv($file, $ligne);
            }
            fclose($file);
        }
        switch($_SESSION["theme"]){
        case 1: header('Location: jungle.php'); break;
        case 2: header('Location: retro.php'); break;
        case 3: header('Location: space.php'); break;
        }

    }
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
    <!-- <div id="right"></div> -->
    <div class="range">
      <form method="post" action="custom.php" class="builder">
        <p>Level name:</p>
        <input type="text" name="levelname" min="1" max="20" placeholder="Level Name" required>
        <p>Size</p>
        <input type="range" name="mazeSize" min="7" max="30" value="5">
        <br>
        <p>Guards</p>
        <input type="range" name="nbrGuard" min="1" max="10" value="0">
        <br>
        <p>Teleporters</p>
        <input type="range" name="nbrTP" min="1" max="4" value="0">
        <br>
        <label>Theme</label>
        <select name="theme">
          <option>Jungle</option>
          <option>Retro</option>
          <option>Space</option>
        </select>
        <br>
        <input class="valid validate" type="submit" name="customgo" value="Generate">
      </form>
    </div>
  </section>
  <div class="title">
    <h1>Welcome to the level maker  </h1>
    <p>Here you can create your own maze</p>
  </div>
  <a href="home.php" id="to-home">Home</a>
  
</body>