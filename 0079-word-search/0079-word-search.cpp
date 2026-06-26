class Solution {
public:
    int row, col;
    string word;
    vector<vector<char>> board;

    bool exist(vector<vector<char>>& b, string w) {
        board = b;
        word = w;
        row = board.size();
        col = board[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (dfs(i, j, 0)) return true;
            }
        }
        return false;
    }

    bool dfs(int i, int j, int index) {
        if (index == word.size()) return true;
        if (i < 0 || i >= row || j < 0 || j >= col) return false;
        if (board[i][j] != word[index]) return false;

        char temp = board[i][j];
        board[i][j] = '#'; // mark visited

        // explore in 4 directions using normal loops
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (dfs(ni, nj, index + 1)) {
                board[i][j] = temp; // restore before returning
                return true;
            }
        }

        board[i][j] = temp; // restore
        return false;
    }
}; 