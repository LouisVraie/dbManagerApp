-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost
-- Généré le : jeu. 24 fév. 2022 à 15:54
-- Version du serveur : 10.3.31-MariaDB-0+deb10u1
-- Version de PHP : 7.3.29-1~deb10u1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `dbManagerApp_test`
--

-- --------------------------------------------------------

--
-- Structure de la table `Achat`
--

CREATE TABLE `Achat` (
  `numeroAchat` int(11) NOT NULL,
  `numeroClient` int(11) NOT NULL,
  `numeroVendeur` int(11) NOT NULL,
  `numeroTypeProduit` int(11) NOT NULL,
  `numeroProduit` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `Achat`
--

INSERT INTO `Achat` (`numeroAchat`, `numeroClient`, `numeroVendeur`, `numeroTypeProduit`, `numeroProduit`) VALUES
(1, 1, 4, 5, 1003),
(2, 3, 3, 6, 1008),
(3, 3, 6, 6, 1007),
(4, 2, 2, 3, 1011),
(5, 2, 3, 1, 1001),
(6, 4, 1, 4, 1006),
(7, 4, 1, 4, 1015);

-- --------------------------------------------------------

--
-- Structure de la table `Client`
--

CREATE TABLE `Client` (
  `numeroClient` int(11) NOT NULL,
  `nom` varchar(25) DEFAULT NULL,
  `prenom` varchar(25) DEFAULT NULL,
  `age` int(11) DEFAULT NULL,
  `dateInscription` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `Client`
--

INSERT INTO `Client` (`numeroClient`, `nom`, `prenom`, `age`, `dateInscription`) VALUES
(1, 'thomassin', 'gilles', 25, '2022-02-24'),
(2, 'legrand', 'julien', 30, '2022-02-20'),
(3, 'Arnaud', 'martine', 50, '2022-02-20'),
(4, 'coret', 'benoit', 40, '2022-01-15');

-- --------------------------------------------------------

--
-- Structure de la table `Produit`
--

CREATE TABLE `Produit` (
  `numeroProduit` int(11) NOT NULL,
  `numeroTypeProduit` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `Produit`
--

INSERT INTO `Produit` (`numeroProduit`, `numeroTypeProduit`) VALUES
(1001, 1),
(1010, 1),
(1005, 2),
(1009, 2),
(1002, 3),
(1011, 3),
(1006, 4),
(1014, 4),
(1015, 4),
(1003, 5),
(1012, 5),
(1013, 5),
(1004, 6),
(1007, 6),
(1008, 6);

-- --------------------------------------------------------

--
-- Structure de la table `TypeContrat`
--

CREATE TABLE `TypeContrat` (
  `numeroTypeContrat` int(11) NOT NULL,
  `libelle` varchar(25) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `TypeContrat`
--

INSERT INTO `TypeContrat` (`numeroTypeContrat`, `libelle`) VALUES
(1, 'CDD'),
(2, 'CDI'),
(3, 'Aprentissage');

-- --------------------------------------------------------

--
-- Structure de la table `TypeProduit`
--

CREATE TABLE `TypeProduit` (
  `numeroTypeProduit` int(11) NOT NULL,
  `libelle` varchar(25) DEFAULT NULL,
  `prix` float DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `TypeProduit`
--

INSERT INTO `TypeProduit` (`numeroTypeProduit`, `libelle`, `prix`) VALUES
(1, 'pantalon', 25.99),
(2, 'short', 19.59),
(3, 'maillot de bain', 29.99),
(4, 'tee shirt', 11.9),
(5, 'chemise', 28),
(6, 'echarpe', 5.7);

-- --------------------------------------------------------

--
-- Structure de la table `Vendeur`
--

CREATE TABLE `Vendeur` (
  `numeroVendeur` int(11) NOT NULL,
  `nom` varchar(25) DEFAULT NULL,
  `prenom` varchar(25) DEFAULT NULL,
  `age` int(11) DEFAULT NULL,
  `numeroTypeContrat` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `Vendeur`
--

INSERT INTO `Vendeur` (`numeroVendeur`, `nom`, `prenom`, `age`, `numeroTypeContrat`) VALUES
(1, 'maissa', 'remi', 19, 2),
(2, 'vrai', 'louis', 20, 1),
(3, 'lopez', 'jonathan', 20, 3),
(4, 'pourroy', 'theo', 19, 2),
(5, 'casanelli', 'nolann', 20, 1),
(6, 'bittoni', 'ugo', 19, 3);

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `Achat`
--
ALTER TABLE `Achat`
  ADD PRIMARY KEY (`numeroAchat`),
  ADD KEY `numeroClient` (`numeroClient`),
  ADD KEY `numeroVendeur` (`numeroVendeur`),
  ADD KEY `numeroTypeProduit` (`numeroTypeProduit`),
  ADD KEY `numeroProduit` (`numeroProduit`);

--
-- Index pour la table `Client`
--
ALTER TABLE `Client`
  ADD PRIMARY KEY (`numeroClient`);

--
-- Index pour la table `Produit`
--
ALTER TABLE `Produit`
  ADD PRIMARY KEY (`numeroProduit`),
  ADD KEY `numeroTypeProduit` (`numeroTypeProduit`);

--
-- Index pour la table `TypeContrat`
--
ALTER TABLE `TypeContrat`
  ADD PRIMARY KEY (`numeroTypeContrat`);

--
-- Index pour la table `TypeProduit`
--
ALTER TABLE `TypeProduit`
  ADD PRIMARY KEY (`numeroTypeProduit`);

--
-- Index pour la table `Vendeur`
--
ALTER TABLE `Vendeur`
  ADD PRIMARY KEY (`numeroVendeur`),
  ADD KEY `numeroTypeContrat` (`numeroTypeContrat`);

--
-- Contraintes pour les tables déchargées
--

--
-- Contraintes pour la table `Achat`
--
ALTER TABLE `Achat`
  ADD CONSTRAINT `Achat_ibfk_1` FOREIGN KEY (`numeroClient`) REFERENCES `Client` (`numeroClient`),
  ADD CONSTRAINT `Achat_ibfk_2` FOREIGN KEY (`numeroVendeur`) REFERENCES `Vendeur` (`numeroVendeur`),
  ADD CONSTRAINT `Achat_ibfk_3` FOREIGN KEY (`numeroTypeProduit`) REFERENCES `TypeProduit` (`numeroTypeProduit`),
  ADD CONSTRAINT `Achat_ibfk_4` FOREIGN KEY (`numeroProduit`) REFERENCES `Produit` (`numeroProduit`);

--
-- Contraintes pour la table `Produit`
--
ALTER TABLE `Produit`
  ADD CONSTRAINT `Produit_ibfk_1` FOREIGN KEY (`numeroTypeProduit`) REFERENCES `TypeProduit` (`numeroTypeProduit`);

--
-- Contraintes pour la table `Vendeur`
--
ALTER TABLE `Vendeur`
  ADD CONSTRAINT `Vendeur_ibfk_1` FOREIGN KEY (`numeroTypeContrat`) REFERENCES `TypeContrat` (`numeroTypeContrat`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
