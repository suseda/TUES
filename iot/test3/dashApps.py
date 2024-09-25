from pymongo import MongoClient
from dash import Dash, html, callback, Output, Input, dash_table, dcc
import pandas as pd
import plotly.express as px
DATABASE_NAME = "ClusterIOTExercise"

CONNECTION_STRING = "mongodb+srv://kalkobusiness1914:oCGx1DAEARTUNRyW@cluster0.wxhvnux.mongodb.net/?retryWrites=true&w=majority&appName=Cluster0"

client = MongoClient(CONNECTION_STRING)
db = client[DATABASE_NAME]
collection = db["thermometers"]
collection1 = db["temperatures"]

app = Dash(__name__)
app.layout = html.Div(id="html-div", children=[
    html.H2(children="Thermometers table"),
    dash_table.DataTable(id="thermometer-data-table", page_size=10),
    html.H2(children="Themperature graph"),
    dcc.RadioItems(id="buttons", options=[{"label":"All", "value":"All"}], value="All"),
    dcc.Graph(id="temperature-graph"),
    dcc.Interval(id="interval", interval=10000, n_intervals=0)
])
@callback(
    Output(component_id='thermometer-data-table', component_property='data'),
    Output(component_id='temperature-graph', component_property='figure'),
    Output(component_id='buttons', component_property='options'),
    Input(component_id='interval', component_property='n_intervals'),
    Input(component_id='buttons', component_property='value')
)
def update_func(interval, buttonValue):
    df = pd.DataFrame(list(collection.find()))
    df['_id'] = df['_id'].astype(str)

    df1 = pd.DataFrame(list(collection1.find()))
    df1['_id'] = df1['_id'].astype(str)
    df1['thermometer_id'] = df1['thermometer_id'].astype(str)

    unique_options = set()
    radio_options_dict = [{"label":"All", "value":"All"}]
    for _, row in df1.iterrows():
        if row['thermometer_id'] not in unique_options:
            radio_options_dict.append({'label': row['thermometer_id'], 'value': row['thermometer_id']})
            unique_options.add(row['thermometer_id'])

    if buttonValue == "All":
        fig = px.line(df1, x="timestamp", y="value", color='thermometer_id')
    else:
        filtered_df = df1[df1['thermometer_id'] == buttonValue]
        fig = px.line(filtered_df, x="timestamp", y="value")

    return df.to_dict('records'), fig, radio_options_dict

if __name__ == '__main__':
    app.run(debug=True, port=8051)