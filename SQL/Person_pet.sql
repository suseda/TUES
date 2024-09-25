DROP DATABASE IF EXISTS DTB1;
CREATE DATABASE DTB1;
USE DTB1;
SET SQL_SAFE_UPDATES=0;


CREATE TABLE Person(
	id int primary key auto_increment, 
    name varchar(40) not null,
    age int check(age>0)
);

CREATE TABLE Pet(
	id int primary key auto_increment, 
	name varchar(40) not null,
    type enum("cat","dog","bird"),
    breed varchar(15),
    age int check(age>0)
);

CREATE TABLE Person_Pet(
	id int primary key auto_increment, 
	person_id int not null,
    FOREIGN KEY(person_id) references Person(id),
    pet_id int not null,
    FOREIGN KEY(pet_id) references Pet(id)
    -- UNIQUE(person_id,pet_id) 
);

CREATE TABLE Room(
	id int primary key auto_increment, 
	name varchar(40) not null,
    address varchar(20) not null
);


INSERT INTO Person(name,age) values("Misho", 26);
INSERT INTO Person(name,age) values("Stefi", 23);

INSERT INTO Pet(name,age,type,breed) values("Chocho", 4, "dog", "Labradoodle");
INSERT INTO Pet(name,age,type,breed) values("Coockie", 1, "bird", "Parrot");

INSERT INTO Person_Pet(person_id, pet_id) VALUES(1,1);
INSERT INTO Person_Pet(person_id,pet_id) VALUES(2,1);
INSERT INTO Person_Pet(person_id,pet_id) VALUES(2,2);

Select * from Person
Left join Person_pet on Person_pet.person_id = Person.id
Left join Pet on Person_pet.pet_id = Pet.id;

-- 1
Select Person.name, COUNT(Pet.type) from Person
Left join Person_pet on Person_pet.person_id = Person.id
Left join Pet on Person_pet.pet_id = Pet.id
where Person.name = "Misho" and Pet.type = "dog";

-- 2
Select Person.name, Person.age, Pet.name, Pet.age from Person
Left join Person_pet on Person_pet.person_id = Person.id
Left join Pet on Person_pet.pet_id = Pet.id
where Person.age > 20 and Pet.age < 5;


-- 3
Select Person.name, Person.age, Pet.name, Pet.age from Person
Left join Person_pet on Person_pet.person_id = Person.id
Left join Pet on Person_pet.pet_id = Pet.id
Group by Person.name;

INSERT INTO Room(name, address) Values ("4.1", "TUES");
INSERT INTO Room(name, address) Values ("4.2", "TUES");

CREATE TABLE Person_Room(
	id int primary key auto_increment, 
	person_id int not null,
    FOREIGN KEY(person_id) references Person(id),
    room_id int not null,
    FOREIGN KEY(room_id) references Room(id)
);

INSERT INTO Person_Pet(person_id, pet_id) VALUES(1,1);
INSERT INTO Person_Pet(person_id,pet_id) VALUES(1,2);
INSERT INTO Person_Pet(person_id, pet_id) VALUES(2,1);
INSERT INTO Person_Pet(person_id,pet_id) VALUES(2,2);

Select * from Person
Left join Person_Room on Person.id = Person_room.person_id
Left join Room on Room.id = Person_room.room_id;

-- 1
ALTER TABLE Person_Room
ADD entered_at datetime;

INSERT Person_Room (person_id,room_id, entered_at) values(1,1,"2023-01-03 20:00:07");

-- 2
Select Person.name, Room.name, Person_Room.entered_at From Person
Left join Person_Room on Person.id = Person_room.person_id
Left join Room on Room.id = Person_room.room_id
Where Person_Room.entered_at is null or
month(Person_Room.entered_at) in (1,5,9)
and day(Person_Room.entered_at) in (3,6,9)
and hour(Person_Room.entered_at) in (20);