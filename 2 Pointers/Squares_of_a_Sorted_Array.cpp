/*
https://leetcode.com/problems/squares-of-a-sorted-array/
*/

#include<bits/stdc++.h>
using namespace std;

// Method: Sorted insert into a vector
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int sq;
        
        for(int i=0; i<nums.size(); i++){
            sq = pow(nums[i], 2);
            
            if(ans.empty()){
                ans.push_back(sq);
            }
            else{
                vector<int>::iterator i = ans.begin();
                while( i < ans.end() && sq > *i){
                    i++;
                }
                ans.insert(i, sq);
            }
        }
        
        return ans;
    }
};

int main(){
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(6);

    vector<int>::iterator i = vec.begin();
    while(4 > *i && i <= vec.end()){
        i++;
    }

    vec.insert(i, 4);

    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
}
