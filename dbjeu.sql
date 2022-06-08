-- phpMyAdmin SQL Dump
-- version 5.0.4
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost:3306
-- Généré le : mer. 08 juin 2022 à 11:55
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
  `AUTHOR` varchar(64) NOT NULL,
  `STAR_SHORT` int(1) NOT NULL,
  `STAR_LONG` int(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `custom_level`
--

INSERT INTO `custom_level` (`ID`, `NAME`, `THEME`, `ID_AUTHOR`, `DATA`, `CUSTOM`, `AUTHOR`, `STAR_SHORT`, `STAR_LONG`) VALUES
(1, '', 3, 5, 'kffhkffhmhmfhkfhgkhjikhjfikhjckcggjfhggkhkcgmiggglkfilgglggjffiggkikffijbijfffoggjhjffhmikfhkfhggkikfogkfdogehjigjheffijhkhgglkhefijhmbfigjigkigebfojhgkhgkheimigjfbhggglgggjffhjfhgjigjfiljhnkikfiebfdfbfbfieingmhglkhnehjbfahgjhgjfiggljhjhglgmijfffijffimijfi;0,16,32,48,64,80,96,112,128,144,145,161,162,163,179,195,196,197,198,199,200,201,202,218,219,220,221,237,253,254,255;8:53,49:207,78:133;189:2,218:1;0,1,2,3,19,20,4,5,6,7,23,24,25,9,8,53,37,21,22,38,54,70,69,68,67,83,84,85,86,102,118,117,116,115,131,132,148,149,165,181,180,164,163,162,161,145,144,128,129,130,114,113,97,98,82,81,65,66,50,51,52,36,35,34,18,17,33,49,207,223,239,255', 1, '', 0, 0),
(2, '', 3, 5, 'kbhmhkffbfokfhmhggefigkfikfinjhgggjhkijfhgkbdhjigjhggkokigggnebhehgggjhgkiggjigllgggjfcgjhgjhmdhkigeffijfijhjfhggkiefffffffikfiggjhjfbfhkfhkikfijhjfheojingjhjfhneokiefffcjhgkhlggkinefhkinglgjhjigmdikijfigkingkhjhkfdfhnkijbiggjhgeffhjigkhgkijojijfojfojijijo;0,1,2,18,19,20,4,3,153,169,168,167,166,165,181,197,196,195,206,222,221,220,204,205,189,173,174,190,191,207,223,239,238,254,255;3:153,195:206,180:162;35:2,212:1;0,1,2,18,19,20,4,3,153,169,168,167,166,165,149,133,134,135,151,152,136,137,138,154,170,171,187,203,219,218,234,250,251,235,236,252,253,237,221,220,204,205,189,173,174,190,191,207,223,239,238,254,255', 1, '', 0, 0),
(3, '', 3, 5, 'mfffbbffhkhkfffhkokfiehngggjffhgjfikhgjigggmffcgkokijaokiljhkhgggkikfdhjfffilgglglmikfabbbbokijheokfikigggjfimhgjfikogngggkffhjcmhnjfijigjdhnjhgkigkokfbckheinjijfcjhjhgjiggkcmhkfinjfijfhgjcjfijfhjfbbffijhgkfhkhjhkijfokhggjhggjhjckfffijilkigjojfijfffffffimi;0,1,2,3,4,5,21,37,53,69,70,86,87,88,104,120,136,152,168,169,153,154,170,186,202,203,219,235,234,218,217,233,232,231,230,229,245,246,247,248,249,250,251,252,253,237,238,222,221,205,206,207,223,239,255;17:174,157:49,91:81;88:2,84:1;0,1,2,3,4,20,19,18,34,33,32,16,17,174,175,191,190,189,173,172,188,187,171,155,139,138,137,121,105,89,90,91,81,65,66,50,51,35,36,52,53,69,70,86,87,88,104,120,136,152,168,169,153,154,170,186,202,203,219,235,234,218,217,233,232,231,230,229,245,246,247,248,249,250,251,252,253,237,238,222,221,205,206,207,223,239,255', 1, '', 0, 0);

-- --------------------------------------------------------

--
-- Structure de la table `users`
--

CREATE TABLE `users` (
  `ID` int(64) NOT NULL,
  `Pseudo` text NOT NULL,
  `Mdp` text NOT NULL,
  `Nbr_Points` int(64) NOT NULL COMMENT 'Nbr de Points total de l''utilisateur',
  `avatar` varchar(64) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `users`
--

INSERT INTO `users` (`ID`, `Pseudo`, `Mdp`, `Nbr_Points`, `avatar`) VALUES
(14, 'Dousai', '4f0d24b941645161ed5ee39bc053f9ea5afc63f19ee3a0f4323f2092851886c1', 0, 'jungle guard');

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
  MODIFY `ID` int(64) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT pour la table `users`
--
ALTER TABLE `users`
  MODIFY `ID` int(64) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=15;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
