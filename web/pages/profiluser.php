<?php
include "../tools/_main_tools.php";
?>
<!DOCTYPE html>
<html lang='en'>

<head>
    <meta name="viewport" content="width=device-width,initial-scale=1">
    <link rel="stylesheet" type="text/css" href="../css/profiluser.css">
    <link rel='icon' href='../images/front/favicon.ico' type='image/x-icon'>
    <title>Page de profil</title>
</head>

<body>
    <header>
        <a href="./home.php" id="homeButton">MENU</a>
    </header>
    <main>
        <div id="informations">
            <div id="picture">
                <?php
                $connexion = connect();
                $username = $_COOKIE["login"];
                $resultat = mysqli_query($connexion, "SELECT `avatar` FROM `users` WHERE Pseudo = '$username'");
                $row = mysqli_fetch_assoc($resultat);
                switch ($row['avatar']) {
                    case 'jungle hero':
                        $avatar = './../images/profileuser/profil/profile_jungle_hero.png';
                        break;
                    case 'jungle guard':
                        $avatar = './../images/profileuser/profil/profile_jungle_guard.png';
                        break;
                    case 'retro hero':
                        $avatar = './../images/profileuser/profil/profile_retro_hero.png';
                        break;
                    case 'retro guard':
                        $avatar = './../images/profileuser/profil/profile_retro_guard.png';
                        break;
                    case 'space hero':
                        $avatar = './../images/profileuser/profil/profile_space_hero.png';
                        break;
                    case 'space guard':
                        $avatar = './../images/profileuser/profil/profile_space_guard.png';
                        break;
                }
                ?>
                <img width="50%" src=<?php echo $avatar ?>>

            </div>
            <div id="profil">
                <div id="pseudo"><?php echo $_COOKIE["login"] ?></div>
                <div id="points"><?php echo GetUserPoints($_COOKIE["login"]) . 'pts'; ?></div>
            </div>
            <div id="rank">
                <?php
                $rank = Rank_User($_COOKIE["login"]);
                switch ($rank) {
                    case 0:
                        $grade = "./../images/profileuser/Rank/wood.png";
                        $name = 'wood';
                        break;
                    case 1:
                        $grade = './../images/profileuser/Rank/Bronze.png';
                        $name = 'bronze';
                        break;
                    case 2:
                        $grade = './../images/profileuser/Rank/Silver.png';
                        $name = 'silver';
                        break;
                    case 3:
                        $grade = './../images/profileuser/Rank/gold.png';
                        $name = 'gold';
                        break;
                    case 4:
                        $grade = './../images/profileuser/Rank/Diamond.png';
                        $name = 'diamond';
                        break;
                    case 5:
                        $grade = './../images/profileuser/Rank/Chad.png';
                        $name = 'chad';
                        break;
                }
                ?>
                <img width="30%" src=<?php echo $grade ?>>
                <br>
                <span> <?php echo $name ?></span>
            </div>
        </div>
        <div id="levels">
            <div id="titleLevels">
                <span>Gallery of your levels</span>
            </div>
            <div id="level">
                <?php
                $connexion = connect();
                $username = $_COOKIE['login'];
                $resultat = mysqli_query($connexion, "SELECT `NAME` FROM `custom_level` WHERE `AUTHOR` = 'Dousai'");
                if ($resultat) {
                    while ($row = mysqli_fetch_assoc($resultat)) {
                ?>
                        <a href="#"> <?php echo $row['NAME'] ?></a>
                        <br>
                <?php
                    }
                }
                ?>
            </div>
            <div id="buttonLevel">
                <a href="./custom.php">Create a level</a>
            </div>
        </div>
        <div id="parameters">
            <a onclick="openPopup('avatar')">Change avatar</a>
            <span style="width:10%;display:inline-block"></span>
            <a onclick="openPopup('resetStats')">Reset stats</a>
            <span style="width:10%;display:inline-block"></span>
            <a onclick="openPopup('newPseudo')">Change pseudo</a>
        </div>
    </main>
    <div id="popup">
        <div id="avatar">
            <p>Change your avatar</p>
            <form method="POST">
                <select name="avatar">
                    <option>jungle hero</option>
                    <option>jungle guard</option>
                    <option>retro hero</option>
                    <option>retro guard</option>
                    <option>jungle hero</option>
                    <option>space hero</option>
                    <option>space guard</option>
                </select>
                <br>
                <input type="submit" value="change">
            </form>
            <?php
            if (isset($_POST['avatar'])) {
                $avatar = $_POST['avatar'];
                $username = $_COOKIE["login"];
                $connexion = connect();
                $resultat = mysqli_query($connexion, "UPDATE users SET avatar='$avatar' WHERE Pseudo='$username'");
                unset($_POST['avatar']);
                header('Location: ./profiluser.php');
            }
            ?>
            <a onclick="closePopup('avatar')">Close</a>
        </div>
        <div id="newPseudo">
            <p>Change pseudo</p>
            <form method="POST">
                <input type="text" name="newPseudo" style="width: 50%;" placeholder="New pseudo">
                <br>
                <input type="submit" value="change">
            </form>
            <?php
            if (isset($_POST['newPseudo'])) {
                $newPseudo = $_POST['newPseudo'];
                $username = $_COOKIE["login"];
                $connexion = connect();
                $resultat1 = mysqli_query($connexion, "UPDATE users SET Pseudo='$newPseudo' WHERE Pseudo='$username'");
                $resultat2 = mysqli_query($connexion, "UPDATE custom_level SET AUTHOR='$newPseudo' WHERE AUTHOR='$username'");
                setcookie("login", $newPseudo, time() + (3600 * 24 * 365));
                unset($_POST['newPseudo']);
                header('Location: ./profiluser.php');
            }
            ?>
            <a onclick="closePopup('newPseudo')">Close</a>
        </div>
        <div id="resetStats">
            <p>You want to reset your statistics ?</p>
            <p>Sure ?</p>
            <form method="POST">
                <input type="submit" name="resetStats" value="YES">
                <input type="submit" onclick="closePopup('resetStats')" value="NO">
                <?php
                if (isset($_POST["resetStats"])) {
                    $connexion = connect();
                    $username = $_COOKIE["login"];
                    $resultat = mysqli_query($connexion, "UPDATE users SET Nbr_Points='0' WHERE Pseudo='$username'");
                    unset($_POST['resetStats']);
                    header('Location: ./profiluser.php');
                }
                ?>
            </form>
            <a onclick="closePopup('resetStats')">Close</a>
        </div>
    </div>

    <script>
        function openPopup($name) {
            document.getElementById($name).style.display = "block"
            document.querySelector('header').style.opacity = "0.3"
            document.querySelector('main').style.opacity = "0.3"
            document.querySelector('header').style.pointerEvents = "none"
            document.querySelector('main').style.pointerEvents = "none"
        }

        function closePopup($name) {
            document.getElementById($name).style.display = "none"
            document.querySelector('header').style.opacity = "1"
            document.querySelector('main').style.opacity = "1"
            document.querySelector('header').style.pointerEvents = "auto"
            document.querySelector('main').style.pointerEvents = "auto  "
        }
    </script>
</body>