var labyrinthe = [
  ["k", "f", "b", "f", "f", "f", "b", "f", "f", "o"],
  ["e", "h", "g", "m", "b", "h", "g", "m", "f", "h"],
  ["l", "g", "j", "f", "i", "g", "g", "k", "f", "i"],
  ["n", "j", "f", "h", "k", "d", "a", "a", "f", "h"],
  ["e", "f", "h", "j", "i", "m", "i", "g", "k", "i"],
  ["g", "n", "j", "f", "b", "f", "f", "i", "j", "o"],
  ["g", "j", "f", "f", "i", "k", "h", "k", "f", "h"],
  ["e", "b", "f", "f", "b", "i", "j", "d", "o", "l"],
  ["g", "j", "f", "f", "i", "k", "h", "k", "f", "h"],
  ["j", "f", "f", "f", "f", "i", "j", "d", "o", "l"],
];

var correspondance = {
  a: [0, 0, 0, 0],
  b: [1, 0, 0, 0],
  c: [0, 1, 0, 0],
  d: [0, 0, 1, 0],
  e: [0, 0, 0, 1],
  f: [1, 0, 1, 0],
  g: [0, 1, 0, 1],
  h: [1, 1, 0, 0],
  i: [0, 1, 1, 0],
  j: [0, 0, 1, 1],
  k: [1, 0, 0, 1],
  l: [0, 1, 1, 1],
  m: [1, 0, 1, 1],
  n: [1, 1, 0, 1],
  o: [1, 1, 1, 0],
};

var ListGuarde;

var Jungle = {
  W1: [
    "../images/mazes/jungle_maze_one_a.png",
    "../images/mazes/jungle_maze_one_b.png",
    "../images/mazes/jungle_maze_one_c.png",
    "../images/mazes/jungle_maze_one_d.png",
  ],
  W2: [
    "../images/mazes/jungle_maze_two_a.png",
    "../images/mazes/jungle_maze_two_b.png",
    "../images/mazes/jungle_maze_two_c.png",
    "../images/mazes/jungle_maze_two_d.png",
  ],
  W3: ["../images/mazes/jungle_maze_three.png"],
  W4: ["../images/mazes/jungle_maze_four_a.png"],
  B: [
    "../images/mazes/jungle_maze_border_a.png",
    "../images/mazes/jungle_maze_border_b.png",
    "../images/mazes/jungle_maze_border_c.png",
  ],
  Pl: "../images/heros/jungle_hero_gauche_sprite.png",
  Pr: "../images/heros/jungle_hero_droite_sprite.png",
};

var Retro = {
  W1: [
    "../images/mazes/retro_maze_one.png",
    "../images/mazes/retro_maze_one.png",
    "../images/mazes/retro_maze_one.png",
    "../images/mazes/retro_maze_one.png",
  ],
  W2: [
    "../images/mazes/retro_maze_two.png",
    "../images/mazes/retro_maze_two.png",
    "../images/mazes/retro_maze_two.png",
    "../images/mazes/retro_maze_two.png",
  ],
  W3: ["../images/mazes/retro_maze_three.png"],
  W4: ["../images/mazes/retro_maze_four.png"],
  B: [
    "../images/mazes/retro_maze_border.png",
    "../images/mazes/retro_maze_border.png",
    "../images/mazes/retro_maze_border.png",
  ],
  Pl: "../images/heros/jungle_hero_gauche_sprite.png",
  Pr: "../images/heros/jungle_hero_droite_sprite.png",
};

var Space = {
  W1: [
    "../images/mazes/space_maze_one_a.png",
    "../images/mazes/space_maze_one_b.png",
    "../images/mazes/space_maze_one_c.png",
    "../images/mazes/space_maze_one_c.png",
  ],
  W2: [
    "../images/mazes/space_maze_two.png",
    "../images/mazes/space_maze_two.png",
    "../images/mazes/space_maze_two.png",
    "../images/mazes/space_maze_two.png",
  ],
  W3: ["../images/mazes/space_maze_three.png"],
  W4: ["../images/mazes/space_maze_four.png"],
  B: [
    "../images/mazes/space_maze_border.png",
    "../images/mazes/space_maze_border.png",
    "../images/mazes/space_maze_border.png",
  ],
  Pl: "../images/heros/jungle_hero_gauche_sprite.png",
  Pr: "../images/heros/jungle_hero_droite_sprite.png",
};

let Ambiance = Space;

const container = document.getElementById("container");
let rows = document.getElementsByClassName("gridRow");
let cells = document.getElementsByClassName("cell");

CreateGrid(10, labyrinthe, 14);

function CreateGrid(size, tab, spawnCellId) {
  //#region ROWS
  makeRows(size);
  cellNum = size;
  //#endregion

  //#region CELLS
  for (i = 0; i < rows.length; i++) {
    for (j = 0; j < cellNum; j++) {
      let newCell = document.createElement("td");
      rows[j].appendChild(newCell).className = "cell";

      let newCellp = document.createElement("p");
      newCell.appendChild(newCellp).className = "absolute";
      newCell.id = i + j * cellNum;
      //newCellp.innerHTML = tab[j][i];
      switch (tab[j][i]) {
        case "a":
          AppendImage(Ambiance.W4[0], newCell, "t1");
          break;
        case "b":
          AppendImage(Ambiance.W3[0], newCell, "t2");
          break;
        case "c":
          tmp_img = AppendImage(Ambiance.W3[0], newCell, "t3");
          tmp_img.style.transform = "rotate(90deg)";
          break;
        case "d":
          tmp_img = AppendImage(Ambiance.W3[0], newCell, "t4");
          tmp_img.style.transform = "rotate(180deg)";
          break;
        case "e":
          tmp_img = AppendImage(Ambiance.W3[0], newCell, "t1");
          tmp_img.style.transform = "rotate(-90deg)";
          break;
        case "f":
          R = Math.round(Math.random());
          R1 = Math.round(Math.random());
          if (R) {
            if (R1) {
              tmp_img = AppendImage(Ambiance.W2[0], newCell, "t2");
            } else {
              tmp_img = AppendImage(Ambiance.W2[1], newCell, "t2");
            }
          } else {
            if (R1) {
              tmp_img = AppendImage(Ambiance.W2[2], newCell, "t2");
            } else {
              tmp_img = AppendImage(Ambiance.W2[3], newCell, "t2");
            }
          }
          tmp_img.style.transform = "rotate(90deg)";
          break;
        case "g":
          R = Math.round(Math.random());
          R1 = Math.round(Math.random());
          if (R) {
            if (R1) {
              tmp_img = AppendImage(Ambiance.W2[0], newCell, "t3");
            } else {
              tmp_img = AppendImage(Ambiance.W2[1], newCell, "t3");
            }
          } else {
            if (R1) {
              tmp_img = AppendImage(Ambiance.W2[2], newCell, "t3");
            } else {
              tmp_img = AppendImage(Ambiance.W2[3], newCell, "t3");
            }
          }
          break;
        case "h":
          R = Math.round(Math.random());
          R1 = Math.round(Math.random());
          if (R) {
            if (R1) {
              tmp_img = AppendImage(Ambiance.B[0], newCell, "t4");
            } else {
              tmp_img = AppendImage(Ambiance.B[1], newCell, "t4");
            }
          } else {
            if (R1) {
              tmp_img = AppendImage(Ambiance.B[1], newCell, "t4");
            } else {
              tmp_img = AppendImage(Ambiance.B[2], newCell, "t4");
            }
          }
          tmp_img.style.transform = "rotate(90deg)";
          break;
        case "i":
          R = Math.round(Math.random());
          R1 = Math.round(Math.random());
          if (R) {
            if (R1) {
              tmp_img = AppendImage(Ambiance.B[0], newCell, "t1");
            } else {
              tmp_img = AppendImage(Ambiance.B[1], newCell, "t1");
            }
          } else {
            if (R1) {
              tmp_img = AppendImage(Ambiance.B[1], newCell, "t1");
            } else {
              tmp_img = AppendImage(Ambiance.B[2], newCell, "t1");
            }
          }
          tmp_img.style.transform = "rotate(180deg)";
          break;
        case "j":
          R = Math.round(Math.random());
          R1 = Math.round(Math.random());
          if (R) {
            if (R1) {
              tmp_img = AppendImage(Ambiance.B[0], newCell, "t2");
            } else {
              tmp_img = AppendImage(Ambiance.B[1], newCell, "t2");
            }
          } else {
            if (R1) {
              tmp_img = AppendImage(Ambiance.B[1], newCell, "t2");
            } else {
              tmp_img = AppendImage(Ambiance.B[2], newCell, "t2");
            }
          }
          tmp_img.style.transform = "rotate(-90deg)";
          break;
        case "k":
          R = Math.round(Math.random());
          R1 = Math.round(Math.random());
          if (R) {
            if (R1) {
              tmp_img = AppendImage(Ambiance.B[0], newCell, "t3");
            } else {
              tmp_img = AppendImage(Ambiance.B[1], newCell, "t3");
            }
          } else {
            if (R1) {
              tmp_img = AppendImage(Ambiance.B[1], newCell, "t3");
            } else {
              tmp_img = AppendImage(Ambiance.B[2], newCell, "t3");
            }
          }
          break;
        case "l":
          tmp_img = AppendImage(Ambiance.W1[0], newCell, "t4");
          tmp_img.style.transform = "rotate(180deg)";
          break;
        case "m":
          tmp_img = AppendImage(Ambiance.W1[1], newCell, "t2");
          tmp_img.style.transform = "rotate(-90deg)";
          break;
        case "n":
          tmp_img = AppendImage(Ambiance.W1[2], newCell, "t3");

          break;
        case "o":
          tmp_img = AppendImage(Ambiance.W1[3], newCell, "t4");
          tmp_img.style.transform = "rotate(90deg)";
          break;
      }
    }
  }
  //#endregion

  //#region ANIMATION
  LabAnim("t1");
  LabAnim("t2");
  LabAnim("t3");
  LabAnim("t4");

  //#endregion

  //#region PLAYER
  SpawnPlayer(spawnCellId);
  //#endregion PLAYER
}

function SpawnPlayer(cellId) {
  var PlayerPos = cellId;
  var PlayerPosElement = document.getElementById(cellId);
  PlayerPosElement.classList.add("identify");

  const Player = document.createElement("div");
  const PlayerImg = document.createElement("img");
  Player.appendChild(PlayerImg);
  Player.id = "player";
  PlayerImg.id = "playerimg";
  PlayerImg.src = Ambiance.Pl;
  PlayerPosElement.appendChild(Player);

  anime({
    targets: "#player",
    translateY: 1000,
    duration: 3500,
    direction: "reverse",
  });

  activate = false;
  document.addEventListener("keydown", function (event) {
    if (activate == false) {
      activate = true;
      let box = document.getElementById("1");
      let width = box.offsetWidth;
      let height = box.offsetHeight;

      const animation = anime({
        targets: "#playerimg",
        translateX: [25, -130],
        easing: "steps(6)",
        duration: 550,
      });

      MoveGarde(0, 1, -height, 0);

      if (event.key == "ArrowDown") {
        PHP_Function("../tools/function.php", "Down", function Handle(output) {
          if (output) {
            PlayerPos += cellNum;
            let newPos = document.getElementById(PlayerPos);
            newPos.appendChild(Player);
            PlayerAnim(0, -height);
          }
        });
      }
      if (event.key == "ArrowUp") {
        PHP_Function("../tools/function.php", "Up", function Handle(output) {
          if (output) {
            PlayerPos -= cellNum;
            let newPos = document.getElementById(PlayerPos);
            newPos.appendChild(Player);
            PlayerAnim(0, height);
          }
        });
      }

      if (event.key == "ArrowLeft") {
        PHP_Function("../tools/function.php", "Left", function Handle(output) {
          if (output) {
            PlayerPos -= 1;
            let newPos = document.getElementById(PlayerPos);
            PlayerImg.src = Ambiance.Pl;
            newPos.appendChild(Player);
            PlayerAnim(height, 0);
          }
        });
      }
      if (event.key == "ArrowRight") {
        PHP_Function("../tools/function.php", "Right", function Handle(output) {
          if (output) {
            PlayerPos += 1;
            let newPos = document.getElementById(PlayerPos);
            PlayerImg.src = Ambiance.Pr;
            newPos.appendChild(Player);
            PlayerAnim(-height, 0);
          }
        });
      }
      //document.getElementById("pos").innerHTML = PlayerPos;
      setTimeout(function () {
        activate = false;
      }, 150);
    }
  });
}

function LabAnim(attClass) {
  anime({
    targets: "." + attClass,
    translateY: 1000,
    duration: 1000,
    direction: "reverse",
    delay: anime.stagger(50, { easing: "easeOutQuad" }),
    update: function (a) {
      for (
        let i = 0;
        i < document.getElementsByClassName(attClass).length;
        i++
      ) {
        document.getElementsByClassName(attClass)[i].style.opacity =
          (100 - Math.round(a.progress)) / 100; //(-0.2)
        //if (a.progress == 100) {
        //document.getElementsByClassName(attClass)[i].style.opacity = "1";
        //}
      }
    },
  });
}

function PlayerAnim(indentX, indentY) {
  anime({
    targets: "#player",
    translateX: indentX,
    translateY: indentY,
    easing: "easeInOutSine",
    direction: "reverse",
    duration: 100,
  });
}

function makeRows(rowNum) {
  for (r = 0; r < rowNum; r++) {
    let row = document.createElement("tr");
    container.appendChild(row).classList.add("gridRow");
    container.appendChild(row).classList.add(r + 1);
  }
}

function AppendImage(mediaPath, cell, speClass) {
  cell.classList.add(speClass);
  let newImg = document.createElement("img");
  newImg.classList.add("walls");
  newImg.src = mediaPath;
  cell.appendChild(newImg);
  return newImg;
}

function PHP_Function(fileName, functionName, Awaiting, Arguments) {
  $.ajax({
    type: "POST",
    url: fileName,
    async: false,
    data: {
      functionName: functionName,
      functionParameters: Arguments,
    },
    success: function (data) {
      Awaiting(data);
      console.log(data);
      return data;
    },
    error: function (data) {
      console.error(data);
      return data;
    },
  });
}

var list = [new Garde(0, 20)];
GenerationGarde(list);

function Garde(id, pos) {
  this.id = id;
  this.pos = pos;
}

function GenerationGarde(gardeList) {
  var ListGarde = [];
  for (i = 0; i < gardeList.length; i++) {
    ListGarde.push(Garde(gardeList[i].id, gardeList[i].pos));
  }

  for (i = 0; i < gardeList.length; i++) {
    console.log(gardeList[i].id);
    var Cell = document.getElementById(gardeList[i].pos);
    const GardeDiv = document.createElement("div");
    const GardeImg = document.createElement("img");
    Cell.appendChild(GardeDiv);
    GardeDiv.classList.add("Garde");
    GardeDiv.id = "G_div" + gardeList[i].id;
    GardeDiv.classList.add("Garde");
    GardeImg.classList.add("GardeImg");
    GardeImg.id = "G_ui" + gardeList[i].id;
    GardeImg.src = "../images/gardes/retro_guard.png";
    GardeDiv.appendChild(GardeImg);
  }
}

function MoveGarde(gardeId, posIndent, indentX, indentY) {
  for (i = 0; i < list.length; i++) {
    if (list[i].id == gardeId) {
      list[i].pos += posIndent;
      let newCell = document.getElementById(list[i].pos);
      let Garde = document.getElementById("G_div" + list[i].id);
      newCell.appendChild(Garde);
    }
  }
  anime({
    targets: "#G_div" + gardeId,
    translateX: indentX,
    translateY: indentY,
    easing: "easeInOutSine",
    direction: "reverse",
    duration: 150,
  });
}
