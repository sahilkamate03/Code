import pandas as pd
df = pd.read_csv('test/test.csv')

# Get the text from the CSV file
text = df.iloc[0]
print(text['text'])