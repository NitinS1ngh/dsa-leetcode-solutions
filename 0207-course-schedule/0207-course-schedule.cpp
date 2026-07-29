class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& nums) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto &edges: nums){
            int u = edges[0];
            int v = edges[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        for(int i=0; i<n; i++){
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto &neighbour: adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0) q.push(neighbour);
            }
        }

        for(int i=0; i<indegree.size(); i++){
            if(indegree[i] != 0) return false;
        }
        return true;
    }
};