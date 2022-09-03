/*
https://leetcode.com/problems/average-of-levels-in-binary-tree/

Easy

BT- Level order traversel

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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> lvl;
        vector<double> ans;
        
        TreeNode *temp = new TreeNode(INT_MAX);
        
        lvl.push(root);
        lvl.push(temp);
        
        double buff = 0, n = 0;
        
        while(!lvl.empty()){
            
            if(lvl.front() != NULL && lvl.front() == temp){
                lvl.pop();
                
                if(n == 0) break;
                
                ans.push_back(buff / n);
                
                buff = 0; n = 0;
                
                lvl.push(temp);
            }
            else{
                TreeNode *node = lvl.front();
                
                if(node != NULL){
                    buff += node->val;
                    n++;

                    lvl.push(node->left);
                    lvl.push(node->right);
                }
                
                lvl.pop();
            }
            
        }
        
        return ans;
    }
};