<?php
switch($theme){
    case 'jungle':
        $hyperlink = './retro.html';
        $link = "../images/popup/popup_jungle.png";
        break;
    case 'retro':
        $hyperlink = './space.php';
        $link = "";
        break;
    case 'space':
        $link = "";
        break;
}


echo "<canvas class='confetti' id='canvas'></canvas>";
echo "
<div id='popup' style='background-image: url($link)'>
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
        <button>replay</button>
        <button>home</button>
        <button id='save'>save</button>";
        if ($theme == 'jungle' || $theme == 'retro'){
            echo "<button><a href='$hyperlink'>next level</a></button>";
        }
    echo "</div>

</div>";
?>

<?php
if($theme == 'jungle'){
    echo "
    <style>
    h1, h2, p, img{
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
        width: 70vw;
        height: calc(0.82 * 50vw);
        position: absolute;
        top: 50%;
        left: 48%;
        transform: translateX(-50%) translateY(-50%);
        background-size: cover;
        z-index: 10;
    }
    canvas{
        z-index: 9;
        position: absolute;
        top: 0;
        left: 0;
        background-image: none;
    }
    a{
        color: black;
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
    </style>";
}
else if($theme == 'retro'){
    
}
else{

}

?>
