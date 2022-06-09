-- phpMyAdmin SQL Dump
-- version 5.0.4
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost:3306
-- Généré le : jeu. 09 juin 2022 à 14:43
-- Version du serveur :  5.7.24
-- Version de PHP : 8.0.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `dbjeu`
--

-- --------------------------------------------------------

--
-- Structure de la table `custom_level`
--

CREATE TABLE `custom_level` (
  `ID` int(64) NOT NULL,
  `NAME` varchar(700) DEFAULT NULL,
  `THEME` int(64) DEFAULT NULL,
  `ID_AUTHOR` int(64) DEFAULT NULL,
  `DATA` varchar(2000) DEFAULT NULL,
  `CUSTOM` tinyint(1) DEFAULT NULL,
  `LINK` varchar(700) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `custom_level`
--

INSERT INTO `custom_level` (`ID`, `NAME`, `THEME`, `ID_AUTHOR`, `DATA`, `CUSTOM`, `LINK`) VALUES
(25, 'Houle', 2, 6, 'kffhkbokhkfhmfhkhnkffhnkfhkfhngkhggjfigjhjfhggggjhmijcmijogggggggmfbdognkijijckikfhgkhkfiggglggkhlkheigkbhkddfikijieimbcgjfieijfijikiggjikhkhjffhjfhlgebffikokfokikcjhngjijhmheffdbigjfbfikikbikignggjhmhjhjckfhjojfhgkfimigkimcgjdojhgnjhgjhjfhnkigjhkfhgefhggkffhjiefigngmfijimdhjinjijogeigmhjffikoeijhmhkfbfimfcnkffijojhjfhmhjhgkojfcehjfhkfijikffffhgkhjhjfadckffiljhkigkffhjfffhjilgnjhmikcjhmhkfijfigkhefhkfikffijfckbijhjhgehmhnkigjikigkojffffhjilkhehgggjhgeikimfikijfhkhkogkffiggjigeojignjffffimbojiggkilkhkigkfijhkfigkfffhkhjbfhgggkfijdbigkhkigmbijfhnggjhjhjdaiehkfhjfclgefikikbojiggngmikhjbijimikhefieffafijffhjigjffijheffhkfigefoefhjfhkbogkbdfhkbogjfhjikhggkhjhjfheijhjijhmiggkimfdbogeilggnehkijfojffhjffcjikfhngkigkfigjigjffffhmfikfhgmfikiggjhlgkfinkahmfhnjfhkikiefbogkcgkikilkhgggjffiehkijhgkcnjfigjijfikfigjigkfffigjbogglggmhkikfffhjfogkfijhmfhgnjhljheikieogkfhjfffijfffdffijdojffijfdfdfdimdffffo;0,30,60,90,120,150,151,181,182,183,213,243,273,274,304,303,302,301,300,330,331,361,362,392,391,390,420,450,480,510,511,541,540,570,600,601,602,603,604,605,575,576,606,607,608,609,639,669,670,640,641,671,672,702,703,704,705,735,765,795,825,855,885,886,887,888,889,890,891,892,862,863,864,894,895,896,897,898,899;382:148,827:690,388:29;870:1;0,30,60,90,120,150,151,181,182,183,213,243,273,274,304,303,302,301,300,330,331,361,362,392,391,390,420,450,480,510,511,541,540,570,600,601,602,603,604,605,575,576,606,607,608,609,639,669,670,640,641,671,672,702,703,704,705,735,765,795,825,855,885,886,887,888,889,890,891,892,862,863,864,894,895,896,897,898,899', 1, '.php?NAME=Houle&ID_AUTHOR=6&custo=1');

-- --------------------------------------------------------

--
-- Structure de la table `users`
--

CREATE TABLE `users` (
  `ID` int(64) NOT NULL,
  `Pseudo` text NOT NULL,
  `Mdp` text NOT NULL,
  `Nbr_Points` int(64) NOT NULL COMMENT 'Nbr de Points total de l''utilisateur',
  `avatar` varchar(700) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `users`
--

INSERT INTO `users` (`ID`, `Pseudo`, `Mdp`, `Nbr_Points`, `avatar`) VALUES
(6, 'FreshAvocado2', '012afd865185dc82e0020d168df781c6bb74ae07a33d44f766a97b5fed54fdb0', 0, 'jungle hero');

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `custom_level`
--
ALTER TABLE `custom_level`
  ADD PRIMARY KEY (`ID`);

--
-- Index pour la table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `custom_level`
--
ALTER TABLE `custom_level`
  MODIFY `ID` int(64) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=26;

--
-- AUTO_INCREMENT pour la table `users`
--
ALTER TABLE `users`
  MODIFY `ID` int(64) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
