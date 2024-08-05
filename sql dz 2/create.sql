CREATE TABLE GENRE (
  idGenre SERIAL PRIMARY KEY,
  genre TEXT NOT NULL
);

CREATE TABLE EXECUTOR (
    idExecutor SERIAL PRIMARY KEY,
    executor TEXT NOT NULL
);

CREATE TABLE GenreExecutor (
    idGenre INT REFERENCES GENRE,
    idExecutor INT REFERENCES EXECUTOR,
    PRIMARY KEY (idGenre, idExecutor)
);

CREATE TABLE ALBUM (
    idAlbum SERIAL PRIMARY KEY,
    album TEXT NOT NULL,
    year INT
);

CREATE TABLE SONG (
    idSong SERIAL PRIMARY KEY,
    song TEXT NOT NULL,
    duration INT
);

CREATE TABLE AlbumSong (
    idAlbum INT REFERENCES ALBUM,
    idSong INT REFERENCES SONG,
    PRIMARY KEY (idAlbum, idSong)
);

CREATE TABLE ExecutorSong (
    idExecutor INT REFERENCES EXECUTOR,
    idSong INT REFERENCES SONG,
    PRIMARY KEY (idExecutor, idSong)
);

CREATE TABLE COLLECTION (
    idCollection SERIAL PRIMARY KEY,
    collection TEXT NOT NULL,
    year INT
);

CREATE TABLE CollectionSong (
    idCollection INT REFERENCES ALBUM,
    idSong INT REFERENCES SONG,
    PRIMARY KEY (idCollection, idSong)
);