<?php
session_start();
$_SESSION['customManuel']=true;
?>

<body>
<h1>Concepteur Manuel</h1>
<div class="range">
    <form method="post" action="ConcepteurManuelSuite2.php" class="builder">
        <p>Size</p>
        <input type="range" name="mazeSize" min="7" max="30" value="5">
        <br>
        <label>Theme</label>
        <select name="theme">
            <option>Jungle</option>
            <option>Retro</option>
            <option>Space</option>
        </select>
        <br>
        <p><input type="submit" value="OK"></p>
    </form>
</div>
</body>
