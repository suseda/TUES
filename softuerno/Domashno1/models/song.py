from datetime import datetime
from sqlalchemy import Column, Integer, TIMESTAMP, String, ForeignKey
from sqlalchemy.orm import relationship
from database import Base

class Song(Base):
    __tablename__ = "songs"
    id = Column(Integer, primary_key=True, index=True)
    title = Column(String, index=True)
    artist = Column(String, index=True)
    genre = Column(String)
    playlist_id = Column(Integer, ForeignKey('playlists.id'))
    playlist = relationship("Playlist", back_populates="song")    
    
    created_at = Column(TIMESTAMP, default=datetime.now())
    updated_at = Column(TIMESTAMP, default=datetime.now())
