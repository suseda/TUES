import pandas as pd
import plotly.express as px

from bson import ObjectId
from pymongo import MongoClient
from dash import Dash, html, callback, Output, Input, dash_table, dcc

# Please do not modify the database name
DATABASE_NAME = "dash-exam"
# Insert your MongoDB connection string here
CONNECTION_STRING = "mongodb+srv://kalkobusiness1914:Koko-real6484@cluster0.wxhvnux.mongodb.net/?retryWrites=true&w=majority&appName=Cluster0"

app = Dash(__name__)

app.layout = html.Div(children=[
    html.H1(children='Thermometer Data'),

    dash_table.DataTable(
        id='thermometer-table',
        columns=[{"name": i, "id": i} for i in ['label', 'manufacturer', 'room']],
        data=[]
    ),

    dcc.Interval(
        id='interval-component',
        interval=1*1000,  
        n_intervals=0
    ),

    html.Div(id='graph-container', children=[
        dcc.Graph(id='temperature-graph')
    ]),

    html.Div(children=[
        dcc.RadioItems(
            id='thermometer-filter',
            options=[{'label': 'All', 'value': 'all'}],
            value='all'
        )
    ])
])


@app.callback(
    Output('thermometer-table', 'data'),
    [Input('interval-component', 'n_intervals')]
)
def update_table(n_intervals):

    data = list(thermometer_collection.find())

    df = pd.DataFrame(data)
    table_data = df.to_dict('records')

    return table_data

@app.callback(
    Output('temperature-graph', 'figure'),
    [Input('thermometer-filter', 'value')]
)
def update_graph():
    data = list(temperature_collection.find())
    df = pd.DataFrame(data)
    fig = px.line(df, x='timestamp', y='temperature', title='Temperature Measurements Over Time', color='lable')

    return fig


if __name__ == "__main__":
    mongo_client = MongoClient(CONNECTION_STRING)
    database = mongo_client.get_database(DATABASE_NAME)
    thermometer_collection = database.get_collection("thermometers")
    temperature_collection = database.get_collection("temperatures")
    app.run(debug=True, port=8050)