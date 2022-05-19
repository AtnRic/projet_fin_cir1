<!DOCTYPE html>
<html lang='fr'>
<head>
<link rel="stylesheet" type="text/css" href="../css/custom.css">
</head>
<body>
  <div class="title">
    <h1>Welcome to the sandbox</h1>
    <h4>Here you can create your own maze</h4>
  </div>
<div class="range">
  <!--[X] : valeur qui changera selon la position du curseur-->
  <label for="panel_size">Taille du labyrinthe : [X]</label>
  <input
      type="range"
      name="participants"
      min="5"
      max="51"
      value="20"
    >
    <br>
    <label for="panel_size">Nombre de garde : [X]</label>
    <input
      type="range"
      name="participants"
      min="5"
      max="51"
      value="20"
    > 
  <button>Générer</button>
</div>

</body>