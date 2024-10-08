import datetime
from sqlalchemy.orm import Session

from models import torrent as models
from schemas import torrent as schemas


def get_torrents(db: Session, skip: int = 0, limit: int = 100):
    return db.query(models.Torrent).offset(skip).limit(limit).all()


def create_user_torrent(db: Session, torrent: schemas.TorrentCreate, user_id: int):
    db_torrent = models.Torrent(**torrent.dict(), owner_id=user_id)
    db.add(db_torrent)
    db.commit()
    db.refresh(db_torrent)
    return db_torrent

def list_all(db: Session, skip: int = 0, limit: int = 100):
    return (db.query(models.Torrent)
            .offset(skip)
            .limit(limit)
            .all())



def update(db: Session, torrent_id: int, torrent: schemas.TorrentCreate):
    db_torrent = get_torrents(db, torrent_id)
    db_torrent.name = torrent.name
    db_torrent.description = torrent.description
    db_torrent.file = torrent.file
    db_torrent.image = torrent.image 
    db_torrent.times_downloaded = torrent.times_downloaded
    db_torrent.updated_at = datetime.now()
    db.commit()
    db.refresh(db_torrent)
    return db_torrent



def delete(db: Session, torrent_id: int):
    db_torrent = get_torrents(db, torrent_id)
    db.delete(db_torrent)
    db.commit()
    return None
