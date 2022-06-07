<?php
//echo "<canvas class='confetti' id='canvas'></canvas>";
echo "
<div id='popup'>
    <h1>Tartaros Fantasy</h1>
    <h2>Well Done !</h2>
    <p id='number'>number of steps : </p>
    <p id='short'>shortest solution : </p>
    <p id='long'>longest solution : </p>
    <div class='star'>
        <div class='center_img'>
            <img id='starOne' src='../images/popup/star.png' alt='star'>
            <img id='starTwo' src='../images/popup/star_empty.png' alt='star'>
        </div>    
    </div>  
    <div class='but'>
        <a class='restart'><p>replay</p></a>
        <a href='./home.php'><p>home</p></a>
        <a class='save'><p>save</p></a>
        <a href='./space.php'><p>next level</p></a>
    </div>

</div>";
?>
<style>
    @font-face {
	font-family: "8-bit HUD";
	src: url('../images/font/8-bit-hud.ttf');
}

    *{
        font-family: "8-bit HUD", serif;
    }
    #popup{
        z-index: 10;
        visibility: hidden;
        position: absolute;
        top: 22.4vh;
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
    #popup h1, p, h2{
        color: white;
        background-color: transparent;
    }
    h1{
        font-size: 1.3em;
    }
    #popup h2{
        font-size: 1.5em;
        margin-bottom: 10px;
        top: 0;
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
        cursor: pointer;
    }
    a:hover{
        border-style: solid;
        border-width: 5px;
        border-color: #0ff;
        box-shadow: 0 0 10px 3px #0ff;
        background-color: transparent;
    }

    .star{
        background-image: none;
        background-color: transparent;
        width: 100%;
        justify-content: center;
        display: flex;

    }
    .center_img{
        background-color: transparent;
        width: 200px;
        background-image: none;
        justify-content: center;
        display: flex;
    }
    img{
        background-color: transparent;
        display: flex;
        justify-content: center;

        margin: auto;
        height: 50px;
        width: 50px;
    }
    #popup .but{
        position: relative;
        top: 25px;
    }
    .but, a{
        background-color: transparent;
        text-decoration: none;
    }
    a p{
        position: static;
    }
</style>

