// You are given a 0-indexed integer matrix grid and an integer k.
// Return the number of submatrices that contain the top-left element of the grid, and have a sum less than or equal to k.

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        if(grid[0][0]>k) return 0;

        int l = grid[0].size();
        int b = grid.size();
        
        int count = 0;
        for(int i=0;i<b;i++)
        {
            for(int j=0;j<l;j++)
            {
                if(i==0 & j>0)
                grid[i][j] += grid[i][j-1];
                else if(j==0 & i>0)
                grid[i][j] += grid[i-1][j];
                else if(i>0 && j>0)
                grid[i][j] += grid[i][j-1]+grid[i-1][j]-grid[i-1][j-1];
                if(grid[i][j]<=k)
                count++;
            }
        }
        return count;
    }
};
