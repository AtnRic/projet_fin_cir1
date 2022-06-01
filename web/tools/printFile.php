<?php
function printFile($mazeSize, $nbrTP, $nbrGuard, $theme){
    $customMaze = array(
      array($mazeSize),
      array($nbrTP),
      array($nbrGuard),
      array($theme)
    );
 
    $path = './dataCustomMaze.csv';
    if ($file = @fopen('dataCustomMaze.csv', 'w')) {
      foreach ($customMaze as $ligne) {
        fputcsv($file, $ligne);
      }
      fclose($file);
    }
}
?>

<?php 
  $mazeSize = $_GET['mazeSize'];
  $nbrTP = $_GET['nbrTP'];
  $nbrGuard = $_GET['nbrGuard'];
  $theme = $_GET['theme'];
  if(isset($_GET['mazeSize']) && isset($_GET['nbrTP']) && isset($_GET['nbrGuard']) && isset($_GET['theme'])){
    echo "déjà les get fonctionnent";
    printFile($mazeSize, $nbrTP, $nbrGuard, $theme);
    
  switch($theme){
    case "1" : header("jungle.html"); break;
    case "2" : header("retro.html"); break;
    case "3" : header("space.php"); break;
  }
}
  ?>