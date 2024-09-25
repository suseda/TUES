DROP DATABASE IF EXISTS DTB1;
CREATE DATABASE DTB1;
USE DTB1;
SET SQL_SAFE_UPDATES=0;


CREATE TABLE Person(
	id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(50) NOT NULL UNIQUE,
    email VARCHAR(100) NOT NULL CHECK( email LIKE "%@%")
); 

INSERT INTO Person(name,email) VALUES("Misho","mkirilov@elsys_bg.org");
INSERT INTO Person(name,email) VALUES("Joro","gminkov@elsys_bg.org");
INSERT INTO Person(name,email) VALUES("Atanas","akurtakov@elsys_bg.org");
INSERT INTO Person(name,email) VALUES("Mitko","ddimitrov@elsys_bg.org");


CREATE TABLE Phones(
 id INT PRIMARY KEY AUTO_INCREMENT,
 brand ENUM("Apple","Samsung"),
 phone_number VARCHAR(50) CHECK( phone_number LIKE "+359%"),
 person_id INT,
 FOREIGN KEY (person_id) REFERENCES Person(id)
);

INSERT INTO Phones(brand,phone_number,person_id) VALUES("Apple","+359 898 7821", 2);
INSERT INTO Phones(brand,phone_number,person_id) VALUES("Apple","+359 271 7614", 3);
INSERT INTO Phones(brand,phone_number,person_id) VALUES("Samsung","+359 896 9002", 1);
INSERT INTO Phones(brand,phone_number,person_id) VALUES("Samsung","+359 445 2711", 2);

SELECT Phones.id, Phones.brand, Phones.person_id, Person.id, Person.name FROM Phones
LEFT JOIN Person
ON Phones.person_id = Person.id;

SELECT Person.name, Phones.brand FROM Phones
LEFT JOIN Person
ON Phones.person_id = Person.id;


SELECT Person.name, Phones.phone_number FROM Phones
LEFT JOIN Person 
ON Phones.person_id = Person.id  WHERE Phones.phone_number LIKE "%271%";

SELECT Phones.brand, COUNT(Phones.brand) FROM Phones
GROUP BY Phones.brand;
