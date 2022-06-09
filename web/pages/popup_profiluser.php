<!DOCTYPE html>
<html lang='en'>
<head>
    <meta name="viewport" content="width=device-width,initial-scale=1">
    <link rel="stylesheet" type="text/css" href="../css/popup_profiluser.css">
    <link rel='icon' href='../images/front/favicon.ico' type='image/x-icon'>
    <title>Profil - Maze'ltov</title>
</head>
<?php
    include "../tools/_main_tools.php";
?>
<div id=Thepopup>
    <p>Here is the link to let your friend play your level : </p>
    <?php
        $name=$_GET["level_name"];
        $newlink=GenerateLevelCustom($name);
    ?>
    <br>
    <br>
    <br>
    <a href="http://localhost/projet2/projet_fin_cir1/web/pages/<?php echo $newlink; ?>"><?php echo "http://localhost/projet2/projet_fin_cir1/web/pages/.$newlink"; ?></a>
    <br>
    <br>
    <br>
    <a class="close" href="profiluser.php">Close</a>
</div>
</html>