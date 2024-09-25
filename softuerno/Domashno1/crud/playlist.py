from datetime import datetime

from sqlalchemy.orm import Session

from models import playlist as playlist_model
from schemas import playlist as playlist_schema


def list_all(db: Session, skip: int = 0, limit: int = 100):
    return (db.query(playlist_model.Playlist)
            .offset(skip)
            .limit(limit)
            .all())


def get(db: Session, playlist_id: int):
    return (db.query(playlist_model.Playlist)
            .get({'id': playlist_id}))


def create(db: Session, playlist: playlist_schema.PlaylistCreate):
    db_playlist = playlist_model.Playlist(title=playlist.title,description=playlist.description)
    db.add(db_playlist)
    db.commit()
    db.refresh(db_playlist)
    return db_playlist


def update(db: Session, playlist_id: int, playlist: playlist_schema.PlaylistCreate):
    db_playlist = get(db, playlist_id)
    db_playlist.title = playlist.title
    db_playlist.description = playlist.description
    db_playlist.updated_at = datetime.now()
    db.commit()
    db.refresh(db_playlist)
    return db_playlist


def delete(db: Session, playlist_id: int):
    db_playlist = get(db, playlist_id)
    db.delete(db_playlist)
    db.commit()
    return None
