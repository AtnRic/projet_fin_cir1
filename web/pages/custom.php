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
    if (isset($_POST['mazeSize']) && isset($_POST['nbrGuard']) && isset($_POST['nbrTP']) && isset($_POST['theme'])){
      $mazeSize = $_POST['mazeSize']; 
      $nbrGuard = $_POST['nbrGuard']; 
      $nbrTP = $_POST['nbrTP']; 
      $theme = $_POST['theme'];

      $customMaze = array($mazeSize, $nbrGuard, $nbrTP, $theme);

      $path = './dataCustomMaze.csv';
      $file = fopen($path, 'w');
      fputcsv($file, $customMaze);
    }
  ?>
  <section class="back">
    <div class="moon"></div>
    <img src="../images/accueil/static-left-leaves.png" class="left">
    <img src="../" alt="" class="right">
    <!-- <div id="right"></div> -->
    <div class="range">
      <form method="POST" action="custom.php" class="builder">
        <p>Size</p>
        <input type="range" name="mazeSize" min="5" max="30" value="5">
        <br>
        <p>Guards</p>
        <input type="range" name="nbrGuard" min="0" max="10" value="0">
        <br>
        <p>Teleporters</p>
        <input type="range" name="nbrTP" min="0" max="5" value="0">
        <br>
        <label>Theme</label>
        <select name="theme">
          <option>Jungle</option>
          <option>Retro</option>
          <option>Space</option>
        </select>
        <br>
        <input type="submit" value="Generate">
      </form>
    </div>
  </section>
  <div class="title">
    <h1>Welcome to the level maker  </h1>
    <p>Here you can create your own maze</p>
  </div>

</body>