<!DOCTYPE html>
<html lang="en">
<head>
    <title>Maze'ltov - jungle</title>
    <link rel="stylesheet" type="text/css" href="../css/main.css">
    <link rel='icon' href='../images/front/favicon.ico' type='image/x-icon'>
</head>

<body>
    <!--<div class="one sline"></div>-->
    <div class="two sline"></div>
    <div class="global">
        <table id="container"></table>
    </div>
    <?php
    $theme = 'jungle';
    include 'popups/popup_outro.php';
    ?>
</body>  
<script src="../js/conf.js"></script>
<script src="https://code.jquery.com/jquery-3.1.1.min.js"   integrity="sha256-hVVnYaiADRTO2PzUGmuLJr8BLUSjGIZsDYGmIJLv2b8="   crossorigin="anonymous"></script>
<script src="../js/node_modules/animejs/lib/anime.min.js"></script>
<script src="../js/main.js"></script>
<script>
SetAmbiance("Jungle");
PHP_Start(true, false, null);
</script>

</html>