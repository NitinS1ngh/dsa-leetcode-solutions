class Solution {
public:
    int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<long long> dis(n, LLONG_MAX);
        vector<long long> paths(n, 0);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

        dis[0] = 0;
        paths[0] = 1;
        pq.push({0, 0});

        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();

            if(d > dis[node]) continue;

            for(auto &it: adj[node]){
                int neib = it.first;
                int wt = it.second;

                if(dis[neib] > d + wt){
                    dis[neib] = d + wt;
                    pq.push({d+wt, neib});
                    paths[neib] = paths[node];
                }
                else if(dis[neib] == d + wt){
                    paths[neib] = (paths[neib] + paths[node])%MOD;
                }
            }
        }

        return paths[n-1]%MOD;
    }
};