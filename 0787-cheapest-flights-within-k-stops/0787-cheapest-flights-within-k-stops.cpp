class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];

            adj[u].push_back({v, w});
        }

        vector<int> dis(n,INT_MAX);
        
        queue<pair<int,int>> q;
        q.push({src,0});
        dis[src] = 0;
        int steps = 0;

        while(!q.empty() && steps<=k){
            int size = q.size();

            while(size--){
                int node = q.front().first;
                int cost = q.front().second;

                q.pop();

                for(auto &it: adj[node]){
                    int neib = it.first;
                    int wt = it.second;

                    if(dis[neib] > cost + wt){
                        dis[neib] = cost + wt;
                        q.push({neib,cost+wt});
                    }
                }
            }
            steps++;
        }

        if(dis[dst] != INT_MAX) return dis[dst];
        else return -1;
        
    }
};
