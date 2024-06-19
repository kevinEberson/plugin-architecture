import random
import string
import time
import json
import paho.mqtt.client as mqtt

BROKER_ADDRESS = "your_mqtt_broker_address"

# Function to generate random string of given length
def random_string(length):
    return ''.join(random.choices(string.ascii_uppercase + string.digits, k=length))

# Function to generate random fixed value
def random_fixed_value(min_value=0, max_value=100):
    return round(random.uniform(min_value, max_value), 2)

# Function to generate random timestamp
def random_timestamp():
    return time.strftime('%Y-%m-%d %H:%M:%S', time.gmtime())

# Function to generate random on/off value
def random_on_off():
    return random.choice(["On", "Off"])

# Function to generate random data for each endpoint
def generate_data():
    return {
        "identification": random_string(10),
        "p1_version": random_string(5),
        "p1_version_be": random_string(5),
        "timestamp": random_timestamp(),
        "equipment_id": random_string(10),
        "energy_delivered_tariff1": random_fixed_value(0, 1000),
        "energy_delivered_tariff2": random_fixed_value(0, 1000),
        "energy_returned_tariff1": random_fixed_value(0, 1000),
        "energy_returned_tariff2": random_fixed_value(0, 1000),
        "electricity_tariff": random.choice(["0001", "0002"]),
        "power_delivered": random_fixed_value(0, 10),
        "power_returned": random_fixed_value(0, 10),
        "message_short": random_string(20),
        "message_long": random_string(50),
        "voltage_l1": random_fixed_value(220, 240),
        "voltage_l2": random_fixed_value(220, 240),
        "voltage_l3": random_fixed_value(220, 240),
        "current_l1": random_fixed_value(0, 16),
        "current_l2": random_fixed_value(0, 16),
        "current_l3": random_fixed_value(0, 16),
        "power_delivered_l1": random_fixed_value(0, 10),
        "power_delivered_l2": random_fixed_value(0, 10),
        "power_delivered_l3": random_fixed_value(0, 10),
        "power_returned_l1": random_fixed_value(0, 10),
        "power_returned_l2": random_fixed_value(0, 10),
        "power_returned_l3": random_fixed_value(0, 10),
        "mbus1_device_type": random.randint(0, 65535),
        "mbus1_equipment_id_tc": random_string(10),
        "mbus1_equipment_id_ntc": random_string(10),
        "mbus1_valve_position": random.randint(0, 255),
        "mbus1_delivered": random_timestamp(),
        "mbus1_delivered_ntc": random_timestamp(),
        "mbus1_delivered_dbl": random_timestamp(),
        "mbus2_device_type": random.randint(0, 65535),
        "mbus2_equipment_id_tc": random_string(10),
        "mbus2_equipment_id_ntc": random_string(10),
        "mbus2_valve_position": random.randint(0, 255),
        "mbus2_delivered": random_timestamp(),
        "mbus2_delivered_ntc": random_timestamp(),
        "mbus2_delivered_dbl": random_timestamp(),
        "mbus3_device_type": random.randint(0, 65535),
        "mbus3_equipment_id_tc": random_string(10),
        "mbus3_equipment_id_ntc": random_string(10),
        "mbus3_valve_position": random.randint(0, 255),
        "mbus3_delivered": random_timestamp(),
        "mbus3_delivered_ntc": random_timestamp(),
        "mbus3_delivered_dbl": random_timestamp(),
        "mbus4_device_type": random.randint(0, 65535),
        "mbus4_equipment_id_tc": random_string(10),
        "mbus4_equipment_id_ntc": random_string(10),
        "mbus4_valve_position": random.randint(0, 255),
        "mbus4_delivered": random_timestamp(),
        "mbus4_delivered_ntc": random_timestamp(),
        "mbus4_delivered_dbl": random_timestamp(),
        "gas_delivered": random_fixed_value(0, 1000),
        "gas_delivered_timestamp": random_timestamp(),
        "water_delivered": random_fixed_value(0, 1000),
        "LWT": random_on_off()
    }

def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("Connected to MQTT Broker!")
    else:
        print(f"Failed to connect, return code {rc}\n")

client = mqtt.Client()
client.on_connect = on_connect
client.connect(BROKER_ADDRESS)

client.loop_start()

try:
    while True:
        data = generate_data()
        for key, value in data.items():
            topic = f"P1-DONGLE-PRO/{key}"
            client.publish(topic, json.dumps({key: value}))
            print(f"Published to {topic}: {value}")
        time.sleep(10)  # Adjust the frequency of publishing as needed
except KeyboardInterrupt:
    print("Script interrupted.")
finally:
    client.loop_stop()
    client.disconnect()
