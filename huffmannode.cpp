
#include "huffmannode.h"

// Implement all the HuffmanNode methods here

// Creates a Huffman tree node with a given frequency.
HuffmanNode::HuffmanNode(double freq) : frequency(freq) {}

// Cleans up the memory held by the node.  Subclasses must
// override this destructor to provide any extra
// clean up they may require.
HuffmanNode::~HuffmanNode() {}

// Returns the frequency of this Huffman tree node.
double HuffmanNode::get_frequency() const
{
    return frequency;
}

// Returns the string representation of this Huffman
// tree node. (Used when drawing the tree.)
std::string HuffmanNode::to_string() const
{
    return "";
}

// Gets the code associated with the character c.
// Derived classes must override this method.
std::string HuffmanNode::get_code(char c) const 
{ 
    (void) c;
    return "";
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

// This constant string is available to all the methods
const std::string HuffmanNode::NO_MATCH{"NO MATCH"};
