#include<bits/stdc++.h>
#include<Node.h>
using namespace std;

/*  Sorted List:
https://www.codingninjas.com/codestudio/problems/unique-sorted-list_2420283?leftPanelTab=0
*/

Node * uniqueSortedList(Node * head) {
    // Write your code here.
    Node *cur = head;
    
    while(cur != NULL){
        Node *p = cur;
        
        while(p->next != NULL && p->next->data == cur->data){
            p = p->next;
        }
        
        cur->next = p->next;
        cur = cur->next;
    }
    
    return head;
}

/* Unsorted List:
https://www.codingninjas.com/codestudio/problems/remove-duplicates-from-unsorted-linked-list_1069331
*/

// O(n^2)
Node *removeDuplicatesM1(Node *head)
{
    // Write your code here
    Node *cur = head;
    
    while(cur != NULL){
        Node *p = cur;
        
        while(p->next != NULL){
            if(p->next->data == cur->data){
                p->next = p->next->next;
            }
            else{
                if(p->next != NULL) p = p->next;   
            }
        }
        cur = cur->next;
    }
    
    return head;
}

// O(n)
Node *removeDuplicates(Node *head)
{
    // Write your code here
    Node *cur = head;
    unordered_map<int, bool> visited;
    visited[head->data] = true;
    
    while(cur->next != NULL){
        if(visited[cur->next->data]){
            cur->next = cur->next->next;
        }
        else{
            visited[cur->next->data] = true;
            cur = cur->next;
        }
    }
    
    return head;
}


int main()
{
    Node *head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(3);

    head = removeDuplicates(head);

    Node *temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
    }

    return 0;

}