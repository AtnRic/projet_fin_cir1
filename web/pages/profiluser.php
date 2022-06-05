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
    <header>
        <a href="./home.php" id="homeButton">MENU</a>
    </header>
    <div id="block">
        <div id="informations">
            <div id="profil">
                <img width="50%" src="./../images/profileuser/profil/gigachad.png">
            </div>
            <div id="pseudo" class="text8bit">
                <label><?php echo $_COOKIE["login"] ?></label>
            </div>
            <div id="rank">
                <?php 
                $rank = 0;
                switch($rank){
                    case 0:
                        $grade = './../profiluser/images/Rank/wood.png';
                        break;     
                    case 1:
                        $grade = './../profiluser/images/Rank/Bronze.png';
                        break;  
                    case 2:
                        $grade = './../profiluser/images/Rank/Silver.png';
                        break;   
                    case 3:
                        $grade = './../profiluser/images/Rank/gold.png';
                    case 4:
                        $grade = './../profiluser/images/Rank/Diamond.png';
                        break;    
                    case 5:
                        $grade = './../profiluser/images/Rank/Chad.png';
                        break;  
                }
                ?>
                <img src= <?php $rank ?> >
            </div>
        </div>
    </div>
</body>