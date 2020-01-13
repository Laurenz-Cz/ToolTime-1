import requests
import thingspeak
import time

# setup ThingSpeak
channel_id = 526104  # PUT CHANNEL ID HERE
write_key = 'VHUTP3IGY7BMB9P2'  # PUT YOUR WRITE KEY HERE
read_key = '36D7UK3AN6XUX0D8'  # PUT YOUR READ KEY HERE

def update(channel, value1, value2):
    try:

        print('message sent')
        # write
        channel.update({'field1': value1, \
                        'field2': value2})

    except:
        print("connection failed")
        print("retrying ...")
        update(channel)

if __name__ == "__main__":

    while True:
        url = 'http://octopi.local/api/printer/bed?apikey=B9E20C725947458181F805B8E6DAA48F'

        resp = requests.get(url=url)
        data = resp.json()
        bedTemperature = data['bed']['actual']
        targetTemperature = data['bed']['target']
        print(bedTemperature)
        print(targetTemperature)
        channel = thingspeak.Channel(id=channel_id, write_key=write_key, api_key=read_key)
        update(channel, bedTemperature, targetTemperature)
        time.sleep(20)
