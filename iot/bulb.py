import json
import time
import threading

class Bulb:
    def __init__(self, thing_id, brightness, color):
        self.thing_id = self.policy_id = thing_id
        self.file_name = thing_id + ".json"
        self.event = threading.Event()
        self.attributes = {
            "model": "UltraLux",
            "diameter": 10,
            "warranty": 2
        }
        self.features = {
            "indicators": {
                "properties": {
                    "brightness": brightness,
                    "color": color
                },
                "desiredProperties": {
                    "brightness": 50,
                    "colors": ["Yellow","Red","Green","Blue","White","Orange"] 
                }
            },
            "state": {
                "properties": {
                    "working": "On"
                }
            },
        }

    def save_to_json(self):
        serializable = {
            "thingId": self.thing_id,
            "policyId": self.policy_id,
            "attributes": self.attributes,
            "features": self.features
        }
        with open("./digital-twins/" + self.file_name, 'w') as output:
            json.dump(serializable, output, indent=4, ensure_ascii=False)

    def break_bulb(self):

        print("Bulb with id " + str(self.thing_id) + " is broken")
        self.features["state"]["properties"]["working"] = "Off"
        self.features["indicators"]["properties"]["brightness"] = 0
        self.save_to_json()

    def fix_bulb(self, tech_id):
        print("Technician " + str(tech_id) + " is fixing bulb with id " + str(self.thing_id))
        time.sleep(3)
        print("Bulb with id " + str(self.thing_id) + " is fixed")
        self.features["state"]["properties"]["working"] = "On"
        self.save_to_json()

    def update_indicators(self, brightness , color):
        self.features["indicators"]["properties"]["brightness"] = brightness
        self.features["indicators"]["properties"]["color"] = color
        print("Update from bulb with id " + str(self.thing_id) + ": brightness: " + str(brightness) +"%" + ", color: " + str(color))
        self.save_to_json()