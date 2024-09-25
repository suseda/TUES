from datetime import datetime
from sqlalchemy import Column, String, Integer, TIMESTAMP
from sqlalchemy.orm import relationship
from database import Base

class Playlist(Base):
    __tablename__ = "playlists"
    id = Column(Integer, primary_key=True, index=True)
    title = Column(String)
    description = Column(String)

    song = relationship("Song",back_populates="playlist") 
    
    created_at = Column(TIMESTAMP, default=datetime.now())
    updated_at = Column(TIMESTAMP, default=datetime.now())
