<?php
if(!isset($pageName)){
    $pageName ="";//si le nom de la page n'a pas été precise, on initialise la variable pour eviter une erreur
}
if(!isset($cssPath)){
    $cssPath="";
}

echo "
<head>
    <meta charset='utf-8'/>
    <meta name='description' content='Mazeltov'>
    <meta name='keywords' content='Mazeltov'>
    <meta name='author' content='Antoine RICHARD, Adrien VERHAEGHE, Enzo SERGIANI, Hippolyte DEPARIS, Matthieu BAUM, Thibaut LEMICHEL'>
    <meta name='viewport' content='width=device-width, initial-scale=1.0'>
    <meta http-equiv='X-UA-Compatible' content='IE=edge'>
    <title>$pageName - Mazeltov</title>
    <script src='https://kit.fontawesome.com/235593db07.js' crossorigin='anonymous'></script>
    <link rel='icon' type='image/png' href='../images/front/favicon.ico'/>
    <link rel='stylesheet' href='../css/$cssPath'>
    </head>";
