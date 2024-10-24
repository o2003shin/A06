#include "leafnode.h"

// Add your code to implement the LeafNode methods here.

// Constructor
LeafNode::LeafNode(char ch, double freq) 
    : character(ch), HuffmanNode(freq) {}


// Returns a displayable string representing the leaf node when
// drawing the Huffman tree.
std::string LeafNode::to_string() const {

    return "no string";
}   