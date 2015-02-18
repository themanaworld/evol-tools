CREATE TABLE IF NOT EXISTS `acc_reg_num_db` (
  `account_id` INT(11) UNSIGNED NOT NULL DEFAULT '0',
  `key` VARCHAR(32) BINARY NOT NULL DEFAULT '',
  `index` INT(11) UNSIGNED NOT NULL DEFAULT '0',
  `value` INT(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`account_id`,`key`,`index`),
  KEY `account_id` (`account_id`)
) ENGINE=InnoDB;

