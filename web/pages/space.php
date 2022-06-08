<!DOCTYPE html>
<html lang="en">
<head>
    <title>Maze'ltov - space</title>
    <link rel="stylesheet" type="text/css" href="../css/space.css">
    <link rel='icon' href='../images/front/favicon.ico' type='image/x-icon'>
</head>

<body>

<div class="global">
    <table id="container"></table>
</div>
<?php
    include 'popups/popup_intro_space.php';
    include 'popups/popup_win_space.php';
    include 'popups/popup_lose_space.php'; ?>
</body>
<script src="../js/conf.js"></script>
<script src="https://code.jquery.com/jquery-3.1.1.min.js"   integrity="sha256-hVVnYaiADRTO2PzUGmuLJr8BLUSjGIZsDYGmIJLv2b8="   crossorigin="anonymous"></script>
<script src="../js/node_modules/animejs/lib/anime.min.js"></script>
<script src="../js/main.js">
</script>
<script>
    SetAmbiance("Space");
    PHP_Start(true, false, null);
</script>

</html>