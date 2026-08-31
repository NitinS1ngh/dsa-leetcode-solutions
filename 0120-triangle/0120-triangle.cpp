
class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, int n, vector<vector<int>>& triangle) {
        if (i == n-1) return triangle[i][j];
        if(dp[i][j] != INT_MAX) return dp[i][j];

        int down = solve(i+1, j, n, triangle);
        int diag = solve(i+1, j+1, n, triangle);

        return  dp[i][j] =triangle[i][j] + min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        dp.assign(n, vector<int>(n, INT_MAX));
        return solve(0, 0, n, triangle);
    }
};