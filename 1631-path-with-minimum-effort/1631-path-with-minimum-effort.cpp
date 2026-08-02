class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int rows = h.size();
        int cols = h[0].size();

        vector<vector<int>> effort(rows, vector<int>(cols, 1e9));
        effort[0][0] = 0;

        priority_queue<
            pair<int, pair<int,int>>, 
            vector<pair<int, pair<int,int>>>, 
            greater<pair<int, pair<int,int>>>
        > pq;

        pq.push({0, {0, 0}});
        
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!pq.empty()) {
            int curEffort = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if (r == rows - 1 && c == cols - 1) return curEffort;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    int diff = abs(h[nr][nc] - h[r][c]);
                    int newEffort = max(curEffort, diff);

                    if (newEffort < effort[nr][nc]) {
                        effort[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }
        return 0; 
    }
};