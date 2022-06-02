<!DOCTYPE html>
<html lang='fr'>

<head>
  <title>Maze'ltov - customisation</title>
  <link rel="stylesheet" type="text/css" href="../css/custom.css">
  <link rel='icon' href='../images/front/favicon.ico' type='image/x-icon'>
</head>

<body>
  <?php
    if (isset($_POST['mazeSize']) && isset($_POST['nbrGuard']) && isset($_POST['nbrTP']) && isset($_POST['theme'])){
      $mazeSize = $_POST['mazeSize']; 
      $nbrGuard = $_POST['nbrGuard']; 
      $nbrTP = $_POST['nbrTP']; 
      $theme = $_POST['theme'];
      switch($theme){
        case('Jungle'): $theme = 1; break;
        case('Retro'): $theme = 2; break;
        case('Space'): $theme = 3; break;
      }

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
    }
  }
  ?>
  <div class="title">
    <h1>Welcome to the sandbox</h1>
    <h4>Here you can create your own maze</h4>
  </div>
  <div class="range">
    <!--[X] : valeur qui changera selon la position du curseur-->
    <form method="POST" action="./custom.php">
      <label>Size of the maze : [X]</label>
      <input type="range" name="mazeSize" min="5" max="30" value="5">
      <br>
      <label>Number of guards : [X]</label>
      <input type="range" name="nbrGuard" min="0" max="10" value="0">
      <br>
      <label>Number of teleporter pairs : [X]</label>
      <input type="range" name="nbrTP" min="0" max="5" value="0">
      <br>
      <label>Select the theme :</label>
      <select name="theme">
        <option>Jungle</option>
        <option>Retro</option>
        <option>Space</option>
      </select>
      <br>
      <input type="submit" value="Generate">
    </form>
  </div>

</body>