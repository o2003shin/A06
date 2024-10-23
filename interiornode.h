#pragma once

#include <string>

#include "huffmannode.h"


// An interior node of a Huffman tree maintains a frequency and
// has pointers to its left and right subtrees.  It inherits its 
// frequency field from its base class.
class InteriorNode: public HuffmanNode {
    HuffmanNode *left;     // Pointer to its left subtree
    HuffmanNode *right;    // Pointer to its right subtree
    // Note: The bottom-up tree building process ensures that 
    // these pointers never should be null.

public:
    // When creating an interior node it constructor needs the
    // node's frequency (freq) and pointers to its left and 
    // right subtrees (lf and rt).
    InteriorNode(double freq, HuffmanNode *lf, HuffmanNode *rt);

    // Properly deallocates the nodes in the subtrees attached to 
    // this node.
    ~InteriorNode();

    // All interior nodes have a left subtree
    HuffmanNode *get_left() const override;

    // All interior nodes have a right subtree
    HuffmanNode *get_right() const override;

    // Returns a printable representation of this node.
    std::string to_string() const override;

    // Returns the suffix of the code for the letter located
    // in the subtree rooted at this interior node.  Returns
    // NO_MATCH if the letter is not found in this subtree.
    std::string get_code(char c) const override;
};
