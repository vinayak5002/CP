/*
https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* reverseLL(Node *head){
    Node *prev = NULL, *next = NULL;
    Node *cur = head;
    
    while(cur != NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    
    return prev;
}

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    // code here
    first = reverseLL(first);
    second = reverseLL(second);

    int c = 0, sum;
    
    Node *head = new Node(0);
    Node *p = head;
    
    while(first != NULL || second != NULL){
        sum = 0;
        
        if(first != NULL) sum += first->data;
        if(second != NULL) sum += second->data;
        
        sum += c;
        
        if( sum>=10 ){ c = 1; sum = sum %10; }
        else{ c = 0; }
        
        p->data = sum;
        p->next = new Node(0);
        p = p->next;
        
        if(first != NULL) first = first->next;
        if(second != NULL) second = second->next;
    }
    
    head = reverseLL(head);
    head->data += c;
    
    if(head->data == 0) return head->next;
    else return head;
}