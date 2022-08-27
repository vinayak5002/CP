/*
https://leetcode.com/problems/move-zeroes/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        
        int i=0;

        for(int j=0; j<n; j++){

            if(nums[j] != 0){
                swap(nums[j], nums[i]);
                i++;
            }

        }
    }
};

int main(){
    vector<int> vec;

    vec.push_back(1);
    vec.push_back(0);
    vec.push_back(1);
    // vec.push_back(0);
    // vec.push_back(3);
    // vec.push_back(12);

    // moveZeroes(vec);

    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
}