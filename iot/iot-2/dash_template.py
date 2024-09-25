# All imports that you would need are already provided.
import pandas as pd
import plotly.express as px

from bson import ObjectId
from pymongo import MongoClient
from dash import Dash, html, callback, Output, Input, dash_table, dcc

# Please do not modify the database name
DATABASE_NAME = "dash-exam"
# Insert your MongoDB connection string here
CONNECTION_STRING = "mongodb+srv://userDb:userDbPass@clusteriot.ggtljgg.mongodb.net/?retryWrites=true&w=majority&appName=ClusterIoT"

app = Dash(__name__)
# Replace None with the layout of the application based on the instructions
app.layout = html.Div(id="html-div", children=[
    html.H2(children="Thermometer's table"),
    dash_table.DataTable(id="thermometer-table"),
    html.Br(),
    html.Br(),
    dcc.RadioItems(
        id='thermometer-filter',
        options=[
            {'label': 'All', 'value': 'All'}
        ],
        value='All'
    ),
    dcc.Graph(id="temperature-graph"),
    dcc.Interval(id="interval", interval=1000, n_intervals=0)
])

# Write the callback function(s) based on the instructions
@callback(
    [Output("thermometer-table", "data"),
     Output("temperature-graph", "figure"),
     Output("thermometer-filter", "options")],
    [Input("interval", "n_intervals"),
     Input("thermometer-filter", "value")]
)

def update_thermometer_table(_, selected_thermometer):
    thermometers = list(thermometer_collection.find({}))
    for thermometer in thermometers:
        thermometer["_id"] = str(thermometer["_id"])
    
    if selected_thermometer == 'All':
        temperatures = list(temperature_collection.find({}))
    else:
        temperatures = list(temperature_collection.find({"thermometer_id": ObjectId(selected_thermometer)}))
    
    temperatures_df = pd.DataFrame(temperatures)
    temperatures_df["timestamp"] = pd.to_datetime(temperatures_df["timestamp"])
    
    if not temperatures_df.empty:
        fig = px.line(temperatures_df, x="timestamp", y="value", color="thermometer_id")
    else:
        fig = px.line()

    existing_thermometer_ids = [str(thermometer["_id"]) for thermometer in thermometers]

    options = [{'label': 'All', 'value': 'All'}] + [{'label': thermometer_id, 'value': thermometer_id} for thermometer_id in existing_thermometer_ids]

    return thermometers, fig, options



# Please do not modify the below function
# Use the thermometer_collection and temperature_collection objects to query the database
if __name__ == "__main__":
    mongo_client = MongoClient(CONNECTION_STRING)
    database = mongo_client.get_database(DATABASE_NAME)
    thermometer_collection = database.get_collection("thermometers")
    temperature_collection = database.get_collection("temperatures")
    app.run(debug=True, port=8050)