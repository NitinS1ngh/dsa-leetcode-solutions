class Solution {
public:
    vector<vector<vector<int>>> dp;
    int m, n;

    int solve(vector<vector<int>>& grid, int i, int j1, int j2) {

        if (i == m - 1) {
            if (j1 == j2) return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }

        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int cherries = grid[i][j1];
        if (j1 != j2) cherries += grid[i][j2];

        int maxi = 0;

        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {

                int newJ1 = j1 + d1;
                int newJ2 = j2 + d2;

                if (newJ1 >= 0 && newJ1 < n && newJ2 >= 0 && newJ2 < n) {
                    maxi = max(maxi, solve(grid, i + 1, newJ1, newJ2));
                }
            }
        }
        return dp[i][j1][j2] = cherries + maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<vector<int>>(n,vector<int>(n, -1)));
        return solve(grid, 0, 0, n - 1);
    }
};