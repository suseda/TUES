import datetime
import json
from flask import Flask, request, jsonify

from time import time
from bson import json_util
from bson.objectid import ObjectId
from pymongo import MongoClient

app = Flask(__name__)

DATABASE_NAME = "mongo-raise-exam"

# Insert your MongoDB connection string here
CONNECTION_STRING = "mongodb+srv://kalkobusiness1914:oCGx1DAEARTUNRyW@cluster0.wxhvnux.mongodb.net/?retryWrites=true&w=majority&appName=Cluster0"

# Global variables for the database and collections
# DO NOT MODIFY
mongo_client = MongoClient(CONNECTION_STRING)
database = mongo_client.get_database(DATABASE_NAME)
security_devices_collection = database.get_collection("security_devices")
security_devices_entries_collection = database.get_collection("security_devices_entries")


@app.route("/devices", methods=["POST"])
def create_security_device():
    data = request.get_json()
    device = {
        "building": data.get("building"),
        "manufacturer": data.get("manufacturer")
    }
    security_devices_collection.insert_one(device)
    return jsonify(json.loads(json_util.dumps(device))), 201


@app.route("/devices/<device_id>", methods=["PUT"])
def update_security_device(device_id):
    device = security_devices_collection.find({"_id": ObjectId(device_id)})
    if device:
        data = request.get_json()
        device = {
            "building": data.get("building"),
            "manufacturer": data.get("manufacturer")
        }
        security_devices_collection.update_one({"_id": ObjectId(device_id)}, {"$set": device})
        return jsonify(json.loads(json_util.dumps(device))), 200
    else:
        return jsonify({"error": "Device not found"}), 404



@app.route("/devices/<device_id>", methods=["DELETE"])
def delete_security_device(device_id):
    device = security_devices_collection.find({"_id": ObjectId(device_id)})
    if device:
        security_devices_collection.delete_one({"_id": ObjectId(device_id)})
        return jsonify({"message": "Device was deleted"}), 200
    else:
        return jsonify({"error": "Device not found"}), 404


@app.route("/devices/<device_id>/data", methods=["POST"])
def create_security_device_entry(device_id):
    data = request.get_json()
    device_entry = {
        "security_device_id": ObjectId(device_id),
        "person": data.get("person"),
        "timestamp": int(time())
    }
    security_devices_entries_collection.insert_one(device_entry)
    return jsonify(json.loads(json_util.dumps(device_entry))), 201


@app.route("/devices/<device_id>/data/<data_id>", methods=["DELETE"])
def delete_security_device_entry(device_id, data_id):
    device_entry = security_devices_entries_collection.find({"_id": ObjectId(data_id)})
    if device_entry:
        security_devices_entries_collection.delete_one({"_id": ObjectId(data_id)})
        return jsonify({"message": "Device entry was deleted"}), 200
    else:
        return jsonify({"error": "Device not found"}), 404

    


@app.route("/devices/<device_id>", methods=["GET"])
def get_security_device_by_id(device_id):
    device = security_devices_collection.find({"_id": ObjectId(device_id)})
    if device:
        return jsonify(json.loads(json_util.dumps(device))), 200
    else:
        return jsonify({"error": "Device not found"}), 404


@app.route("/devices/building/<building>", methods=["GET"])
def get_security_devices_by_building_sorted_descending(building):
    building = security_devices_collection.find({"building": building})
    building.sort("_id", -1)
    return jsonify(json.loads(json_util.dumps(building))), 200


@app.route("/devices/<device_id>/count", methods=["GET"])
def get_security_device_entry_count_by_id(device_id):
    device_entries = security_devices_entries_collection.find({"security_device_id": ObjectId(device_id)})
    cnt = 0
    for entry in device_entries:
        cnt += 1
    return jsonify({"count": cnt}), 200


@app.route("/devices/<device_id>/data/filter/<date>", methods=["GET"])
def get_security_device_entries_after_date(device_id, date):
    device = security_devices_collection.find_one({"_id": ObjectId(device_id)})
    if device:
        device_entries = security_devices_entries_collection.find({"security_device_id": ObjectId(device_id)})
        filtered = []
        d = int(date)
        for entry in device_entries:
            if d < int(entry.get("timestamp")):
                filtered.append(entry)
                
        return jsonify(json.loads(json_util.dumps(filtered)), 200)
    else:
        return jsonify({"error": "Device not found"}), 404


@app.route("/devices/<device_id>/data/limit/<n>", methods=["GET"])
def get_security_device_last_n_entries(device_id, n):
    device = security_devices_collection.find_one({"_id": ObjectId(device_id)})
    if device:
        device_entries = security_devices_entries_collection.find({"security_device_id": ObjectId(device_id)})
        device_entries.sort("timestamp", -1)
        n = int(n)
        return jsonify(json.loads(json_util.dumps(device_entries.limit(n))), 200)
    else:
        return jsonify({"error": "Device not found"}), 404


# -----------------------------------------------------------------------------------------------

if __name__ == "__main__":
    app.run(debug=True, port=8000)