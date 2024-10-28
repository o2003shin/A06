
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



// Used some code from: 
// https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/
// https://www.geeksforgeeks.org/custom-comparator-in-priority_queue-in-cpp-stl/

// Custom comparator object
class Compare {
    public:
        bool operator() (HuffmanNode* left, HuffmanNode* right) const {
            return left->get_frequency() > right->get_frequency();
        }
};

// Constructs a Huffman tree given a map of letters and
// their associated counts.
HuffmanTree::HuffmanTree(const std::map<char, int> &counts) {
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, Compare> queue; // Compare is the custom comparator object
    double total = 0.0; // Total to calculate percentage in decimal form (freq / total = 0.xxxx)
    for (const auto& pair : counts) {
        total += pair.second;
    }

    for (const auto& pair : counts) {
        // Pushing the LeafNode that contains the char and frequency into the queue.
        double subTotal = pair.second / total; // Percentage of frequency 
        queue.push(new LeafNode(pair.first, subTotal)); // char : frequency -- e.g. 'A': 0.00166. Frequency represented as a percentage of whole 
    }
    while (queue.size() > 1) {
        // This is taking the 2 lowest value nodes and combining them together, and adding them to the queue.
        HuffmanNode* left = queue.top(); // The node with lowest value is on the 'top'. 
        queue.pop(); // Pop the top to update the queue
        HuffmanNode* right = queue.top(); // The new 'top' is the right sub tree.
        queue.pop();
        // Now merging these nodes together into an interior node
        queue.push(new InteriorNode(left->get_frequency() + right->get_frequency(), left, right)); // Adding the two lowest value nodes and inserting into the queue based on their value
    }
    // After all the interior and leaf nodes are placed, the very top of the tree (queue) should have the root node.
    root = queue.top();
}

// Deallocates the space held by the nodes of the Huffman tree
HuffmanTree::~HuffmanTree() {
    delete root;
}

// Draws a picture of the tree sideways with text using
// the adapted tree_printer.h code.
void HuffmanTree::draw() const {
    print_tree(root);
}

// Returns the Huffman encoded binary string for the given
// character.
std::string HuffmanTree::get_code(char ch) const {
    return root->get_code(ch); // returns the code
}
