/*
https://leetcode.com/problems/max-area-of-island/submissions/

Medium
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea = 0;
    int m, n;
    
    bool check(int i, int j){
        return i>=0 && i<m && j>=0 && j<n;
    }
    
    int dfs(vector<vector<int>> &grid, int i, int j){
        if(!check(i, j)) return 0;
        if(grid[i][j] != 1) return 0;
        
        grid[i][j] = 2;
        
        int ni = i-1, pi = i+1, nj = j-1, pj = j+1;
        
        int l = dfs(grid, ni, j);
        int r = dfs(grid, pi, j);
        int b = dfs(grid, i, nj);
        int t = dfs(grid, i, pj);
        
        return l+r+t+b+1;
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        int area;
        
        for(int i=0; i<grid.size(); i++){
            
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    area = dfs(grid, i, j);
                
                    maxArea = max(area, maxArea);
                }
            }
            
        }
        
        return maxArea;
    }
};