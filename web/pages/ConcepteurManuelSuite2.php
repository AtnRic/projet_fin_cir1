<!DOCTYPE html>
<html lang="en">
<head>
    <title>Concepteur manuel</title>
    <link rel="stylesheet" type="text/css" href="../css/custom.css">
    <link rel='icon' href='../images/front/favicon.ico' type='image/x-icon'>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
</head>

<body>
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
<?php
if (isset($_GET['mazeSize']) && isset($_GET['theme'])) {
    $mazeSize = $_GET['mazeSize'];
    $theme = $_GET['theme'];
    switch ($theme) {
        case('Jungle'):
            $theme = 1;
            break;
        case('Retro'):
            $theme = 2;
            break;
        case('Space'):
            $theme = 3;
            break;
    }

    $customMaze = array(
        array($mazeSize),
        array($theme)
    );

    $path = './dataCustomMaze.csv';
    if ($file = @fopen('../tools/ManuelAutresDonnees.csv', 'w')) {
        foreach ($customMaze as $ligne) {
            fputcsv($file, $ligne);
        }
        fclose($file);
    }
}
?>
<div class="formular">
<h1>Manual custom :</h1>
<h2>You have chosen a maze of <?php $SSize=$mazeSize; echo"$SSize";?> side squares (<?php $tot = $SSize*$SSize; echo"$tot";?>): </h2>
<div>
    <p>
        Please enter the letters of the generation without spaces, without line breaks, boxes from left to right, line by line
    </p>
    <a href="Correspondences.pdf">Download PDF file of correspondences</a>
</div>
<div>
    <form action="ConcepteurManuelSuite2.php?mazeSize=<?php echo$mazeSize;?>&theme=<?php echo $theme;?>" method="post">
        <div>
            <label>
                <textarea name="code_labyrinthe"></textarea>
            </label>
        </div>
        <br>
        <a href="../tools/function.php?customManuel=1"><input type="submit" name="submit1" value="Send" class="valid validate"></a>
    </form>
</div>
</div>
</section>
</body>

<?php
if (isset($_POST['code_labyrinthe'])){
    $code_labyrinthe = $_POST['code_labyrinthe'];
    $mazeSize = $_GET['mazeSize'];
    $theme = $_GET['theme'];
    $customMazee = array(
            array($code_labyrinthe)
    );

    if ($filee = @fopen('../tools/ManuelChaineCaractere.csv', 'w')) {
        foreach ($customMazee as $lignee) {
            fputcsv($filee, $lignee);
        }
        fclose($filee);
    }

    switch($theme){
        case 1: header("Location: jungle.php?customManuel=1"); break;
        case 2: header("Location: retro.php?customManuel=1"); break;
        case 3: header("Location: space.php?customManuel=1"); break;
    }
}
?>
