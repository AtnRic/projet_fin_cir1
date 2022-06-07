<?php
//echo "<canvas class='confetti' id='canvas'></canvas>";
echo "
<div id='popup'>
    <h1>A grand day out</h1>
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
        <a class='restart'><p>replay</p></a>
        <a id='home' href='./home.php'><p>home</p></a>
        <a id='save' href='../../tools/save.php?custom=false&theme=3'><p>save</p></a>
        <a id='next' href='./space.php'><p>next level</p></a>
    </div>

</div>";
?>
    <style>
        @font-face {
            font-family: "space age";
            src: url('../../images/font/space age.ttf');
        }

        *{
            font-family: "space age", serif;
        }
        #popup{
            visibility: hidden;
            position: absolute;
            background-image: none;
            top: 50%;
            height: 70vh;
            width: 100vh;
            left: 50%;
            transform: translateX(-50%) translateY(-50%);
            background-color: #2E4052;
            border-radius: 20px;
            padding: 15px;

            text-align: center;
            align-items: center;
        }
        #popup h1, p, h2{
            color: white;
            background-color: transparent;
            background-image: none;
        }
        #popup h1{
            font-size: 2.5em;
        }
        #popup h2{
            font-size: 3em;
            margin-bottom: 10px;
        }
        #popup p{
            font-size: 1.5em;
        }
        #popup a{
            background-image: none;
            display: inline-block;
            margin: 5px;
            font-size: 1.2em;
            border: none;
            padding: 0 5px;
            text-decoration: none;
            cursor: pointer;
            box-shadow: none;
        }
        #popup a p:hover{
            text-decoration: underline;
        }

        #popup .star{
            background-image: none;
            background-color: transparent;
            width: 100%;
            justify-content: center;
            display: flex;

        }
        #popup .center_img{
            background-color: transparent;
            width: 200px;
            background-image: none;
            justify-content: center;
            display: flex;
        }
        #popup img{
            background-color: transparent;
            display: flex;
            justify-content: center;
            background-image: none;
            margin: auto;
            height: 50px;
            width: 50px;
        }
        #popup .but{
            background-image: none;
            position: relative;
            top: 25px;
        }
        #popup .but, a{
            background-image: none;
            background-color: transparent;
        }
        #popup a p{
            background-image: none;
            position: static;
        }
    </style>

<?php
