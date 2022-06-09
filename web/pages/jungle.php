<!DOCTYPE html>
<html lang="en">

<head>
    <title>Maze'ltov - jungle</title>
    <link rel="stylesheet" type="text/css" href="../css/main.css">
    <link rel="stylesheet" type="text/css" href="../css/overlay.css">
    <link rel='icon' href='../images/front/favicon.ico' type='image/x-icon'>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
</head>

<body>
    <!--<div class="one sline"></div>-->
    <div class="two sline"></div>
    <div class="global">
        <table id="container"></table>
    </div>
    <?php
    if (isset($_SESSION['custom'])) {
        $custom = $_SESSION['custom'];
        if ($custom == 1) {
            $custom = true;
        } else {
            $custom = false;
        }
    } else {
        $custom = false;
    }

    if (isset($_SESSION['data'])) {
        $data = $_SESSION['data'];
    } else {
        $data = null;
    }
    
    include 'popups/popup_lose_jungle.php';
    include 'popups/popup_intro_jungle.php';
    include 'popups/popup_win_jungle.php';
    include 'overlay.html';
    ?>
</body>
<script src="../js/conf.js"></script>
<script src="https://code.jquery.com/jquery-3.1.1.min.js" integrity="sha256-hVVnYaiADRTO2PzUGmuLJr8BLUSjGIZsDYGmIJLv2b8=" crossorigin="anonymous"></script>
<script src="../js/node_modules/animejs/lib/anime.min.js"></script>
<script src="../js/main.js"></script>
<script>
    SetAmbiance("Jungle");
    PHP_Start(true, '<?php echo $custom ?>', '<?php echo $data ?>');
</script>

</html>