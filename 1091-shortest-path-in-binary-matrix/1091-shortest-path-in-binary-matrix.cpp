class Solution {
public:
    int row,col;
    bool valid(int i, int j){
        return i>=0 && i<row && j>=0 && j<col;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();

        if(grid[0][0] || grid[row-1][col-1]) return -1;
        if(row==1 && col==1) return 1;
        
        vector<vector<int>> visted(row, vector<int>(col, 0));
        queue<pair<pair<int,int>, int>> q;
        q.push({{0,0},1});
        visted[0][0] = 1;

        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            int dr[8] = {0,-1,-1,-1,0,1,1,1};
            int dc[8] = {-1,-1,0,1,1,1,0,-1};

            for(int k=0; k<8; k++){
                int nr = i + dr[k];
                int nc = j + dc[k];

                if(valid(nr,nc) && !visted[nr][nc] && grid[nr][nc] == 0){
                    if(nr==row-1 && nc==col-1) return dist+1;
                    visted[nr][nc] = 1;
                    q.push({{nr,nc},dist+1});
                }
            }
        }

        return -1;
    }
};