#include <iostream>
#include <map>
#include <cctype>
#include <string>
#include <queue>
#include "huffmantree.h"

// Add any helper functions as needed
void count_letters(std::map<char, int>& frequency) {
    char ch;
    while(std::cin.get(ch)) {
        if (isalpha(ch)) {
            ch = static_cast<char>(toupper(ch));
            std::cout << ch;
            frequency[ch]++;
        }
    }
}

void display_frequency(std::map<char, int>& frequency) {
    int tot = 0;
    for (const auto pair : frequency) {
        std::cout << pair.first << ": " << pair.second << std::endl;
        tot += pair.second;
    }
    std::cout << "Total = " << tot << std::endl << "---------------------";
}

int main() {
    // 1. Get the text and count all the letters in the text
    //    (place in a std::map object).
    std::map<char, int> frequency;
    count_letters(frequency);
    std::cout << std::endl;
    std::cout << std::endl << "Counts:" << std::endl << "------" << std::endl;
    // 2. Display the number of occurrences of each letter.
    display_frequency(frequency);
    // 3. Build the Huffman tree from the std::map of letters
    //    with their associated counts.
    
    // 4. Draw the Huffman tree.

    // 5. Print the Huffman codes for each letter.

    // 6. Print the number of bits required for a fixed-width
    //    encoding of the file (5 bits per letter for 26 letters).

    // 7. Print the number of bits required for a Huffman
    //    encoding of the file.
}

