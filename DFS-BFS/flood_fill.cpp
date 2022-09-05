/*
https://leetcode.com/problems/flood-fill/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int m, n;
    
    bool check(int i, int j){
        return i>=0 && i<m && j>=0 && j<n;
    }
    
    void fill( vector<vector<int>> &mat, int i, int j, int color, int f ){
        
        if(!check(i, j)) return;
        if(mat[i][j] != f) return;
        if(mat[i][j] == color) return;
        
        mat[i][j] = color;
        
        int ni = i-1, pi = i+1, nj = j-1, pj = j+1;
        
        fill(mat, ni, j, color, f);
        fill(mat, pi, j, color, f);
        fill(mat, i, nj, color, f);
        fill(mat, i, pj, color, f);
        
        return;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        
        fill(image, sr, sc, color, image[sr][sc]);
        
        return image;
    }
};