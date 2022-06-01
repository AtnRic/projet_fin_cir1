<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Connexion</title>
    <link rel="stylesheet" type="text/css" href="../css/log.css">
    <link rel='icon' href='../images/front/favicon.ico' type='image/x-icon'>
    <meta name="viewport" content="width=device-width,initial-scale=1">
</head>
<body>

<script>
    activate = true; //pour désactiver facilement
    document.addEventListener("keydown", function (event) {
        if (activate == true) {
            if (event.key == " ") {//quand espace est pressé
                location.href = "#choose" //on scroll vers la page suivante
                activate = false;
            }
        }
    });
</script>

<div class="press">
    <h1 id="name">Maze'ltov</h1>
    <img src="../images/front/retro_logo.png" alt="Logo" id="logoimage">
    <a href="#choose">
        <h1 id="press">PRESS START</h1>
    </a>

</div>

<div class="choose" id="choose">
    <h1>Choose your player :</h1>
    <div class="container">
        <a href="log.php?type=i#log">
            <div class="login but">
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
                <div class="tuile">
                    <div class="hero"></div>
                </div>
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
            echo "<form class='formulaires' action='' method='POST'>
                <label for='login'></label><input type='text' id='login' name='login' placeholder='nickname' autofocus required ><br>
                <label for='mdpco'></label><input type='password' id='mdpco' name='mdpco' placeholder='password' required><br><br>
                <input type='submit' class='sub' name='sub' value='Envoyer'>
            </form>";
        }
        if($type == 'u'){
            echo "<h1>Sign up</h1>";
            echo "<form class='formulaires' action='' method='POST'>
                <label for='pseudo'></label><input type='text' id='pseudo' name='pseudo' placeholder='nickname' autofocus required ><br>
                <label for='mdpin'></label><input type='password' id='mdpin' name='mdpin' placeholder='password with num,Cap' required><br>
                <label for='verifmdp'></label><input type='password' id='verifmdp' name='verifmdp' placeholder='password verification' required><br><br>
                <input type='submit' class='sub' name='sub' value='Envoyer'>
            </form>";
        }
        if($type == 'w'){
            echo "<h1 id='title'>Play without account</h1>";
            echo "<form class='formulaires' action='' method='POST'>
                <div id='guest'>
                    <h3>Warning</h3>
                    <div>if you play without account you will not be able to access level creation mode and your profile will be deleted at the end of your session</div><br>
                </div>
                <label for='login'></label><input type='text' id='login' name='anonymes' placeholder='nickname' autofocus required /><br>
                <input type='submit' class='sub' name='subanonymes' value='Send'/>
            </form>";
        }
    ?>
</div>
</body>
</html>





<?php
include '../tools/_main_tools.php';
// Register.
$count = 0;
if (isset($_POST['mdpin'])) {
    if (!passwd($_POST['mdpin'])) {
        echo Console("wrong Password.");
        echo "<style>
                .formulaires #mdpin{
                    outline: none;
                    border-style: solid;
                    border-radius: 5px;
                    border-width: 2px;
                    border-color:red;
                }
                </style>";
    } else {
        $count++;
    }
    //on profite du isset pour le mot de passe pour verifier que les autres champs soient biens remplis
    if (empty($_POST['pseudo'])) {
        echo Console("Pseudo empty.");
        echo "<style>
                    .formulaires #pseudo{
                        outline: none;
                        border-style: solid;
                        border-radius: 5px;
                        border-width: 2px;
                        border-color:red;
                    }
                    </style>";
    } else {
        $count++;
    }

    if (empty($_POST['mdpin'])) {
        echo Console("Password empty.");

        echo "<style>
                    .formulaires #mdpin{
                        outline: none;
                        border-style: solid;
                        border-radius: 5px;
                        border-width: 2px;
                        border-color:red;
                    }
                    </style>";
    }
    if (empty($_POST['verifmdp'])) {
        echo Console("Password empty.");

        echo "<style>
                    .formulaires #verifmdp{
                        outline: none;
                        border-style: solid;
                        border-radius: 5px;
                        border-width: 2px;
                        border-color:red;
                    }
                    </style>";
    }
} else {
    echo "<style>
            .formulaires input[type=text]:focus, input[type=password]:focus{
                outline: none;
                border-style: solid;
                border-radius: 5px;
                border-width: 2px;
                border-color:white;
            }
            </style>";
}

//on vérifie les mdp (inscription)
if (isset($_POST['mdpin']) && isset($_POST['verifmdp'])) {
    if (!verifpasswd($_POST['mdpin'], $_POST['verifmdp'])) {
        echo Console("Password 1 != 2");

        echo "<style>
                .formulaires #verifmdp, #mdpin{
                    outline: none;
                    border-style: solid;
                    border-radius: 5px;
                    border-width: 2px;
                    border-color:red;
                }
                </style>";
    } else {
        $count++;
    }
}

if ($count == 3) {
    $sign = signup($_POST['pseudo']);

    if ($sign) {
        echo Console("Connection granted.");
        $count++;
    } else {
        echo Console("Signup fail.");
        echo "<style>
            .formulaires #mdpin{
                outline: none;
                border-style: solid;
                border-radius: 5px;
                border-width: 2px;
                border-color:red;
            }
            </style>";
    }
}

//si les 3 conditions sont vérifiées :
if ($count == 4) {
    echo Console("Not to twooter.");

    $login = $_POST['pseudo'];
    $mdp_hash = hash('sha256', $_POST['mdpin']); //on fait un hash du mot de passe pour ne pas stocker le mot de passe en clair
    $_SESSION["pseudo"] = $login; //Variable de session "pseudo"
    if (!isset($_COOKIE['pseudo']) && !isset($_COOKIE['mdp_hash'])) {
        setcookie("login", $login, time() + (3600 * 24 * 365));
        setcookie("mdp_hash", $mdp_hash, time() + (3600 * 24 * 365));
    }
    $newURL = "home.php";
    header('Location: ' . $newURL);
    die();
}

// Login.
$count = 0;
if (isset($_POST['mdpco'])) {

    //on profite du isset pour le mot de passe pour verifier que les autres champs soient biens remplis
    if (empty($_POST['login'])) {
        echo "<style>
                        .formulaire #login{
                            outline: none;
                            border-style: solid;
                            border-radius: 5px;
                            border-width: 2px;
                            border-color:red;
                        }
                        </style>";
    } else {
        $count++;
    }

    if ($count == 1) {
        $sign = signin($_POST['login']);
        if ($sign) {
            $count++;
            echo Console("Connection granted.");
        } else {
            echo "<style>
                    .formulaire #login{
                        outline: none;
                        border-style: solid;
                        border-radius: 5px;
                        border-width: 2px;
                        border-color:red;
                    }
                    </style>";
        }
    }
} else {
    echo "<style>
                .formulaires input[type=text]:focus, input[type=password]:focus{
                    outline: none;
                    border-style: solid;
                    border-radius: 5px;
                    border-width: 2px;
                    border-color:white;
                }
                </style>";
}

//si les 2 conditions sont vérifiées :
if ($count == 2) {
    $login = $_POST['login'];
    $mdp_hash = hash('sha256', $_POST['mdpco']); //on fait un hash du mot de passe pour ne pas stocker le mot de passe en clair
    $_SESSION["pseudo"] = $login; //Variable de session "pseudo"
    if (!isset($_COOKIE['pseudo']) && !isset($_COOKIE['mdp_hash'])) {
        setcookie("login", $login, time() + (3600 * 24 * 365));
        setcookie("mdp_hash", $mdp_hash, time() + (3600 * 24 * 365));
    }
    //ajouter utilisateur dans la base de données
    $newURL = "home.php";
    header('Location: ' . $newURL);
    die();
}

//anonymes
if (isset($_POST["subanonymes"])) {
    if (empty($_POST['anonymes'])) {
        echo Console("Pseudo anonyme empty.");

        echo "<style>
                    .formulaires #login{
                        outline: none;
                        border-style: solid;
                        border-radius: 5px;
                        border-width: 2px;
                        border-color:red;
                    }
                    </style>";
    } else {
        $_SESSION["pseudo"] = $_POST['anonymes'];
        $newURL = "home.php";
        header('Location: ' . $newURL);
    }
}

?>