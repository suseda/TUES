DROP DATABASE IF EXISTS DTB1;
CREATE DATABASE DTB1;
USE DTB1;
SET SQL_SAFE_UPDATES=0;

CREATE TABLE Address(
	id int primary key auto_increment, 
    street varchar(40) not null unique
);

CREATE TABLE Hotel(
	id int primary key auto_increment, 
    name varchar(40) not null unique
);

CREATE TABLE Person(
	id int primary key auto_increment, 
    name varchar(40) not null unique,
    age int check(age>0),
    gender ENUM("M","F")
);

CREATE TABLE Room(
	id int primary key auto_increment, 
    name varchar(40) not null,
    date date,
    hotel_id INT,
    FOREIGN KEY (hotel_id) REFERENCES Hotel(id),
    person_id INT,
    FOREIGN KEY (person_id) REFERENCES Person(id)
);


insert into Address(street) values("Opulchenska");

insert into Hotel(name) values("Hotel_V_1");
insert into Hotel(name) values("Hotel2");
insert into Hotel(name) values("Hotel3");

insert into Person(name,age,gender) values("Gosho",19,"M");
insert into Person(name,age,gender) values("Sasho",23,"M");
insert into Person(name,age,gender) values("Milena",20,"F");
insert into Person(name,age,gender) values("Pesho",20,"M");

insert into Room(name,hotel_id,date,person_id) values("Room1",1,'2008-11-11',1);
insert into Room(name,hotel_id,date,person_id) values("Room2",1,'2008-11-11',2);
insert into Room(name,hotel_id,date,person_id) values("Room3",1,'2008-11-10',3);

insert into Room(name,hotel_id,date,person_id) values("Room1",3,'2008-05-18',1);


-- 1
SELECT Hotel.name, COUNT(Room.hotel_id) from Hotel
Left join Room on Room.hotel_id = Hotel.id
Group by Hotel.name;

-- 2
SELECT Hotel.name, COUNT(Room.hotel_id) from Hotel
Left join Room on Room.hotel_id = Hotel.id
Where Room.hotel_id is null
Group by Hotel.name;

-- 4
SELECT Person.name,Room.name,Hotel.name,Day(Room.date) From Hotel
Left join Room on Room.hotel_id = Hotel.id
Left join Person on Person.id = Room.person_id
Where Person.name is not null and Room.name is not null and Day(Room.date) is not null;

-- 5
Select Person.name, COUNT(Room.date) From Person
Left join Room on Room.id = Person.id
Where Person.name LIKE 'M%a' and month(Room.date) != 5 and month(Room.date) != 9 and month(Room.date) != 10
Group by Person.name;


