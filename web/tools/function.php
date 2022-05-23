<?php
$functionName = $_POST['functionName'];

if($functionName == 'Up')
{
    // Appeler le C, peut-il se déplacer dans cette direction ?
    echo true; // true ou false.
}
if($functionName == 'Down')
{
    // Appeler le C, peut-il se déplacer dans cette direction ?
    echo true; // true ou false.
}
if($functionName == 'Left')
{
    // Appeler le C, peut-il se déplacer dans cette direction ?
    echo true; // true ou false.
}
if($functionName == 'Right')
{
    // Appeler le C, peut-il se déplacer dans cette direction ?
    echo true; // true ou false.
}
if($functionName == 'generation')
{
    $output = "";
    $var = 0;
    exec('solve.exe', $output, $var);
    // Appeler le C, lancement du jeu ?
    $out = "";
    for($i = 0; $i < count($output); $i++){
        $out = $out . $output[$i];
    }
    echo $out; // true ou false.
}


?>