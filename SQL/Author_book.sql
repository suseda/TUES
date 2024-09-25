DROP DATABASE IF EXISTS MyDTB1;
CREATE DATABASE MyDTB1;
USE MyDTB1;

SET sql_safe_updates=0;
SET sql_mode=only_full_group_by;


CREATE TABLE Person(
	id int PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(100) NOT NULL,
    age int check(age > 0)
);

create table Adress(
	id int PRIMARY KEY AUTO_INCREMENT,
    city varchar(100) not null, 
    street varchar(100) not null,
    person_id int not null unique,
    foreign key(person_id) references Person(id)
);

create table Cover_type(
	id int PRIMARY KEY AUTO_INCREMENT,
    type enum("hard","soft")
);

create table Category(
	id int primary key auto_increment,
    name varchar(100) not null unique
);


CREATE TABLE Book(
	id int primary key auto_increment,
    name varchar(100) not null,
    pages int check(pages > 0),
    published_date date,
    cover_id int not null,
    foreign key(cover_id) references Cover_type(id)
);

create table Book_category(
	id int primary key auto_increment,
	category_id int not null,
    foreign key(category_id) references Category(id),
    book_id int not null,
    foreign key(book_id) references Book(id)
);

create table Author(
	id int primary key auto_increment,
    person_id int not null,
    foreign key(person_id) references Person(id),
    book_id int not null,
    foreign key(book_id) references Book(id)
);

create table Reader(
	id int primary key auto_increment,
    person_id int not null,
    foreign key(person_id) references Person(id),
    book_id int not null,
    foreign key(book_id) references Book(id),
    date_started date not null,
    date_ended date
);

insert into Person(name,age) values("Sun Tzu",2000);
insert into Person(name,age) values("Shakespeare",400);
insert into Person(name,age) values("JK Rowling",60);


insert into Person(name,age) values("Misho",25);
insert into Person(name,age) values("Ivancho",16);
insert into Person(name,age) values("Mariyka",21);


insert into Adress(city, street, person_id) values("Sofia","bul.bulgaria",4);
insert into Adress(city, street, person_id) values("Sofia","bul.car boris 3",5);
insert into Adress(city, street, person_id) values("Sofia","ul. todor kableshkov",6);
insert into Adress(city, street, person_id) values("Beijing","chin chong",1);
insert into Adress(city, street, person_id) values("London","First street",2);
insert into Adress(city, street, person_id) values("London","Second boulevard",3);

insert into cover_type(type) value("hard");
insert into cover_type(type) value("soft");


insert into book(name,pages,published_date,cover_id) values("Harry Potter",300,"2000-01-01",1);
insert into book(name,pages,published_date,cover_id) values("Harry Potter 2",300,"2000-01-01",1);
insert into book(name,pages,published_date,cover_id) values("Hamlet",300,"1700-01-01",2);
insert into book(name,pages,published_date,cover_id) values("The art of war",90,"2022-01-01",1);
insert into book(name,pages,published_date,cover_id) values("Harry Potter 3",300,"2000-01-01",2);
insert into book(name,pages,published_date,cover_id) values("Harry Potter 4",300,"2000-01-01",2);


insert into category(name) value("Fantasy");
insert into category(name) value("Philosophy");
insert into category(name) value("Tragedy");


insert into book_category(book_id,category_id) values(1,1);
insert into book_category(book_id,category_id) values(2,3);
insert into book_category(book_id,category_id) values(3,2);
insert into book_category(book_id,category_id) values(3,1);
insert into book_category(book_id,category_id) values(5,1);
insert into book_category(book_id,category_id) values(6,3);


insert into author(person_id,book_id) values(1,3);
insert into author(person_id,book_id) values(2,2);
insert into author(person_id,book_id) values(3,1);


insert into reader(person_id,book_id,date_started) values(4,1,"2022-02-13");
insert into reader(person_id,book_id,date_started) values(5,2,"2022-02-13");
insert into reader(person_id,book_id,date_started) values(6,3,"2022-02-13");

insert into reader(person_id,book_id,date_started, date_ended) values(1,1,"2022-02-13", "2022-02-14");
insert into reader(person_id,book_id,date_started, date_ended) values(2,2,"2022-02-13", "2022-02-15");
insert into reader(person_id,book_id,date_started, date_ended) values(3,3,"2022-02-13", "2022-02-16");
insert into reader(person_id,book_id,date_started, date_ended) values(4,2,"2022-02-13", "2023-03-13" );
insert into reader(person_id,book_id,date_started, date_ended) values(5,2,"2022-02-13", "2022-04-13");
insert into reader(person_id,book_id,date_started, date_ended) values(6,2,"2022-02-13", "2022-05-13");


insert into reader(person_id,book_id,date_started) values(4,1,"2022-02-13");
insert into reader(person_id,book_id,date_started) values(5,2,"2022-02-13");
insert into reader(person_id,book_id,date_started) values(6,3,"2022-02-13");


-- Select * from Person;
-- 1 - [Име на Човек, Име на книга, Име на автор, Име на Категория на Книга, Тип на Корицата] 
-- за всяка прочетена публикувана книга.
Select Person_reader.name, Book.name, Person_author.name, Category.name, Cover_type.type from Reader
LEFT JOIN Person as Person_reader ON Reader.person_id = Person_reader.id
LEFT JOIN Book ON Reader.book_id = Book.id
LEFT JOIN Author On Book.id = Author.book_id
LEFT JOIN Person as Person_author On Author.person_id = Person_author.id
LEFT JOIN Book_Category on Book_Category.book_id = Book.id
LEFT JOIN Category on Book_Category.category_id = Category.id
LEFT JOIN Cover_type On Cover_type.id = Book.cover_id
WHERE Book.published_date IS NOT NULL;

-- Error Code: 1066. Not unique table/alias: 'Person'

-- 2 За всяка прочетена книга изведете [Име на човек, Име на книга, Кога човекът е започнал да я чете, Кога човекът е приключил с четенето]
Select Person_reader.name, Book.name, Reader.date_started, Reader.date_ended from Reader
LEFT JOIN Person as Person_reader ON Reader.person_id = Person_reader.id
LEFT JOIN Book ON Reader.book_id = Book.id;

-- 3

Select id, 365 * ABS(Year(date_ended) - Year(date_started)) + 30 * ABS(MONTH(date_ended) - MONTH(date_started)) + ABS(DAY(date_ended) - DAY(date_started)), id from Reader
WHERE date_ended IS NOT NULL;


-- 4
Select  Book.name, Count(Category.name) from Book
LEFT JOIN Book_Category on Book_Category.book_id = Book.id
LEFT JOIN Category on Book_Category.category_id = Category.id
GROUP BY Book.name;

-- 5  Изведете за всеки автор [Име автор, Тип Корица, Брой книги]

Select Person_author.name, Cover_type.type, COUNT(Book.name) from Author
LEFT JOIN Person as Person_author On Author.person_id = Person_author.id
LEFT JOIN Book On Author.book_id = Book.id
LEFT JOIN Cover_type On Book.cover_id = Cover_type.id
Group by Person_author.name, Cover_type.type;



-- 6
Select Cover_type.type, Count(DISTINCT Category.name) as oorder from Cover_type
LEFT JOIN Book ON Cover_type.id = Book.cover_id
LEFT JOIN Book_Category on Book_Category.book_id = Book.id
LEFT JOIN Category on Book_Category.category_id = Category.id
GROUP BY Cover_type.type
ORDER BY oorder DESC
LIMIT 1;

