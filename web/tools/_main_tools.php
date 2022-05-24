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

    if(!$majuscule || !$minuscule || !$chiffre || strlen($mdp) < 8){
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
    $requete2 = "INSERT INTO `users` (`Pseudo`, `Mdp`) VALUES ('$pseudo', '$mdp_hash')"; //La requete SQL
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