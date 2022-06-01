<?php
echo "<canvas class='confetti' id='canvas'></canvas>";
echo "
<div id='popup'>
    <h1>Tartaros Fantasy</h1>
    <h2>Well Done !</h2>
    <p id='number'>number of steps : </p>
    <p id='short'>shortest solution : </p>
    <p id='long'>longest solution : </p>
    <div class='star'>
        <div class='center_img'>
            <img src='../images/popup/star.png' alt='star'>
            <img src='../images/popup/star_empty.png' alt='star'>
        </div>  
    </div>
    <div class='but'>
        <a><p>replay</p></a>
        <a><p>home</p></a>
        <a id='save'><p>save</p></a>
        <a><p>next level</p></a>
    </div>

</div>";
?>
<style>
    *{
        font-family: "8-bit HUD", serif;
    }
    #popup{
        position: absolute;
        top: 21vh;
        height: 50vh;
        width: 60vh;
        left: 50%;
        transform: translateX(-50%);

        border-style: solid;
        border-width: 5px;
        border-color: #0ff;
        box-shadow: 0 0 10px 5px #0ff;
        background-color: rgba(0,4, 23, 0.8);
        border-radius: 10px;
        padding: 20px;

        text-align: center;
        align-items: center;
    }
    #popup h1, p, h2{
        color: white;
        background-color: transparent;
    }
    h1{
        font-size: 2em;


    }
    h2{
        font-size: 1.3em;
        margin-bottom: 10px;
    }
    p{
        font-size: 0.8em;
    }
    a{
        display: inline-block;
        margin: 10px;

    }
    a:hover{
        border-style: solid;
        border-width: 5px;
        border-color: #0ff;
        box-shadow: 0 0 10px 3px #0ff;
        background-color: #000417;
        border-radius: 10px;
        padding: 0 5px;
    }

    .star{
        background-image: none;
        background-color: transparent;
        width: 100%;
        justify-content: center;
        display: flex;
        margin-top: -20px;
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
    .but, a{
        background-color: transparent;
    }
</style>
