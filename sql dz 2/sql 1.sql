
-- create
CREATE TABLE GENRE (
  id INT PRIMARY KEY,
  genre TEXT NOT NULL
);

-- insert
INSERT INTO GENRE (id, genre) VALUES
    (1, 'Рок'),
    (2, 'Рэп'),
    (3, 'Поп'),
    (4, 'Хип-хоп');

-- fetch 
--SELECT * FROM GENRE;

CREATE TABLE EXECUTOR (
    id INT PRIMARY KEY,
    executor TEXT NOT NULL,
    lookup_genre INT[]
);

INSERT INTO EXECUTOR (id, executor, lookup_genre) VALUES
    (1, 'Queen', ARRAY[1]::INT[]),
    (2, 'Scorpions', ARRAY[1]::INT[]),
    (3, 'Лжедитрий IV', ARRAY[2, 4]::INT[]),
    (4, 'DEEP-EX-SENSE', ARRAY[2, 4]::INT[]),
    (5, 'Пицца', ARRAY[3]::INT[]),
    (6, 'Руки Вверх', ARRAY[3]::INT[]);
    
--SELECT * FROM EXECUTOR;
--SELECT * FROM EXECUTOR WHERE executor NOT LIKE '% %';

--SELECT genre, executor FROM GENRE, EXECUTOR WHERE EXECUTOR.lookup_genre = GENRE.id;
--SELECT genre, executor FROM GENRE JOIN EXECUTOR ON EXECUTOR.lookup_genre = GENRE.id;

CREATE TABLE ALBUM (
    id INT PRIMARY KEY,
    lookup_executor INT[],
    album TEXT NOT NULL,
    year INT
);

INSERT INTO ALBUM (id, lookup_executor, album, year) VALUES
    (1, ARRAY[1]::INT[], 'Made in Heaven', 1995),
    (2, ARRAY[2]::INT[], 'Blackout', 1982),
    (3, ARRAY[3]::INT[], 'Некрооазис', 2020),
    (4, ARRAY[4]::INT[], 'Мёртвый шёлк', 2019),
    (5, ARRAY[5]::INT[], 'Сахар', 2022),
    (6, ARRAY[6]::INT[], 'Территория Нежность', 2004),
    (7, ARRAY[3, 4]::INT[], 'Синергис', 2024);
    
--SELECT * FROM ALBUM;
--SELECT * FROM ALBUM WHERE year >= 2019 AND year <= 2020;
    
CREATE TABLE SONG (
    id INT PRIMARY KEY,
    lookup_album INT[],
    song TEXT NOT NULL,
    duration INT
);

INSERT INTO SONG (id, lookup_album, song, duration) VALUES
    (1, ARRAY[1]::INT[], 'Made in Heaven', 287),
    (2, ARRAY[2]::INT[], 'My City My Town', 228),
    (3, ARRAY[3]::INT[], 'Око великого эля', 385),
    (4, ARRAY[4]::INT[], 'Кокон', 319),
    (5, ARRAY[5]::INT[], 'Люблю', 235),
    (6, ARRAY[6]::INT[], 'Одиннадцать минут', 218);
    
-- SELECT * FROM SONG;
-- SELECT song, duration FROM SONG ORDER BY duration DESC LIMIT 1;
-- SELECT song, duration FROM SONG WHERE duration >= 210;
-- SELECT song FROM SONG WHERE LOWER(song) LIKE '%my%' OR LOWER(song) LIKE '%мой%';
SELECT * FROM SONG WHERE ANY(lookup_album) = (SELECT id FROM ALBUM WHERE year >= 2019 AND year <= 2020);

CREATE TABLE COLLECTION (
    id INT PRIMARY KEY,
    collection TEXT NOT NULL,
    year INT,
    lookup_song INT[]
);

INSERT INTO COLLECTION (id, lookup_song, collection, year) VALUES
    (1, ARRAY[3, 4, 5]::INT[], 'Лучшие песни', 2024),
    (2, ARRAY[1, 2, 6]::INT[], 'Песни прошлого', 2022),
    (3, ARRAY[1, 2]::INT[], 'Сборник рока', 2018),
    (4, ARRAY[3, 4]::INT[], 'Сборник рэпа', 2021);
    
-- SELECT * FROM COLLECTION;
--SELECT collection FROM COLLECTION WHERE year >= 2018 AND year <= 2020;