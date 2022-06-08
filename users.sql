-- phpMyAdmin SQL Dump
-- version 5.0.4
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost:3306
-- Généré le : mer. 08 juin 2022 à 08:42
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
(11, 'Dousai', '4f0d24b941645161ed5ee39bc053f9ea5afc63f19ee3a0f4323f2092851886c1', 0, 'jungle guard'),
(12, 'Patrick', '4f0d24b945161ed5ee39bc053f9ea5afc63f19ee3a0f4323f2092851886c1', 0, 'retro hero'),
(13, 'Paul', '4f0d24b945161ed5ee39bc053f9ea5afc63f19ee3a0f4323f2092851886c1', 0, 'retro hero');

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `users`
--
ALTER TABLE `users`
  MODIFY `ID` int(64) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=14;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
