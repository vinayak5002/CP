/*
https://www.codingninjas.com/codestudio/problems/merge-two-sorted-linked-lists_800332?leftPanelTab=0
*/

#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Node {
    public:
    T data;
    Node* next;

    Node(T data) {
        next = NULL;
        this->data = data;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    Node<int> *temp = new Node<int>(-1);
    temp->next = first;
    
    Node<int> *ret = temp;
    
    while(second != NULL){
        while(temp->next != NULL && temp->next->data <= second->data){
            temp = temp->next;
        }
        
        // inserting
        Node<int> *p = second->next;
        
        second->next = temp->next;
        temp->next = second;
        
        second = p;
    }
    
    return ret->next;
}