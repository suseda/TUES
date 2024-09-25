from datetime import datetime

from sqlalchemy.orm import Session

from models import user as user_model
from schemas import user as user_schema


def list_all(db: Session, skip: int = 0, limit: int = 100):
    return (db.query(user_model.User)
            .offset(skip)
            .limit(limit)
            .all())


def get(db: Session, user_id: int):
    return (db.query(user_model.User)
            .get({'id': user_id}))


def create(db: Session, user: user_schema.UserCreate):
    db_user = user_model.User(name = user.name, email = user.email)
    db.add(db_user)
    db.commit()
    db.refresh(db_user)
    return db_user


def update(db: Session, user_id: int, user: user_schema.UserCreate):
    db_user = get(db, user_id)
    
    db_user.name = user.name
    db_user.email = user.email
    
    db_user.updated_at = datetime.now()
    db.commit()
    db.refresh(db_user)
    return db_user


def delete(db: Session, user_id: int):
    db_user = get(db, user_id)
    db.delete(db_user)
    db.commit()
    return None
