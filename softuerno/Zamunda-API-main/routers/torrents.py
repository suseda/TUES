from ast import List
from fastapi import APIRouter, Depends
from sqlalchemy.orm import Session

from schemas import torrent as schema
from dependencies import get_token_header, get_db
from crud import torrents as torrent_crud

router = APIRouter(
    prefix="/torrents",
    tags=["torrents"],
    dependencies=[Depends(get_token_header)],
    responses={404: {"description": "Not found"}},
)

@router.get("/", response_model=List[schema.Torrent])
def index(db: Session = Depends(get_db)):
    return torrent_crud.list_all(db)

@router.get("/{torrent_id}", response_model=schema.Torrent)
def show(torrent_id: int, db: Session = Depends(get_db)):
    return torrent_crud.get(db, torrent_id)


@router.post("/", response_model=schema.Torrent)
def create(torrent: schema.TorrentCreate, db: Session = Depends(get_db)):
    return torrent_crud.create(db, torrent)


@router.put("/{torrent_id}", response_model=schema.Torrent)
def update(torrent_id: int, category: schema.Torrent, db: Session = Depends(get_db)):
    return torrent_crud.update(db, torrent_id, category)


@router.delete("/{torrent_id}")
def delete(torrent_id: int, db: Session = Depends(get_db)):
    return torrent_crud.delete(db, torrent_id)