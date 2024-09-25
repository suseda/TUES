DROP DATABASE IF EXISTS DataBase1;
CREATE DATABASE DataBase1;
USE DataBase1;
SET SQL_SAFE_UPDATES=0;

CREATE TABLE Company(
	id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(20) NOT NULL UNIQUE,
    email VARCHAR(30) NOT NULL check(email LIKE "%@%")
);

INSERT INTO Company(name,email) VALUES("Company1","company1@gmail.com");
INSERT INTO Company(name,email) VALUES("Microsoft","microsoft@gmail.com");
INSERT INTO Company(name,email) VALUES("Euromarket","eurom@gmail.com");

CREATE TABLE Client(
	name VARCHAR(20) NOT NULL,
    phone_number VARCHAR(20) NOT NULL check(phone_number LIKE "+359%"),
    company_id int DEFAULT(NULL),
    FOREIGN KEY (company_id) REFERENCES Company(id)
);


INSERT INTO Client(name,phone_number, company_id)  VALUES("Joro","+359 888 3241",1);
INSERT INTO Client(name,phone_number, company_id)  VALUES("Pesho","+359 845 6641",2);
INSERT INTO Client(name,phone_number, company_id)  VALUES("Misho","+359 878 0021",1);
INSERT INTO Client(name,phone_number)  VALUES("Tisho","+359 078 7731");

SELECT Company.name, Client.name FROM Company LEFT JOIN Client ON Company.id = company_id;

SELECT Client.name FROM Client 
WHERE Client.company_id IS NULL;

SELECT Company.name, Client.name FROM Company LEFT JOIN Client ON Company.id = company_id
WHERE Client.company_id IS NULL;


SELECT Company.name, COUNT(Client.company_id) FROM Company LEFT JOIN Client ON Company.id = company_id
GROUP BY Client.company_id;

SELECT Company.name, COUNT(Client.company_id) FROM Company LEFT JOIN Client ON Company.id = company_id
GROUP BY Company.name
ORDER BY COUNT(Client.name) DESC
LIMIT 1;
