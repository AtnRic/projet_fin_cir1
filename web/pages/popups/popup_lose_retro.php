<?php
echo "<canvas class='confetti' id='canvas'></canvas>";
echo "
<div id='popup_lose'>
    <h1>Tartaros Fantasy</h1>
    <h2>Game Over</h2>
    
    
    <div class='but'>
        <a><p>replay</p></a>
        <a><p>home</p></a>
        <a id='save'><p>save</p></a>
    </div>

</div>";
?>
<style>
    *{
        font-family: "8-bit HUD", serif;
    }
    #popup_lose{
        z-index: -10;
        position: absolute;
        top: 22.2vh;
        height: 47vh;
        width: 60vh;
        left: 50%;
        transform: translateX(-50%);

        border-style: solid;
        border-width: 5px;
        border-color: #0ff;
        box-shadow: 0 0 10px 5px #0ff;
        background-color: rgba(0,4, 23, 0.75);
        border-radius: 20px;
        padding: 20px;

        text-align: center;
        align-items: center;
    }
    #popup_lose h1, p, h2{
        color: white;
        background-color: transparent;
    }
    h1{
        font-size: 1.3em;
    }
    h2{
        position: relative;
        top: 60px;
        font-size: 2em;
        margin-bottom: 20px;
    }
    p{
        font-size: 0.8em;
    }
    a{
        display: inline-block;
        margin: 5px;
        font-size: 0.8em;
        border-style: solid;
        border-width: 5px;
        border-color: transparent;
        border-radius: 10px;
        padding: 0 5px;
    }
    a:hover{
        border-style: solid;
        border-width: 5px;
        border-color: #0ff;
        box-shadow: 0 0 10px 3px #0ff;
        background-color: transparent;
    }
    .but{
        position: relative;
        top: 100px;
    }
    .but, a{
        background-color: transparent;
    }
    a p{
        position: static;
    }
</style>

