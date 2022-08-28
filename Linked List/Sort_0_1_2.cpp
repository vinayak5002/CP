/*
https://www.codingninjas.com/codestudio/problems/sort-linked-list-of-0s-1s-2s_1071937?leftPanelTab=1
*/

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

Node* sortList(Node *head)
{
    // Write your code here.
    Node *head0 = NULL, *p0;
    Node *head1 = NULL, *p1;
    Node *head2 = NULL, *p2;
    
    while(head != NULL){
        if(head->data == 0){
            if(head0 == NULL){
                head0 = head;
                p0 = head0;
            }
            else{
                p0->next = head;
                p0 = p0->next;
            }
            head = head->next;
            p0->next = NULL;
        }
        else if(head->data == 1){
            if(head1 == NULL){
                head1 = head;
                p1 = head1;
            }
            else{
                p1->next = head;
                p1 = p1->next;
            }
            head = head->next;
            p1->next = NULL;
        }
        else{
            if(head2 == NULL){
                head2 = head;
                p2 = head2;
            }
            else{
                p2->next = head;
                p2 = p2->next;
            }
            head = head->next;
            p2->next = NULL;
        }
    }
    Node *ret = NULL, *retEnd = NULL;

    
    if(head0 != NULL){
        ret = head0;
        retEnd = p0;
    }
    
    if(head1 != NULL){
        if(head0 == NULL){
            ret = head1;
            retEnd = p1;
        }
        else{
            retEnd->next = head1;
            retEnd = p1;
        }
    }
    
    if(head2 != NULL){
        if(ret == NULL){
            ret = head2;
            retEnd = p2;
        }
        else{
            retEnd->next = head2;
            retEnd = p2;
        }
    }
    return ret;
}

void insertAtTail(Node* &tail, Node* curr ) {
    tail -> next = curr;
    tail = curr;
}


Node* sortList(Node *head)
{
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* curr = head;
    
    // create separate list 0s, 1s and 2s
    while(curr != NULL) {
        
        int value = curr -> data;
        
        if(value == 0) {
            insertAtTail(zeroTail, curr);
        }
        else if(value == 1) {
            insertAtTail(oneTail, curr);
        }
        else if(value == 2) {
            insertAtTail(twoTail, curr);
        }       
        curr = curr -> next;
    }
    
    //merge 3 sublist
    
    // 1s list not empty
    if(oneHead -> next != NULL) {
        zeroTail -> next = oneHead -> next;
    }
    else {
        //1s list -> empty
        zeroTail -> next = twoHead -> next;
    }
    
    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;
    
    //setup head 
    head = zeroHead -> next;
    
    //delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
}

int main()
{
    cout<<"YES"<<endl;
    Node *head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    // head->next->next->next->next->next = new Node(3);

    head = sortList(head);

    if(head == NULL) cout<<"FUCK\n";

    Node *temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    return 0;

}