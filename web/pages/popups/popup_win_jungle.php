<?php
echo "<canvas class='confetti' id='canvas'></canvas>";
$link = '../images/popup/popup_jungle.png';
echo "<div id='popup' style='background-image: url($link)'>
    
    <h1 class='fin'>Welcome to the Jungle</h1>
    <h2>Well Done !</h2>
    <p id='number'>number of steps : </p>
    <p id='short'>shortest solution : </p>
    <p id='long'>longest solution : </p>
    
    <div class='but'>
        <a class='restart'>replay</a>
        <a href='./home.php'>home</a>
        <a class='save'>save</a>
        <a href='./retro.php'>next level</a>
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

    img{
        display: flex;
        justify-content: center;
        margin: auto;
        height: 80px;
        width: 80px;

    }
    h1.fin{
        margin-top: 120px;
        font-size: 3em;
    }
    h2{
        margin-top: 30px;
        font-size: 2.5em;
    }
    p{
        margin-top: 15px;
        margin-left: 10px;
        margin-right: 10px;
        margin-bottom: 15px;
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
        bottom: 70px;
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
        left: 50.5%;
        transform: translateX(-50%) translateY(-50%);
        background-size: cover;
    }
    #canvas{
        visibility: visible;
        position: absolute;
        top: 0;
        left: 0;
        height: 100vh;
        width: 100vw;
        background-image: none;
    }

    .but a{
        color: #3E3228;
        background: none;
        text-decoration: none;
        box-shadow: none;
        font-size: 2em;
        cursor: pointer;
    }

    a:hover{
        box-shadow: none;
        border: none;
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
