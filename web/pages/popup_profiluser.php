<head>
    <meta name="viewport" content="width=device-width,initial-scale=1">
    <link rel="stylesheet" type="text/css" href="../css/popup_profiluser.css">
    <link rel='icon' href='../images/front/favicon.ico' type='image/x-icon'>
    <title>Page de profil</title>
</head>
<?php
    include "../tools/_main_tools.php";
?>
<div id=Thepopup>
    <p>here is the link to let your friend play your level</p>
    <?php
        $name=$_GET["level_name"];
        $newlink=GenerateLevelCustom($name);
    ?>
    <a href="<?php echo $newlink; ?>"><?php echo $newlink; ?></a>
    <br>
    <a href="profiluser.php">Close</a>
</div>