/*
https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

Hard

Hash-table | DFS | BFS | Tree

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
    map<int, map<int, vector<int>>> colMap;
    
    void trav(TreeNode *root, int row, int col){
        if(root == NULL) return;
        
        colMap[col][row].push_back(root->val);
        
        trav(root->left, row+1, col-1);
        trav(root->right, row+1, col+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {        
        trav(root, 0, 0);
        
        vector<vector<int>> ans;
        
        for (auto& [col, rowMap] : colMap) {
            
            vector<int> temp;
            
            for(auto& [row, vect] : rowMap){
                sort(vect.begin(), vect.end());
                
                for(auto& i : vect){
                    temp.push_back(i);
                }
                
            }
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};