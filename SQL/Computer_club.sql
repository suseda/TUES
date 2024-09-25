DROP DATABASE IF EXISTS mydtb3;
CREATE DATABASE mydtb3;
USE mydtb3;

SET sql_safe_updates=0;
SET sql_mode=only_full_group_by;

CREATE TABLE Person (
	id int PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(100) NOT NULL,
    age int check(age > 0)
);

CREATE TABLE Club (
	id int PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(100) NOT NULL,
    adress VARCHAR(100) NOT NULL
);

CREATE TABLE Computer (
	id int PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(100) NOT NULL UNIQUE,
    club_id int,
    FOREIGN KEY (club_id) REFERENCES Club(id)
);

CREATE TABLE Peripheral (
	id int PRIMARY KEY AUTO_INCREMENT,
    brand VARCHAR(100) NOT NULL,
    type enum("mouse", "keyboard", "monitor"),
    computer_id int NOT NULL,
    FOREIGN KEY (computer_id) REFERENCES Computer(id)
);

CREATE TABLE Person_computer (
	id int PRIMARY KEY AUTO_INCREMENT,
    date date NOT NULL,
    person_id int,
    FOREIGN KEY (person_id) REFERENCES Person(id),
    computer_id int,
    FOREIGN KEY (computer_id) REFERENCES Computer(id),
    UNIQUE(computer_id, date)
);

INSERT INTO Person(name, age) VALUES("Misho", 26);
INSERT INTO Person(name, age) VALUES("Stefi", 23);

INSERT INTO Club(name, adress) VALUES("Tues", "Mladost");
INSERT INTO Club(name, adress) VALUES("Not Tues", "Not Mladost");

INSERT INTO Computer(name, club_id) VALUES("Alienware 1", 1);
INSERT INTO Computer(name, club_id) VALUES("Alienware 51", 1);
INSERT INTO Computer(name, club_id) VALUES("Apple", NULL);

INSERT INTO Peripheral(brand, type, computer_id) VALUES("Microsoft ergo", "mouse", 1);
INSERT INTO Peripheral(brand, type, computer_id) VALUES("Microsoft ergo", "keyboard", 1);
INSERT INTO Peripheral(brand, type, computer_id) VALUES("ALienware 37", "monitor", 1);

INSERT INTO Peripheral(brand, type, computer_id) VALUES("Logitech MX2", "mouse", 2);
INSERT INTO Peripheral(brand, type, computer_id) VALUES("Logitech MX3", "keyboard", 2);
INSERT INTO Peripheral(brand, type, computer_id) VALUES("DELL XPS 25", "monitor", 2);

INSERT INTO Peripheral(brand, type, computer_id) VALUES("Apple", "mouse", 3);
INSERT INTO Peripheral(brand, type, computer_id) VALUES("Apple", "keyboard", 3);
INSERT INTO Peripheral(brand, type, computer_id) VALUES("Apple 25", "monitor", 3);

INSERT INTO Person_computer(person_id, computer_id, date) VALUES(1,1,"2022-01-01");
INSERT INTO Person_computer(person_id, computer_id, date) VALUES(1,2,"2022-01-01");

INSERT INTO Person_computer(person_id, computer_id, date) VALUES(2,1,"2022-01-02");
INSERT INTO Person_computer(person_id, computer_id, date) VALUES(2,2,"2023-02-02");

-- 1
SELECT Club.name, Computer.name, Peripheral.brand, Peripheral.type FROM Computer
LEFT JOIN Club ON Computer.club_id = Club.id
LEFT JOIN Peripheral ON Peripheral.computer_id = Computer.id
WHERE Computer.id IS NOT NULL;

-- 2
SELECT Person.name, Computer.name FROM Person_computer
LEFT JOIN Person ON Person.id = Person_computer.person_id
LEFT JOIN Computer ON Computer.id = Person_computer.computer_id
WHERE Computer.id IS NOT NULL;

-- 3
SELECT Computer.name FROM Computer
WHERE Computer.club_id IS NULL;

-- 4
SELECT Peripheral.brand, Peripheral.type FROM Peripheral
LEFT JOIN Computer ON Peripheral.computer_id = Computer.id
WHERE Computer.club_id IS NULL;

-- 5
SELECT Computer.name FROM Computer
LEFT JOIN Person_computer ON Person_computer.computer_id = Computer.id
WHERE year(Person_computer.date) = 2022
GROUP BY Computer.name
ORDER BY COUNT(Computer.id) DESC
LIMIT 1;

-- 6
SELECT Computer.name FROM Computer
LEFT JOIN Person_computer ON Person_computer.computer_id = Computer.id
GROUP BY Computer.name
ORDER BY COUNT(Computer.id) ASC
LIMIT 1;

-- 7
SELECT Computer.name FROM Computer
LEFT JOIN Person_computer ON Person_computer.computer_id = Computer.id
WHERE Person_computer.id IS NULL;