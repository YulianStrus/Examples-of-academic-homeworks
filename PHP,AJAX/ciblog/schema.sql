SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";

CREATE TABLE `authors` (
  `id` int(11) UNSIGNED NOT NULL COMMENT 'PK',
  `name` varchar(128) NOT NULL,
  `website` varchar(128) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COMMENT='authors';

CREATE TABLE `categories` (
  `id` int(11) UNSIGNED NOT NULL COMMENT 'pk',
  `name` varchar(128) NOT NULL,
  `display` enum('yes','no') NOT NULL DEFAULT 'yes'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COMMENT='categories';

CREATE TABLE `posts` (
  `id` int(11) UNSIGNED NOT NULL COMMENT 'pk',
  `title` varchar(255) NOT NULL,
  `author_id` int(11) UNSIGNED NOT NULL,
  `category_id` int(11) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;


ALTER TABLE `authors`
  ADD PRIMARY KEY (`id`);

ALTER TABLE `categories`
  ADD PRIMARY KEY (`id`);

ALTER TABLE `posts`
  ADD PRIMARY KEY (`id`),
  ADD KEY `author_id` (`author_id`),
  ADD KEY `category_id` (`category_id`);


ALTER TABLE `authors`
  MODIFY `id` int(11) UNSIGNED NOT NULL AUTO_INCREMENT COMMENT 'PK';

ALTER TABLE `categories`
  MODIFY `id` int(11) UNSIGNED NOT NULL AUTO_INCREMENT COMMENT 'pk';
