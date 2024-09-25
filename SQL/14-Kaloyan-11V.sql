DROP DATABASE IF EXISTS MyDTB1;
CREATE DATABASE MyDTB1;
USE MyDTB1;

SET sql_safe_updates=0;
SET sql_mode=only_full_group_by;


CREATE TABLE Person(
	id int PRIMARY KEY AUTO_INCREMENT,
    name varchar(20) not null,
    phone_number varchar(20) not null,
    email varchar(20) check(email LIKE "%@%")
 );
 
 
 CREATE TABLE Channel(
	id int PRIMARY KEY AUTO_INCREMENT,
    name varchar(20) not null,
    url varchar(20) check(url LIKE "https://%")
 );
 
 CREATE TABLE Post(
	id int PRIMARY KEY AUTO_INCREMENT,
    content varchar(20) not null,
    type enum("text","link","image"),
    published date,
    channel_id int not null,
    foreign key(channel_id) references Channel(id)
 );
 
 
  CREATE TABLE Video(
	id int PRIMARY KEY AUTO_INCREMENT,
    name varchar(20) not null,
    description varchar(50),
    slug varchar(20),
    published date,
    channel_id int not null,
    foreign key(channel_id) references Channel(id)
 );
 
 
 CREATE TABLE Comment(
	id int PRIMARY KEY AUTO_INCREMENT,
    content varchar(20) not null,
    post_id int not null,
    foreign key(post_id) references Post(id),
    video_id int not null,
    foreign key(video_id) references Video(id)
 );
 
 CREATE TABLE Owner(
	id int PRIMARY KEY AUTO_INCREMENT,
    person_id int not null,
    foreign key(person_id) references Person(id),
    channel_id int not null,
    foreign key(channel_id) references Channel(id)
 );
 
 
 CREATE TABLE Comment_Owner(
	id int PRIMARY KEY AUTO_INCREMENT,
    person_id int not null,
    foreign key(person_id) references Person(id),
    comment_id int not null,
    foreign key(comment_id) references Comment(id)
 );
 
 
 
 INSERT INTO Person(name,phone_number,email) values("Gosho","0882855971","gosho@gmail");
 INSERT INTO Person(name,phone_number,email) values("Pesho","0880095971","pesho@gmail");
 INSERT INTO Person(name,phone_number,email) values("Tosho","0882852433","tosho@gmail");
 INSERT INTO Person(name,phone_number,email) values("Misho","0882850808","misho@gmail");
 
 
 INSERT INTO Channel(name,url) values("Channel 1","https://ch1");
 INSERT INTO Channel(name,url) values("Channel 2","https://ch2");
 INSERT INTO Channel(name,url) values("Channel 3","https://ch3");
 
 
 INSERT INTO Post(content,type,published,channel_id) values("Hello1","text","2000-01-01",1);
 INSERT INTO Post(content,type,published,channel_id) values("Link1","link","2001-04-03",1);
 INSERT INTO Post(content,type,published,channel_id) values("Hello2","text","2002-01-01",2);
 INSERT INTO Post(content,type,published,channel_id) values("Image2","image","2001-03-03",2);
 INSERT INTO Post(content,type,published,channel_id) values("Hello3","text","2010-07-01",3);
 
 
 INSERT INTO Video(name,description,slug,published,channel_id) values("Video1","First video","fv1","2000-01-01",1);
 INSERT INTO Video(name,description,slug,published,channel_id) values("Video2.1","First video","fv2","2005-08-26",2);
 INSERT INTO Video(name,description,slug,published,channel_id) values("Video2.2","Second video","sv2","2007-07-07",2);
 INSERT INTO Video(name,description,slug,published,channel_id) values("Video3","First video","fv3","2015-11-01",3);
 
 INSERT INTO Video(name,description,slug,channel_id) values("Video1.2","Second video","fv1",1);
 INSERT INTO Video(name,description,slug,channel_id) values("Video3.2","Second video","fv3",3);
 
 
 INSERT INTO Comment(content,post_id,video_id) values("Good video!",1,1);
 INSERT INTO Comment(content,post_id,video_id) values("Bad video!",2,1);
 INSERT INTO Comment(content,post_id,video_id) values("Awesome!",1,1);
 INSERT INTO Comment(content,post_id,video_id) values("Meh boring!",4,3);
 
 INSERT INTO Owner(person_id,channel_id) values(1,1);
 INSERT INTO Owner(person_id,channel_id) values(2,2);
 INSERT INTO Owner(person_id,channel_id) values(3,3);
 
 INSERT INTO Comment_Owner(person_id,comment_id) values(1,1);
 INSERT INTO Comment_Owner(person_id,comment_id) values(3,2);
 INSERT INTO Comment_Owner(person_id,comment_id) values(3,3);
 INSERT INTO Comment_Owner(person_id,comment_id) values(4,4);
 
 
 -- Select * from Person;
-- 1 - Изведете Всяко публикувано Видео и неговия канал.
Select Video.name, Channel.name from Video
left join Channel on Video.channel_id = Channel.id;

-- 2 - Колко не публикувани видеа и постове има всеки канал. Има канали с 0 непубликувани видеа, изведете ги.
Select Video.name, Channel.name from Video
left join Channel on Video.channel_id = Channel.id
where Video.published is null;


-- 3 - Кой е канала с най-много коментари под Пост
Select Channel.name, COUNT(Comment.id) from Comment
left join Post on Comment.post_id = Post.id
left join Channel on Post.channel_id = Channel.id
Group By Channel.name
LIMIT 1;


-- 4 - Изведете Owner.name, Channel.name, Video.name, Comment.content, CommentOwner.name за всеки коментар
Select Person_owner.name, Channel.name, Video.name, Comment.content, Person_comment.name from Comment
left join Video on Comment.video_id = Video.id
left join Channel on Video.channel_id = Channel.id
left join Owner on Channel.id = Owner.channel_id
LEFT JOIN Person as Person_owner ON Owner.person_id = Person_owner.id
left join Comment_Owner on Comment.id = Comment_Owner.comment_id
left join Person as Person_comment on Comment_Owner.person_id = Person_comment.id;



-- 5 - Кой е човека написал най-малко коментари (минимум 1)
 Select Person.name, COUNT(Comment.id) from Person
 left join Comment_Owner on Person.id = Comment_Owner.person_id
 left join Comment on Comment_Owner.comment_id = Comment.id
 Group by Person.name
 Having COUNT(Comment.id) > 0
 ORDER BY COUNT(Comment.id) ASC 
 LIMIT 1;
 

 