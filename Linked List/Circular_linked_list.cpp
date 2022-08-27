/*
https://www.codingninjas.com/codestudio/problems/circularly-linked_1070232
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    
};

bool isCircular(Node* head){
    // Write your code here.
    if(head == NULL) return true;
    if(head->next == NULL) return false;
    if(head->next == head) return true;
    
    Node *temp = head->next;
    
    while(temp != NULL){
        if(temp->next == head) return true;
        if(temp->data == -1) break;
        temp->data = -1;
        temp = temp->next;
    }
    
    return false;
}
