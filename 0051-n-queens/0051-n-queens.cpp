class Solution {
public:
    bool check(int n, vector<string>& board, int i, int j){

        //check upper left no queen should be present
        int row = i, col = j;
        while(row>-1&&col>-1){
            if(board[row][col]=='Q'){
                return 0;
            }
            row--, col--;
        }
        //check upper right 
        row = i, col = j;
        while(row>-1&&col<n){
            if(board[row][col]=='Q'){
                return 0;
            }
            row--, col++;
        }
        return 1;
    }
    void find(int row, int n, vector<vector<string>>& ans, vector<string>& board, vector<bool>& column){
        // base case
        if(row==n){
            ans.push_back(board);
            return;
        }
        //put queens at any n positions in row
        for(int j=0; j<n; j++){
            if(column[j]==0&&check(n,board,row,j)){
                column[j] = 1;
                board[row][j] = 'Q';
                find(row+1,n,ans,board,column);
                column[j] = 0;
                board[row][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<bool> column(n,0);
        find(0,n,ans,board,column);
        return ans;
    }
};