#include <iostream>
#include <map>
#include <cctype>
#include <string>
#include <queue>
#include "huffmantree.h"

//  Name: Oswin Shin
//  Assignment number: 6
//  Assignment: Huffman Encoding Tree
//  File name: main.cpp
//  Date last modified: October 25, 2024
//  Honor statement: I have neither given nor received any unauthorized help on this assignment. 

// Add any helper functions as needed
void count_letters(std::map<char, int>& frequency) {
    char ch;
    while(std::cin.get(ch)) {
        if (((int)ch >= 65 && (int)ch <= 90) || ((int)ch >= 97 && (int)ch <= 122)) {
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
    std::cout << "Total = " << tot << std::endl << "---------------------------------" << std::endl;
}

void draw_tree(HuffmanTree* tree) {
    std::cout << std::endl << std::endl;
    tree->draw();
    std::cout << "---------------------------------" << std::endl;
}

int main() {
    // 1. Get the text and count all the letters in the text
    //    (place in a std::map object).
    std::map<char, int> frequency;
    count_letters(frequency);
    std::cout << std::endl;
    std::cout << std::endl << "Counts:" << std::endl << "-------" << std::endl;

    // 2. Display the number of occurrences of each letter.
    display_frequency(frequency);

    // 3. Build the Huffman tree from the std::map of letters
    //    with their associated counts.
    HuffmanTree* tree = new HuffmanTree(frequency);
    
    // 4. Draw the Huffman tree.
    draw_tree(tree);

    // 5. Print the Huffman codes for each letter.
    std::map<char, std::string> huffman_codes; // Holds char: huffman code
    for (const auto& pair : frequency) {
        char ch = pair.first;
        std::string code = tree->get_code(ch);
        huffman_codes[ch] = code;
    }
    for (const auto& pair : huffman_codes) {
        std::cout << pair.first << ": " << pair.second << std::endl; 
    }
    std::cout << std::endl;
    // 6. Print the number of bits required for a fixed-width
    //    encoding of the file (5 bits per letter for 26 letters).
    int totalChars = 0;
    for (const auto& pair : frequency) {
        totalChars += pair.second;
    }
    int fixed_width_bits = 5 * totalChars;
    std::cout << "   Fixed Encoding: " << fixed_width_bits << " bits" << std::endl;

    // 7. Print the number of bits required for a Huffman
    //    encoding of the file.
    size_t huffman_encoding_bits = 0;
    for (const auto& pair : huffman_codes) {
        std::string code = pair.second;
        int char_frequency = frequency[pair.first]; // Mapping to the character's frequency
        huffman_encoding_bits += static_cast<int>(char_frequency) * code.length();
    }
    std::cout << " Huffman Encoding: " << huffman_encoding_bits << " bits" << std::endl;
}

