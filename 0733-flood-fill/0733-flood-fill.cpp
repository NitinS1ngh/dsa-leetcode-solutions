class Solution {
public:
    int row;
    int col;
    bool valid(int i, int j){
        return i>=0&&i<row && j>=0&&j<col;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        row = image.size();
        col = image[0].size();
        queue<pair<int,int> > q;
        int startingPixelColour = image[sr][sc];
        image[sr][sc] = color;
        if(startingPixelColour == color) return image;
        q.push({sr,sc});

        while(!q.empty()){
            int pixcels = q.size();

            while(pixcels--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                int row[4] = {1,-1,0,0};
                int col[4] = {0,0,1,-1};

                for(int k=0; k<4; k++){
                    if(valid(i+row[k],j+col[k]) && image[i+row[k]][j+col[k]]==startingPixelColour ) {
                        image[i+row[k]][j+col[k]] = color;
                        q.push({i+row[k],j+col[k]});
                    }
                }
            }
        }
        return image;
    }
};