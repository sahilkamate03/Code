#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>

// Function to generate a random word from a vector of words
std::string generateWord(const std::vector<std::string> &words)
{
    // Use the default random engine and an uniform distribution
    std::default_random_engine eng(static_cast<unsigned int>(time(nullptr)));
    std::uniform_int_distribution<int> dist(0, words.size() - 1);

    // Generate a random index from 0 to the size of the vector
    int index = dist(eng);

    // Return the word at the generated index
    return words[index];
}

// Function to shuffle a string
void shuffle(std::string &word)
{
    // Convert the string to a vector of characters
    std::vector<char> chars(word.begin(), word.end());

    // Shuffle the vector of characters
    std::random_shuffle(chars.begin(), chars.end());

    // Convert the shuffled vector of characters back to a string
    word = std::string(chars.begin(), chars.end());
}

int main()
{
    // Vector of words to be used in the game
    std::vector<std::string> words = {"apple", "banana", "orange", "grape", "pineapple"};

    // Generate a random word from the vector of words
    std::string word = generateWord(words);

    // Shuffle the word
    shuffle(word);

    // Print the shuffled word and ask the user to guess the original word
    std::cout << "Guess the original word: " << word << std::endl;
    std::cout << "Enter your guess: ";

    std::string guess;
    std::cin >> guess;

    // Check if the user's guess is correct
    if (guess == word)
    {
        std::cout << "Congratulations! You guessed the correct word." << std::endl;
    }
    else
    {
        std::cout << "Sorry, your guess is incorrect. The correct word is: " << word << std::endl;
    }

    return 0;
}
