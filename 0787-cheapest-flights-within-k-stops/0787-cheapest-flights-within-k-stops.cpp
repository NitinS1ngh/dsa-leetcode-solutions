class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0], v = flights[i][1], w = flights[i][2];
            adj[u].push_back({v, w});
        }

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({0, src, 0});

        vector<int> minStops(n, INT_MAX); // minimum stops used to reach a node

        while (!pq.empty()) {
            auto [cost, node, stops] = pq.top();
            pq.pop();

            if (node == dst) return cost;
            if (stops > k) continue;
            if (stops >= minStops[node]) continue;

            minStops[node] = stops;

            for (int j = 0; j < adj[node].size(); j++) {
                int next = adj[node][j].first;
                int price = adj[node][j].second;
                pq.push({cost + price, next, stops + 1});
            }
        }
        return -1;
    }
};
