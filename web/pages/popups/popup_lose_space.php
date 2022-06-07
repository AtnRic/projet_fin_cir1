<?php
//echo "<canvas class='confetti' id='canvas'></canvas>";
echo "
<div id='popup_lose'>
    <h1>A grand day out</h1>
    <h2>Game Over</h2>  
    <div class='but'>
        <a class='restart'><p>replay</p></a>
        <a id='home' href='./home.php'><p>home</p></a>
        <a id='save' href='../../tools/save.php?custom=false&theme=3'><p>save</p></a>
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
        #popup_lose{
            visibility: hidden;
            position: absolute;
            top: 50%;
            height: 70vh;
            width: 100vh;
            left: 50%;
            transform: translateX(-50%) translateY(-50%);
            background-color: #2E4052;
            border-radius: 20px;
            padding: 15px;
            background-image: none;
            text-align: center;
            align-items: center;
        }
        #popup_lose h1, p, h2{
            background-image: none;
            color: white;
            background-color: transparent;
        }
        #popup_lose h1{
            margin-top: 30px;
            font-size: 2.5em;
        }
        #popup_lose h2{
            font-size: 5em;
            position: relative;
            top: 0;
            transform: translateY(50%);
            margin-bottom: 10px;
        }
        #popup_lose p{
            font-size: 1.5em;
        }
        #popup_lose a{
            background-image: none;
            display: inline-block;
            margin: 5px;
            font-size: 1.2em;
            border: none;
            padding: 0 5px;
            text-decoration: none;
            cursor: pointer;
        }
        #popup_lose a p:hover{
            background-image: none;
            text-decoration: underline;
            box-shadow: none;
        }
        #popup_lose a:hover{
            box-shadow: none;
        }
        #popup_lose .star{
            background-image: none;
            background-color: transparent;
            width: 100%;
            justify-content: center;
            display: flex;

        }
        #popup_lose .center_img{
            background-color: transparent;
            width: 200px;
            background-image: none;
            justify-content: center;
            display: flex;
        }
        #popup_lose img{
            background-image: none;
            background-color: transparent;
            display: flex;
            justify-content: center;
            margin: auto;
            height: 50px;
            width: 50px;
        }
        #popup_lose .but{
            background-image: none;
            position: relative;
            top: 150px;
        }
        #popup_lose .but, a{
            background-image: none;
            background-color: transparent;
        }
        #popup_lose a p{
            background-image: none;
            position: static;
        }
    </style>

<?php
