/*
https://leetcode.com/problems/sort-colors/submissions/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0, j=0;
        int n = nums.size();
        
        for(; j<n; j++){
            while(j<n && nums[j] != 0){
                j++;
            }
            
            if(j>=n) break;
            
            swap(nums[i], nums[j]);
            i++;
        }
        
        for(j=i; j<n; j++){
            while(j<n && nums[j] != 1){
                j++;
            }
            
            if(j>=n) break;
            
            swap(nums[i], nums[j]);
            i++;
        }
        
    }
};