<body>
<?php
if (isset($_POST['mazeSize']) && isset($_POST['theme'])) {
    $_SESSION["mazeSize"] = $_POST['mazeSize'];
    $_SESSION["theme"] = $_POST['theme'];
    switch ($_SESSION["theme"]) {
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
}
?>
<h1>Manual custom :</h1>
<h2>You have chosen a maze of <?php echo"$_SESSION["mazeSize"]"?> side squares (<?php $tot = $mazeSize*$mazeSize; echo"$tot"?>): </h2>
<div>
    <p>
        Please enter the letters of the generation without spaces, without line breaks, boxes from left to right, line by line
    </p>
</div>
<div>
    <form action="ConcepteurManuelSuite2.php" method="post">
        <div>
            <label>Maze :</label>
            <textarea name="code_labyrinthe"></textarea>
        </div>
        <br>
        <input type="submit" value="Send">
    </form>
</div>
</body>

<?php
if (isset($_POST['submit'])&&isset($_POST['code_labyrinthe'])){
    $_SESSION["code_labyrinthe"] = $_POST['code_labyrinthe'];
    $customMaze = array(
        array($_SESSION["code_labyrinthe"]),
    );

    $path = './dataCustomMaze.csv';
    if ($file = @fopen('../tools/ManuelChaineCaractere.csv', 'w')) {
        foreach ($customMaze as $ligne) {
            fputcsv($file, $ligne);
        }
        fclose($file);
    }
}

if (isset($_POST['mazeSize'])&&isset($_POST['theme'])){
    $customMaze = array(
        array($_SESSION["mazeSize"]),
        array($_SESSION["theme"])
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