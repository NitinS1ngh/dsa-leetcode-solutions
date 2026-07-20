class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m, vector<int>(n));

        k %= (m * n); 

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {

                int newCol = (col + k) % n;
                int newRow = (row + (col + k) / n) % m;

                ans[newRow][newCol] = grid[row][col];
            }
        }

        return ans;
    }
};