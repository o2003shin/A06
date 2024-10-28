
#include <iostream>
#include "interiornode.h"


// An interior node of a Huffman tree maintains a frequency and
// has pointers to its left and right subtrees.  It inherits its 
// frequency field from its base class.

// Add your code to implement the InteriorNode methods here.

// The constructor
InteriorNode::InteriorNode(double freq, HuffmanNode *lf, HuffmanNode *rt)
    : HuffmanNode(freq), left(lf), right(rt) {}

// Destructor
InteriorNode::~InteriorNode() {
    delete left;
    delete right;
}

// For left subtree
HuffmanNode* InteriorNode::get_left() const {
    return left;
}

// For right subtree
HuffmanNode* InteriorNode::get_right() const {
    return right;
}

// String representation
std::string InteriorNode::to_string() const {
    double sum = left->get_frequency() + right->get_frequency();
    std::string sum_to_string = std::to_string(sum);
    return "(" + sum_to_string + ")";
}


std::string InteriorNode::get_code(char c) const {
    return "no string";
}

