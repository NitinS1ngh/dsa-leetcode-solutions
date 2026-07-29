class Solution {
public:
    int row, col;
    bool valid(int i, int j){
        return i>=0 && i<row && j>=0 && j<col;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        row = mat.size();
        col = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dis(row, vector<int>(col, -1));

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    dis[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            int newrow[4] = {-1,1,0,0};
            int newcol[4] = {0,0,-1,1};

            for(int k=0; k<4; k++){
                if(valid(i+newrow[k], j+newcol[k]) && dis[i+newrow[k]][j+newcol[k]] == -1){
                    dis[i+newrow[k]][j+newcol[k]] = dis[i][j] + 1;
                    q.push({i+newrow[k], j+newcol[k]});
                }
            }
        }

        return dis;
    }
};