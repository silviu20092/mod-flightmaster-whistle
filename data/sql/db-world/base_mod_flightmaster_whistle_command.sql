DELETE FROM `command` WHERE `name` = 'fmw';
INSERT INTO `command` (`name`, `security`, `help`) VALUES ('fmw', 0, 'Syntax: .fmw
Teleports to nearest flight master in your current area');