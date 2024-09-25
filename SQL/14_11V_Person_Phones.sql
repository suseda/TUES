DROP DATABASE IF EXISTS DTB1;

CREATE DATABASE DTB1;

USE DTB1;

SET sql_safe_updates=0;
SET sql_mode=only_full_group_by;

DROP DATABASE IF EXISTS DTB1;
CREATE DATABASE DTB1;
USE DTB1;
SET sql_safe_updates=0;


CREATE TABLE Person(
    id int PRIMARY KEY AUTO_INCREMENT,
    name varchar(50) NOT NULL UNIQUE,
    email varchar(100) NOT NULL check(email LIKE "%@%")
);

INSERT INTO PERSON(name, email) VALUES("Misho", "mkirilov@elsys-bg.org");
INSERT INTO PERSON(name, email) VALUES("Joro", "gminkov@elsys-bg.org");
INSERT INTO PERSON(name, email) VALUES("Atanas", "akurtakov@elsys-bg.org");
INSERT INTO PERSON(name, email) VALUES("Mitko", "@ddimitrovelsys-bg.org");

CREATE TABLE Phones(
    id int PRIMARY KEY AUTO_INCREMENT,
    brand ENUM("Apple", "Samsung"),
    model varchar(10) NOT NULL,
    phone_number varchar(50) check( phone_number LIKE "+359%" ),
    person_id int,
    FOREIGN KEY (person_id) REFERENCES Person(id)
);
-- Няма +359 вътре в номера.
-- INSERT INTO Phones(brand, phone_number, person_id)
-- VALUES("Apple", "123", NULL);
-- INSERT INTO Phones(brand, phone_number, person_id)
-- VALUES("Apple", "123+359 898 790 271", NULL);
INSERT INTO Phones(brand,model, phone_number, person_id)
VALUES("Apple","12", "+359 898 790 271", 1);
INSERT INTO Phones(brand,model, phone_number, person_id)
VALUES("Apple","x4", "+359 898 790 271", 1);

INSERT INTO Phones(brand,model, phone_number, person_id)
VALUES("Apple","S6", "+359 1", 2);
INSERT INTO Phones(brand,model, phone_number, person_id)
VALUES("Apple","A6", "+359 2", 3);
INSERT INTO Phones(brand,model, phone_number, person_id)
VALUES("Samsung","7", "+359 3", 4);
INSERT INTO Phones(brand,model, phone_number, person_id)
VALUES("Apple","sx", "+359 898 790 271", 1);

-- Този ще има person_id = 1 защото имаме Default
INSERT INTO Phones(brand,model, phone_number)
VALUES("Apple","a71", "+359 898 790 271");

INSERT INTO PERSON(name, email) VALUES("Kaloyan", "@ksotirovelsys-bg.org");

SELECT Person.name, COUNT(Phones.brand) FROM Person 
LEFT JOIN Phones ON Person.id = person_id 
GROUP BY Person.name;

SELECT Phones.brand, Phones.model FROM Phones
LEFT JOIN Person ON Person.id = person_id
WHERE person_id IS NULL;

SELECT Person.name,Phones.person_id FROM Person
LEFT JOIN Phones ON Person.id = person_id
WHERE person_id IS NULL;

