#pragma once

#include <string>


// The base class for all nodes in the Huffman tree.
// This is an abstract class, as derived concrete classes 
// must override the print_codes, get_code methods.
// Subclasses represent leaf nodes and interior nodes.
class HuffmanNode {
    double frequency;
protected:
    // "Letter not found" constant shared by all Huffman node objects
    static const std::string NO_MATCH;

public:
    // Creates a Huffman tree node with a given frequency.
    HuffmanNode(double freq);

    // Cleans up the memory held by the node.  Subclasses must
    // override this destructor to provide any extra
    // clean up they may require.
    virtual ~HuffmanNode();

    // Returns the frequency of this Huffman tree node.
    double get_frequency() const;

    // Returns the string representation of this Huffman
    // tree node. (Used when drawing the tree.)
    virtual std::string to_string() const;

    // Gets the code associated with the character c.
    // Derived classes must override this method.
    virtual std::string get_code(char c) const = 0;

    // Returns a pointer to the node's left subtree or null if it
    // is a leaf.
    virtual HuffmanNode *get_left() const;
    
    // Returns a pointer to the node's right subtree or null if it
    // is a leaf.
    virtual HuffmanNode *get_right() const;
};

