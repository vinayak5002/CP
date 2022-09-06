/*
https://leetcode.com/problems/binary-tree-pruning/

Medium
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    
    int prune(TreeNode *root){
        if(root == NULL) return 0;
        
        int l = prune(root->left);
        int r = prune(root->right);
        
        if(l == 0) root->left = NULL;
        if(r == 0) root->right = NULL;
        
        return l+r+root->val;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        int dump = prune(root);
        
        if(root->val == 0 && root->left == NULL && root->right == NULL) return NULL;
        
        return root;
    }
};