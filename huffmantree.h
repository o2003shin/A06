#pragma once

#include <map>

#include "huffmannode.h"

class HuffmanTree {
    // Root of the Huffman tree
    HuffmanNode *root;

public:
    // Constructs a Huffman tree given a map of letters and
    // their associated counts.
    HuffmanTree(const std::map<char, int>& counts);

    // Deallocates the space held by the nodes of the Huffman tree
    ~HuffmanTree();

    // Disallow copying and assignment
    HuffmanTree(const HuffmanTree&) = delete;
    HuffmanTree(HuffmanTree&&) = delete;
    HuffmanTree& operator=(const HuffmanTree&) = delete;
    HuffmanTree& operator=(HuffmanTree&&) = delete;
    
    // Draws a picture of the tree sideways with text using 
    // the adapted tree_printer.h code.
    void draw() const;

    // Returns the Huffman encoded binary string for the given 
    // character.
    std::string get_code(char ch) const;
};

