/*
https://leetcode.com/problems/number-of-islands/

Medium
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    int m, n;
    
    bool check(int i, int j){
        return i>=0 && i<m && j>=0 && j<n;
    }
    
    void dfs(vector<vector<char>> &grid, int i, int j){
        if(!check(i, j)) return ;
        if(grid[i][j] != '1') return ;
        
        grid[i][j] = '0';
        
        int ni = i-1, pi = i+1, nj = j-1, pj = j+1;
        
        dfs(grid, ni, j);
        dfs(grid, pi, j);
        dfs(grid, i, nj);
        dfs(grid, i, pj);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(); n = grid[0].size();
        int num = 0;
        
        for(int i=0; i<grid.size(); i++){
            
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    num++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return num;
    }
};