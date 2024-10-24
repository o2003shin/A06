
#include <string>
#include <iostream>
#include <queue> // For std::priority_queue

#include "huffmantree.h"
#include "leafnode.h"
#include "interiornode.h"
#include "tree_printer.h"

// Implement the methods of the HuffmanTree class here.

// You will use a std::priority_queue to assist the Huffman
// tree construction.

// Constructs a Huffman tree given a map of letters and
// their associated counts.
HuffmanTree::HuffmanTree(const std::map<char, int> &counts) {
    return;
}

// Deallocates the space held by the nodes of the Huffman tree
HuffmanTree::~HuffmanTree() {

}

// Draws a picture of the tree sideways with text using
// the adapted tree_printer.h code.
void HuffmanTree::draw() const {

}

// Returns the Huffman encoded binary string for the given
// character.
std::string get_code(char ch) {
    return "";
}
