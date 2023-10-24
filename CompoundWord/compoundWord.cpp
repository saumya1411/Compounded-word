#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <chrono>
#include <iomanip>

class TwoStrings {
public:
    std::string first;
    std::string second;

    TwoStrings(const std::string& first, const std::string& second) : first(first), second(second) {}
};

// Function to check if a word is a compound word
bool isCompound(const std::unordered_set<std::string>& wordDictionary, const std::string& word, bool isOriginal) {
    if (isOriginal && wordDictionary.count(word)) {
        return true;
    }
   //Checking if word can be split into two smaller compound words
    for (int i = 1; i < word.length(); ++i) {
        std::string prefix = word.substr(0, i);
        std::string suffix = word.substr(i);

        if (wordDictionary.count(prefix) && isCompound(wordDictionary, suffix, true)) {
            return true;
        }
    }

    return false;
}

// Function to find the longest and second longest compound words
TwoStrings longestAndSecondLongestCompoundedWords(const std::string& filename) {
    std::vector<std::string> words;
    std::ifstream inputFile(filename);

    if (!inputFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return TwoStrings("", "");
    }

    std::string word;
    while (inputFile >> word) {
        words.push_back(word);
    }

    inputFile.close();
    
   // Sorting words by length in descending order
    std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
        return a.length() > b.length();
    });

    std::unordered_set<std::string> wordDictionary(words.begin(), words.end());

    TwoStrings result("", "");

    for (const std::string& word : words) {
        if (isCompound(wordDictionary, word, false)) {
            if (result.first.empty()) {
                result.first = word;
            } else if (word.length() != result.first.length() && (result.second.empty() || word.length() == result.second.length())) {
                result.second = word;
            }
        }
    }

    return result;
}

int main() {
    std::cout << "Enter the filename: ";
    std::string filename;
    std::cin >> filename;

    std::cout << "\nOutput for Input file ( " << filename << " ):\n\n";

    auto startTime = std::chrono::high_resolution_clock::now();   // Finding the start time for measuring execution time.
    TwoStrings result = longestAndSecondLongestCompoundedWords(filename);
    auto endTime = std::chrono::high_resolution_clock::now();     // Finding the end time for measuring execution time.

    double processingTime = std::chrono::duration<double>(endTime - startTime).count();     // Calculating the processing time in seconds

    std::cout << "Longest compound word: " << result.first << std::endl;
    std::cout << "Second longest compound word: " << result.second << std::endl;
    std::cout << "Time taken to process the input file: " << std::fixed << std::setprecision(6) << processingTime << " seconds" << std::endl;

    return 0;
}
