/*
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0, j = numbers.size()-1;
        int sum;
        
        while(i<j){
            sum = numbers[i] + numbers[j];
            
            if(sum == target){
                return {i+1, j+1};
            }
            else if(sum > target){
                j--;
            }
            else{
                i++;
            }
        }
        
        return {1, 2};
    }
};

int main(){

}