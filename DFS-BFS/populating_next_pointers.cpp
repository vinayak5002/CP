/*
https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

Meduim
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        
        queue<Node*> lvl;
                
        lvl.push(root);
        lvl.push(NULL);
        
        Node *frontNode;
        
        while(!lvl.empty()){
            frontNode = lvl.front();
            lvl.pop();

            if(frontNode != NULL){

                if(frontNode->left != NULL) lvl.push(frontNode->left);
                if(frontNode->right != NULL) lvl.push(frontNode->right);

                frontNode->next = lvl.front();
            }
            else{
                if(lvl.empty()) break;
                lvl.push(NULL);
            }
        }
        
        return root;
        
    }
};