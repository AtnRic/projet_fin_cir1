<?php

echo "<canvas class='confetti' id='canvas'></canvas>";
$link = "../images/popup/popup_jungle.png";
echo "
<div class='popup' style='background-image: url($link)'>
    <h1>Welcome to the Jungle</h1>
    <h2>Well Done !</h2>
    <p>number of steps : </p>
    <p>shortest solution : </p>
    <p>longest solution : </p>
    <div class='star'>
        <img src='../images/popup/star.png' alt='star'>
        <img src='../images/popup/star_empty.png' alt='star'>
    </div>
    <div class='but'>
        <button>replay</button>
        <button>home</button>
        <button>record</button> 
        <button>next level</button> 
    </div>
    
     
</div>";
?>

<style>
    h1, h2, p, img{
        background-image: none;
        text-align: center;
        align-items: center;
    }
    .star{
        align-items: center;
        background-image: none;
        position: absolute;
        top: 75%;
        left: 50%;
        transform: translateX(-50%) translateY(-50%);
    }
    img{
        display: inline-block;
        margin: auto;
        height: 80px;
        width: 80px;

    }
    h1{
        margin-top: 80px;
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
        margin: 10px;
        flex: fit-content;
    }
    .but{
        position: absolute;
        display: flex;
        background-image: none;
        align-items: center;
    }
    .popup{
        width: 60vw;
        height: calc(0.7 * 50vw);
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





    @media screen and (max-width: 1170px) {
        .popup h1 {
            font-size: 2em;
        }
        .popup h2 {
            font-size: 1.5em;
        }
        .popup p, button {
            font-size: 1em;
        }

    }
</style>


<script>
//-----------Var Inits--------------
canvas = document.getElementById("canvas");
ctx = canvas.getContext("2d");
canvas.width = window.innerWidth;
canvas.height = window.innerHeight;
cx = ctx.canvas.width / 2;
cy = ctx.canvas.height / 2;

let confetti = [];
    const confettiCount = 700;
    const gravity = 1;
    const terminalVelocity = 4;
    const drag = 0.075;
    const colors = [
    { front: 'red', back: 'darkred' },
    { front: 'green', back: 'darkgreen' },
    { front: 'blue', back: 'darkblue' },
    { front: 'yellow', back: 'darkyellow' },
    { front: 'orange', back: 'darkorange' },
    { front: 'pink', back: 'darkpink' },
    { front: 'purple', back: 'darkpurple' },
    { front: 'turquoise', back: 'darkturquoise' }];


    //-----------Functions--------------
    resizeCanvas = () => {
    canvas.width = window.innerWidth;
    canvas.height = window.innerHeight;
    cx = ctx.canvas.width / 2;
    cy = ctx.canvas.height / 2;
};

    randomRange = (min, max) => Math.random() * (max - min) + min;

    initConfetti = () => {
    for (let i = 0; i < confettiCount; i++) {
        confetti.push({
          color: colors[Math.floor(randomRange(0, colors.length))],
          dimensions: {
            x: randomRange(10, 20),
            y: randomRange(10, 30) },

          position: {
            x: randomRange(0, canvas.width),
            y: canvas.height - 1 },

          rotation: randomRange(0, 2 * Math.PI),
          scale: {
            x: 1,
            y: 1 },

          velocity: {
            x: randomRange(-25, 25),
            y: randomRange(0, -50) } });


      }
    };

    //---------Render-----------
    render = () => {
    ctx.clearRect(0, 0, canvas.width, canvas.height);

    confetti.forEach((confetto, index) => {
        let width = confetto.dimensions.x * confetto.scale.x;
        let height = confetto.dimensions.y * confetto.scale.y;

        // Move canvas to position and rotate
        ctx.translate(confetto.position.x, confetto.position.y);
        ctx.rotate(confetto.rotation);

        // Apply forces to velocity
        confetto.velocity.x -= confetto.velocity.x * drag;
        confetto.velocity.y = Math.min(confetto.velocity.y + gravity, terminalVelocity);
        confetto.velocity.x += Math.random() > 0.5 ? Math.random() : -Math.random();

        // Set position
        confetto.position.x += confetto.velocity.x;
        confetto.position.y += confetto.velocity.y;

        // Delete confetti when out of frame
        if (confetto.position.y >= canvas.height) confetti.splice(index, 1);

        // Loop confetto x position
        if (confetto.position.x > canvas.width) confetto.position.x = 0;
        if (confetto.position.x < 0) confetto.position.x = canvas.width;

        // Spin confetto by scaling y
        confetto.scale.y = Math.cos(confetto.position.y * 0.1);
        ctx.fillStyle = confetto.scale.y > 0 ? confetto.color.front : confetto.color.back;

        // Draw confetto
        ctx.fillRect(-width / 2, -height / 2, width, height);

        // Reset transform matrix
        ctx.setTransform(1, 0, 0, 1, 0, 0);
      });

      window.requestAnimationFrame(render);

    };

    //---------Execution--------
    initConfetti();
    render();

    //----------Resize----------
    window.addEventListener('resize', function () {
        resizeCanvas();
    });
</script>