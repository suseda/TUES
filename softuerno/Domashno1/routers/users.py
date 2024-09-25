from typing import List

from fastapi import APIRouter, Depends, HTTPException
from sqlalchemy.orm import Session
from dependencies import get_db

import crud.user as user_crud
from schemas.user import User, UserCreate

router = APIRouter(
    prefix="/users",
    tags=["users"],
    responses={404: {"description": "Not found"}},
)


@router.get("/", response_model=List[User])
def index(db: Session = Depends(get_db)):
    return user_crud.list_all(db)


@router.get("/{user_id}", response_model=User)
def show(user_id: int, db: Session = Depends(get_db)):
    return user_crud.get(db, user_id)


@router.post("/", response_model=User)
def create(user: UserCreate, db: Session = Depends(get_db)):
    return user_crud.create(db, user)


@router.put("/{user_id}", response_model=User)
def update(user_id: int, user: UserCreate, db: Session = Depends(get_db)):
    return user_crud.update(db, user_id, user)


@router.delete("/{user_id}")
def delete(user_id: int, db: Session = Depends(get_db)):
    return user_crud.delete(db, user_id)