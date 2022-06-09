<body>
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
<h1>Manual custom :</h1>
<h2>You have chosen a maze of <?php $SSize=$mazeSize; echo"$SSize";?> side squares (<?php $tot = $SSize*$SSize; echo"$tot";?>): </h2>
<div>
    <p>
        Please enter the letters of the generation without spaces, without line breaks, boxes from left to right, line by line
    </p>
</div>
<div>
    <form action="ConcepteurManuelSuite2.php?mazeSize=<?php echo$mazeSize;?>&theme=<?php echo $theme;?>" method="post">
        <div>
            <label>Maze :</label>
            <label>
                <textarea name="code_labyrinthe"></textarea>
            </label>
        </div>
        <br>
        <a href="../tools/function.php?customManuel=1"><input type="submit" name="submit1" value="Send"></a>
    </form>
</div>
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
