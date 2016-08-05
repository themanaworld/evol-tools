DROP TABLE IF EXISTS `login`;

CREATE TABLE IF NOT EXISTS `login` (
  `account_id` INT(11) UNSIGNED NOT NULL AUTO_INCREMENT,
  `userid` VARCHAR(23) NOT NULL DEFAULT '',
  `user_pass` VARCHAR(32) NOT NULL DEFAULT '',
  `sex` ENUM('M','F','S') NOT NULL DEFAULT 'M',
  `email` VARCHAR(39) NOT NULL DEFAULT '',
  `group_id` TINYINT(3) NOT NULL DEFAULT '0',
  `state` INT(11) UNSIGNED NOT NULL DEFAULT '0',
  `unban_time` INT(11) UNSIGNED NOT NULL DEFAULT '0',
  `expiration_time` INT(11) UNSIGNED NOT NULL DEFAULT '0',
  `logincount` MEDIUMINT(9) UNSIGNED NOT NULL DEFAULT '0',
  `lastlogin` DATETIME NULL, 
  `last_ip` VARCHAR(100) NOT NULL DEFAULT '',
  `birthdate` DATE NULL,
  `character_slots` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
  `pincode` VARCHAR(4) NOT NULL DEFAULT '',
  `pincode_change` INT(11) UNSIGNED NOT NULL DEFAULT '0',
  PRIMARY KEY (`account_id`),
  KEY `name` (`userid`)
) ENGINE=InnoDB AUTO_INCREMENT=2000000; 

INSERT INTO `login` (`account_id`, `userid`, `user_pass`, `sex`, `email`) VALUES ('1', 's1', 'p1', 'S','athena@athena.com');

