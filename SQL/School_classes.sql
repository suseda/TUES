DROP DATABASE IF EXISTS DTB1;    
CREATE DATABASE DTB1;
USE DTB1;
SET sql_safe_updates=0;

CREATE TABLE Student(
    id int PRIMARY KEY AUTO_INCREMENT,
    name varchar(50) NOT NULL,
    number_in_class int check(number_in_class > 0),
    class int check(class > 0 and class < 13),
    paralelka ENUM("A", "B", "V", "G")
);

INSERT INTO Student(name, number_in_class, class, paralelka)
VALUES("Misho", 1, 12,"A");

CREATE TABLE Grade(
    id int PRIMARY KEY AUTO_INCREMENT,
    name varchar(20) NOT NULL,
    grade float check(grade >= 2 and grade <= 6),
    student_id int NOT NULL,
    FOREIGN KEY (student_id) REFERENCES Student(id)
);

INSERT INTO Grade(name, grade, student_id)
VALUES("BEL", 6, 1);

-- Не работи, защото нямаме Student.id = 2;
-- UPDATE Grade SET student_id = 2 WHERE student_id = 1;

-- Не работи, защото не можем да изтрием Student, който е референция.
-- DELETE FROM Student WHERE Student.id = 1;

-- Не работи, защото имаме оценки, който са 'закачени' за Student.id = 1;
-- Error Code: 1451. Cannot delete or update a parent row: a foreign key constraint fails (`dtb1`.`grade`, CONSTRAINT `grade_ibfk_1` FOREIGN KEY (`student_id`) REFERENCES `student` (`id`))
-- UPDATE Student SET id = 2 WHERE Student.id = 1;


INSERT INTO Student(name, number_in_class, class, paralelka)
VALUES("Joro", 1, 12,"A");
-- Работи, защото от другата страна няма рефенреция към Student.id = 2;
UPDATE Student SET id = 56 WHERE Student.id = 2;