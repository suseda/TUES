from pydantic import BaseModel
from datetime import datetime


class SongCreate(BaseModel):
    title: str
    artist: str
    genre: str
    playlist_id: int

class Song(BaseModel):
    id: int
    
    title: str
    artist: str
    genre: str
    playlist_id: int
    
    created_at: datetime
    updated_at: datetime

    
    
    
