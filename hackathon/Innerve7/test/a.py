import openai
import pandas as pd

# Set the API key for OpenAI
openai.api_key = "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"

# Load the CSV file into a Pandas DataFrame
csv_file = 'test/test.csv'
df = pd.read_csv(csv_file)

# Get the text from the CSV file
text = df.iloc[0]['text']

# Fine-tune the GPT model using the text from the CSV file
model = "text-davinci-002"
fine_tuned_model = openai.FineTune(
    model=model,
    train_dataset=[text],
    batch_size=2,
    num_epochs=5
)

# Save the fine-tuned model to a tar file
# fine_tuned_model.save_checkpoint("fine_tuned_model.ckpt")

# Save the fine-tuned model to a file
# fine_tuned_model.save("fine_tuned_model.pkl")
