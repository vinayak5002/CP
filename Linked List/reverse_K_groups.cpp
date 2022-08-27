/****************************************************************
https://www.codingninjas.com/codestudio/problems/reverse-list-in-k-groups_983644?leftPanelTab=0
*****************************************************************/

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node* kReverse(Node* head, int k) {
    if(head == NULL){
        return NULL;
    }
    
    Node *prev = NULL, *next = NULL;
    Node *cur = head;
    
    for(int i=0; i<k; i++){
        if(cur == NULL){
            return prev;
        }
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    
    head->next = kReverse(next, k);
    
    return prev;
}