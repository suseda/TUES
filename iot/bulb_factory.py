import time
import random
import threading
from queue import Queue

from bulb import Bulb
from dashboard import dashboard

BULBS = 5
TECHNICIANS = 3
COLORS = ["Yellow","Red","Green","Blue","White","Orange"] 

def bulb_functioning(bulb):
    while 1:
        brightness = bulb.features["indicators"]["desiredProperties"]["brightness"]

        if random.randint(0, 100) < 40:
            bulb.break_bulb()
            smart_home_manager_queue.put(bulb)
            
            smart_home_manager_event.set()
            smart_home_manager_event.clear()

            bulb.event.wait()
        else:
            
            brightness = random.randint(brightness - 3, brightness + 3)
            index = random.randint(0,5)
            color = COLORS[index]
            bulb.update_indicators(brightness, color)

        time.sleep(random.randint(3, 5))


def technician_fix_bulb(technician_id, bulb):
    bulb.fix_bulb(technician_id)
    bulb.event.set()
    bulb.event.clear()
    available_technicians.put(technician_id)


def smart_home_manager():
    while True:
        smart_home_manager_event.wait()
        while not smart_home_manager_queue.empty():
            if not available_technicians.empty():
                threading.Thread(target=technician_fix_bulb, args=(available_technicians.get(), smart_home_manager_queue.get(),), daemon=True).start()


if __name__ == "__main__":
   
    smart_home_manager_thread = threading.Thread(target=smart_home_manager, daemon=True)
    smart_home_manager_queue = Queue()
    smart_home_manager_event = threading.Event()

 
    smart_home_manager_thread.start()

   
    available_technicians = Queue()
    for i in range(TECHNICIANS):
        available_technicians.put(i + 1)

    
    bulbs_brightness = [random.randint(40,90) for i in range(BULBS)]
    
    bulb_thing_ids = ["bulb-" + str(id) for id in range(BULBS)]
    
    bulbs_colors = [COLORS[random.randint(0,5)] for i in range(BULBS)]

    bulbs = [Bulb(bulb_thing_ids[i], bulbs_brightness[i],bulbs_colors[i]) for i in range(BULBS)]

    bulb_threads = []
    for bulb in bulbs:
        bt = threading.Thread(target=bulb_functioning, args=(bulb,), daemon=True)
        bulb_threads.append(bt)


    for bt in bulb_threads:
        bt.start()
        time.sleep(.5)
    
    dashboard(bulbs)

    for bt in bulb_threads:
        bt.join()

    