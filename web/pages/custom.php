<!DOCTYPE html>
<html lang='fr'>

<head>
  <title>Maze'ltov - customisation</title>
  <link rel="stylesheet" type="text/css" href="../css/custom.css">
  <link rel='icon' href='../images/front/favicon.ico' type='image/x-icon'>
</head>

<body>
  <?php
    $_SESSION["custom"]=true;
    if (isset($_POST['mazeSize']) && isset($_POST['nbrGuard']) && isset($_POST['nbrTP']) && isset($_POST['theme']) && isset($_POST["Maze_Name"])){
      $_SESSION["name"]=$_POST['Maze_Name'];
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
      case 1: header('Location:jungle.php'); break;
      case 2: header('Location:retro.php'); break;
      case 3: header('Location:space.php'); break;
    }
  }
  ?>
  <div class="title">
    <h1>Welcome to the sandbox</h1>
    <h4>Here you can create your own maze</h4>
  </div>
  <?php
  echo "
  <div class='range'>
    <!--[X] : valeur qui changera selon la position du curseur-->
    <form method='POST' action='./custom.php'>
      <label>Name of the maze : </label>
      <input type='text' placeholder='Name' name='Maze_Name'>
      <label>Size of the maze : [X]</label>
      <input type='range' name='mazeSize' min=\"5\" max=\"37\" value=\"5\">
      <br>
      <label>Number of guards : [X]</label>
      
      <input type='range' name='nbrGuard' min=\"0\" max=\"10\" value=\"0\">
      <br>
      <label>Number of teleporter pairs : [X]</label>
      <input type='range' name='nbrTP' min=\"0\" max=\"5\" value=\"0\">
      <br>
      <label>Select the theme :</label>
      <select name='theme'>
        <option>Jungle</option>
        <option>Retro</option>
        <option>Space</option>
      </select>
      <br>
      <input type='submit' value='Generate'>
    </form>
  </div>

  ";
  ?>
  
  
</body>