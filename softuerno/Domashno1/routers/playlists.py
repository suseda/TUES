from typing import List

from fastapi import APIRouter, Depends, HTTPException
from sqlalchemy.orm import Session
from dependencies import get_db

import crud.playlist as playlist_crud
from schemas.playlist import Playlist, PlaylistCreate

router = APIRouter(
    prefix="/playlists",
    tags=["playlists"],
    responses={404: {"description": "Not found"}},
)


@router.get("/", response_model=List[Playlist])
def index(db: Session = Depends(get_db)):
    return playlist_crud.list_all(db)


@router.get("/{playlist_id}", response_model=Playlist)
def show(playlist_id: int, db: Session = Depends(get_db)):
    return playlist_crud.get(db, playlist_id)


@router.post("/", response_model=Playlist)
def create(playlist: PlaylistCreate, db: Session = Depends(get_db)):
    return playlist_crud.create(db, playlist)


@router.put("/{playlist_id}", response_model=Playlist)
def update(playlist_id: int, playlist: PlaylistCreate, db: Session = Depends(get_db)):
    return playlist_crud.update(db, playlist_id, playlist)


@router.delete("/{playlist_id}")
def delete(playlist_id: int, db: Session = Depends(get_db)):
    return playlist_crud.delete(db, playlist_id)
