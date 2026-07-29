class Solution {
public:
    int row, col;
    bool valid(int i, int j){
        return i>=0&&i<row && j>=0&&j<col;
    }
    void solve(vector<vector<char>>& board) {
        row = board.size(), col = board[0].size();
        queue<pair<int,int>> q;

        for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
        if((i==0 || j==0 || i==row-1 || j==col-1) && board[i][j] == 'O')
        q.push({i,j}), board[i][j] = 'Y';

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            int row[4] = {1,-1,0,0};
            int col[4] = {0,0,1,-1};

            for(int k=0; k<4; k++){
                if(valid(i+row[k],j+col[k]) && board[i+row[k]][j+col[k]] == 'O'){
                    q.push({i+row[k],j+col[k]});
                    board[i+row[k]][j+col[k]] = 'Y';
                }
            }
        }

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j]=='O'){
                    board[i][j] = 'X';
                }
                if(board[i][j]=='Y'){
                    board[i][j] = 'O';
                }
            }
        }

    }
};