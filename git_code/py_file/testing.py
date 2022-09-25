import requests
import json
response = requests.get(
            "https://api.waifu.im/sfw/waifu/")
data = json.loads(response.text)
print(data['images'][0]['url'])