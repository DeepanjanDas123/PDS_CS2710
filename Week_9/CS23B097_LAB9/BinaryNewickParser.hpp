#include <iostream>
using namespace std;

// Node structure for a binary tree
struct TreeNode {
    string label;
    TreeNode* left;
    TreeNode* right;

    // Constructor for a tree node
    TreeNode(const string& lbl) : label(lbl), left(nullptr), right(nullptr) {}
};

// Function to parse a Newick format string and build the tree recursively
TreeNode* parseNewick(const string& newick, size_t& pos) {
    if (pos >= newick.length()) return nullptr;

    // If we find an opening parenthesis, it means this is an internal node with children
    if (newick[pos] == '(') {
        pos++;  // Move past '('
        TreeNode* node = new TreeNode("");  // Create an internal node with no label initially

        // Parse left child recursively
        node->left = parseNewick(newick, pos);

        // Skip the comma
        if (newick[pos] == ',') pos++;

        // Parse right child recursively
        node->right = parseNewick(newick, pos);

        // Move past ')'
        if (newick[pos] == ')') pos++;

        // Now there should be a label (number) after the closing parenthesis
        string label;
        while (pos < newick.length() && (isdigit(newick[pos]) || newick[pos] == '-')) {
            label += newick[pos++];
        }
        node->label = label;

        return node;
    } else {
        // If we encounter '-', it means this is a null child
        if (newick[pos] == '-') {
            pos++;  // Move past '-'
            return nullptr;  // No child here
        }

        // Parse leaf node (number)
        string label;
        while (pos < newick.length() && (isdigit(newick[pos]) || newick[pos] == '-')) {
            label += newick[pos++];
        }
        return new TreeNode(label);
    }
}