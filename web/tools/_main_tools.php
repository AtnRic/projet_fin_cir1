<?php 
/*connection à la base de données*/
function connect()
{
    $hostname="localhost";//à changer
    $username="root";//nom d'utilisateur pour accéder au serveur (root)
    $password="root"; //mot de passe pour accéder au serveur (root)
    $dbname="dbjeu"; //nom de la base de données
    
    $connexion = mysqli_connect($hostname, $username, $password, $dbname);

    if (!$connexion) {
        echo Console("<p>Erreur d'exécution de la requete : ".mysqli_error($connexion)."</p>");
        return false;
    }
    else
    {
        return $connexion;
    }
}

//vérification d'un certain pattern de mdp
function passwd($mdp): bool
{
    $majuscule = preg_match('@[A-Z]@', $mdp);
    $minuscule = preg_match('@[a-z]@', $mdp);
    $chiffre = preg_match('@\d@', $mdp);

    if(!$majuscule || !$minuscule || !$chiffre || strlen($mdp) <= 8){
        return false;
    }
    else{
        return true;
    }
}

//vérifier que les mots de passe (inscription) sont identiques :
function verifpasswd($mdp, $verif): bool
{
        if($verif==$mdp){
            return true;
        }
        else{
            return false;
        }
}


function signup($pseudo): bool
{
    $connexion = connect();

    $requete = "SELECT * FROM `users`";
    $resultat = mysqli_query($connexion, $requete);

    if ( $resultat == NULL){
       echo Console("<p>Erreur d'exécution de la requete : ".mysqli_error($connexion)."</p>");
       return false;
    }

    while ($ligne = $resultat -> fetch_assoc()) {
        $nickname = $ligne['Pseudo']; 
        if($nickname == $pseudo){
            return false;
        }
    }
    $mdp_hash = hash('sha256', $_POST['mdpin']);//on fait un hash du mot de passe pour ne pas stocker le mot de passe en clair
    $requete2 = "INSERT INTO `users` (`Pseudo`, `Mdp`, `Nbr_Points`) VALUES ('$pseudo', '$mdp_hash', 0)"; //La requete SQL
    $resultat2 = mysqli_query($connexion, $requete2); //Executer la requete
    if (!$resultat2){
        echo Console("<p>Erreur d'exécution de la requete : ".mysqli_error($connexion)."</p>");
        return false;
    }
    else{
        return true;
    }
}


function signin($pseudo): bool
{
    $connexion = connect();
    $requete = "SELECT * FROM `users`";
    $resultat = mysqli_query($connexion, $requete);
    if ( $resultat == NULL){
        return false;
    }
    $mdp_hash = hash('sha256', $_POST['mdpco']);//on fait un hash du mot de passe pour ne pas stocker le mot de passe en clair


    while ($ligne = $resultat -> fetch_assoc()) {
        $nickname = $ligne['Pseudo']; 
        $password = $ligne['Mdp'];
        if($nickname == $pseudo){
            if($password == $mdp_hash){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
}

//récupére le rank du joueur
function Rank_User($username){
    $Points=GetUserPoints($username);
    $connexion=connect();
    //echo "points du joueur:".$Points;
        if($Points>=0 && $Points<10000){
            $rank=0;//Wood rank de départ
            //echo"true 0";
            return $rank;
        }
        if($Points>=10000 && $Points<25000){
            $rank=1;//Copper premier rank
            echo"true 1";
            return $rank;
        }
        if ($Points>=25000 && $Points<50000){
            $rank=2;//Silver deuxieme rank
            //echo"true 2";
            return $rank;
        }
        if ($Points>=50000 && $Points<100000){
            $rank=3;//Gold Troisieme rank
            //echo"true 3";
            return $rank;
        }
        if ($Points>=100000 && $Points<200000){
            $rank=4;//Diamond Quatrieme rank
            //echo"true 4";
            return $rank;
        }
        if ($Points>=200000){
            $rank=5;//Chad of the maze Cinquieme rank   
            //echo"true 5";  
            return $rank; 
        }
}

//récupére les points de l'utilisateur pour les display
function GetUserPoints($username){
    $connexion=connect();
    $resultat=mysqli_query($connexion,"SELECT Nbr_Points FROM users WHERE Pseudo='$username'");
    while($Points=mysqli_fetch_assoc($resultat)){
        $pointsjoueur=$Points["Nbr_Points"];
    }
    return $pointsjoueur;

}

//Reset les points de l'utilisateur connecté
function ResetPoint($username){
    $connexion=connect();
    $resultat=mysqli_query($connexion,"UPDATE Nbr_Points=0 FROM dbjeu WHERE Pseudo='$username'");
}

function GetUserLevels($username){
    $connexion=connect();
    $resultat=mysqli_query($connexion,"SELECT 'NAME,SIZE,GUARD_NUMBER,TELEPORTER_NUMBER,THEME' FROM 'custom_level,users' WHERE 'users.Pseudo=custom_level.AUTHOR'" );
    if($resultat!=NULL){
        while ($niveaux = mysqli_fetch_assoc($resultat)){
            $Name = $niveaux['NAME'];
            $Size = $niveaux['SIZE'];
            $Guard = $niveaux['GUARD_NUMBER'];
            $Teleporteur = $niveaux['TELEPORTER_NUMBER'];
            $Theme = $niveaux['THEME'];
            ?>
            <div id="niveaux_display">
                <p><?php echo $Name;?></p>
                <p>Size:<?php echo $Size;?></p>
                <p>Guard Number:<?php echo $Guard;?></p>
                <p>Portal Number:<?php echo $Teleporteur;?></p>
                <p>Background:<?php echo GetTheme($Theme);?></p>
                <a href="">play level</a>
                <input type="submit" value="Share" href="../tools/rintFile.php?"/>
            </div>
            <style>
                #niveaux_display{
                    border: solid 2px black;
                }
            </style>
            <?php
        }
    }
    else{
        echo"erreur connexion data base";
    }
}

//Récupére le theme pour l'afficher dans l'explorateur de niveaux sur la page de profil
function GetTheme($Theme){
    if($Theme==1){
        echo"Jungle";
    }
    if($Theme==2){
        echo"Retro";
    }
    if($Theme==3){
        echo"Space";
    }
}

//récupère l'id de l'utilisateur à partir de son pseudo
function GetUserId($nickname)
{
    $connexion = connect();
    $requete = "SELECT * FROM `users`";
    $resultat = mysqli_query($connexion, $requete);
    while ($ligne = $resultat -> fetch_assoc()) 
    {
        if($ligne['Pseudo'] == $nickname)
        {    
            return $ligne['id'];
        }
    }
    return null;
}

//récupère le chemin vers la photo de profil de l'utilisateur dont le pseudo est passé en paramètre
function GetUserPdpPath($nickname)
{
    $connexion = connect();
    $requete = "SELECT * FROM `users`";
    $resultat = mysqli_query($connexion, $requete);
    while ($ligne = $resultat -> fetch_assoc()) 
    {
        if($ligne['Pseudo'] == $nickname)
        {    
            if($ligne['pdpPath']==NULL){
                return "../images/pp/bat.png"; //photo de profil par défaut
            }
            else{
                return $ligne['pdpPath'];
            }

        }
    }

    return NULL;

}

//permet d'afficher des infos dans la console (debug)
function Console($data): string
{
    $start = array("'", "<p>", "</p>");
    $end   = array(" ", "", "");
    $new = str_replace($start, $end, $data);
    return "<script> console.log('$new'); </script>";
}
?>