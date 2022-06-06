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
                <img width="50%" src="./../images/profileuser/profil/profile_retro.png">
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
                <!-- Manque le back -->
            </div>
            <div id="buttonLevel">
                <a href="./custom.php">Create a level</a>
            </div>
        </div>
        <div id="parameters">
            <a onclick="openPopup('resetStats')">Reset stats</a>
            <span style="width:10%;display:inline-block"></span>
            <a onclick="openPopup('newPseudo')">Change pseudo</a>
        </div>
    </main>
    <div id="popup">
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
                $resultat = mysqli_query($connexion, "UPDATE users SET Pseudo='$newPseudo' WHERE Pseudo='$username'");
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
            document.querySelector('header').classList.add('disableLink');
            document.querySelector('main').classList.add('disableLink');

        }

        function closePopup($name) {
            document.getElementById($name).style.display = "none"
            document.querySelector('header').style.opacity = "1"
            document.querySelector('main').style.opacity = "1"
            document.querySelector('header').classList.remove('disableLink');
            document.querySelector('main').classList.remove('disableLink');

        }
    </script>
</body>