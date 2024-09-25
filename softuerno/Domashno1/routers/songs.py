from typing import List

from fastapi import APIRouter, Depends, HTTPException
from sqlalchemy.orm import Session
from dependencies import get_db

import crud.song as song_crud
from schemas.song import Song, SongCreate

router = APIRouter(
    prefix="/songs",
    tags=["songs"],
    responses={404: {"description": "Not found"}},
)


@router.get("/", response_model=List[Song])
def index(db: Session = Depends(get_db)):
    return song_crud.list_all(db)


@router.get("/{song_id}", response_model=Song)
def show(song_id: int, db: Session = Depends(get_db)):
    return song_crud.get(db, song_id)


@router.post("/", response_model=Song)
def create(song: SongCreate, db: Session = Depends(get_db)):
    return song_crud.create(db, song)


@router.put("/{song_id}", response_model=Song)
def update(song_id: int, song: SongCreate, db: Session = Depends(get_db)):
    return song_crud.update(db, song_id, song)


@router.delete("/{song_id}")
def delete(song_id: int, db: Session = Depends(get_db)):
    return song_crud.delete(db, song_id)