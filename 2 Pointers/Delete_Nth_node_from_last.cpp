/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/
*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next) return NULL;
        if(!head) return NULL;
        
        ListNode *p1 = head, *p2 = head;
        int c = n;
        
        while(c--){
            p2 = p2->next;
        }
        
        if(p2 == NULL) return head->next;
        
        while(p2->next != NULL){
            p1 = p1->next;
            p2 = p2->next;
        }
        
        p1->next = p1->next->next;
        
        return head;
    }
};