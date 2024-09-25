from datetime import datetime

from sqlalchemy.orm import Session

from models import song as song_model
from schemas import song as song_schema


def list_all(db: Session, skip: int = 0, limit: int = 100):
    return (db.query(song_model.Song)
            .offset(skip)
            .limit(limit)
            .all())


def get(db: Session, song_id: int):
    return (db.query(song_model.Song)
            .get({'id': song_id}))


def create(db: Session, song: song_schema.SongCreate):
    db_song = song_model.Song(title = song.title, artist = song.artist, genre = song.genre, playlist_id = song.playlist_id)
    db.add(db_song)
    db.commit()
    db.refresh(db_song)
    return db_song


def update(db: Session, song_id: int, song: song_schema.SongCreate):
    db_song = get(db, song_id)
    
    db_song.title = song.title
    db_song.artist = song.artist
    db_song.genre = song.genre
    db_song.playlist_id = song.playlist_id
    
    
    db_song.updated_at = datetime.now()
    db.commit()
    db.refresh(db_song)
    return db_song


def delete(db: Session, song_id: int):
    db_song = get(db, song_id)
    db.delete(db_song)
    db.commit()
    return None
