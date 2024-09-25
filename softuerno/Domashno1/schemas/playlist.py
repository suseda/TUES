from pydantic import BaseModel
from datetime import datetime

from models.song import Song

class PlaylistCreate(BaseModel):
    title: str 
    description: str

class Playlist(BaseModel):
    id: int
    
    title: str 
    description: str

    created_at: datetime
    updated_at: datetime