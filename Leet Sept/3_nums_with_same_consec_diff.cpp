/*
https://leetcode.com/problems/numbers-with-same-consecutive-differences/

Medium

Depth first traversel

*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    
    vector<int> ans;
    
    void search(int n, int k, int num, int i){
        if(i == n-1){
            ans.push_back(num);
            return;
        }
        
        int prev = num % 10;
        
        int new1 = prev+k, new2 = prev-k;
                
        if(new1 >= 0 && new1 <= 9){
            num *= 10; num += new1;
            
            search(n, k, num, i+1);
            
            num /= 10;
        }
        
        if( new1 != new2 && new2 >= 0 && new2 <= 9){
            num *= 10; num += new2;
            
            search(n, k, num, i+1);
            
            num /= 10;
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> pass;
        for(int i=1; i<=9; i++){
            
            search(n, k, i, 0);
            
        }
        
        return ans;
        
    }
};