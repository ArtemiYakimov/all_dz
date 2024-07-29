INSERT INTO GENRE (genre) VALUES
    ('Рок'),
    ('Рэп'),
    ('Поп'),
    ('Хип-хоп');

INSERT INTO EXECUTOR (executor) VALUES
    ('Queen'),
    ('Scorpions'),
    ('Лжедитрий IV'),
    ('DEEP-EX-SENSE'),
    ('Пицца'),
    ('Руки Вверх');
    
INSERT INTO GenreExecutor (idGenre, idExecutor) VALUES
    (1, 1),
    (1, 2),
    (2, 3),
    (2, 4),
    (4, 3),
    (4, 4),
    (3, 5),
    (3, 6);

INSERT INTO ALBUM (album, year) VALUES
    ('Made in Heaven', 1995),
    ('Blackout', 1982),
    ('Некрооазис', 2020),
    ('Мёртвый шёлк', 2019),
    ('Сахар', 2022),
    ('Территория Нежность', 2004),
    ('Синергис', 2024);

INSERT INTO SONG (song, duration) VALUES
    ('Made in Heaven', 287),
    ('My City My Town', 228),
    ('Око великого эля', 385),
    ('Кокон', 319),
    ('Люблю', 235),
    ('Одиннадцать минут', 218),
    ('Первоначало', 220),
    ('Кайлеон', 256);

INSERT INTO AlbumSong (idAlbum, idSong) VALUES
    (1, 1),
    (2, 2),
    (3, 3),
    (4, 4),
    (5, 5),
    (6, 6),
    (7, 7),
    (7, 8);

INSERT INTO ExecutorSong (idExecutor, idSong) VALUES
    (1, 1),
    (2, 2),
    (3, 3),
    (4, 4),
    (5, 5),
    (6, 6),
    (3, 7),
    (4, 7),
    (3, 8),
    (4, 8);

INSERT INTO COLLECTION (collection, year) VALUES
    ('Лучшие песни', 2024),
    ('Песни прошлого', 2022),
    ('Сборник рока', 2018),
    ('Сборник рэпа', 2021);

INSERT INTO CollectionSong (idCollection, idSong) VALUES
    (1, 3),
    (1, 4),
    (1, 5),
    (2, 1),
    (2, 2),
    (2, 6),
    (3, 1),
    (3, 2),
    (4, 3),
    (4, 4),
    (4, 7);