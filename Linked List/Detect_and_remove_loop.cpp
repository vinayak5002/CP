/*
https://www.youtube.com/watch?v=7pgs-wT5d4c
*/

#include<bits/stdc++.h>
using namespace std;

    
class Node {
    public :

    int data;
    Node *next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

Node *detectCycle(Node *head){
    if(head == NULL) return NULL;
    
    Node *slow = head, *fast = head;
    
    while(slow != NULL && fast != NULL){
        slow = slow->next;
        
        if(fast->next != NULL) fast = fast->next->next;
        else break;
        
        if(slow == fast) return slow;
    }
    
    return NULL;
}

Node* getStartingNode(Node *head, Node *intersection){
    Node *slow = head;
    
    while(intersection != slow){
        slow = slow->next;
        intersection = intersection->next;
    }
    
    return slow;
}

Node *removeLoop(Node *head)
{
    if( head == NULL)
        return NULL;
    
    Node *intersection = detectCycle(head);
    if(intersection == NULL) return head;

    Node* startOfLoop = getStartingNode(head, intersection);
    
    if(startOfLoop == NULL)
        return head;
    
    Node* temp = startOfLoop;

    while(temp -> next != startOfLoop) {
        temp = temp -> next;
    } 

    temp -> next = NULL;
    return head;
}