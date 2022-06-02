<?php
    include "../tools/_main_tools.php";
?>    
<!DOCTYPE html>
<html lang='fr'>
<head>
<meta name="viewport" content="width=device-width,initial-scale=1">
<link rel="stylesheet" type="text/css" href="../css/profiluser.css">
<link rel='icon' href='../images/front/favicon.ico' type='image/x-icon'>
</head>
<body>
    <div id="block">
        <!--Premiere moitier-->
        <div id="first">
            <!--Image joueur-->
            <input id="imageuser" type="image" src="../images/profileuser/profilimage/jungle_hero_cut.png">
            <!--Pseudo player-->
            <div id="pseudo"><label>your name:<br><?php echo $_COOKIE["pseudo"] ?></div>
            <form method="POST">
                <input class="button"type="submit" value="Reset stats" name="chadbutton">
            </form>
            <?php
            if(isset($_POST["chadbutton"])){
                ?>
                <style>
                    #reset{
                        display: block;
                    }
                </style>
                <?php
                if(isset($_POST["OMEGALUL"])){
                    ResetPoint($_COOKIE["pseudo"]);
                    header("Location:profiluser.php");
                }
            }    
            ?>    
        </div>
        <!--deuxieme moitier-->
        <div id="second">
            <!--information compte-->
            <div id="rank">
                <p>Points Total du compte : <?php //$Points=GetUserPoints($username); echo $Points;?></p>
                <p>niveaux du compte :<br/></p>
                <?php $Rank=Rank_User($_COOKIE["pseudo"]); echo $Rank;?>
                <img src="../images/profileuser/Rank/wood.png" alt="Woodrank" id="wood" class="rank_image"/>
                <img id="bronze" class="rank_image" src="../images/profileuser/Rank/Bronze.png" alt="Bronzerank"/>
                <img id="silver" class="rank_image" src="../images/profileuser/Rank/Silver.png" alt="Silverrank">
                <img src="../images/profileuser/Rank/gold.png" alt="Goldrank" id="gold" class="rank_image">
                <img src="../images/profileuser/Rank/Diamond.png" alt="Diamondrank" id="diamond" class="rank_image">
                <img  src="../images/profileuser/Rank/Chad.png" alt="Chadrank" id="chad" class="rank_image">
                <?php
                switch($Rank){
                    case 0:
                        echo "wood rank";
                        ?>
                        <style>
                            #wood{
                                display: block;
                            }
                        </style>
                        <?php
                        break;     
                    case 1:
                        echo "bronze rank";
                        ?>
                        <style>
                            #bronze{
                                display: block;
                            }
                        </style>
                        <?php
                        break;  
                    case 2:
                        echo "silver rank";
                        ?>
                        <style>
                            #silver{
                                display: block;
                            }
                        </style>
                        <?php
                        break;   
                    case 3:
                        echo "gold rank";
                        ?>
                        <style>
                            #gold{
                                display: block;
                            }
                        </style>
                        <?php 
                        break;  
                    case 4:
                        echo "diamond rank";
                        ?>
                        <style>
                            #diamond{
                                display: block;
                            }
                        </style>
                        <?php
                        break;    
                    case 5:
                        echo "chad of the maze rank";
                        ?>
                        <style>
                            #chad{
                                display: block;
                            }
                        </style>
                        <?php
                        break;      
                }
                ?>
            </div>
            <div id="leveleditor">
                <div>galerie de tes niveaux</div>
                <a><div  class="niveau">niveau 1</div></a>
                <a><div  class="niveau">niveau 2</div></a>
                <input class="button" type="submit" value="Create a level" href="">  
            </div>
        </div>
        <!--POPUP 1,changement de pseudo-->
        <div class="Popup" id="newpseudo">
            <p>Enter your new name</p>
            <form method="POST">
            <input type="text" name="PogChamp">
            <input type="submit" name="PEPPE">
            </form>
            <?php
            if(isset($_POST["PEPPE"]) && isset($_POST["PogChamp"])){
                $newPseudo=$_POST["PogChamp"];
                $username=$_COOKIE["pseudo"];
                $connexion=connect();
                $resultat=mysqli_query($connexion,"UPDATE Pseudo=$newPseudo FROM users WHERE Pseudo=$username");
            }
            elseif(empty($_POST["PogChamp"])){
                echo "Pseudo invalide";
            }
            ?>
        </div>
        <!--POPUP 2,reset de compte-->
        <div class="Popup" id="reset">
                <p>Are you sure about that ?</p>
                <form method="POST"> 
                <input type="submit" value="YES" name="OMGALUL"/>
                <input type="submit" value="NO" name="POGGERS"/>
                </form>
                <?php
                if(isset($_POST["OMGALUL"])){
                    $connexion=connect();
                    $username=$_COOKIE["pseudo"];
                    $resultat=mysqli_query($connexion,"UPDATE Nbr_Points=0 FROM users WHERE Pseudo=$username");
                }
                if(isset($_POST["POGGERS"])){
                   ?>
                   <style>
                        .Popup{
                            display: none;
                        }
                   </style>
                   <?php
                }
                ?>
        </div>
        <div>
        
        </div>
    </div>
</body>