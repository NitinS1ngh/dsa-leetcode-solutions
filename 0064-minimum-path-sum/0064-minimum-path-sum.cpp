class Solution {
public:
    int dp[220][220];
    int n = 0, m = 0;

    int solve(int i, int j, vector<vector<int>>& grid) {
        if (i == n-1 && j==m-1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        int down = INT_MAX;
        if(i+1 < n) down = grid[i][j] + solve(i+1, j, grid);

        int right = INT_MAX;
        if(j+1 < m) right = grid[i][j] + solve(i, j+1, grid);
         
        return  dp[i][j] = min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0, 0, grid);
    }
};