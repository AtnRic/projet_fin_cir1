-- phpMyAdmin SQL Dump
-- version 5.0.4
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost:3306
-- Généré le : mer. 08 juin 2022 à 08:45
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
  `NAME` text NOT NULL,
  `SIZE` int(64) NOT NULL,
  `GUARD_NUMBER` int(64) NOT NULL,
  `TELEPORTER_NUMBER` int(64) NOT NULL,
  `THEME` int(64) NOT NULL,
  `AUTHOR` text NOT NULL,
  `GUARD_LOCATION` varchar(2000) NOT NULL,
  `TELEPORTEUR_LOCATION` varchar(2000) NOT NULL,
  `MAZE` varchar(2000) NOT NULL,
  `etoileCheminCourt` int(11) NOT NULL,
  `etoileCheminLong` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Déchargement des données de la table `custom_level`
--

INSERT INTO `custom_level` (`ID`, `NAME`, `SIZE`, `GUARD_NUMBER`, `TELEPORTER_NUMBER`, `THEME`, `AUTHOR`, `GUARD_LOCATION`, `TELEPORTEUR_LOCATION`, `MAZE`, `etoileCheminCourt`, `etoileCheminLong`) VALUES
(1, 'Laby', 5, 2, 2, 1, 'Dousai', '', '', '', 1, 1),
(3, 'Rinte', 5, 2, 2, 1, 'Dousai', '', '', '', 1, 0);

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `custom_level`
--
ALTER TABLE `custom_level`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `custom_level`
--
ALTER TABLE `custom_level`
  MODIFY `ID` int(64) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
