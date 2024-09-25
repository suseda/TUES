DROP DATABASE IF EXISTS DTB1;
CREATE DATABASE DTB1;
USE DTB1;

set sql_safe_updates=0;
set sql_mode=only_full_group_by;

CREATE TABLE Team(
id int PRIMARY KEY AUTO_INCREMENT,
name varchar(200) NOT NULL UNIQUE,
email varchar(200) CHECK (email LIKE "%@%")
);

CREATE TABLE Racer(
id int PRIMARY KEY AUTO_INCREMENT,
name varchar(200) NOT NULL,
-- Това може да е char(10), защото се кара, когато въведем различен брой символи
-- от 10
phone_number varchar(10) CHECK (phone_number LIKE "__________"),
weight int CHECK( weight > 0),
team_id int not null,
FOREIGN KEY(team_id) REFERENCES Team(id)
);

CREATE TABLE Race(
id int PRIMARY KEY AUTO_INCREMENT,
name varchar(200) NOT NULL,
city varchar(200) NOT NULL,
date date NOT NULL
);

CREATE Table Lap(
id int PRIMARY KEY AUTO_INCREMENT,
duration float CHECK(duration > 0),
number int CHECK( number > 0),
racer_id int not null,
FOREIGN KEY (racer_id) REFERENCES Racer(id),
race_id int not null,
FOREIGN KEY (race_id) REFERENCES Race(id),
UNIQUE (number, racer_id, race_id)
);

insert into Team(name, email) values ("Team1", "team1@example.com");
insert into Team(name, email) values ("Team2", "team2@example.com");
insert into Team(name, email) values ("Team3", "team3@example.com");

insert into Racer(name, phone_number, weight, team_id) values ("T1 R1", "1234567890", 70, 1);
insert into Racer(name, phone_number, weight, team_id) values ("T1 R2", "1234567890", 90, 1);

insert into Race(name, city, date) values ("R1", "City1", "2022-01-01");

insert into Lap(duration, number, racer_id, race_id) values (50, 1, 1, 1);
insert into Lap(duration, number, racer_id, race_id) values (50.1, 2, 1, 1);
insert into Lap(duration, number, racer_id, race_id) values (50.4, 3, 1, 1);
insert into Lap(duration, number, racer_id, race_id) values (50.2, 4, 1, 1);
insert into Lap(duration, number, racer_id, race_id) values (50.1, 5, 1, 1);


-- 1 - [Име на отбор, име на състезател, номер на обиколка, време, име на състезание] За всяка обиколка.
SELECT Team.name, Racer.name, Lap.number, Lap.duration, Race.name FROM Lap
LEFT JOIN Racer on Lap.racer_id = Racer.id
LEFT JOIN Race on Lap.race_id = Race.id
LEFT JOIN Team on Racer.team_id = Team.id;


-- 2 - Изведете колко обиколки е направил всеки състезател [Име състезател, брой]
SELECT Racer.name, COUNT(Lap.number) FROM Racer
LEFT JOIN Lap ON Lap.racer_id = Racer.id
GROUP BY Racer.name;

-- 3 - Изведете колко обиколки е направил всеки състезател за всяко състезание [Име състезател, Име състезание, брой]
SELECT Racer.name, Race.name, COUNT(Lap.number) FROM Lap
LEFT JOIN Racer ON Lap.racer_id = Racer.id
LEFT JOIN Race ON Lap.race_id = Race.id
GROUP BY Racer.name, Race.name;


-- 4 - Изведете кой състезател има най-малко обиколки на всички състезания по време на 2022.
SELECT * FROM Racer
LEFT JOIN Racer ON Racer.id = Lap.racer_id AND YEAR(Race.date) = 2022
GROUP BY Racer.name
ORDER BY COUNT(Race.id) ASC
LIMIT 1;

-- 5 - Изведете най-бързите обилколки за всеки състезател на всяко състезание [Име състезател, Име състезание, най-бърза]
SELECT Racer.name,Race.name, MIN(Lap.duration) FROM Lap
LEFT JOIN Racer ON Lap.racer_id = Racer.id
LEFT JOIN Race ON Lap.race_id = Race.id
GROUP BY Racer.name, Race.name;

-- 6 - Изведете [Име на състезател, Име на състезаение] за всеки състезател (без повторения).
SELECT DISTINCT Racer.name,Race.name FROM Lap
LEFT JOIN Race ON Race.id = Lap.race_id
LEFT JOIN Racer ON Racer.id = Lap.racer_id;


-- 7 - Изведете всички състезания, които нямат обиколки
SELECT Race.name FROM Race
LEFT JOIN Lap ON Lap.race_id = Race.id
WHERE Lap.id IS NULL;

-- 8 - Изведете всички отбори, които нямат хора тях
SELECT Team.name FROM Team
LEFT JOIN Racer ON Racer.team_id = Team.id
WHERE Lap.id IS NULL;

-- 9 - Кой отбор е направил най бързата обиколка на състезанието V 4h? 

-- 10 - Кой отбор е направил най много на брой обиколки на състезанието V 4h?

