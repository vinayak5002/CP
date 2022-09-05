/*
https://leetcode.com/problems/n-ary-tree-level-order-traversal/

Medium

Tree lvl order traversels
*/

#include<bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;    

        queue<Node*> trav;
        Node *dummy = new Node(0);

        trav.push(root);
        trav.push(dummy);
                
        vector<int> temp;
        
        while(!trav.empty()){
            Node *frontNode = trav.front();
            
            if(frontNode != dummy && frontNode != NULL){
                temp.push_back(frontNode->val);
                
                for(auto &i : frontNode->children){
                    trav.push(i);
                }
                
                trav.pop();
            }
            else{
                if(!temp.empty()) ans.push_back(temp);
                else break;
                
                temp.clear();
                
                trav.pop();
                trav.push(dummy);
            }

        }
        
        return ans;
        
    }
};