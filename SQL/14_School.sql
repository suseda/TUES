DROP DATABASE IF EXISTS MyDTB1;
CREATE DATABASE MyDTB1;
USE MyDTB1;

SET sql_safe_updates=0;
SET sql_mode=only_full_group_by;

CREATE TABLE Adress(
	id int PRIMARY KEY AUTO_INCREMENT,
    street VARCHAR(100) NOT NULL
);

CREATE TABLE School(
	id int PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(100) NOT NULL UNIQUE
);

CREATE TABLE Class(
	id int PRIMARY KEY AUTO_INCREMENT,
    class int NOT NULL check(class > 0 && class < 13),
    paralelka ENUM("A", "B", "V"),
    school_id int NOT NULL UNIQUE,
    FOREIGN KEY (school_id) REFERENCES School(id)
);

CREATE TABLE Student(
	id int PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(100) NOT NULL UNIQUE,
    age int NOT NULL check(age > 0),
    adress_id int NOT NULL UNIQUE,
    FOREIGN KEY (adress_id) REFERENCES Adress(id),
    class_id int NOT NULL UNIQUE,
    FOREIGN KEY (class_id) REFERENCES Class(id)
);

CREATE TABLE Subject(
	id int PRIMARY KEY AUTO_INCREMENT,
    name ENUM("Bel", "Math", "Sports")
);


CREATE TABLE Grade(
	id int PRIMARY KEY AUTO_INCREMENT,
    subject_id int NOT NULL,
    FOREIGN KEY (subject_id) REFERENCES Subject(id),
    student_id int NOT NULL,
    FOREIGN KEY (student_id) REFERENCES Student(id),
    grade float NOT NULL check(grade BETWEEN 2 AND 6),
    date DATE NOT NULL,
    CONSTRAINT edna_ocenka_na_den UNIQUE(student_id, subject_id, date)
);

INSERT INTO Subject(name) VALUES("Math");
INSERT INTO Subject(name) VALUES("Bel");
INSERT INTO Subject(name) VALUES("Sports");

INSERT INTO School(name) VALUES("TUES");
INSERT INTO School(name) VALUES("163to");
INSERT INTO School(name) VALUES("68mo");
INSERT INTO School(name) VALUES("150to");

INSERT INTO Adress(street) VALUES("Lozenec");
INSERT INTO Adress(street) VALUES("Lulin");
INSERT INTO Adress(street) VALUES("Drujba 2");
INSERT INTO Adress(street) VALUES("Bunkera");

INSERT INTO Class(class, paralelka, school_id) VALUES(10, "A", 1);
INSERT INTO Class(class, paralelka, school_id) VALUES(10, "B", 2);
INSERT INTO Class(class, paralelka, school_id) VALUES(11, "V", 3);
INSERT INTO Class(class, paralelka, school_id) VALUES(11, "V", 4);

INSERT INTO Student(name, age, adress_id, class_id) VALUES("Gosho", 16, 1, 1);
INSERT INTO Student(name, age, adress_id, class_id) VALUES("Maisie", 16, 2, 2);
INSERT INTO Student(name, age, adress_id, class_id) VALUES("Tosho", 17, 3, 3);
-- INSERT INTO Student(name, age, adress_id, class_id) VALUES("Misho", 17, 4, 4);

INSERT INTO Grade(subject_id, student_id, grade, date) VALUES(1, 1, 6, "2022-05-20");
INSERT INTO Grade(subject_id, student_id, grade, date) VALUES(2, 2, 5, "2022-05-23");
INSERT INTO Grade(subject_id, student_id, grade, date) VALUES(3, 3, 6, "2022-06-10");


-- 1
Select School.name,Count(Student.name) From School
left join Class on Class.school_id = School.id
left join Student on Student.class_id = Class.id
Group by School.name
Order by Count(Student.name) Desc;

-- 2
Select School.name,AVG(Grade.grade) From School
Left Join Class on Class.school_id = School.id
Left Join Student on Student.class_id = Class.id
Left Join Grade on Grade.subject_id = Student.id
Group by School.name
Order by AVG(Grade.grade) desc
LIMIT 1;

-- 3
Select Grade.grade, Subject.name, Student.name, Class.class, Class.paralelka, School.name, Grade.date from Grade
right join Subject on Subject.id = Grade.subject_id
left join Student on Student.id = Grade.student_id
left join Class on Student.class_id = Class.id
left join School on School.id = Class.school_id;


-- 4
Select Student.name,AVG(Grade.grade) From Student
Left Join Grade on Grade.student_id = Student.id
Left Join Subject on Subject_id = Grade.subject_id
Where Student.name Like 'M%e' and month(Grade.date)  not IN(1,3,9) and year(Grade.date) = 2022 and Subject.name in("Math","Sports")
Group by Student.name
Order by AVG(Grade.grade) desc
limit 1;

-- 5
Select School.name,Class.class,Class.paralelka,AVG(Grade.grade) From School
Left Join Class on Class.school_id = School.id
Left Join Student on Student.class_id = Class.id
Left Join Grade on Grade.subject_id = Student.id
Group by School.name
Order by AVG(Grade.grade) desc;


-- 6 
Select distinct Student.name, Subject.name From Student
left join Grade on Grade.student_id = Student.id
Left join Subject on Grade.subject_id = Subject.id
Where Grade.grade is not null; 

-- 7 
Select School.name From School
left join Class on Class.school_id = School.id
left join Student on Student.class_id = Class.id
Where Student.class_id is null;