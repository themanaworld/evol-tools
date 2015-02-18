CREATE TABLE IF NOT EXISTS `inventory` (
  `id` INT(11) UNSIGNED NOT NULL AUTO_INCREMENT,
  `char_id` INT(11) UNSIGNED NOT NULL DEFAULT '0',
  `nameid` INT(11) UNSIGNED NOT NULL DEFAULT '0',
  `amount` INT(11) UNSIGNED NOT NULL DEFAULT '0',
  `equip` INT(11) UNSIGNED NOT NULL DEFAULT '0',
  `identify` SMALLINT(6) NOT NULL DEFAULT '0',
  `refine` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
  `attribute` TINYINT(4) UNSIGNED NOT NULL DEFAULT '0',
  `card0` SMALLINT(11) NOT NULL DEFAULT '0',
  `card1` SMALLINT(11) NOT NULL DEFAULT '0',
  `card2` SMALLINT(11) NOT NULL DEFAULT '0',
  `card3` SMALLINT(11) NOT NULL DEFAULT '0',
  `expire_time` INT(11) UNSIGNED NOT NULL DEFAULT '0',
  `favorite` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
  `bound` TINYINT(1) UNSIGNED NOT NULL DEFAULT '0',
  `unique_id` BIGINT(20) UNSIGNED NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  KEY `char_id` (`char_id`)
) ENGINE=InnoDB;

