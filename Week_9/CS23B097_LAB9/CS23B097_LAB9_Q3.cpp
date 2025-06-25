#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)

// Node structure for a binary tree
struct TreeNode {
    string label;
    vector<TreeNode*> ch;

    // Constructor for a tree node
    TreeNode(const string& lbl) : label(lbl) {}
};

// Function to parse a Newick format string and build the tree recursively
TreeNode* parseNewick(const string& newick, size_t& pos) {
    if (pos >= newick.length()) return nullptr;

    // If we find an opening parenthesis, it means this is an internal node with children
    if (newick[pos] == '(') {
        pos++;  // Move past '('
        TreeNode* node = new TreeNode("");  // Create an internal node with no label initially

        while(pos < newick.length() && newick[pos]!=')'){
            if(newick[pos]==',') {pos++;continue;}
            node->ch.push_back(parseNewick(newick,pos));
            //pos++;
        }

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

signed main(){
    string newick; cin>>newick;
    size_t pos = 0;
    TreeNode *root = parseNewick(newick,pos);
    
}