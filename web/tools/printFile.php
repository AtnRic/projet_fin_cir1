<?php
function printFile($argDirection, $argPosition){
    $data = array(
      array($argDirection),
      array($argPosition),
    );
 
    if ($f = @fopen('test.csv', 'w')) { //bah là en gros faudra mettre le chemin mais vas-y je sais pas où sera le document
      foreach ($data as $ligne) {
        fputcsv($f, $ligne);
      }
      fclose($f);
    }
    else {
      echo "Impossible d'acceder au fichier.";
    }
}?>
<?php
$argDirection = -1;
$argPosition = 21;
printFile($argDirection, $argPosition);
?>