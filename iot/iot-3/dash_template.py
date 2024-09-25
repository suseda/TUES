# All imports that you would need are already provided.
import pandas as pd
import plotly.express as px

from bson import ObjectId
from pymongo import MongoClient
from dash import Dash, html, callback, Output, Input, dash_table, dcc

# Please do not modify the database name
DATABASE_NAME = "dash-raise-exam"
# Insert your MongoDB connection string here
CONNECTION_STRING = "mongodb+srv://kalkobusiness1914:oCGx1DAEARTUNRyW@cluster0.wxhvnux.mongodb.net/?retryWrites=true&w=majority&appName=Cluster0"

# Global variables for the database and collections
# DO NOT MODIFY
mongo_client = MongoClient(CONNECTION_STRING)
database = mongo_client.get_database(DATABASE_NAME)
thermometer_collection = database.get_collection("thermometers")
temperature_collection = database.get_collection("temperatures")

app = Dash(__name__)
# Replace None with the layout of the application based on the instructions
app.layout = html.Div(id="html-div", children=[
    html.H1("Temperatures"),
    dash_table.DataTable(
        id="temperatures-data-table",
        columns=[
            {"name": "_id", "id": "_id"},
            {"name": "value", "id": "value"},
            {"name": "timestamp", "id": "timestamp"},
            {"name": "thermometer_id", "id": "thermometer_id"}
        ],
        page_size=10
    ),
    html.H1(children="Thermometer Average Bar"),
    dcc.Graph(id="thermometers-bar"),
    dcc.Interval(id="interval", interval=1000, n_intervals=0),
    dcc.RadioItems(
        id="buttons",
        options=[
            {"label": "All", "value": "All"}
        ],
        value="All"
    )
])

@app.callback(
    Output("temperatures-data-table", "data"),
    Output("thermometers-bar", "figure"),
    Output("buttons", "options"),
    Input("interval", "n_intervals"),
    Input("buttons", "value")
)
def update_data_table_and_graph(n_intervals, button_value):
    
    df_temperatures = pd.DataFrame(list(temperature_collection.find()))
    df_thermometers = pd.DataFrame(list(thermometer_collection.find()))

    df_temperatures["_id"] =  df_temperatures["_id"].astype(str)
    df_temperatures["thermometer_id"] =  df_temperatures["thermometer_id"].astype(str)
    data_table = df_temperatures.to_dict("records")

    if button_value == "All":
        avg_temperatures = df_temperatures.groupby("thermometer_id")["value"].mean().reset_index()
    else:
        filtered_temperatures = df_temperatures[df_temperatures["thermometer_id"] == button_value]
        avg_temperatures = filtered_temperatures.groupby("thermometer_id")["value"].mean().reset_index()

    avg_temperatures["thermometer_id"] = avg_temperatures["thermometer_id"].astype(str)

    fig = px.bar(avg_temperatures, x="thermometer_id", y="value",
                 labels={"thermometer_id": "Thermometer ID", "value": "Average Temperature"})

  
    unique_thermometer_ids = df_thermometers["_id"].astype(str)
    radio_options = [{"label": "All", "value": "All"}] + [
        {"label": therm_id, "value": therm_id} for therm_id in unique_thermometer_ids
    ]

    return data_table, fig, radio_options


if __name__ == "__main__":
    app.run(debug=True, port=8050)