DROP DATABASE IF EXISTS DTB1;

CREATE DATABASE DTB1;

USE DTB1;

SET sql_safe_updates=0;
SET sql_mode=only_full_group_by;

CREATE TABLE Person(
	id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(20),
    phone_number VARCHAR(20) NOT NULL,
    email_address VARCHAR(20) NOT NULL
);


CREATE TABLE Address(
	id INT PRIMARY KEY AUTO_INCREMENT,
    street VARCHAR(10) NOT NULL,
    city VARCHAR(10) NOT NULL,
    state VARCHAR(10) NOT NULL,
    postal_code VARCHAR(10) NOT NULL,
    country VARCHAR(20) NOT NULL,
    person_id INT UNIQUE NOT NULL,
    FOREIGN KEY (person_id) REFERENCES Person(id)
);


INSERT INTO Person(name,phone_number,email_address) VALUES("Misho","0882855971","mkirilov@elsys-bg.org");
INSERT INTO Person(name,phone_number,email_address) VALUES("Joro","08828589112","joro@elsys-bg.org");
INSERT INTO Person(name,phone_number,email_address) VALUES("Tisho","0880055971","tisho@elsys-bg.org");

INSERT INTO Address(street,city,state, postal_code, country,person_id) VALUES("STREET1","City1","ST1","1510","Country1",1);
INSERT INTO Address(street,city,state, postal_code, country,person_id) VALUES("STREET2","City2","ST2","1511","Country2",2);
INSERT INTO Address(street,city,state, postal_code, country,person_id) VALUES("STREET3","City3","ST3","1512","Country3",3);


SELECT *FROM Person;
SELECT *FROM Address;