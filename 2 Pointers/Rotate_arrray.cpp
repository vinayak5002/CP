/*
https://leetcode.com/problems/rotate-array/
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ans(nums);
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            ans[(i+k)%n] = nums[i];
        }
        
        nums = ans;
    }
};
