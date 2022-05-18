<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Connexion</title>
    <link rel="stylesheet" type="text/css" href="../css/log.css">
</head>
<body>
<div class="press">
    <h1 id="name">Tartaros fantasy</h1>
    <a href="#choose">
        <h1 id="press">PRESS START</h1>
    </a>

</div>

<div class="choose" id="choose">
    <h1>Choose your player :</h1>
    <div class="container players">
        <a href="log.php?type=i#log">
            <div class="signin but">
                <div class="tuile"></div>
                <h3>Login</h3>
            </div>
        </a>
        <a href="log.php?type=u#log">
            <div class="signup but">
                <div class="tuile"></div>
                <h3>Sign Up</h3>
            </div>
        </a>
        <a href="log.php?type=w#log">
            <div class="without but">
                <div class="tuile"></div>
                <h3>Play without account</h3>
            </div>
        </a>

    </div>
</div>
<div id="log">
    <?php
        $type = $_GET['type'];
        if($type == 'i'){
            echo "<h1>Login</h1>";
            echo "<form action='' method='POST'>
                <label for='pseudo'></label><input type='text' id='pseudo' name='pseudo' placeholder='nickname' autofocus required ><br>
                <label for='mdpin'></label><input type='password' id='mdpin' name='mdpin' placeholder='password' required><br><br>
                <input type='submit' class='sub' name='sub' value='Envoyer'>
            </form>";
        }
        if($type == 'u'){
            echo "<h1>Sign up</h1>";
            echo "<form action='' method='POST'>
                <label for='pseudo'></label><input type='text' id='pseudo' name='pseudo' placeholder='nickname' autofocus required ><br>
                <label for='mdpin'></label><input type='password' id='mdpin' name='mdpin' placeholder='password' required><br>
                <label for='verifmdp'></label><input type='password' id='verifmdp' name='verifmdp' placeholder='password verification' required><br><br>
                <input type='submit' class='sub' name='sub' value='Envoyer'>
            </form>";
        }
        if($type == 'w'){
            echo "<h1>Play without account</h1>";
            echo "<form action='' method='POST'>
                <div id='guest'>
                    <h3>Warning</h3>
                    <div>if you play without account you will not be able to access level creation mode and your profile will be deleted at the end of your session</div>
                </div>
                <label for='pseudo'></label><input type='text' id='pseudo' name='pseudo' placeholder='nickname' autofocus required ><br>
                <input type='submit' class='sub' name='sub' value='Envoyer'>
            </form>";
        }
    ?>
</div>
</body>