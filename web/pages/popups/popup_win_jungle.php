<?php
echo "<canvas class='confetti' id='canvas'></canvas>";
$link = '../images/popup/popup_jungle.png';
echo "<div id='popup' style='background-image: url($link)'>
    <h1>Welcome to the Jungle</h1>
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
        <button class='restart'>replay</button>
        <button><a href='./home.php'>home</a></button>
        <button id='save'>save</button>
    <button><a href='./retro.php'>next level</a></button>
    </div>

</div>";
?>

<style>
    @font-face {
	font-family: 'permanent marker';
	src: url('../images/font/PermanentMarker-Regular.ttf');
}

    *{
        font-family: "permanent marker", serif;
    }
    h1, h2, p, img{
        color: #3E3228;
        background-image: none;
        text-align: center;
        align-items: center;
    }
    .star{
        background-image: none;
        width: 100%;
        justify-content: center;
        display: flex;
        margin-top: -20px;
    }
    .center_img{
        width: 200px;
        background-image: none;
        justify-content: center;
        display: flex;
    }
    img{
        display: flex;
        justify-content: center;
        margin: auto;
        height: 80px;
        width: 80px;

    }
    h1{
        margin-top: 100px;
        font-size: 3em;
    }
    h2{
        margin-top: -30px;
        font-size: 2.5em;
    }
    p{
        margin-top: -15px;
        font-size: 1.5em;
    }
    button{
        background-image: none;
        font-size: 1.2em;
        display: flex;
        flex-wrap: wrap;
        margin: 10px;
        top: 30px;
    }
    .but{
        position: absolute;
        display: flex;
        background-image: none;
        width: 100%;
        justify-content: center;
    }
    #popup{
        z-index: 1000;
        visibility: hidden;
        width: 70vw;
        height: calc(0.82 * 50vw);
        position: absolute;
        top: 50%;
        left: 48%;
        transform: translateX(-50%) translateY(-50%);
        background-size: cover;
       
    }
    canvas{
        z-index: 9;
        position: absolute;
        top: 0;
        left: 0;
        background-image: none;
    }
    a{
        color: #3E3228;
        background: none;
        text-decoration: none;
    }

    


    @media screen and (max-width: 1300px) {
        #popup h1 {
            font-size: 2em;
        }
        #popup h2 {
            font-size: 1.5em;
        }
        #popup p, button {
            font-size: 1em;
        }

    }
    
    </style>
