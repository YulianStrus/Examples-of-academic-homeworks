-- phpMyAdmin SQL Dump
-- version 5.0.1
-- https://www.phpmyadmin.net/
--
-- Хост: 127.0.0.1
-- Час створення: Квт 14 2020 р., 22:41
-- Версія сервера: 10.4.11-MariaDB
-- Версія PHP: 7.4.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- База даних: `bookshelf`
--

-- --------------------------------------------------------

--
-- Структура таблиці `author`
--

CREATE TABLE `author` (
  `Id` int(11) UNSIGNED NOT NULL,
  `Name` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Дамп даних таблиці `author`
--

INSERT INTO `author` (`Id`, `Name`) VALUES
(1, 'David Matthew'),
(2, 'Rebecca Levis'),
(3, 'Daniel Bronson'),
(4, 'Ed Lecky-Thompson'),
(5, 'Steven D. Nowicki'),
(6, 'Alec Cove');

-- --------------------------------------------------------

--
-- Структура таблиці `book`
--

CREATE TABLE `book` (
  `Id` int(11) UNSIGNED NOT NULL,
  `Image` varchar(128) NOT NULL DEFAULT 'NoImage.jpeg',
  `Date_publisher` date NOT NULL,
  `Publisher_id` int(11) UNSIGNED NOT NULL,
  `Rating` tinyint(3) UNSIGNED NOT NULL,
  `Price` float(6,2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Дамп даних таблиці `book`
--

INSERT INTO `book` (`Id`, `Image`, `Date_publisher`, `Publisher_id`, `Rating`, `Price`) VALUES
(1, 'NoImage.jpeg', '2019-06-01', 1, 5, 58.69),
(2, 'NoImage.jpeg', '2018-03-01', 2, 3, 45.01),
(3, 'NoImage.jpeg', '2018-07-01', 3, 4, 39.99);

-- --------------------------------------------------------

--
-- Структура таблиці `book_author`
--

CREATE TABLE `book_author` (
  `Id` int(11) UNSIGNED NOT NULL,
  `Book_id` int(10) UNSIGNED NOT NULL,
  `Author_id` int(10) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Дамп даних таблиці `book_author`
--

INSERT INTO `book_author` (`Id`, `Book_id`, `Author_id`) VALUES
(1, 1, 1),
(2, 1, 1),
(3, 1, 2),
(4, 2, 3),
(5, 3, 4),
(6, 3, 2),
(7, 3, 5),
(8, 3, 6);

-- --------------------------------------------------------

--
-- Структура таблиці `publisher`
--

CREATE TABLE `publisher` (
  `Id` int(11) UNSIGNED NOT NULL,
  `Name` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Дамп даних таблиці `publisher`
--

INSERT INTO `publisher` (`Id`, `Name`) VALUES
(1, 'PHP 7 for Beginners'),
(2, 'PHP 5.6 for Professionals'),
(3, 'PHP 5. Objects & Patterns. Best Practices.');

-- --------------------------------------------------------

--
-- Структура таблиці `review`
--

CREATE TABLE `review` (
  `Id` int(11) UNSIGNED NOT NULL,
  `Book_id` int(10) UNSIGNED NOT NULL,
  `Review` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Індекси збережених таблиць
--

--
-- Індекси таблиці `author`
--
ALTER TABLE `author`
  ADD PRIMARY KEY (`Id`);

--
-- Індекси таблиці `book`
--
ALTER TABLE `book`
  ADD PRIMARY KEY (`Id`),
  ADD KEY `Publisher_id` (`Publisher_id`),
  ADD KEY `Publisher_id_2` (`Publisher_id`);

--
-- Індекси таблиці `book_author`
--
ALTER TABLE `book_author`
  ADD PRIMARY KEY (`Id`),
  ADD KEY `Book_id` (`Book_id`),
  ADD KEY `Author_id` (`Author_id`);

--
-- Індекси таблиці `publisher`
--
ALTER TABLE `publisher`
  ADD PRIMARY KEY (`Id`);

--
-- Індекси таблиці `review`
--
ALTER TABLE `review`
  ADD PRIMARY KEY (`Id`),
  ADD KEY `Book_id` (`Book_id`);

--
-- AUTO_INCREMENT для збережених таблиць
--

--
-- AUTO_INCREMENT для таблиці `author`
--
ALTER TABLE `author`
  MODIFY `Id` int(11) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- AUTO_INCREMENT для таблиці `book`
--
ALTER TABLE `book`
  MODIFY `Id` int(11) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT для таблиці `book_author`
--
ALTER TABLE `book_author`
  MODIFY `Id` int(11) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- AUTO_INCREMENT для таблиці `publisher`
--
ALTER TABLE `publisher`
  MODIFY `Id` int(11) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT для таблиці `review`
--
ALTER TABLE `review`
  MODIFY `Id` int(11) UNSIGNED NOT NULL AUTO_INCREMENT;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
