import requests
import json
from bs4 import BeautifulSoup

url = 'https://docs.accops.com/HyWorks34/content/release_notes/3.4_ga/3.4_ga_features_enhancements.html'
response = requests.get(url)
soup = BeautifulSoup(response.text, 'html.parser')



h3_tags = soup.find_all('h4')

data_dict = {}

for i in range(len(h3_tags)-1):
    start_tag = h3_tags[i]
    end_tag = h3_tags[i+1]

    key = start_tag.text.strip()
    value = ''
    next_tag = start_tag.next_sibling
    while next_tag != end_tag:
        if hasattr(next_tag, 'text'):
            value += next_tag.text.strip()
        next_tag = next_tag.next_sibling

    data_dict[key] = value

print(data_dict)
# Convert data_dict to JSON format
json_data = json.dumps(data_dict, indent=4)

# # Save the JSON data to a file
# with open('data.json', 'w') as f:
#     f.write(json_data)

json_data = []
for key, value in data_dict.items():
    json_obj = {"prompt": key, "completion": value}
    json_data.append(json_obj)

with open('test/scraper/data1.json', 'w') as f:
    json.dump(json_data, f, indent=4)