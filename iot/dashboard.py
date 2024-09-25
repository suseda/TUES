import json
import time  

def read_bulb_info(file_name):
    with open(f'./digital-twins/{file_name}', 'r') as file:
        data = json.load(file)
    return data

def dashboard(bulbs):
    while True:
        for bulb in bulbs:
            bulb_info = read_bulb_info(bulb.file_name)
            print(f"{bulb_info['thingId']} | {bulb_info['features']['indicators']['properties']['color']} | {bulb_info['features']['indicators']['properties']['brightness']}% | {bulb_info['features']['state']['properties']['working']}")
        time.sleep(1)
        print("="*30)


