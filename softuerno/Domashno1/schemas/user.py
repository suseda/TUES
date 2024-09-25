from pydantic import BaseModel
from datetime import datetime

class UserCreate(BaseModel):
    name: str
    email: str

class User(BaseModel):
    id: int
    
    name: str
    email: str
    
    created_at: datetime
    updated_at: datetime