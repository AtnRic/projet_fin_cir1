<?php

$link = '../images/popup/popup_jungle.png';
echo "
<div id='popup_intro' style='background-image: url($link)'>
    <h1>Welcome to the Jungle</h1>
    <div class='carrousel'>
		<input type='radio' name='slides' id='radio-1' checked>
		<input type='radio' name='slides' id='radio-2'>
		<input type='radio' name='slides' id='radio-3'>
		<input type='radio' name='slides' id='radio-4'>
        <ul class='slides'>
            <li class='slide'>
                <p>You must reach the exit of the maze : </p>
                <img class='tp' src='../images/mazes/maze_sortie.png' alt='exit'> 
            <li class='slide' id='slide2'>
                <p>You have teleporters available with <br> an entrance : </p><img class='tp' src='../images/mazes/tp_red_input.png' alt='tp'> <p>and an exit :</p> <img  class='tp' src='../images/mazes/tp_red_output.png' alt='tp'><p>Be careful, these teleporters are one-way!</p>
            </li>
            <li class='slide'>
                <p>You must also dodge the guards that advance in sync with you<br> You step, the guards step. <br>They move between two walls and go back and forth : <img class='guard' src='../images/popup/jungle_guard_animation.gif' alt='guard'></p>
            </li>
            <li class='slide'>
                <h1>Press Start</h1>
            </li>
		</ul>
		<div class='slidesNavigation'>
			<label for='radio-1' id='dotForRadio-1'></label>
			<label for='radio-2' id='dotForRadio-2'></label>
			<label for='radio-3' id='dotForRadio-3'></label>
			<label for='radio-4' id='dotForRadio-4'></label>
		</div>
	</div>
</div>";
?>
<style>
    @font-face {
        font-family: 'permanent marker';
        src: url('../../images/font/PermanentMarker-Regular.ttf');
    }

    *{
        font-family: "permanent marker", serif;
    }
    #popup_intro{
        z-index: 1000;
        visibility: visible;
        width: 70vw;
        height: calc(0.82 * 50vw);
        position: absolute;
        top: 50%;
        left: 48%;
        transform: translateX(-50%) translateY(-50%);
        background-size: cover;
    }
    #popup_intro h1, p, h2{
        color: #3E3228;
        background-image: none;
        text-align: center;
        align-items: center;
    }
    h1{
        font-size: 2.5em;
    }
    #popup_intro h2{
        font-size: 1.5em;
        margin-bottom: 10px;
        top: 0;
    }
    p{

        top: 0;
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
        background-color: transparent;
        background-image: none;
    }
    a:hover{
        border-style: solid;
        border-width: 5px;
        border-color: #0ff;
        box-shadow: 0 0 10px 3px #0ff;
        background-color: transparent;
    }

    .carrousel .tp {
        display: block;
        margin: auto auto 10px auto;
        background-color: transparent;
        background-image: none;

    }
    img{
        background-color: transparent;
        display: flex;
        justify-content: center;
        background-image: none;
        margin: auto;
        height: 50px;
        width: 50px;
    }


    a p{
        position: static;
        background-color: transparent;
        background-image: none;
    }
    #canvas{
        visibility: hidden;
    }




    /*Carousel*/
    .carrousel {
        z-index: 1000;
        background-color: transparent;
        text-align: center;
        /*padding: 4.5em 0;
        height: 7.5em;*/
        height: 50vh;
        max-width: 750px;
        margin: auto;
        position: relative;
        overflow: hidden;
        background-image: none;
    }

    .carrousel .slides {
        width: 400%;
        left: 0;
        padding-left: 0;
        padding-top: 1em;
        overflow: hidden;
        list-style: none;
        position: relative;
        background-color: transparent;
        background-image: none;
        -webkit-transition: transform .5s;
        -moz-transition: transform .5s;
        -o-transition: transform .5s;
        transition: transform .5s;
    }
    .carrousel #slide2{
        top: -20px;
        background-color: transparent;
        background-image: none;
    }
    .carrousel .slides li {
        width: 25%;
        position: relative;
        float: left;
        background-color: transparent;
        background-image: none;
    }
    .carrousel li p{
        margin-top: 0;
        background-color: transparent;
        background-image: none;
        font-size: 1.5em;
    }


    .carrousel img {
        width: 3em;
        height: 3em;
        object-fit: cover;
        border-radius: 50%;
        margin-left: -1.5em;
        margin-top: -50px;
        margin-right: 0.5em;
        vertical-align: middle;
        background-color: transparent;
        background-image: none;
    }
    .carrousel img.guard{

        width: 50vh;
        height: auto;
        object-fit: cover;
        border-radius: 0;
        left: 50%;
        transform: translateX(57%);
        margin-top: 40px;
        vertical-align: middle;
        background-color: transparent;
        background-image: none;
    }
    .carrousel .slidesNavigation {
        display: block;
        background-color: transparent;
        background-image: none;
        list-style: none;
        text-align: center;
        bottom: 1em;
        /*--- Centering trick---*/
        /* Absolute positioning*/
        position: absolute;
        /* Abosulte positioning*/
        width: 104px; /*This width  is the addition of the width of all the navigations dots - So in this case is   104 because the navigation dots are 26px (width:10px and 6px marginleft + 6 px marginright) and there are 4 dots so 4x26=104 */
        left: 50%; /*Centering de element*/
        margin-left: -52px; /*adjusting the centering by applying a negative margin of half of the width*/
    }
    .carrousel input {
        display: none;
        background-color: transparent;
        background-image: none;
    }
    .carrousel .slidesNavigation label {
        background-color: transparent;
        float: left;
        margin: 6px;
        display: block;
        height: 10px;
        width: 10px;
        -webkit-border-radius: 50%;
        border-radius: 50%;
        border: solid 2px #3E3228;
        font-size: 0;
        background-image: none;
    }

    #radio-1:checked ~ .slides {
        transform: translateX(0%);
    }
    #radio-2:checked ~ .slides {
        transform: translateX(-25%);
    }
    #radio-3:checked ~ .slides {
        transform: translateX(-50%);
    }
    #radio-4:checked ~ .slides {
        transform: translateX(-75%);
    }

    .carrousel .slidesNavigation label:hover {
        cursor: pointer;
    }
    /* You have to repeat this with each slide/dot */
    .carrousel #radio-1:checked ~ .slidesNavigation label#dotForRadio-1,
    .carrousel #radio-2:checked ~ .slidesNavigation label#dotForRadio-2,
    .carrousel #radio-3:checked ~ .slidesNavigation label#dotForRadio-3,
    .carrousel #radio-4:checked ~ .slidesNavigation label#dotForRadio-4 {
        background: #3E3228;
    }

    @media  (max-width: 796px) {
        .carrousel{
            height: 8.5em;
        }
    }
    @media  (max-width: 480px) {
        .carrousel li p {
            padding-left: 0.5em;
            padding-right: 0.5em;
        }
        .carrousel li q {
            font-size: 1em;
        }
        .carrousel li img {
            width:2em;
            margin-left: -1em;
            margin-right: 0.25em;
        }
    }
</style>


