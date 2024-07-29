-- Задание 2, Задача 1 -- Название и продолжительность самого длительного трека.
SELECT song, duration FROM SONG ORDER BY duration DESC LIMIT 1;

-- Задание 2, Задача 2 -- Название треков, продолжительность которых не менее 3,5 минут.
SELECT song, duration FROM SONG WHERE duration >= 210;

-- Задание 2, Задача 3 -- Названия сборников, вышедших в период с 2018 по 2020 годы включительно.
SELECT * FROM COLLECTION WHERE year between 2018 and 2020;

-- Задание 2, Задача 4 -- Исполнители, чьё имя состоит из одного слова.
Select executor from EXECUTOR where executor not like '% %';

-- Задание 2, Задача 5 -- Название треков, которые содержат слова «мой» или «my».
SELECT song FROM SONG WHERE LOWER(song) LIKE '%my%' OR LOWER(song) LIKE '%мой%';


-- Задание 3, Задача 1
SELECT genre, count(idexecutor) as count_executor FROM GENRE
JOIN GenreExecutor USING (idGenre)
GROUP BY genre;

-- Задание 3, Задача 2
Select ALBUM.album, count(SONG.song) as count_song, ALBUM.year from AlbumSong
JOIN ALBUM USING (idAlbum)
JOIN SONG USING (idSong)
where ALBUM.year between 2019 and 2020
GROUP BY album, year;

-- Задание 3, Задача 3 
Select album, (SUM(duration) / count(duration)) AS sum_duration from AlbumSong
JOIN ALBUM USING (idAlbum)
JOIN SONG USING (idSong)
GROUP BY album;

-- Задание 3, Задача 4
Select executor, album, year  from AlbumExecutor -- ALBUM.album, count(SONG.song) as count_song, ALBUM.year
JOIN ALBUM USING (idAlbum)
JOIN EXECUTOR USING (idExecutor)
WHERE AlbumExecutor.idAlbum = ANY(SELECT idAlbum FROM ALBUM WHERE year != 2020);

-- Задание 3, Задача 5
SELECT collection as name_collections FROM COLLECTION
WHERE idCollection = ANY(
  SELECT idCollection FROM CollectionSong
  WHERE idsong = ANY(
    SELECT idSong FROM ExecutorSong 
    WHERE idExecutor = ANY(
      SELECT idExecutor FROM EXECUTOR WHERE executor = 'DEEP-EX-SENSE'
    )
  )
  GROUP BY idCollection
);