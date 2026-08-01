class Solution {
public:
    int row, col;
    bool valid(int i, int j){
        return i>=0 && i<row && j>=0 && j<col;
    }
    void dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<int>>& heights){
        visited[i][j] = 1;

        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,-1,1};

        for(int k=0; k<4; k++){
            int nr = i + dr[k];
            int nc = j + dc[k];

            if(valid(nr,nc) && !visited[nr][nc] && heights[nr][nc] >= heights[i][j]){
                dfs(nr,nc,visited,heights);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        row = heights.size();
        col = heights[0].size();

        vector<vector<bool>> pvisited(row, vector<bool>(col, 0));
        vector<vector<bool>> avisited(row, vector<bool>(col, 0));

        for(int i=0; i<row; i++){
            dfs(i,0,pvisited,heights);
            dfs(i,col-1,avisited,heights);
        }

        for(int i=0; i<col; i++){
            dfs(0,i,pvisited,heights);
            dfs(row-1,i,avisited,heights);
        }

        vector<vector<int>> ans;

        for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
        if(pvisited[i][j] && avisited[i][j]) ans.push_back({i,j});

        return ans;
    }
};