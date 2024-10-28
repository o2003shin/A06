#include "leafnode.h"

// Add your code to implement the LeafNode methods here.

// Constructor
LeafNode::LeafNode(char ch, double freq) 
    : character(ch), HuffmanNode(freq) {}


// Returns a displayable string representing the leaf node when
// drawing the Huffman tree.
std::string LeafNode::to_string() const {
    return "[" + std::string(1, character) + ":"  + std::to_string(get_frequency()) + "]";
}   

// If the c parameter matches this node's character field, it
// represents a successful match.  This means the parent node
// can prepend a 0 or 1 depending on whether this node is its 
// left or right child.
// If c does not match this node's character field, the method
// returns "NO MATCH".  This means the parent node will propogate
// up the recursive call chain this non-match value so that the
// interior node logic can try the other branch.
std::string LeafNode::get_code(char c) const {
    if (c == character) {
        return "";
    } else {
        return NO_MATCH;
    }
}
