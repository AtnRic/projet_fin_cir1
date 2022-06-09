let custom; // Si la page a été customisé


// Lettres du labyrinthe
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

let WallDown = ["d", "f", "i", "j", "l", "m", "o"];
let WallLeft = ["e", "g", "j", "k", "l", "m", "n"];
let WallRight = ["c", "g", "h", "i", "l", "n", "o"];
let WallTop = ["b", "f", "h", "k", "m", "n", "o"];

// Redirection vers les images par ambiance.
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

  Gl: "../images/gardes/jungle_guard_gauche.png",
  Gr: "../images/gardes/jungle_guard_droite.png",
  Gar: "../images/gardes/jungle_guard_attack_droite.png",
  Gal: "../images/gardes/jungle_guard_attack_gauche.png",
  Death: "../images/heros/jungle_hero_death.png",

  Theme: "../son/theme_jungle.mp3",
  DeathSound: "../son/sound_hero_death.mp3",
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
  Pl: "../images/heros/space_hero_gauche.png",
  Pr: "../images/heros/space_hero_droite.png",

  Gr: "../images/gardes/space_guard_red_droite.png",
  Gl: "../images/gardes/space_guard_red_gauche.png",
  Gar: "../images/gardes/space_guard_attack_droite.png",
  Gal: "../images/gardes/space_guard_attack_gauche.png",

  Theme: "../son/theme_space.mp3",
  Death: "../images/heros/space_hero_death.png",

  DeathSound: "../son/sound_hero_death.mp3",
};
var Retro = {
  W1: [
    "../images/mazes/pac_maze_one.png",
    "../images/mazes/pac_maze_one.png",
    "../images/mazes/pac_maze_one.png",
    "../images/mazes/pac_maze_one.png",
  ],
  W2: [
    "../images/mazes/pac_maze_two.png",
    "../images/mazes/pac_maze_two.png",
    "../images/mazes/pac_maze_two.png",
    "../images/mazes/pac_maze_two.png",
  ],
  W3: ["../images/mazes/pac_maze_three.png"],
  W4: ["../images/mazes/pac_maze_four.png"],
  B: [
    "../images/mazes/pac_maze_border.png",
    "../images/mazes/pac_maze_border.png",
    "../images/mazes/pac_maze_border.png",
  ],
  Pl: "../images/heros/pac_hero_gauche.png",
  Pr: "../images/heros/pac_hero_droite.png",
  Death: "../images/heros/retro_hero_death.png",
  Gr: "../images/gardes/pac_guard_blue_droite.png",
  Gl: "../images/gardes/pac_guard_blue_gauche.png",
  Gar: "../images/gardes/retro_guard_attack_droite.png",
  Gal: "../images/gardes/retro_guard_attack_gauche.png",

  Theme: "../son/theme_retro.mp3",
  DeathSound: "../son/sound_hero_death.mp3",
};

// Mise en place de l'ambiance.
function SetAmbiance(AmbianceName) {
  switch (AmbianceName) {
    case "Jungle":
      console.warn("A:\n JUNGLE.");
      ThemeGlobal = 1;
      Ambiance = Jungle;
      break;
    case "Retro":
      console.warn("A:\n RETRO.");
      ThemeGlobal = 2;
      Ambiance = Retro;
      break;
    case "Space":
      console.warn("A:\n SPACE.");
      ThemeGlobal = 3;
      Ambiance = Space;
      break;
  }
}

const container = document.getElementById("container");
let rows = document.getElementsByClassName("gridRow");
let cells = document.getElementsByClassName("cell");

// Ajout des class aux pop-up.
let start = false;
document.getElementById("popup").style.visibility = "hidden";
for (i = 0; i < document.getElementsByClassName("restart").length; i++) {
  document
    .getElementsByClassName("restart")
    [i].addEventListener("click", Restart);
}
for (i = 0; i < document.getElementsByClassName("save").length; i++) {
  document.getElementsByClassName("save")[i].addEventListener("click", Save);
}

// Fonction appelée depuis le js.
function PHP_Start(anime, custom, data) {
  document.getElementById("popup_intro").style.visibility = "visible";
  animation = anime;
  console.log("custom : "+custom);
  console.log("data : "+data);
  if (custom) {
    start = true;
    MainMusic = PlaySound(Ambiance.Theme);
    document.getElementById("popup_intro").style.visibility = "hidden";
    sch_Start(anime, custom, data);
  } else {
    document.addEventListener("keydown", function (event) {
      if (!start && event.key != "m" && event.key != "r") {
        start = true;
        document.getElementById("popup_intro").style.visibility = "hidden";
        MainMusic = PlaySound(Ambiance.Theme);
        sch_Start(anime, custom, data);
      }
      if (event.key == "x") {
        if (cheat == true) {
          cheat = false;
        } else {
          cheat = true;
        }
      }
      if (event.key == "m") {
        console.log("theme");
        ThemeSound();
      }
      if (event.key == "r") {
        location.reload();
      }
    });
  }
}

// Lancement différent.
function sch_Start(anime, custom, data) {
  if (custom == true) {
    if (data == null) {
      console.log("RELOAD");
      location.reload();
    }
    let output = data;
    BaseOut = output;

    newOut = output.split(";");
    solveOut = newOut[1].split(",");
    Solver = solveOut;
    tpOut = newOut[2].split(",");
    gardeOut = newOut[3].split(",");
    LongestSolver = newOut[4].split(",");

    console.log("SOLUTION TP " + tpOut.length + " : " + tpOut);
    console.log("SOLUTION GARDE " + gardeOut.length + " : " + gardeOut);
    console.log("SOLUTION S " + Solver.length + " : " + Solver);
    console.log("SOLUTION L " + LongestSolver.length + " : " + LongestSolver);
    console.log("Taille : " + Math.sqrt(newOut[0].length) + " : " + newOut[0]);

    for (i = 0; i < tpOut.length; i++) {
      tpOut[i] = tpOut[i].split(":").map(function (item) {
        return parseInt(item, 10);
      });
    }

    for (i = 0; i < gardeOut.length; i++) {
      gardeOut[i] = gardeOut[i].split(":").map(function (item) {
        return parseInt(item, 10);
      });
    }

    gardeList = [];
    for (i = 0; i < gardeOut.length; i++) {
      gardeList.push(new Garde(i, gardeOut[i][1], gardeOut[i][0]));
    }

    if (output.length == 0) {
      location.reload();
    }
    gardeGlobal = gardeList;
    Launch(
      Math.sqrt(newOut[0].length),
      Array.from(newOut[0]),
      0,
      anime,
      solveOut,
      tpOut
    );
  } else {
    using = false;
    while (using == false) {
      PHP_Function(
        "../tools/function.php",
        "generation",
        function Handle(output) {
          console.log(output);
          if (output == null || output == "") {
            using = false;
          } else {
            using = true;
            BaseOut = output;
            newOut = output.split(";");
            solveOut = newOut[1].split(",");
            Solver = solveOut;
            tpOut = newOut[2].split(",");
            gardeOut = newOut[3].split(",");
            LongestSolver = newOut[4].split(",");

            console.log("SOLUTION TP " + tpOut.length + " : " + tpOut);
            console.log("SOLUTION GARDE " + gardeOut.length + " : " + gardeOut);
            console.log("SOLUTION S " + Solver.length + " : " + Solver);
            console.log(
              "SOLUTION L " + LongestSolver.length + " : " + LongestSolver
            );
            console.log(
              "Taille : " + Math.sqrt(newOut[0].length) + " : " + newOut[0]
            );

            for (i = 0; i < tpOut.length; i++) {
              tpOut[i] = tpOut[i].split(":").map(function (item) {
                return parseInt(item, 10);
              });
            }

            for (i = 0; i < gardeOut.length; i++) {
              gardeOut[i] = gardeOut[i].split(":").map(function (item) {
                return parseInt(item, 10);
              });
            }

            gardeList = [];
            for (i = 0; i < gardeOut.length; i++) {
              gardeList.push(new Garde(i, gardeOut[i][1], gardeOut[i][0]));
            }
            //console.log(gardeList);
            //console.log(tpOut);

            if (output.length == 0) {
              location.reload();
            }
            gardeGlobal = gardeList;
            Launch(
              Math.sqrt(newOut[0].length),
              Array.from(newOut[0]),
              0,
              anime,
              solveOut,
              tpOut
            );
          }
        }
      );
    }
  }
}

// Relancer le labyrinthe sans relancer la page.
function Restart() {
  var e = document.getElementById("container");
  var child = e.lastElementChild;
  while (child) {
    e.removeChild(child);
    child = e.lastElementChild;
  }
  document.removeEventListener("keydown", Click);
  document.getElementById("popup").style.visibility = "hidden";
  document.getElementById("popup_lose").style.visibility = "hidden";
  Attack = false;
  Mouvement = 1;
  PlayerPos = 0;
  LabSize = 0;
  finish = false;
  cheat = false;
  PHP_Start(animation, true, BaseOut);
}

//#region  Variables globales.
let Path = [];
let Mouvement = 1;
let ThemeGlobal;
let BaseOut; // Ensemble de la génération.
let Solver; // Index du solver.
let LongestSolver;
let Labyrinthe; // Lettres du labyrinthe.
let PlayerPos; // Position du joueur.
let LabSize; // Taille du labyrinthe.
let TeleporterStart = []; // Ensemble des téléporteurs de départ.
let TpStruct; // Couples de téléporteurs.
let gardeGlobal = []; // Position des gardes.
let X; // Variation de position des sprites.
let height; // Taille des cases.
let MainMusic; // Musique globale
let animation = false; // Paramètres de lancement.
let cheat = false;
let finish = false; // Le jeu est-il fini.
let Event;
let Attack = false;
//#endregion

// Création d'une grid avec spawn du joueur et des gardes.
function Launch(size, tab, spawnCellId, boolAnimation, solver, tps) {
  Labyrinthe = tab;
  LabSize = size;

  //#region ROWS
  //console.log("Size: " + size);
  makeRows(size);
  cellNum = size;
  //#endregion

  //#region CELLS
  let tmp_img;
  for (i = 0; i < rows.length; i++) {
    for (j = 0; j < cellNum; j++) {
      let newCell = document.createElement("td");
      rows[j].appendChild(newCell).className = "cell";

      let newCellp = document.createElement("p");
      newCell.appendChild(newCellp).className = "absolute";
      newCell.id = i + j * cellNum;
      //newCellp.innerHTML = tab[j][i];
      switch (tab[j * rows.length + i]) {
        case "a":
          tmp_img = AppendImage(Ambiance.W4[0], newCell, "t1");
          break;
        case "b":
          tmp_img = AppendImage(Ambiance.W3[0], newCell, "t2");
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

      newCell.addEventListener("click", function () {
        if (cheat) {
          //TeleportePlayer(newCell.id);
        }
      });
    }
  }

  //#endregion

  //#region ANIMATION

  if (boolAnimation) {
    LabAnim("t1", 1500);
    LabAnim("t2", 1500);
    LabAnim("t3", 1500);
    LabAnim("t4", 1500);
  } else {
    LabAnim("t1", 1);
    LabAnim("t2", 1);
    LabAnim("t3", 1);
    LabAnim("t4", 1);
  }

  //#endregion

  //#region GARDE/TP
  if (gardeGlobal.length == 1 && gardeGlobal[0] == "") {
    console.log("Aucun garde.");
  } else {
    GenerationGarde();
  }
  Teleporter(tps);
  //#endregion

  //#region PLAYER
  setTimeout(function () {
    SpawnPlayer(spawnCellId, solver);
  }, 3000);
  //#endregion
}

// Application lors d'un mouvement du joueur. Input.
function Click(event) {
  cellNum = LabSize;
  const Player = document.getElementById("player");
  const PlayerImg = document.getElementById("playerimg");

  // On vérifie que le mouvement préc. est bien fini & que le joueur n'a pas fini la partie.
  if (activate == false && finish == false) {
    // Génération du solveur.
    if (event.key == "p") {
      Solveur(Solver);
    }
    if (event.key == "o") {
      LongestSolv(LongestSolver);
    }
    // Mouvement vers le bas.
    else if (event.key == "ArrowDown") {
      if (CanMove(PlayerPos, Labyrinthe, "d") || cheat == true) {
        MoveGarde(height, 2);
        activate = true;
        anime({
          targets: "#playerimg",
          translateX: [X, -(7.5 * X)],
          easing: "steps(8)",
          duration: 500,
          loop: false,
        });
        PlayerPos += cellNum;
        NewCell();
        let newPos = document.getElementById(PlayerPos);
        newPos.appendChild(Player);
        PlayerAnim(0, -height);
      }
    }
    // Mouvement vers le haut.
    else if (event.key == "ArrowUp") {
      if (CanMove(PlayerPos, Labyrinthe, "t") || cheat == true) {
        MoveGarde(height, 4);
        activate = true;
        anime({
          targets: "#playerimg",
          translateX: [X, -(7.5 * X)],
          easing: "steps(8)",
          duration: 500,
          loop: false,
        });
        PlayerPos -= cellNum;
        NewCell();
        let newPos = document.getElementById(PlayerPos);
        newPos.appendChild(Player);
        PlayerAnim(0, height);
      }
    }
    // Mouvement vers la gauche.
    else if (event.key == "ArrowLeft") {
      if (CanMove(PlayerPos, Labyrinthe, "l") || cheat == true) {
        MoveGarde(height, 3);
        activate = true;
        anime({
          targets: "#playerimg",
          translateX: [X, -(7.5 * X)],
          easing: "steps(8)",
          duration: 500,
          loop: false,
        });
        PlayerPos -= 1;
        NewCell();
        let newPos = document.getElementById(PlayerPos);
        PlayerImg.src = Ambiance.Pl;
        newPos.appendChild(Player);
        PlayerAnim(height, 0);
      }
    }
    // Mouvement vers la droite.
    else if (event.key == "ArrowRight") {
      if (CanMove(PlayerPos, Labyrinthe, "r") || cheat == true) {
        MoveGarde(height, 1);
        activate = true;
        anime({
          targets: "#playerimg",
          translateX: [X, -(7.5 * X)],
          easing: "steps(8)",
          duration: 500,
          loop: false,
        });
        PlayerPos += 1;
        NewCell();
        let newPos = document.getElementById(PlayerPos);
        PlayerImg.src = Ambiance.Pr;
        newPos.appendChild(Player);
        PlayerAnim(-height, 0);
      }
    }
    // Passage du temps.
    else if (event.key == " ") {
      MoveGarde(height, -1);
    }
    // Si le joueur est sur la case de sortie.
    if (PlayerPos == LabSize * LabSize - 1) {
      Win();
    }
    // Vérification des positions des gardes.
    for (i = 0; i < gardeGlobal.length; i++) {
      if (gardeGlobal[i].pos == PlayerPos) {
        Attack = true;
        break;
      }
    }
    // Mise en mouvement.
    activate = true;
    // Sortie du mouvement.
    setTimeout(function () {
      if (Attack) {
        console.log("Finish");
        Loose();
      }
      if (TeleporterStart.includes(PlayerPos)) {
        for (p = 0; p < TpStruct.length; p++) {
          if (TpStruct[p][0] == PlayerPos) {
            TeleportePlayer(TpStruct[p][1]);
            setTimeout(function () {
              activate = false;
            }, 1000);
          }
        }
      } else {
        activate = false;
      }
    }, 250);
  }
}

// Génération du joueur.
function SpawnPlayer(cellId, solver) {
  //#region Identification
  PlayerPos = cellId;
  var PlayerPosElement = document.getElementById(cellId);
  PlayerPosElement.classList.add("identify");
  //#endregion

  //#region Instantiation
  const Player = document.createElement("div");
  const PlayerImg = document.createElement("img");
  Player.appendChild(PlayerImg);
  Player.id = "player";
  PlayerImg.id = "playerimg";
  PlayerImg.src = Ambiance.Pl;
  PlayerPosElement.appendChild(Player);

  let box = document.getElementById("1");
  let width = box.offsetWidth;
  height = box.offsetHeight;

  Player.style.width = width / 2 + "px";
  Player.style.height = height + "px";
  X = parseFloat(Player.style.width);
  anime({
    targets: "#player",
    translateY: 1000,
    duration: 500,
    easing: "easeInElastic(1, .6)",
    direction: "reverse",
  });
  //#endregion

  //#region Input
  activate = false;
  document.addEventListener("keydown", Click);

  anime({
    targets: ".global",
    rotate: anime.stagger([-360, 360]),
    easing: "easeInOutQuad",
    loop: true,
  });
  //#endregion
}

// Niveau fini.
function Win() {
  if (Solved == false && SolvedLong == false) {
    if (Shortest()) {
      PHP_Function(
        "../pages/points.php",
        "short",
        function Handle(output) {
          console.log(output);
        },
        LabSize
      );
    }
    if (Longest()) {
      PHP_Function(
        "../pages/points.php",
        "long",
        function Handle(output) {
          console.log(output);
        },
        LabSize
      );
    }
  }
  PHP_Function(
    "../pages/points.php",
    "finish",
    function Handle(output) {
      console.log(output);
    },
    LabSize
  );
  Mouvement++;
  // Fin de la partie.
  finish = true;
  MainMusic.pause();

  // Activation de la pop-up et de ses paramètres.
  document.getElementById("short").innerHTML =
    "shortest solution : " + Solver.length;
  document.getElementById("long").innerHTML =
    "longest solution : " + 2 * Solver.length;
  document.getElementById("number").innerHTML = "number of steps :" + Mouvement;
  PlaySound("../son/sound_hero_win.mp3");

  // Pop-up visible.
  setTimeout(function () {
    document.getElementById("popup").style.visibility = "visible";
  }, 1000);

  // Lancement des conf.
  initConfetti();
  render();
}

// Niveau perdu.
function Loose() {
  MainMusic.pause();
  PlaySound(Ambiance.DeathSound);
  finish = true;
  let player = document.getElementById("playerimg");
  console.log(player);
  player.src = Ambiance.Death;
  console.log(Ambiance.Death);

  // Animation de mort.
  anime({
    targets: "#playerimg",
    translateX: [X, -(7.5 * X)],
    easing: "steps(8)",
    duration: 1500,
    loop: false,
  });

  // Pop-up visible.
  setTimeout(function () {
    document.getElementById("popup_lose").style.visibility = "visible";
  }, 1000);
}

// Autorisation d'un mouvement d'une case à une autre.
function CanMove(index, lab, direction) {
  switch (direction) {
    case "t":
      if (index < Math.sqrt(lab.length)) {
        return false;
      }
      if (WallTop.includes(lab[index], 0)) {
        return false;
      } else {
        return true;
      }
      break;
    case "d":
      if (index > LabSize * LabSize - 1 - LabSize) {
        return false;
      }
      if (WallDown.includes(lab[index], 0)) {
        return false;
      } else {
        return true;
      }
      break;
    case "r":
      if (WallRight.includes(lab[index], 0)) {
        return false;
      } else {
        return true;
      }
      break;
    case "l":
      if (index == 0) {
        return false;
      }
      if (WallLeft.includes(lab[index], 0)) {
        return false;
      } else {
        return true;
      }
      break;
  }
}

// Sauvegarde du niveau.
function Save() {
  Arg = [];
  Arg.push(BaseOut);
  Arg.push(ThemeGlobal);
  PHP_Function(
    "../pages/save.php",
    "save",
    function Handle(output) {
      document.location.href = "../pages/profiluser.php";
    },
    Arg
  );
}

// Génération d'un random.
function getRandomInt(max) {
  return Math.floor(Math.random() * max);
}

// Animation d'arrivée des murs.
function LabAnim(attClass, distance) {
  anime({
    targets: "." + attClass,
    translateY: getRandomInt(distance) - getRandomInt(distance),
    translateX: getRandomInt(distance) - getRandomInt(distance),
    duration: 3000,
    direction: "reverse",
    easing: "easeInElastic(1, .2)",
    delay: anime.stagger(10, {}),
  });
}

// Mouvement du joueur.
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

// Création des lignes.
function makeRows(rowNum) {
  for (r = 0; r < rowNum; r++) {
    let row = document.createElement("tr");
    container.appendChild(row).classList.add("gridRow");
    container.appendChild(row).classList.add(r + 1);
  }
}

// Création des murs.
function AppendImage(mediaPath, cell, speClass) {
  cell.classList.add(speClass);
  let newImg = document.createElement("img");
  newImg.classList.add("walls");
  newImg.src = mediaPath;
  cell.appendChild(newImg);
  return newImg;
}

// Fonction d'appel d'une fonction PHP.
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

// Nouvelle structure de garde.
function Garde(id, dir, pos) {
  this.dir = dir;
  this.pos = pos;
  this.id = id;
}

// Génération des gardes avec une liste de garde.
function GenerationGarde() {
  for (i = 0; i < gardeGlobal.length; i++) {
    var Cell = document.getElementById(gardeGlobal[i].pos);
    const GardeDiv = document.createElement("div");
    const GardeImg = document.createElement("img");
    if (Cell == null) {
      break;
    }
    Cell.appendChild(GardeDiv);
    let box = document.getElementById("1");
    let width = box.offsetWidth;
    let height = box.offsetHeight;
    GardeDiv.style.width = width / 2 + "px";
    GardeDiv.style.height = height + "px";
    GardeDiv.classList.add("Garde");
    GardeDiv.id = "G_div" + gardeGlobal[i].id;
    GardeDiv.classList.add("Garde");
    GardeImg.classList.add("GardeImg");
    GardeImg.id = "G_ui" + gardeGlobal[i].id;
    GardeImg.src = Ambiance.Gl;
    GardeDiv.appendChild(GardeImg);
    anime({
      targets: "#G_div" + gardeGlobal[i].id,
      translateY: getRandomInt(3000) - getRandomInt(1500),
      translateX: getRandomInt(3000) - getRandomInt(1500),
      duration: 2000,
      direction: "reverse",
      easing: "easeInElastic(1, .7)",
      delay: anime.stagger(100, {}),
    });
  }
}

// Mouvement d'un garde dans une certaine position.
function MoveGarde(size, move) {
  for (i = 0; i < gardeGlobal.length; i++) {
    let GardeCheck = document.getElementById("G_div" + gardeGlobal[i].id);
    if (GardeCheck == null) {
      break;
    }
    indexIndent = 0;
    XposIndent = 0;
    YposIndent = 0;
    //#region Position
    switch (gardeGlobal[i].dir) {
      case 1: // vers la droite.
        if (!CanMove(gardeGlobal[i].pos, Labyrinthe, "l")) {
          gardeGlobal[i].dir = 3;
          XposIndent = -size;
          indexIndent = 1;
        } else {
          XposIndent = size;
          indexIndent = -1;
        }
        break;
      case 2: //vers le bas.
        if (!CanMove(gardeGlobal[i].pos, Labyrinthe, "d")) {
          gardeGlobal[i].dir = 4;
          YposIndent = size;
          indexIndent = -LabSize;
        } else {
          YposIndent = -size;
          indexIndent = LabSize;
        }
        break;
      case 3: // vers la gauche.
        if (!CanMove(gardeGlobal[i].pos, Labyrinthe, "r")) {
          gardeGlobal[i].dir = 1;
          XposIndent = size;
          indexIndent = -1;
        } else {
          XposIndent = -size;
          indexIndent = 1;
        }
        break;
      case 4: // vers la haut.
        if (!CanMove(gardeGlobal[i].pos, Labyrinthe, "t")) {
          gardeGlobal[i].dir = 2;
          YposIndent = -size;
          indexIndent = LabSize;
        } else {
          YposIndent = size;
          indexIndent = -LabSize;
        }
        break;
    }
    //#endregion

    //#region Check
    switch (gardeGlobal[i].dir) {
      case 1: // vers la droite.
        if (PlayerPos == gardeGlobal[i].pos - 1 && move == 1) {
          Attack = true;
        }
        break;
      case 2: //vers le bas.
        if (PlayerPos == gardeGlobal[i].pos + LabSize && move == 4) {
          Attack = true;
        }
        break;
      case 3: // vers la gauche.
        if (PlayerPos == gardeGlobal[i].pos + 1 && move == 3) {
          Attack = true;
        }
        break;
      case 4: // vers la haut.
        if (PlayerPos == gardeGlobal[i].pos - LabSize && move == 2) {
          Attack = true;
        }
        break;
    }
    //#endregion
    //#region Animation
    gardeGlobal[i].pos += indexIndent;
    let newCell = document.getElementById(gardeGlobal[i].pos);
    if (newCell == null) {
      console.log(gardeGlobal[i].pos);
    }
    let Garde = document.getElementById("G_div" + gardeGlobal[i].id);
    let GardeImg = document.getElementById("G_ui" + gardeGlobal[i].id);

    if (indexIndent < 0) {
      GardeImg.src = Ambiance.Gl;
      if (Attack == true) {
        GardeImg.src = Ambiance.Gal;
      }
    } else {
      GardeImg.src = Ambiance.Gr;
      if (Attack == true) {
        GardeImg.src = Ambiance.Gar;
      }
    }

    let X;
    let box = document.getElementById("1");
    let width = box.offsetWidth;
    let height = box.offsetHeight;
    X = parseFloat(width) / 2;
    newCell.appendChild(Garde);
    Garde.style.width = width / 2 + "px";
    Garde.style.height = height + "px";

    anime({
      targets: "#G_ui" + gardeGlobal[i].id,
      translateX: [X, -(7.5 * X)],
      easing: "steps(8)",
      duration: 500,
      loop: false,
    });
    anime({
      targets: "#G_div" + gardeGlobal[i].id,
      translateX: XposIndent,
      translateY: YposIndent,
      easing: "easeInOutSine",
      direction: "reverse",
      duration: 150,
    });
    //#endregion
  }
}

let Solved = false;
let SolvedLong = false;
// Envoyer la liste de cases qui composent le chemin du solveur.
function LongestSolv(tab) {
  console.log("Long : " + tab.length);

  if (!SolvedLong) {
    SolvedLong = true;
    for (i = 0; i < tab.length; i++) {
      let Cell = document.getElementById(tab[i]);
      const Div = document.createElement("div");

      let box = document.getElementById("1");
      let width = box.offsetWidth;
      let height = box.offsetHeight;

      Div.style.width = width + "px";
      Div.style.height = height + "px";

      const Img = document.createElement("img");
      Cell.appendChild(Div);
      Div.appendChild(Img);

      Div.classList.add("Solveur");
      Img.classList.add("SolveurImg");
      Img.classList.add("s" + i);
      Img.classList.add("l" + i);
      Img.src = "../images/solveur/point.png";
      anime({
        targets: ".l" + i,
        scale: [
          { value: 0, easing: "easeOutSine", duration: 500 + i * 75 },
          { value: 1, easing: "easeInOutQuad", duration: 1200 },
          { value: 0, easing: "easeOutSine", duration: 500 },
        ],
      });
    }
  } else {
    for (i = 0; i < tab.length; i++) {
      anime({
        targets: ".l" + i,
        scale: [
          { value: 0, easing: "easeOutSine", duration: 500 + i * 75 },
          { value: 1, easing: "easeInOutQuad", duration: 1200 },
          { value: 0, easing: "easeOutSine", duration: 500 },
        ],
      });
    }
  }
}
function Solveur(tab) {
  console.log("Court : " + tab.length);
  if (!Solved) {
    Solved = true;
    for (i = 0; i < tab.length; i++) {
      let Cell = document.getElementById(tab[i]);
      const Div = document.createElement("div");

      let box = document.getElementById("1");
      let width = box.offsetWidth;
      let height = box.offsetHeight;

      Div.style.width = width + "px";
      Div.style.height = height + "px";

      const Img = document.createElement("img");
      //console.log(tab[i]);
      Cell.appendChild(Div);
      Div.appendChild(Img);

      Div.classList.add("Solveur");
      Img.classList.add("SolveurImg");
      Img.classList.add("s" + i);
      Img.classList.add("sh" + i);
      Img.src = "../images/solveur/point.png";
      anime({
        targets: ".sh" + i,
        scale: [
          { value: 0, easing: "easeOutSine", duration: 500 + i * 75 },
          { value: 1, easing: "easeInOutQuad", duration: 1200 },
          { value: 0, easing: "easeOutSine", duration: 500 },
        ],
      });
    }
  } else {
    for (i = 0; i < tab.length; i++) {
      anime({
        targets: ".sh" + i,
        scale: [
          { value: 0, easing: "easeOutSine", duration: 500 + i * 75 },
          { value: 1, easing: "easeInOutQuad", duration: 1200 },
          { value: 0, easing: "easeOutSine", duration: 500 },
        ],
      });
    }
  }
}
// Génération des téléporteurs, 0 => [0, 1], 1 => [1, 2]
function Teleporter(tab) {
  let Cell1 = document.getElementById(0);
  let Cell2 = document.getElementById(LabSize * LabSize - 1);

  const Div1 = document.createElement("div");
  const Div2 = document.createElement("div");

  let box = document.getElementById("1");
  let width = box.offsetWidth;
  let height = box.offsetHeight;

  Div1.style.width = width + "px";
  Div1.style.height = height + "px";
  Div2.style.width = width + "px";
  Div2.style.height = height + "px";

  const Img1 = document.createElement("img");
  const Img2 = document.createElement("img");
  Img1.src = "../images/mazes/maze_entree.png";
  Img2.src = "../images/mazes/maze_sortie.png";

  Cell1.appendChild(Div1);
  Div1.appendChild(Img1);
  Cell2.appendChild(Div2);
  Div2.appendChild(Img2);

  Div1.classList.add("Teleporteur");
  Div2.classList.add("Teleporteur");
  Img1.classList.add("TeleporteurImg");
  Img2.classList.add("TeleporteurImg");

  TpStruct = tab;
  for (i = 0; i < tab.length; i++) {
    if (tab[i][0] < 0) {
      break;
    }
    TeleporterStart.push(tab[i][0]);
    let Cell1 = document.getElementById(tab[i][0]);
    let Cell2 = document.getElementById(tab[i][1]);

    const Div1 = document.createElement("div");
    const Div2 = document.createElement("div");

    let box = document.getElementById("1");
    let width = box.offsetWidth;
    let height = box.offsetHeight;

    Div1.style.width = width + "px";
    Div1.style.height = height + "px";
    Div2.style.width = width + "px";
    Div2.style.height = height + "px";

    const Img1 = document.createElement("img");
    const Img2 = document.createElement("img");

    Cell1.appendChild(Div1);
    Div1.appendChild(Img1);
    Cell2.appendChild(Div2);
    Div2.appendChild(Img2);

    Div1.classList.add("Teleporteur");
    Div2.classList.add("Teleporteur");
    Img1.classList.add("TeleporteurImg");
    Img2.classList.add("TeleporteurImg");

    let src1 = "";
    let src2 = "";
    switch (i) {
      case 1:
        src1 = "../images/mazes/tp_blue_input.png";
        src2 = "../images/mazes/tp_blue_output.png";
        break;
      case 2:
        src1 = "../images/mazes/tp_yellow_input.png";
        src2 = "../images/mazes/tp_yellow_output.png";
        break;
      case 3:
        src1 = "../images/mazes/tp_orange_input.png";
        src2 = "../images/mazes/tp_orange_output.png";
        break;
      case 4:
        src1 = "../images/mazes/tp_green_input.png";
        src2 = "../images/mazes/tp_green_output.png";
        break;
      case 0:
        src1 = "../images/mazes/tp_red_input.png";
        src2 = "../images/mazes/tp_red_output.png";
        break;
    }

    Img1.src = src1;
    Img2.src = src2;
  }
}
// Téléportation du joueur.
function TeleportePlayer(cellId) {
  PlayerPos = cellId;
  let newPos = document.getElementById(PlayerPos);
  let Player = document.getElementById("player");
  NewCell();
  PlaySound("../son/sound_teleportation.mp3");
  anime({
    targets: "#player",
    scale: [{ value: 0, easing: "easeOutSine", duration: 500 }],
  });
  setTimeout(function () {
    newPos.appendChild(Player);
    PlaySound("../son/sound_teleportation.mp3");
    anime({
      targets: "#player",
      scale: [{ value: 1, easing: "easeOutSine", duration: 500 }],
    });
  }, 500);
}
// Lecture d'un son.
function PlaySound(path) {
  let file = new Audio(path);
  file.play();
  return file;
}

let ThemeSoundActivate = true;
// Pause sur le son principal.
function ThemeSound() {
  if (MainMusic != null) {
    if (ThemeSoundActivate == true) {
      MainMusic.pause();
      ThemeSoundActivate = false;
    } else {
      MainMusic.play();
      ThemeSoundActivate = true;
    }
  }
}

// Retour sur la page main.
function Return() {
  document.location.href = "../pages/home.php";
}

// Ajout d'une case.
function NewCell() {
  Mouvement++;
  Path.push(PlayerPos);
}

// Comparaison du chemin et du solveur.
function Shortest() {
  const arrOfNum = [];
  Solver.forEach((str) => {
    arrOfNum.push(Number(str));
  });

  for (i = 1; i < Solver.length - 1; i++) {
    if (Path.includes(arrOfNum[i]) == false) {
      console.log(
        "case non contenue par le chemin " + arrOfNum[i] + " " + Path
      );
      return false;
    }
  }
  if (Path.length < Solver.length + LabSize) {
    console.log("Shortest.");
    return true;
  }
  return false;
}

function Longest() {
  const arrOfNum = [];
  console.log(LongestSolver);
  LongestSolver.forEach((str) => {
    arrOfNum.push(Number(str));
  });

  for (i = 1; i < LongestSolver.length - 1; i++) {
    if (Path.includes(arrOfNum[i]) == false) {
      console.log(
        "case non contenue par le chemin " + arrOfNum[i] + " " + Path
      );
      return false;
    }
  }
  if (Path.length < LongestSolver.length + LabSize) {
    console.log("Longest.");
    return true;
  }
  return false;
}
