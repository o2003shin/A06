
#include "huffmannode.h"

// Implement all the HuffmanNode methods here

// Creates a Huffman tree node with a given frequency.
HuffmanNode::HuffmanNode(double freq) 
    : frequency(freq) {}

// Cleans up the memory held by the node.  Subclasses must
// override this destructor to provide any extra
// clean up they may require.
HuffmanNode::~HuffmanNode() {}

// Returns the frequency of this Huffman tree node.
double HuffmanNode::get_frequency() const
{
    return frequency;
}

// Returns a pointer to the node's left subtree or null if it
// is a leaf.
HuffmanNode* HuffmanNode::get_left() const 
{
    return nullptr;
}

// Returns a pointer to the node's right subtree or null if it
// is a leaf.
HuffmanNode* HuffmanNode::get_right() const
{
    return nullptr;
}

std::string HuffmanNode::to_string() const {
    return "no string";
}

// NO_MATCH constant
const std::string HuffmanNode::NO_MATCH{"NO MATCH"};
