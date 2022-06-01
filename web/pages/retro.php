<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>retro</title>
    <link rel="stylesheet" type="text/css" href="../css/retro.css">
</head>
<body>
    <div class="two sline"></div>
    <div class="global">
        <table id="container"></table>
    </div>
    <?php
    include 'popups/popup_win_retro.php';
    ?>
</body>
<div class="preload" style="display: none"><img rel="preload" loading="eager" src="../images/retro/retro.png" alt=""></div>
<script src="../js/conf.js"></script>
<script src="https://code.jquery.com/jquery-3.1.1.min.js"   integrity="sha256-hVVnYaiADRTO2PzUGmuLJr8BLUSjGIZsDYGmIJLv2b8="   crossorigin="anonymous"></script>
<script src="../js/node_modules/animejs/lib/anime.min.js"></script>
<script src="../js/main.js"></script>
<script>
    SetAmbiance("Retro");
    PHP_Start(true, false, null);
    </script>
</html>