from fastapi import FastAPI, Request
from starlette.templating import Jinja2Templates

from database import Base, engine
from models import playlist, song, user
from routers import playlists, songs, users

templates = Jinja2Templates(directory="templates")

app = FastAPI()


@app.on_event("startup")
def startup_event():
    Base.metadata.create_all(bind=engine, tables=[
        playlist.Playlist.__table__,
        song.Song.__table__,
        user.User.__table__
    ])


app.include_router(playlists.router)
app.include_router(songs.router)
app.include_router(users.router)

@app.get('/')
def index(request: Request):
    return templates.TemplateResponse('index.html', {'request': request})
