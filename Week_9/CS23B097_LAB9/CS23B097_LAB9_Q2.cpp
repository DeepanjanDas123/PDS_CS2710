#include "BinaryNewickParser.hpp"
#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)

int max_path = -1;

int height(TreeNode*root){
    if(root==NULL) return 0;
    int maxl = height(root->left);
    int maxr = height(root->right);
    int h = max(maxl,maxr)+1;
    return h;
}
void diameter(TreeNode*root){
    if(root==NULL) return;
    diameter(root->left);
    diameter(root->right);
    int d = height(root->left) + height(root->right);
    max_path = max(max_path,d);
}
signed main(){
    string newick; cin>>newick;
    size_t pos = 0;
    TreeNode *root = parseNewick(newick,pos);
    if(root==NULL){cout<<0<<endl; return 0;}
    diameter(root);
    cout<<max_path<<endl;
}