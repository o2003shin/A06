#pragma once

#include "huffmannode.h"


// A leaf in a Huffman tree.  It holds a character and
// its frequency.  It inherits its frequency field from its
// base class.
class LeafNode: public HuffmanNode {
    char character;

public:
    // Initialization code for a new CharNode object.
    LeafNode(char ch, double freq);

    // Returns a displayable string representing the leaf node when
    // drawing the Huffman tree.
    std::string to_string() const override;

    // If the c parameter matches this node's character field, it
    // represents a successful match.  This means the parent node
    // can prepend a 0 or 1 depending on whether this node is its 
    // left or right child.
    // If c does not match this node's character field, the method
    // returns "NO MATCH".  This means the parent node will propogate
    // up the recursive call chain this non-match value so that the
    // interior node logic can try the other branch.
    std::string get_code(char c) const override;
};

