-- Задача 2
--1. Название и продолжительность самого длительного трека.
SELECT song, duration FROM SONG ORDER BY duration DESC LIMIT 1;

--2. Название треков, продолжительность которых не менее 3,5 минут.
SELECT song, duration FROM SONG WHERE duration >= 210;

--3. Названия сборников, вышедших в период с 2018 по 2020 годы включительно.
SELECT collection FROM COLLECTION WHERE year >= 2018 AND year <= 2020;

--4. Исполнители, чьё имя состоит из одного слова.
SELECT * FROM EXECUTOR WHERE executor NOT LIKE '% %';

--5. Название треков, которые содержат слова «мой» или «my».
SELECT song FROM SONG WHERE LOWER(song) LIKE '%my%' OR LOWER(song) LIKE '%мой%';