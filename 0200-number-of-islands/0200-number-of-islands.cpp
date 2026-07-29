class Solution {
public:
    int row,col;
    bool valid(int i, int j){
        return (i>=0 && i<row) && (j>=0 && j<col);
    }

    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int islands = 0;

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {

                if(grid[i][j] == '1') {
                    islands++;
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    grid[i][j] = '0';  

                    while(!q.empty()) {

                        int x = q.front().first;
                        int y = q.front().second;

                        q.pop();

                        int row[4] = {0, 0, 1, -1};
                        int col[4] = {1, -1, 0, 0};

                        for(int k=0; k<4; k++) {

                            if(valid(x+row[k],y+col[k]) && grid[x+row[k]][y+col[k]] == '1') {
                                grid[x+row[k]][y+col[k]] = '0';
                                q.push({x+row[k], y+col[k]});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};