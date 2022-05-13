<?php
    session_start();
?>
<html>
<style>
<?php
    
    include "../css/accueil.css";
?>
</style>
<body>
    <div id="text">
        <h1>THIS IS WHERE THE ADVENTURE BEGIN</h1>
        <div>
            <h2>Never created an account</h2>
            <a class="button" href="#inscription" id="boutton1">Signup</a>
        </div>
        <div>
            <h2>Already part of the team ?</h2>
            <a class="button" href="#connexion" id="boutton2">Login</a>
        </div>
        <div>
            <h2>Become an unknown player </h2>
            <a class="button" href="#anonymes" id="boutton3">Play as a guest</a>
        </div>
    </div>
    <!--Pop-up d'inscription-->
    <div id="inscription" class="overlay">
        <div class="popup">
            <a class="close" href=""><img class ='_close' src="../images/x-mark-xxl.png" alt="X"></a>
            <img class ='logo' src="images/bat.png" alt="logo">
            <h1>Create an account</h1>
            <form action="" method='POST'>
                <label for="pseudo"></label><input type="text" id="pseudo" name="pseudo" placeholder="Pseudo" autofocus required ><br>
                <label for="mdpin"></label><input type="password" id="mdpin" name="mdpin" placeholder="Password (8 Charactere, maj, min et chiffres)" required><br>
                <label for="verifmdp"></label><input type="password" id="verifmdp" name="verifmdp" placeholder="Confirm Password" required><br><br>
                <input type="submit" class='sub' name='sub' value="Send">
            </form> 
        </div>
    </div>

    <!--Popup de connexion-->
    <div id="connexion" class="overlay">
        <div class="popup">
            <a class="close" href=""><img class ='_close' src="../images/x-mark-xxl.png" alt="X"></a>
            <img class ='logo' src="images/bat.png" alt="logo">
            <h1>Login</h1>
            <form action="" method='POST'>
                <label for="login"></label><input type="text" id="login" name="login" placeholder="Pseudo" autofocus required><br>
                <label for="mdpco"></label><input type="password" id="mdpco" name="mdpco" placeholder="Password" required><br>
            <input type="submit" class='sub' value="Send">
            </form> 
            <a class="mdp" href="pages/mdp.html">Lapse of Memory ?</a>  
        </div>
    </div>

    <!--popup d'information pour les anonymes-->
    <div id="anonymes" class="overlay">
        <div class="popup">
            <a class="close" href=""><img class ='_close' src="../images/x-mark-xxl.png" alt="X"></a>
            <img class ='logo' src="images/bat.png" alt="logo">
            <h1>Informations importantes</h1>
            <p>en acceptant de jouer en temps qu'invité vous n'aurez pas accès au tableau des score et votre score ne sera pas inscrit dans ce dernier</p>
            <form action="" method='POST'>
                <label for="login"></label><input type="text" id="login" name="anonymes" placeholder="Pseudo" autofocus required><br>
            <input type="submit" name="subanonymes" class='sub' value="Send">
            </form> 
        </div>
    </div>
</body>
</html>
<?php
    include '_main_tools.php';
    // Register.
        $count = 0;
        if(isset($_POST['mdpin']))
        {
            if(!passwd($_POST['mdpin'])){
                echo Console("wrong Password.");
                echo "<style>
                .popup #mdpin{
                    outline: none;
                    border-style: solid;
                    border-radius: 5px;
                    border-width: 2px;
                    border-color:red;
                }
                </style>"; 
            }
            else{
                $count++;
            }
            //on profite du isset pour le mot de passe pour verifier que les autres champs soient biens remplis
            if(empty($_POST['pseudo'])){
                echo Console("Pseudo empty.");
                echo "<style>
                    .popup #pseudo{
                        outline: none;
                        border-style: solid;
                        border-radius: 5px;
                        border-width: 2px;
                        border-color:red;
                    }
                    </style>"; 
            }
            else{
                $count++;
            }

        if(empty($_POST['mdpin'])){
            echo Console("Password empty.");

                echo "<style>
                    .popup #mdpin{
                        outline: none;
                        border-style: solid;
                        border-radius: 5px;
                        border-width: 2px;
                        border-color:red;
                    }
                    </style>"; 
            }
            if(empty($_POST['verifmdp'])){
                echo Console("Password empty.");

                echo "<style>
                    .popup #verifmdp{
                        outline: none;
                        border-style: solid;
                        border-radius: 5px;
                        border-width: 2px;
                        border-color:red;
                    }
                    </style>"; 
            }
        }
        else{
            echo "<style>
            .popup input[type=text]:focus, input[type=password]:focus{
                outline: none;
                border-style: solid;
                border-radius: 5px;
                border-width: 2px;
                border-color:white;
            }
            </style>";
        }

        //on vérifie les mdp (inscription)
        if(isset($_POST['mdpin']) && isset($_POST['verifmdp'])){
            if(!verifpasswd($_POST['mdpin'], $_POST['verifmdp'])){
                echo Console("Password 1 != 2");

                echo "<style>
                .popup #verifmdp, #mdpin{
                    outline: none;
                    border-style: solid;
                    border-radius: 5px;
                    border-width: 2px;
                    border-color:red;
                }
                </style>"; 
            }
            else{
                $count++;
            }
        }
        
        if($count == 3)
        {
            $sign = signup($_POST['pseudo']);

            if($sign){
            echo Console("Connection granted.");
            $count++;
            }  
            else{            
            echo Console("Signup fail.");
            echo "<style>
            .popup #mdpin{
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
        if($count==4)
        {
            echo Console("Not to twooter.");

            $login= $_POST['pseudo'];
            $mdp_hash = hash('sha256', $_POST['mdpin']);//on fait un hash du mot de passe pour ne pas stocker le mot de passe en clair
            $_SESSION["pseudo"]=$login; //Variable de session "pseudo"
            if (!isset($_COOKIE['pseudo']) && !isset($_COOKIE['mdp_hash'])){
                setcookie("login", $login, time() + (3600 * 24 * 365));
                setcookie("mdp_hash", $mdp_hash, time() + (3600 * 24 * 365));
            }
            $newURL = "home.php";
            header('Location: '.$newURL);
            die();
        }

    // Login.
        $count = 0;
        if(isset($_POST['mdpco'])){

                //on profite du isset pour le mot de passe pour verifier que les autres champs soient biens remplis
                if(empty($_POST['login'])){
                    echo "<style>
                        .popup #login{
                            outline: none;
                            border-style: solid;
                            border-radius: 5px;
                            border-width: 2px;
                            border-color:red;
                        }
                        </style>"; 
                }
                else{
                    $count++;
                }

                if($count == 1)
                {                        
                    $sign = signin($_POST['login']);
                    if($sign){
                        $count++;
                        echo Console("Connection granted.");
                    }   
                    else{
                    echo "<style>
                    .popup #login{
                        outline: none;
                        border-style: solid;
                        border-radius: 5px;
                        border-width: 2px;
                        border-color:red;
                    }
                    </style>"; 
                    }
                }
        }
        else{
                echo "<style>
                .popup input[type=text]:focus, input[type=password]:focus{
                    outline: none;
                    border-style: solid;
                    border-radius: 5px;
                    border-width: 2px;
                    border-color:white;
                }
                </style>";
        }
            
        //si les 2 conditions sont vérifiées :
        if($count==2)
        {
                $login= $_POST['login'];
                $mdp_hash = hash('sha256', $_POST['mdpco']);//on fait un hash du mot de passe pour ne pas stocker le mot de passe en clair
                $_SESSION["pseudo"]=$login; //Variable de session "pseudo"
                if (!isset($_COOKIE['pseudo']) && !isset($_COOKIE['mdp_hash'])){
                    setcookie("login", $login, time() + (3600 * 24 * 365));
                    setcookie("mdp_hash", $mdp_hash, time() + (3600 * 24 * 365));
                }
                //ajouter utilisateur dans la base de données
                $newURL = "home.php";
                header('Location: '.$newURL);
                die();
        }
    
    //anonymes
        if(isset($_POST["subanonymes"])){
            if(empty($_POST['anonymes'])){
            echo Console("Pseudo anonyme empty.");

                echo "<style>
                    .popup #login{
                        outline: none;
                        border-style: solid;
                        border-radius: 5px;
                        border-width: 2px;
                        border-color:red;
                    }
                    </style>"; 
            }
            else{
            $_SESSION["pseudo"]=$_POST['anonymes'];
            header("location:home.php");
            }
        }
    
    ?>