/*
https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        // Finding middle elemnt:
        
        Node *p1 = head, *p2 = head;
        
        while(p2 != NULL && p2->next != NULL){
            p1 = p1->next;
            p2 = p2->next->next;
        }
        
        // middle = p1;
        
        Node *prev = NULL, *next = NULL;
        Node *cur = p1;
        
        while(cur != NULL){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        // head of reverse -> prev;
        Node *temp = head;
        
        while(prev != NULL){
            if(prev->data != head->data) return false;
            
            prev = prev->next;
            head = head->next;
        }
        
        return true;
        
    }
};