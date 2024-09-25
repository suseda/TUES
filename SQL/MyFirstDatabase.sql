DROP DATABASE IF EXISTS MyFirstDatabase;
CREATE DATABASE MyFirstDatabase;
USE MyFirstDatabase;

CREATE TABLE Person(
	id int PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(35) NOT NULL,
    age int NOT NULL
);


INSERT INTO Person(name,age)  VALUES("Misho",25);
INSERT INTO Person(name,age)  VALUES("Nasko",25);
INSERT INTO Person(name,age)  VALUES("Joro",26);
INSERT INTO Person(name,age)  VALUES("Pesho",18);
INSERT INTO Person(name,age)  VALUES("Sofi",3);

SELECT age,name FROM Person;

SELECT age,name FROM Person
WHERE (age>=25 OR age=18) AND name="Nasko" AND NOT name="Nasko";

SELECT * FROM Person
ORDER BY age DESC;

UPDATE Person SET age=26 WHERE id=1;
SELECT * FROM Person;

DELETE FROM Person WHERE id=5;
SELECT * FROM Person;

CREATE TABLE Pet(
	id int PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(35) NOT NULL,
    number_of_legs int NOT NULL DEFAULT 0
);

INSERT INTO Pet(name,number_of_legs)  VALUES("Dog",4);
INSERT INTO Pet(name,number_of_legs)  VALUES("Duck",2);
INSERT INTO Pet(name,number_of_legs)  VALUES("Cat",4);
INSERT INTO Pet(name)  VALUES("Snake");

SELECT * FROM Pet;